#include <iostream>
#include <cmath>

struct Point {
    float x;
    float y;

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }

    double getEuclidDist(const Point &other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

struct Circle {
    Point center;
    float r;
};
enum RelativePosition {
    NO_COMMON_POINTS,
    TOUCHING,
    INTERSECTING,
    SAME
};

RelativePosition findRelativePosition(Circle c1, Circle c2) {
    static const float EPS = 1e-6;

    if (c1.r > c2.r) {
        return findRelativePosition(c2, c1);
    }

    float dist = c1.center.getEuclidDist(c2.center);
    if (dist < EPS) {
        if (fabs(c1.r - c2.r) < EPS) {
            return RelativePosition::SAME;
        }
        return RelativePosition::NO_COMMON_POINTS;
    }

    if (fabs(c1.r + c2.r - dist) < EPS || fabs(c2.r - c1.r - dist) < EPS) {
        return RelativePosition::TOUCHING;
    }

    if (c1.r + c2.r > dist || c2.r - c1.r < dist) {
        return RelativePosition::NO_COMMON_POINTS;
    }

    return RelativePosition::INTERSECTING;
}

int main() {
    std::cout << findRelativePosition({1, 1, 1}, {1, -2, 2}) << std::endl; // TOUCHING
    std::cout << findRelativePosition({1, 1, 1}, {1.1, 1.1, 3}) << std::endl; // NO_COMMON_POINTS
    std::cout << findRelativePosition({1, 1, 1}, {1.1, 1.1, 0.1}) << std::endl; // NO_COMMON_POINTS

    return 0;
}