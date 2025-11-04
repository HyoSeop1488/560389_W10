// Muhammad Izzudinn Yusuf
// 25/560389/TK/63290

#include <iostream>
using namespace std;

const int NUM_STUDENTS = 20;

struct studentType{
    string studentFName;
    string studentLName;
    int testScore;
    char courseGrade;
};

void initializeStudents(studentType students[], int size){
    string firstNames[] = {"Max", "Charles", "Lewis", "Oscar", "Yuki", "George", "Kimi", "Pierre", "Franco", "Ollie",
                           "Esteban", "Fernando", "Lance", "Isack", "Liam", "Nico", "Gabriel", "Alex", "Carlos", "Lando"};
    string lastNames[] = {"Verstappen", "Leclerc", "Hamilton", "Piastri", "Tsunoda", "Russel", "Antoneli", "Gasly", "Colapinto", "Bearman",
                          "Ocon", "Alonso", "Stroll", "Hadjar", "Lawson", "Hulkenberg", "Bortoleto", "Albon", "Sainz jr", "Norris"};
    int testScores[] = {85, 92, 78, 88, 90, 95, 80, 83, 87, 91,
                        76, 89, 94, 82, 84, 93, 77, 81, 86, 60};

    for (int i = 0; i < size; i++) {
        students[i].studentFName = firstNames[i];
        students[i].studentLName = lastNames[i];
        students[i].testScore = testScores[i];
    }
}

void assignGrades(studentType students[], int size){
    for (int i = 0; i < size; i++) {
        if (students[i].testScore >= 90)
            students[i].courseGrade = 'A';
        else if (students[i].testScore >= 80)
            students[i].courseGrade = 'B';
        else if (students[i].testScore >= 70)
            students[i].courseGrade = 'C';
        else if (students[i].testScore >= 60)
            students[i].courseGrade = 'D';
        else
            students[i].courseGrade = 'F';
    }
}

string highValueName(const studentType students[], int size){
    int highIndex = 0;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > students[highIndex].testScore) {
            highIndex = i;
        }
    }
    return students[highIndex].studentFName + " " + students[highIndex].studentLName;
}

int highValueIndex(const studentType students[], int size){
    int highIndex = 0;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > students[highIndex].testScore) {
            highIndex = i;
        }
    }
    return highIndex;
}

int main(){
    studentType students[NUM_STUDENTS];

    initializeStudents(students, NUM_STUDENTS);
    assignGrades(students, NUM_STUDENTS);

    cout << "Displaying Student Data:\n";
    cout << "Name:" << "               "<< "Test Score:" << "     " << "Grade:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << i + 1 << ". " << students[i].studentLName << "," << students[i].studentFName
             << " - Test Score: " << students[i].testScore
             << ", Grade: " << students[i].courseGrade << endl;
    }
    cout << "\nData on students with highest test score:\n";
    cout << "A. Student with highest test score: " << highValueName(students, NUM_STUDENTS) << endl;
    cout << "B. Index of student with highest test score: " << highValueIndex(students, NUM_STUDENTS) << endl;

    return 0;
}