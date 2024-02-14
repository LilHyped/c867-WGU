#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;
using std::string;
using std::cout;

class Student
{
public:
    const static int DaysInCourseArraySize = 3;

private:
    string StudentID;
    string FirstName;
    string LastName;
    string Email;
    int Age;
    double DaysInCourse[DaysInCourseArraySize];
    Degree degreeType;

public:
    Student() { //constructor
    }
    Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, double daysInCourse[], Degree degreeType) { //constructor
     this->StudentID = studentID;
    this->FirstName = firstName;
    this->LastName = lastName;
    this->Email = email;
    this->Age = age;
    for (int i = 0; i < DaysInCourseArraySize; i++) {
        this->DaysInCourse[i] = daysInCourse[i];
    }
        this->degreeType = degreeType;
    }
    
    // accessors-getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    double* getDaysInCourse();
    Degree getdegreeType();

    // mutator-setters
    void setStudentID(string StudentID);
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setEmail(string Email);
    void setAge(int Age);
    void setDaysInCourse(double DaysInCourse[]);
    void setdegreeType(Degree degreeType);

	void print();
    static void printHeader();
    ~Student(); // destructor
};

   void Student::printHeader() {
    cout << "Student ID\tFirst Name\tLast Name\tEmail\tAge\tDays in Course 1\tDays in Course 2\tDays in Course 3\tDegree" << std::endl;
}
Student::~Student() {
}