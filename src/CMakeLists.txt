file(GLOB_RECURSE SOURCES "*.cpp" "*.h")

add_executable(main ${SOURCES})

add_library(main_lib ${SOURCES})