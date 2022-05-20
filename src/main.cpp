#include <iostream>
#include <string>
#include <cassert>

class Student {
private:
    std::string name_;
    int grade_;
    double gpa_;
    void validate();    // Validate

public:
    // Constructor
    Student(std::string name, int grade, double gpa): name_(name), grade_(grade), gpa_(gpa){};

    // Setter(Mutator)
    void SetName(std::string name) {
        name_ = name;
        validate();
    }
    void SetGrade(int grade) {
        grade_ = grade;
        validate();
    }
    void SetGpa(double gpa) {
        gpa_ = gpa;
        validate();
    }

    // Getter(Accessor)
    std::string GetName() {return name_;}
    int GetGrade() {return grade_;}
    double GetGpa() {return gpa_;}

};

void Student::validate() {
    if (GetGrade() < 0 || GetGrade() > 12 || GetGpa() < 0.0 || GetGpa() > 4.0) {
        throw std::invalid_argument("argument out of bounds");
    }
}

int main() {
    Student std1("John", 11, 3.0);
    assert(std1.GetName() == "John");
    assert(std1.GetGrade() == 11);
    assert(std1.GetGpa() == 3.0);

    bool caught{false};
    try {
        std1.SetGrade(20);
    }
    catch(...) {
        caught = true;
    }
    assert(caught);

    return 0;
}