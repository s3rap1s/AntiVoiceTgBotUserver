add_library(telegram)
add_library(telegram::api ALIAS telegram)

file(GLOB TELEGRAM_SOURCES
    src/*.cpp
    src/internal/*.cpp
    src/methods/*.cpp
    src/types/*.cpp
)

target_sources(telegram PRIVATE ${TELEGRAM_SOURCES})

target_include_directories(
    telegram
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
    telegram
    PUBLIC
        userver::core
)
