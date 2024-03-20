#ifndef INTERSECT_PROJECT_SRC_SPACE_H
#define INTERSECT_PROJECT_SRC_SPACE_H

#include "geometry_objects.h"

#include <vector>
#include <map>
#include <utility>
#include <variant>

namespace IntersectProject {

using Intersection = std::pair<std::variant<Point, Segment3D>, bool>;

class Space3D {

public:
  Intersection Intersect(const Segment3D &seg_first,
                         const Segment3D &seg_second);

  double MixedProduct(const Vector3D &vec_first, const Vector3D &vec_second,
                      const Vector3D &vec_third);
  double ScalarProduct(const Vector3D &vec_first, const Vector3D &vec_second);
  Vector3D CrossProduct(const Vector3D &vec_first, const Vector3D &vec_second);
  std::pair<double, double> KramersMethod(const Line &line_first, const Line& line_second);

private:
  bool IsBetween(const Vector3D &first, const Vector3D &second);
  Intersection SearchCommonSegment(const Segment3D &seg_first,
                                   const Segment3D &seg_second,
                                   const Vector3D &guide_first,
                                   const Vector3D &guide_second);
};

} // namespace IntersectProject

#endif // INTERSECT_PROJECT_SRC_SPACE_H