# AntiVoice Telegram bot

Template of a C++ service that uses [userver framework](https://github.com/userver-framework/userver).

## Functionality
This project is an educational `userver` service built with a [Telegram API](https://github.com/s3rap1s/telegram-api-userver) (also was written by me for this project). 

* `telegram-bot` component is registered in the `userver` component list and started by `userver::utils::DaemonMain`.
* The service uses built-in `userver` HTTP and DNS clients to talk to the Telegram Bot API.
* PostgreSQL is integrated through the standard `userver` Postgres component and is used for persistent storage.
* Long-running message updates are executed asynchronously with `userver` task processors and background task storage.
* Static configuration follows the usual `userver` split into `static_config.yaml` and `config_vars.yaml`.
* Local runs and tests use the `userver` testsuite/service-runner flow, so `make start-*` starts the service in the same environment that is used by tests.


## Makefile

`PRESET` is either `debug`, `release`, or if you've added custom presets in `CMakeUserPresets.json`, it
can also be `debug-custom`, `release-custom`.

Before `make start-*` or `make test-*`, create `.env` from `.env.example` and set `BOT_TOKEN`.

* `make cmake-PRESET` - run cmake configure, update cmake options and source file lists
* `make build-PRESET` - build the service
* `make test-PRESET` - build the service and run all tests
* `make start-PRESET` - build the service, start it in testsuite environment and leave it running
* `make db-up` - start the PostgreSQL docker compose service and wait until it becomes ready
* `make db-down` - stop and remove docker compose resources
* `make db-reset` - recreate the PostgreSQL service from scratch and remove its volumes
* `make db-logs` - show logs of the PostgreSQL docker compose service
* `make install-PRESET` - build the service and install it in directory set in environment `PREFIX`
* `make` or `make all` - build and run all tests in `debug` and `release` modes
* `make format` - reformat all C++ and Python sources
* `make dist-clean` - clean build files and cmake cache
* `make docker-COMMAND` - run `make COMMAND` in docker environment
* `make docker-clean-data` - stop docker containers


## License

The original template is distributed under the [Apache-2.0 License](https://github.com/userver-framework/userver/blob/develop/LICENSE)
and [CLA](https://github.com/userver-framework/userver/blob/develop/CONTRIBUTING.md). Services based on the template may change
the license and CLA.