#include "roster.h"
#include <iostream>
#include <sstream>

Roster::Roster() {
    rosterIndex = 0;
}

void Roster::parse(std::string row) {
    if (rosterIndex < numStudents) {
        std::istringstream ss(row);
        std::string token;
        std::string studentData[9];

        int i = 0;
        while (std::getline(ss, token, ',')) {
            studentData[i] = token;
            i++;
        }

        Degree degreeType;

        if (studentData[8] == "SECURITY") {
            degreeType = SECURITY;
        } else if (studentData[8] == "NETWORK") {
            degreeType = NETWORK;
        } else if (studentData[8] == "SOFTWARE") {
            degreeType = SOFTWARE;
        } else {
            std::cerr << "Error: Invalid degree type" << std::endl;
            return;
        }

        add(studentData[0], studentData[1], studentData[2], studentData[3], std::stoi(studentData[4]),
            std::stoi(studentData[5]), std::stoi(studentData[6]), std::stoi(studentData[7]), degreeType);
        rosterIndex++;
    } else {
        std::cerr << "Error: Roster is full" << std::endl;
    }
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType) {
    double daysInCourse[Student::DaysInCourseArraySize] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[rosterIndex] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeType);
}

void Roster::printAll() {
    Student::printHeader();
    for (int i = 0; i < rosterIndex; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printByDegree(Degree degreeType) {
    Student::printHeader();
    for (int i = 0; i < rosterIndex; i++) {
        if (classRosterArray[i]->getDegree() == degreeType) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < rosterIndex; i++) {
        std::string email = classRosterArray[i]->getEmail();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
            std::cout << "Invalid email: " << email << std::endl;
        }
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i < rosterIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            double* daysInCourse = classRosterArray[i]->getDaysInCourse();
            double average = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3.0;
            std::cout << "Student ID: " << studentID << ", Average days in course: " << average << std::endl;
        }
    }
}

void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i < rosterIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Student with ID " << studentID << " not found." << std::endl;
    }
}