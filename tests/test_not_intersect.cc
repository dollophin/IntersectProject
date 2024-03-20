#include "tests.h"

TEST(NotIntersect, CrossingStraightLines) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(-3.93, 3.47, 0),
                                          IntersectProject::Vector3D(4.37147, 1.57313, 5.53607));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(2.06, 0, 0),
                                          IntersectProject::Vector3D(-3.22587, 7.52717, 0));
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    EXPECT_FALSE(is_intersect);
}

TEST(NotIntersect, ParallelLines) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(0, 0, 4),
                                          IntersectProject::Vector3D(0, -4, 0));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(0, 0, 6),
                                          IntersectProject::Vector3D(0, -6, 0));
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    EXPECT_FALSE(is_intersect);
}

TEST(NotIntersect, NotIntersectsSegments) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(-2.68, 2.53, 0.86),
                                          IntersectProject::Vector3D(-1.87, 1.76, 1.5));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(-1.24, 1.17, 2.01),
                                          IntersectProject::Vector3D(-0.59, 0.55, 2.53));
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    EXPECT_FALSE(is_intersect);
}

TEST(NotIntersect, NotIntersectsPointInCommonPlane) {
    IntersectProject::Segment3D segment_1(IntersectProject::Vector3D(1.92, -2.3, 0.63),
                                          IntersectProject::Vector3D(1.39, -2.23, 0.83));
    IntersectProject::Segment3D segment_2(IntersectProject::Vector3D(1.16, -2.83, 0.71),
                                          IntersectProject::Vector3D(0.88, -2.15, 1.02));
    IntersectProject::Space3D space;
    auto [point, is_intersect] = space.Intersect(segment_1, segment_2);
    EXPECT_FALSE(is_intersect);
}

