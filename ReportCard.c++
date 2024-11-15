#include <iostream>
#include <string>
using namespace std;

// Base class: Subject
class Subject {
private:
    string subjectName; // Hidden
    int marksObtained;  // Hidden

public:
    // Constructor to initialize subject details
    Subject(const string name = "", int marks = 0) 
        : subjectName(name), marksObtained(marks) {}

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

// Abstract base class: Student
class Student {
protected:
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

    // Virtual destructor
    virtual ~Student() {
        totalStudents--;
    }

    // Pure virtual method to input student details
    virtual void inputDetails() = 0;

    // Pure virtual method to display student details
    virtual void displayStudentDetails() const = 0;

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

// Derived class: GraduateStudent
class GraduateStudent : public Student {
private:
    string thesisTitle;
    string supervisorName;

public:
    // Constructor to initialize graduate student details
    GraduateStudent(const string name = "", long long id = 0, 
                    const string thesis = "", const string supervisor = "")
        : Student(name, id), thesisTitle(thesis), supervisorName(supervisor) {}

    // Override method to input graduate student details
    void inputDetails() override {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter the ID: ";
        cin >> id;

        for (int i = 0; i < 5; i++) {
            cout << "Enter subject details: " << i + 1 << endl;
            subjects[i].inputSubjectDetails();
        }

        cout << "Enter thesis title: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, thesisTitle);
        cout << "Enter supervisor name: ";
        getline(cin, supervisorName);
    }

    // Override method to display graduate student details
    void displayStudentDetails() const override {
        cout << "Student name: " << name << endl;
        cout << "ID: " << id << endl;
        for (int i = 0; i < 5; i++) {
            subjects[i].displaySubjectDetails();
        }
        cout << "Thesis Title: " << thesisTitle << endl;
        cout << "Supervisor Name: " << supervisorName << endl;
    }
};

int main() {
    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;
    
    // Use array of pointers to handle different types of students
    Student **students = new Student*[numberOfStudents]; 

    for (int i = 0; i < numberOfStudents; i++) {
        int studentType;
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "Is the student a (1) Graduate Student? ";
        cin >> studentType;

        // Dynamically allocate the correct type of student
        if (studentType == 1) {
            students[i] = new GraduateStudent();
        } else {
            cout << "Invalid choice, defaulting to Graduate Student." << endl;
            students[i] = new GraduateStudent();
        }

        // Use polymorphic method
        students[i]->inputDetails();
    }

    // Display the details of each student using polymorphism
    for (int i = 0; i < numberOfStudents; i++) {
        cout << "\nDetails of student " << i + 1 << ":" << endl;
        students[i]->displayStudentDetails(); // Polymorphic call
    }

    // Display the total number of students
    Student::displayTotalStudents();

    // Clean up dynamically allocated memory
    for (int i = 0; i < numberOfStudents; i++) {
        delete students[i]; // Clean up each student object
    }
    delete[] students; // Clean up the array of pointers

    return 0;
}