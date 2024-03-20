#include "tests.h"

TEST(IntersectPoints, InTheMiddleBothSegments) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(1.92, -2.3, 0.63),
                                          IntersectProject::Vector3D(-0.35, -1.97, 1.48));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(1.22, -2.98, 0.65),
                                          IntersectProject::Vector3D(0.46, -1.12, 1.49));
    IntersectProject::Point result(0.88, -2.15, 1.02);
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    EXPECT_FALSE(!is_intersect);
    EXPECT_TRUE(std::get<IntersectProject::Point>(point) == result);
}

TEST(IntersectPoints, AtTheEndOneSegment) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(1.39, -2.23, 0.83),
                                          IntersectProject::Vector3D(0.5, 0, 0));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(1.92, -2.3, 0.63),
                                          IntersectProject::Vector3D(0.88, -2.15, 1.02));
    IntersectProject::Point result(1.39, -2.23, 0.83);
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    EXPECT_FALSE(!is_intersect);
    EXPECT_TRUE(std::get<IntersectProject::Point>(point) == result);
}

TEST(IntersectPoints, AtTheEndBothSegments) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(-0.35, -1.97, 1.48),
                                          IntersectProject::Vector3D(0.88, -2.15, 1.02));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(0.46, -1.12, 1.49),
                                          IntersectProject::Vector3D(0.88, -2.15, 1.02));
    IntersectProject::Point result(0.88, -2.15, 1.02);
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    EXPECT_FALSE(!is_intersect);
    EXPECT_TRUE(std::get<IntersectProject::Point>(point) == result);
}

TEST(IntersectPoints, AtTheStartBothSegments) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(0.88, -2.15, 1.02), 
                                          IntersectProject::Vector3D(-0.35, -1.97, 1.48));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(0.88, -2.15, 1.02),
                                          IntersectProject::Vector3D(0.46, -1.12, 1.49));
    IntersectProject::Point result(0.88, -2.15, 1.02);
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    EXPECT_FALSE(!is_intersect);
    EXPECT_TRUE(std::get<IntersectProject::Point>(point) == result);
}

TEST(IntersectPoints, AtTheEndOfSegmentOnCommonLine) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(1.92, -2.3, 0.63), 
                                          IntersectProject::Vector3D(1.39, -2.23, 0.83));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(1.39, -2.23, 0.83),
                                          IntersectProject::Vector3D(0.88, -2.15, 1.02));
    IntersectProject::Point result(1.39, -2.23, 0.83);
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    EXPECT_FALSE(!is_intersect);
    EXPECT_TRUE(std::get<IntersectProject::Point>(point) == result);
}

TEST(IntersectPoints, AtTheStartOfSegmentOnCommonLine) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(1.39, -2.23, 0.83), 
                                          IntersectProject::Vector3D(1.92, -2.3, 0.63));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(0.88, -2.15, 1.02),
                                          IntersectProject::Vector3D(1.39, -2.23, 0.83));
    IntersectProject::Point result(1.39, -2.23, 0.83);
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    EXPECT_FALSE(!is_intersect);
    EXPECT_TRUE(std::get<IntersectProject::Point>(point) == result);
}