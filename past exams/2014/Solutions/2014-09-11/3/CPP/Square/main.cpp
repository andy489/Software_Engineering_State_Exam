#include <iostream>
#include <cstdlib>

using namespace std;

float abs(float a) {
    return a > 0 ? a : -a;
}

void square(const size_t N, const float *x, const float *y) {
    float mostLeftX = x[0];
    float mostRightX = x[0];

    float mostDownY = y[0];
    float mostUpY = y[0];

    for (int i = 0; i < N; ++i) {
        mostLeftX = min(x[i], mostLeftX);
        mostRightX = max(x[i], mostRightX);

        mostDownY = min(y[i], mostDownY);
        mostUpY = max(y[i], mostUpY);
    }

    float distX = abs(mostRightX - mostLeftX);
    float distY = abs(mostUpY - mostDownY);

    float side = max(distX, distY);

    float centerX = mostLeftX + side / 2.0f;
    float centerY = mostDownY + side / 2.0f;

    printf("Square center coordinates: (%.1f, %.1f)\nSide length: %.1f\n", centerX, centerY, side);
}

int main() {
    const float x[] = {2.2f, 3.3f, 3.0f, 4.0f, -3.0f};;
    const float y[] = {3.2f, -1.3f, 2.0f, 1.0f, -1.5f};

    square(sizeof x / sizeof(float), x, y);

    return 0;
}
