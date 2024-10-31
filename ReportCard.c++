#include <iostream>
#include <string>
using namespace std;

class Subject {
private:
    string subjectName; // Hidden
    int marksObtained;  // Hidden

public:
    // Constructor to initialize subject details
    Subject(const string name = "", int marks = 0) 
        : subjectName(name), marksObtained(marks) {}

    // Destructor
    ~Subject() {}

    // Mutator for subject details
    void setSubjectDetails(const string &name, int marks) {
        subjectName = name;
        marksObtained = marks;
    }

    // Method to input subject details
    void inputSubjectDetails() {
        cout << "Enter your subject: ";
        cin >> subjectName;
        cout << "Enter marks obtained in " << subjectName << ": ";
        cin >> marksObtained;
    }

    // Accessor for marks obtained
    int getMarks() const {
        return marksObtained;
    }

    // Public method to display subject details
    void displaySubjectDetails() const {
        cout << subjectName << ": " << marksObtained << endl;
    }
};

class Student {
private:
    long long id;           // Hidden
    string name;           // Hidden
    Subject subjects[5];   // Hidden
    static int totalStudents; // Hidden

public:
    // Constructor to initialize student details
    Student(const string name = "", long long id = 0) 
        : name(name), id(id) {
        totalStudents++;
    }

    // Destructor
    ~Student() {
        totalStudents--;
    }

    // Method to input student details
    void inputDetails() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter the ID: ";
        cin >> id;

        for (int i = 0; i < 5; i++) {
            cout << "Enter subject details: " << i + 1 << endl;
            subjects[i].inputSubjectDetails();
        }
    }

    // Method to display student details
    void displayStudentDetails() const {
        cout << "Student name: " << name << endl;
        cout << "ID: " << id << endl;
        for (int i = 0; i < 5; i++) {
            subjects[i].displaySubjectDetails();
        }
    }

    // Method to display total number of students
    static void displayTotalStudents() {
        cout << "Total number of students: " << totalStudents << endl;
    }

    // Getter for subject
    Subject &getSubject(int index) {
        return subjects[index];
    }
};

// Static variable to keep track of total number of students
int Student::totalStudents = 0;

int main() {
    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;
    Student *students = new Student[numberOfStudents];

    for (int i = 0; i < numberOfStudents; i++) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        students[i].inputDetails();
    }

    for (int i = 0; i < numberOfStudents; i++) {
        cout << "\nDetails of student " << i + 1 << ":" << endl;
        students[i].displayStudentDetails();
    }

    Student::displayTotalStudents();
    delete[] students;

    return 0;
}
