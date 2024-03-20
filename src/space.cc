#include "space.h"

#define INF 10e9

namespace IntersectProject {

double Space3D::MixedProduct(const Vector3D &vec_first,
                             const Vector3D &vec_second,
                             const Vector3D &vec_third) {
  double first_part = vec_first.GetX() * (vec_second.GetY() * vec_third.GetZ() -
                                          vec_second.GetZ() * vec_third.GetY());
  double second_part =
      vec_first.GetY() * (vec_second.GetX() * vec_third.GetZ() -
                          vec_second.GetZ() * vec_third.GetX());
  double third_part = vec_first.GetZ() * (vec_second.GetX() * vec_third.GetY() -
                                          vec_second.GetY() * vec_third.GetX());
  return first_part - second_part + third_part;
}

double Space3D::ScalarProduct(const Vector3D &vec_first,
                              const Vector3D &vec_second) {
  double first_part = vec_first.GetX() * vec_second.GetX();
  double second_part = vec_first.GetY() * vec_second.GetY();
  double third_part = vec_first.GetZ() * vec_second.GetZ();
  return first_part + second_part + third_part;
}

Vector3D Space3D::CrossProduct(const Vector3D &vec_first,
                               const Vector3D &vec_second) {
  double first_part = vec_first.GetY() * vec_second.GetZ() -
                      vec_first.GetZ() * vec_second.GetY();
  double second_part = vec_first.GetX() * vec_second.GetZ() -
                       vec_first.GetZ() * vec_second.GetX();
  double third_part = vec_first.GetX() * vec_second.GetY() -
                      vec_first.GetY() * vec_second.GetX();
  return Vector3D(first_part, -second_part, third_part);
}

bool Space3D::IsBetween(const Vector3D &first, const Vector3D &second) {
  return (ScalarProduct(first, second) > 0) &&
         first.GetLenght() < second.GetLenght();
}

Intersection Space3D::SearchCommonSegment(const Segment3D &seg_first,
                                          const Segment3D &seg_second,
                                          const Vector3D &guide_first,
                                          const Vector3D &guide_second) {
  Intersection result = std::make_pair(Point(0, 0, 0), false);
  // Если они лежат на одной прямой:
  // Есть два отрезка: AB и CD
  Vector3D c_a = seg_first.GetStart() - seg_second.GetStart();
  Vector3D c_b = seg_first.GetEnd() - seg_second.GetStart();
  Vector3D a_c = seg_second.GetStart() - seg_first.GetStart();
  Vector3D a_d = seg_second.GetEnd() - seg_first.GetStart();
  // Проверяем принадлежат ли точки A или B отрезку CD и наоборот
  // Условие: если A лежит между CD тогда: (CA*CD) > 0 && |CA| < |CD|
  std::vector<Vector3D> vectors = {a_c, c_a, a_d, c_b};
  std::map<int, Vector3D> vectors_map;
  for(size_t i = 0; i < vectors.size(); i++) {
    vectors_map[i] = vectors[i];
  }
  std::vector<Point> all_points = {seg_second.GetStart(), seg_first.GetStart(),
                                   seg_second.GetEnd(), seg_first.GetEnd()};
  std::vector<Point> start_end;
  Vector3D guide_vector;

  for(int i = 0; i < 4 && start_end.size() != 2; i++) {
    guide_vector = (i % 2 == 0) ? guide_first : guide_second;
    if(vectors_map.find(i) != vectors_map.end()) {
        if(IsBetween(vectors_map[i], guide_vector)) {
            start_end.push_back(all_points[i]);
            vectors_map.erase(i);
            i = -1;
        }
    }
  }

  // Если нет общих сегментов или найдена только одна точка, ищем общую точку
  if(start_end.size() == 2) {
    result = std::make_pair(Segment3D(start_end[0], start_end[1]), true);
  } else if(start_end.size() == 1) {
    if(seg_first.GetStart() == seg_second.GetStart())
      start_end.push_back(seg_first.GetStart());
    else if(seg_first.GetEnd() == seg_second.GetEnd())
      start_end.push_back(seg_first.GetEnd());
    result = std::make_pair(Segment3D(start_end[0], start_end[1]), true);
  } else {
    if(seg_first.GetStart() == seg_second.GetEnd())
      result = std::make_pair(Point(seg_first.GetStart()), true);
    else if(seg_second.GetStart() == seg_first.GetEnd())
      result = std::make_pair(Point(seg_first.GetEnd()), true);
  }

  return result;
}

std::pair<double, double> Space3D::KramersMethod(const Line &line_first, 
                                                const Line& line_second) {
  Vector3D guide_first = line_first.GetGuidVector();
  Vector3D guide_second = line_second.GetGuidVector();
  Point ref_first = line_first.GetRefPoint();
  Point ref_second = line_second.GetRefPoint();
  double t = INF, s = INF;
  double det = -guide_first.GetX()*guide_second.GetY() +
               guide_second.GetX()*guide_first.GetY();
  double t_det = -(ref_second - ref_first).GetX()*guide_second.GetY() +
                 (ref_second -ref_first).GetY()*guide_second.GetX();
  double s_det = guide_first.GetX()*(ref_second - ref_first).GetY() -
                 guide_first.GetY()*(ref_second - ref_first).GetX();
  if(det){
    t = t_det/det;
    s = s_det/det;
  }
  return std::make_pair(t, s);
}

Intersection Space3D::Intersect(const Segment3D &seg_first,
                                const Segment3D &seg_second) {
  Vector3D ref_vec = seg_second.GetStart() - seg_first.GetStart();
  Vector3D guide_first = seg_first.GetLine().GetGuidVector();
  Vector3D guide_second = seg_second.GetLine().GetGuidVector();
  Intersection result = std::make_pair(Point(0, 0, 0), false);
  //Если прямые, которым принадлежат отрезки, лежат в разных плоскостях -
  //пересечения нет.
  if (fabs(MixedProduct(guide_first, guide_second, ref_vec)) > 10e-2)
    return result;
  // Проверка на параллельность прямых.
  if (fabs(CrossProduct(guide_first, guide_second).GetLenght()) < 10e-2) {
    // Проверим лежат ли отрезки на одной прямой
    if (fabs(CrossProduct(guide_first, ref_vec).GetLenght()) < 10e-2)
    // Если да, ищем отрезок, который принадлежит обоим отрезкам
      result =
          SearchCommonSegment(seg_first, seg_second, guide_first, guide_second);
    return result;
  } else {
    // Иначе, если прямые лежат в одной плоскости, решаем систему уравнений вида:
    // kt - k's = x_02 - x_01
    // lt - l's = y_02 - y_01
    //         ...
    // Система переопределена, но решение будет т.к. прямые лежат в одной плоскости
    // Условие пересечения: 0 <= t <= 1, 0 <= s <= 1
    auto t_s = KramersMethod(seg_first.GetLine(), seg_second.GetLine());
    if((t_s.first >= 0 && t_s.first <= 1) && (t_s.second >= 0 && t_s.second <= 1)) {
      Point new_vec = Point(seg_first.GetStart() + guide_first*t_s.first);
      new_vec == guide_first;
      result = std::make_pair(Point(seg_first.GetStart() + guide_first*t_s.first), true);
    }
  }
  return result;
}

} // namespace IntersectProject