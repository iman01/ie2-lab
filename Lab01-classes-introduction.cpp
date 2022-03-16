#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Student{

    std::string name;
    std::string surname;
    std::vector<float> grades;
public:
    Student(){}

    Student(std::string n, std::string s, std::vector<float> g){
        name = n;
        surname = s;
        grades = g;
    }

    void set_name(std::string n){ //setter
        name = n;
    }

    std::string get_name(){ //getter
        return name;
    }

    float calculate_grade(){
        std::cout << "calculating grade for " << name << std::endl;
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum/ grades.size();
    }

    bool add_grade(float grade){
        if(grade >= 2.0 && grade <= 5.0){
            grades.push_back(grade);
            return true;
        }
        return false;
    }

};



int main()
{

    Student student3;

    student3.set_name("Alex");
    std::cout << "student name is " << student3.get_name() << std::endl;
    Student student2{"iman", "es", {0.0,1.1}};
    student3.add_grade(4.5);
    student3.add_grade(3.5);


    float ave = student3.calculate_grade();

    std::cout << "ave grade is " << ave << std::endl;

    return 0;
}
