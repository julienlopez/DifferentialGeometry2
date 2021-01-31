include_directories(".")
include_directories("../lib")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SOURCE_FILES ./*)
add_executable(unit_tests ${SOURCE_FILES})

target_link_libraries(unit_tests lib ${CONAN_LIBS})

include(CTest)
include(Catch)
catch_discover_tests(unit_tests)
