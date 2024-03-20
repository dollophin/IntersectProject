# IntersectProject

## Используемый стандарт языка:
* C++17

## Сборка проекта:
* Сборка производится с помощью CMake. Для тогда чтобы собрать проект необходимо прописать: make install. Исполняемый файл тестов "tests" после сборки будет расположен в директории build/tests.

## Информация о проекте:
* Функция Intersect реализована, как метод класса Space3D, который содержит методы для работы с геометрическими объектами. Функция возращает пару значений (псевдоним Intersection):
```C++
std::pair<std::variant<Segment3D, Point>, bool>
```
* Булево значение содержит информацию о том есть ли пересечение, а variant может содержать точку (Point это псевдоним Vector3D), в случае когда отрезки пересекаются в одной точке, и отрезок в случае когда отрезки лежат на одной прямой и в пересечении дают отрезок. В проекте использовался псевдоним Point, когда подразумевалась точка и Vector3D, когда подразумевался вектор.
