PROJECT_NAME = telegram_bot
NPROCS ?= $(shell nproc)
CLANG_FORMAT ?= clang-format
DOCKER_IMAGE ?= ghcr.io/userver-framework/ubuntu-22.04-userver-pg-dev:v2.14
COMPOSE ?= docker compose
DB_SERVICE ?= postgres-db
BUILD_ROOT ?= $(HOME)/.cache/telegram-bot
CMAKE_OPTS ?=
# If we're under TTY, pass "-it" to "docker run"
DOCKER_ARGS = $(shell /bin/test -t 0 && /bin/echo -it || echo)
PRESETS ?= debug release

.PHONY: all
all: test-debug test-release

.PHONY: db-up db-down db-reset db-logs
db-up:
	$(COMPOSE) up -d --wait $(DB_SERVICE)

db-down:
	$(COMPOSE) down

db-reset:
	$(COMPOSE) down -v
	$(COMPOSE) up -d --wait $(DB_SERVICE)

db-logs:
	$(COMPOSE) logs $(DB_SERVICE)

# Run cmake
.PHONY: $(addprefix cmake-, $(PRESETS))
$(addprefix cmake-, $(PRESETS)): cmake-%:
	cmake --preset $* $(CMAKE_OPTS)

$(addsuffix /CMakeCache.txt, $(addprefix $(BUILD_ROOT)/build-, $(PRESETS))): $(BUILD_ROOT)/build-%/CMakeCache.txt:
	$(MAKE) cmake-$*

# Build using cmake
.PHONY: $(addprefix build-, $(PRESETS))
$(addprefix build-, $(PRESETS)): build-%: $(BUILD_ROOT)/build-%/CMakeCache.txt
	cmake --build $(BUILD_ROOT)/build-$* -j $(NPROCS) --target $(PROJECT_NAME)

# Test
.PHONY: $(addprefix test-, $(PRESETS))
$(addprefix test-, $(PRESETS)): test-%: $(BUILD_ROOT)/build-%/CMakeCache.txt
	cmake --build $(BUILD_ROOT)/build-$* -j $(NPROCS)
	set -a; [ -f .env ] && . ./.env; set +a; \
	cd $(BUILD_ROOT)/build-$* && ((test -t 1 && GTEST_COLOR=1 PYTEST_ADDOPTS="--color=yes" ctest -V) || ctest -V)

# Start the service (via testsuite service runner)
.PHONY: $(addprefix start-, $(PRESETS))
$(addprefix start-, $(PRESETS)): db-up
	set -a; [ -f .env ] && . ./.env; set +a; \
	cmake --build $(BUILD_ROOT)/build-$(patsubst start-%,%,$@) -v --target start-$(PROJECT_NAME)

# Cleanup data
.PHONY: $(addprefix clean-, $(PRESETS))
$(addprefix clean-, $(PRESETS)): clean-%:
	cmake --build $(BUILD_ROOT)/build-$* --target clean

.PHONY: dist-clean
dist-clean:
	rm -rf $(BUILD_ROOT)/build-*
	rm -rf tests/__pycache__/
	rm -rf tests/.pytest_cache/
	rm -rf .ccache
	rm -rf .vscode/.cache
	rm -rf .vscode/compile_commands.json

# Install
.PHONY: $(addprefix install-, $(PRESETS))
$(addprefix install-, $(PRESETS)): install-%: build-%
	cmake --install $(BUILD_ROOT)/build-$* -v --component $(PROJECT_NAME)

.PHONY: install
install: install-release

# Format the sources
.PHONY: format
format:
	find src -name '*pp' -type f | xargs $(CLANG_FORMAT) -i
	find tests -name '*.py' -type f | xargs autopep8 -i

# Start targets makefile in docker wrapper.
# The docker mounts the whole service's source directory,
# so you can do some stuff as you wish, switch back to host (non-docker) system
# and still able to access the results.
.PHONY: $(addprefix docker-cmake-, $(PRESETS)) $(addprefix docker-build-, $(PRESETS)) $(addprefix docker-test-, $(PRESETS)) $(addprefix docker-clean-, $(PRESETS))
$(addprefix docker-cmake-, $(PRESETS)) $(addprefix docker-build-, $(PRESETS)) $(addprefix docker-test-, $(PRESETS)) $(addprefix docker-clean-, $(PRESETS)): docker-%:
	docker run $(DOCKER_ARGS) \
		--network=host \
		-v $$PWD:$$PWD \
		-w $$PWD \
		$(DOCKER_IMAGE) \
		env CCACHE_DIR=$$PWD/.ccache \
		    HOME=/home/user \
		    $$PWD/run_as_user.sh $(shell /bin/id -u) $(shell /bin/id -g) make $*
