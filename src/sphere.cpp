#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
public:
    // static member variable is initialized only once and shared by all members in the class
    static int counter;
    Sphere(double radius): radius_(radius) {}

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
    // if I want to initiate pi_ in compile time, I have to set the variable as constexpr
    // on the other hand, if I want to initiate the variable in runtime, it should be const
    static double constexpr pi_{3.141592};
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