#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
public:
    Sphere(double radius): radius_(radius) {};

    // Accessor
    double GetRadius() {return radius_;}
    double GetVolume() {return volume_;}

    // Mutator
    void SetRadius(double radius) {
        radius_ = radius;
        validate();
    }
    void SetVolume() {
        volume_ = pi_ * 4/3 * pow(GetRadius(),3);
    }

private:
    double const pi_{3.141592};     // if the order is changed, it causes an error
    double radius_;
    double volume_;
    void validate() { if (GetRadius() <= 0) throw std::invalid_argument("radius must be positive");}
};

int main() {
    Sphere sphere(5);
    assert(sphere.GetRadius() == 5);
    sphere.SetVolume();
    std::cout << sphere.GetVolume();

    std::cout << "\n";

    sphere.SetRadius(3);
    assert(sphere.GetRadius() == 3);
    sphere.SetVolume();
    std::cout << sphere.GetVolume();

    bool caught{false};
    try {
        sphere.SetRadius(-1);
    } catch (...) {
        caught = true;
    }
    assert(caught);

    return 0;
}