include_directories(".")

file(GLOB_RECURSE SOURCE_FILES ./*)
add_executable(DifferentialGeometry2 ${SOURCE_FILES})
