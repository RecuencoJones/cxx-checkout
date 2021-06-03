file(GLOB_RECURSE TEST_SOURCES "*.cpp" "*.h")

add_executable(test ${TEST_SOURCES})

add_test(
    NAME test
    COMMAND test
)

target_link_libraries(
    test
    PUBLIC main_lib ${CONAN_LIBS}
)