#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
public:
    static float constexpr pi_{3.14159};

    static double Volume(int radius) {
        return pi_ * 4 / 3 * pow(radius, 3);
    }

private:
};

// Test
int main(void) {
    assert(abs(Sphere::Volume(5) - 523.6) < 1);
}