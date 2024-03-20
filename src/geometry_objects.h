#ifndef INTERSECT_PROJECT_SRC_GEOMETRY_OBJ_H
#define INTERSECT_PROJECT_SRC_GEOMETRY_OBJ_H

#include <cmath>

namespace IntersectProject {

class Space3D;

class Vector3D {
public:
  Vector3D() : _x(0), _y(0), _z(0){};
  Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

  double GetX() const { return _x; }
  double GetY() const { return _y; }
  double GetZ() const { return _z; }
  double GetLenght() const { return sqrt(_x * _x + _y * _y + _z * _z); }

  Vector3D operator+(const Vector3D &other) const {
    Vector3D new_vector = Vector3D(_x + other._x, _y + other._y, _z + other._z);
    return new_vector;
  }

  Vector3D operator-(const Vector3D &other) const {
    Vector3D new_vector = Vector3D(_x - other._x, _y - other._y, _z - other._z);
    return new_vector;
  }

  Vector3D operator*(const double val) const {
     Vector3D new_vector = Vector3D(_x*val, _y*val, _z*val);
     return new_vector;
  }

  bool operator==(const Vector3D &other) const {
    bool first = fabs((_x - other._x)) < 10e-2;
    bool second = fabs((_y - other._y)) < 10e-2;
    bool third = fabs((_z - other._z)) < 10e-2;
    return first && second && third;
  }

private:
  double _x, _y, _z;
};

using Point = Vector3D;

class Line {
public:
  Line(const Vector3D &point, const Vector3D &g_vector)
      : _ref_point(point), _guiding_vector(g_vector) {}

  auto GetGuidVector() const { return _guiding_vector; }
  auto GetRefPoint() const { return _ref_point; }

private:
  Point _ref_point;
  Vector3D _guiding_vector;
};

class Segment3D {

public:
  Segment3D(const Vector3D &start, const Vector3D &end)
      : _start(start), _end(end),
        _segment_line(_start, Vector3D(_end - start)) {}

  auto GetStart() const { return _start; }
  auto GetEnd() const { return _end; }
  auto GetLine() const { return _segment_line; }

  bool operator==(const Segment3D &other) const {
    return (_start == other._start && _end == other._end) ||
           (_start == other._end && _end == other._start);
  }

private:
  Point _start;
  Point _end;
  Line _segment_line;
};
} // namespace IntersectProject

#endif // INTERSECT_PROJECT_SRC_GEOMETRY_OBJ_H