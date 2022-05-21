#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
public:
    Sphere(double radius): radius_(radius), volume_(pi_ * 4/3 * pow(radius_,3)) {
        if (radius <= 0) throw std::invalid_argument("radius must be positive");
    };
    // Accessor
    double GetRadius() {return radius_;}
    double GetVolume() {return volume_;}

private:
    double const pi_{3.141592};     // if the order is changed, it causes an error
    double const radius_;
    double const volume_;

};

int main() {
    Sphere sphere(5);
    assert(sphere.GetRadius() == 5);
    std::cout << sphere.GetVolume();
    assert(abs(sphere.GetVolume() - 523.6) < 1);
    return 0;
}