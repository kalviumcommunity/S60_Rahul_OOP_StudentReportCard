#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
using namespace std;

class Subject
{
private:
    string subjectName; //Hidden
    int marksObtained; //Hidden

public:
    // Mutator for subject details
    void setSubjectDetails(const string name, int marks)
    {
        subjectName = name;
        marksObtained = marks;
    }

    // Mutator for subject details
    void inputSubjectDetails()
    {
        cout << "Enter your subject: ";
        cin >> subjectName;
        cout << "Enter marks obtained in " << subjectName << ": ";
        cin >> marksObtained;
    }

    // Accessor for marks obtained
    int getMarks() const
    {
        return marksObtained;
    }

    // Public method to display subject details
    void displaySubjectDetails()
    {
        cout << subjectName << ": " << marksObtained << endl;
    }
};
class Student
{
private:
    long long id; //Hidden
    string name; //Hidden
    Subject subjects[5]; //Hidden
    float CGPA; //Hidden

    static int totalStudents; //Hidden

public:
    // Constructor to increment total students
    Student()
    {
        totalStudents++;
    }

    // Setter for student details
    void setStudentDetails(const string name, long long id)
    {
        this->name = name;
        this->id = id;
    }

    // Method to input student details
    void inputDetails()
    {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter the id: ";
        cin >> id;

        for (int i = 0; i < 5; i++)
        {
            cout << "Enter subject details: " << i + 1 << endl;
            subjects[i].inputSubjectDetails();
        }
    }

    // Method to display student details
    void displayStudentDetails()
    {
        cout << "Student name: " << name << endl;
        cout << "ID: " << this->id << endl;
        for (int i = 0; i < 5; i++)
        {
            subjects[i].displaySubjectDetails();
        }
    }

    // Method to display total number of students
    static void displayTotalStudents()
    {
        cout << "Total number of students: " << totalStudents << endl;
    }

    // Getter for subject
    Subject &getSubject(int index)
    {
        return subjects[index];
    }
};

// Static variable to keep track of total number of students
int Student::totalStudents = 0;

int main()
{
    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;
    Student *students = new Student[numberOfStudents];

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "Enter details for student " << i + 1 << ":" << endl;

        string name;
        long long id;
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student ID: ";
        cin >> id;
        students[i].setStudentDetails(name, id);

        for (int j = 0; j < 5; j++)
        {
            string subjectName;
            int marks;
            cout << "Enter subject " << j + 1 << " name: ";
            cin >> subjectName;
            cout << "Enter marks for " << subjectName << ": ";
            cin >> marks;
            students[i].getSubject(j).setSubjectDetails(subjectName, marks);
        }
    }

    
    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "\nDetails of student " << i + 1 << ":" << endl;
        students[i].displayStudentDetails();
    }

    Student::displayTotalStudents();
    delete[] students;

    return 0;
}