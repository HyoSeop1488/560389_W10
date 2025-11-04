// Muhammad Izzudinn Yusuf
// 25/560389/TK/63290

#include <iostream>
using namespace std;

struct nameType {
    string first;
    string last;
};

struct courseType {
    string name;
    int callNum;
    int credits;
    char grade;
};

struct studentType {
    nameType name;
    double gpa;
    courseType course;
};

int main(){
    studentType student;
    studentType classList[100];
    courseType course;
    nameType name;

    cout << "-------Statement-------" << endl;
    // 1.)
    student.course.callNum = "CSC230"; // a value of type 'int' cannot be assigned to an entity of type 'string'
    // 2.)
    cin >> student.name; // no '>>' operator matches these operands
    // 3.)
    classList[0] = name; // no viable overloaded '='
    // 4.)
    classList[1].gpa = 3.45; // valid
    // 5.)
    name = classList[15].name; // valid
    // 6.)
    student.name = name; // valid
    // 7.)
    cout << classList[10] << endl; // no '<<' operator matches these operands
    // 8.)
    for (int j=0; j < 100; j++)
    classList[j].name = name; // valid
    // 9.)
    classList.course.credits = 3; // 'course' is not a member of 'studentType'
    // 10.)
    course = studentType.course; // 'course' is not a member of 'studentType'
    return 0;
}