cmake_minimum_required(VERSION 3.14)

project(IntersectProject)

set(SOURCE_TESTS tests.cc test_intersect_points.cc test_intersect_segments.cc test_not_intersect.cc)

enable_testing()

add_executable(test ${SOURCE_TESTS})

target_link_libraries(
    test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test)

target_link_libraries(test intersect_lib)