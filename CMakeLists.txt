cmake_minimum_required(VERSION 3.12...3.31)
project(telegram_bot CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(DownloadUserver)

find_package(Boost REQUIRED COMPONENTS context)

find_package(
    userver
    COMPONENTS core #
               postgresql
    QUIET
)
if(NOT userver_FOUND)
    # Tries TRY_DIR first, falls back to downloading userver from GitHub using CPM.
    download_userver(TRY_DIR third_party/userver)
endif()

userver_setup_environment()

# Common sources
include_directories(src)

add_subdirectory(telegram_api)

# The Service
add_executable(${PROJECT_NAME}
    src/bot/core/gradual_editor.cpp
    src/bot/db/message_storage.cpp
    src/bot/db/user_storage.cpp
    src/bot/handlers/callback_query.cpp
    src/bot/handlers/command.cpp
    src/bot/handlers/inline_query.cpp
    src/bot/handlers/message.cpp
    src/bot/types/speed.cpp
    src/bot/utils/text_utils.cpp
    src/bot/bot_app.cpp
    src/components/tg_bot_component.cpp
    src/main.cpp
)
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        telegram::api
        userver::core
        userver::postgresql
)

# # Unit Tests
# add_executable(${PROJECT_NAME}_unittest src/greeting_test.cpp)
# target_link_libraries(${PROJECT_NAME}_unittest PRIVATE ${PROJECT_NAME}_objs userver::utest)
# add_google_tests(${PROJECT_NAME}_unittest)

# # Benchmarks
# add_executable(${PROJECT_NAME}_benchmark src/greeting_benchmark.cpp)
# target_link_libraries(${PROJECT_NAME}_benchmark PRIVATE ${PROJECT_NAME}_objs userver::ubench)
# add_google_benchmark_tests(${PROJECT_NAME}_benchmark)

# Functional testing / service runner target (`start-${PROJECT_NAME}`)
userver_testsuite_add_simple()

# Install
include(GNUInstallDirs)

if(DEFINED ENV{PREFIX})
    message(STATUS "Set install prefix: $ENV{PREFIX}")
    file(TO_CMAKE_PATH "$ENV{PREFIX}" PREFIX_PATH)
    set(CMAKE_INSTALL_PREFIX "${PREFIX_PATH}")
endif()

file(GLOB CONFIGS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/configs/*.yaml ${CMAKE_CURRENT_SOURCE_DIR}/configs/*.json)

install(
    TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT ${PROJECT_NAME}
)
install(
    FILES ${CONFIGS_FILES}
    DESTINATION ${CMAKE_INSTALL_SYSCONFDIR}/${PROJECT_NAME}
    COMPONENT ${PROJECT_NAME}
)
