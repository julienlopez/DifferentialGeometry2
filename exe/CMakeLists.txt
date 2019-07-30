include_directories(".")
include_directories("../lib")

file(GLOB_RECURSE SOURCE_FILES ./*)
add_executable(DifferentialGeometry2 ${SOURCE_FILES})
