#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class to manage Subject details
class Subject {
private:
    string subjectName;
    int marksObtained;

public:
    Subject(const string &name = "", int marks = 0)
        : subjectName(name), marksObtained(marks) {}

    void inputSubjectDetails() {
        cout << "Enter your subject: ";
        cin >> subjectName;
        cout << "Enter marks obtained in " << subjectName << ": ";
        cin >> marksObtained;
    }

    void displaySubjectDetails() const {
        cout << subjectName << ": " << marksObtained << endl;
    }
};

// Abstract base class for students
class Student {
protected:
    long long id;
    string name;
    vector<Subject> subjects; // List of subjects

public:
    Student(const string &name = "", long long id = 0)
        : name(name), id(id) {}

    virtual ~Student() = default;

    virtual void inputDetails() = 0;
    virtual void displayStudentDetails() const = 0;
};

// Class for regular students
class RegularStudent : public Student {
public:
    RegularStudent(const string &name = "", long long id = 0)
        : Student(name, id) {}

    void inputDetails() override {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;

        for (int i = 0; i < 5; i++) {
            Subject sub;
            sub.inputSubjectDetails();
            subjects.push_back(sub);
        }
    }

    void displayStudentDetails() const override {
        cout << "Student name: " << name << endl;
        cout << "ID: " << id << endl;
        for (const auto &sub : subjects) {
            sub.displaySubjectDetails();
        }
    }
};

// Class for graduate students
class GraduateStudent : public Student {
private:
    string thesisTitle;
    string supervisorName;

public:
    GraduateStudent(const string &name = "", long long id = 0,
                    const string &thesis = "", const string &supervisor = "")
        : Student(name, id), thesisTitle(thesis), supervisorName(supervisor) {}

    void inputDetails() override {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;

        for (int i = 0; i < 5; i++) {
            Subject sub;
            sub.inputSubjectDetails();
            subjects.push_back(sub);
        }

        cout << "Enter thesis title: ";
        cin.ignore(); // Clear input buffer
        getline(cin, thesisTitle);
        cout << "Enter supervisor name: ";
        getline(cin, supervisorName);
    }

    void displayStudentDetails() const override {
        cout << "Student name: " << name << endl;
        cout << "ID: " << id << endl;
        for (const auto &sub : subjects) {
            sub.displaySubjectDetails();
        }
        cout << "Thesis Title: " << thesisTitle << endl;
        cout << "Supervisor Name: " << supervisorName << endl;
    }
};

// Class to manage students
class StudentManager {
private:
    vector<Student *> students; // Polymorphic container

public:
    ~StudentManager() {
        for (Student *student : students) {
            delete student;
        }
        students.clear();
    }

    void addStudent() {
        int studentType;
        cout << "Is the student (1) Regular or (2) Graduate? ";
        cin >> studentType;

        Student *student = nullptr;
        if (studentType == 1) {
            student = new RegularStudent();
        } else if (studentType == 2) {
            student = new GraduateStudent();
        } else {
            cout << "Invalid choice. Defaulting to Regular Student." << endl;
            student = new RegularStudent();
        }

        student->inputDetails();
        students.push_back(student);
    }

    void displayAllStudents() const {
        for (size_t i = 0; i < students.size(); ++i) {
            cout << "\nDetails of student " << i + 1 << ":" << endl;
            students[i]->displayStudentDetails();
        }
    }
};

// Main function
int main() {
    StudentManager manager;

    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; i++) {
        cout << "\nEntering details for student " << i + 1 << ":" << endl;
        manager.addStudent();
    }

    cout << "\nDisplaying all student details:" << endl;
    manager.displayAllStudents();

    return 0;
}
