#include "tests.h"

// Прямые: |A-------B| и |C-------D|

// Тест: |A----|C--B|----D|
TEST(IntersectSegment, Test1) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(-3.76,3.54,0),
                                          IntersectProject::Vector3D(-1.87, 1.76, 1.5));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(-2.68, 2.53, 0.86),
                                          IntersectProject::Vector3D(-1.24, 1.17, 2.01));
    IntersectProject::Segment3D result(IntersectProject::Vector3D(-2.68, 2.53, 0.86),
                                       IntersectProject::Vector3D(-1.87, 1.76, 1.5));
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    IntersectProject::Segment3D expect = std::get<IntersectProject::Segment3D>(point);
    expect == result;
    EXPECT_FALSE(!is_intersect);
    EXPECT_TRUE(expect == result);
}

// Тест: |A---|C---D|---B|
TEST(IntersectSegment, Test2) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(-1.87, 1.76, 1.5),
                                          IntersectProject::Vector3D(0, 0, 3));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(-1.24, 1.17, 2.01),
                                          IntersectProject::Vector3D(-0.59, 0.55, 2.53));
    IntersectProject::Segment3D result(IntersectProject::Vector3D(-1.24, 1.17, 2.01),
                                       IntersectProject::Vector3D(-0.59, 0.55, 2.53));
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    IntersectProject::Segment3D expect = std::get<IntersectProject::Segment3D>(point);
    expect == result;
    EXPECT_FALSE(!is_intersect);
    EXPECT_TRUE(std::get<IntersectProject::Segment3D>(point) == result);
}


// Тест: |C--|A---D|---B|
TEST(IntersectSegment, Test3) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(-1.87, 1.76, 1.5),
                                          IntersectProject::Vector3D(-0.59, 0.55, 2.53));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(-2.68, 2.53, 0.86),
                                          IntersectProject::Vector3D(-1.24, 1.17, 2.01));
    IntersectProject::Segment3D result(IntersectProject::Vector3D(-1.87, 1.76, 1.5),
                                       IntersectProject::Vector3D(-1.24, 1.17, 2.01));
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    IntersectProject::Segment3D expect = std::get<IntersectProject::Segment3D>(point);
    expect == result;
    EXPECT_TRUE(std::get<IntersectProject::Segment3D>(point) == result);
}

// Тест: |C--|A---B|---D|
TEST(IntersectSegment, Test4) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(1.39, -2.23, 0.83),
                                          IntersectProject::Vector3D(0.88, -2.15, 1.02));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(1.92, -2.3, 0.63),
                                          IntersectProject::Vector3D(-0.35, -1.97, 1.48));
    IntersectProject::Segment3D result(IntersectProject::Vector3D(1.39, -2.23, 0.83),
                                       IntersectProject::Vector3D(0.88, -2.15, 1.02));
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    IntersectProject::Segment3D expect = std::get<IntersectProject::Segment3D>(point);
    expect == result;
    EXPECT_TRUE(std::get<IntersectProject::Segment3D>(point) == result);
}

// Тест: C|A---B|---D|
TEST(IntersectSegment, Test5) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(1.92, -2.3, 0.63),
                                          IntersectProject::Vector3D(1.39, -2.23, 0.83));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(1.92, -2.3, 0.63),
                                          IntersectProject::Vector3D(0.88, -2.15, 1.02));
    IntersectProject::Segment3D result(IntersectProject::Vector3D(1.92, -2.3, 0.63),
                                       IntersectProject::Vector3D(1.39, -2.23, 0.83));
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    IntersectProject::Segment3D expect = std::get<IntersectProject::Segment3D>(point);
    expect == result;
    EXPECT_TRUE(std::get<IntersectProject::Segment3D>(point) == result);
}

// Тест: C---|A----D|B
TEST(IntersectSegment, Test6) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(1.39, -2.23, 0.83), 
                                          IntersectProject::Vector3D(1.92, -2.3, 0.63));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(0.88, -2.15, 1.02), 
                                          IntersectProject::Vector3D(1.92, -2.3, 0.63));
    IntersectProject::Segment3D result(IntersectProject::Vector3D(1.39, -2.23, 0.83),
                                       IntersectProject::Vector3D(1.92, -2.3, 0.63));
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    IntersectProject::Segment3D expect = std::get<IntersectProject::Segment3D>(point);
    expect == result;
    EXPECT_TRUE(std::get<IntersectProject::Segment3D>(point) == result);
}