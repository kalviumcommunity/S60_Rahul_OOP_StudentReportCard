#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Enum for student types
enum class StudentType { Regular, Graduate };

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
    StudentType type;

    void inputSubjects() {
        for (int i = 0; i < 5; i++) {
            Subject sub;
            sub.inputSubjectDetails();
            subjects.push_back(sub);
        }
    }

    void displaySubjects() const {
        for (const auto &sub : subjects) {
            sub.displaySubjectDetails();
        }
    }

public:
    Student(const string &name = "", long long id = 0, StudentType type = StudentType::Regular)
        : name(name), id(id), type(type) {}

    virtual ~Student() = default;

    virtual void inputDetails() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        inputSubjects(); // Shared behavior
    }

    virtual void displayStudentDetails() const {
        cout << "Student name: " << name << endl;
        cout << "ID: " << id << endl;
        displaySubjects(); // Shared behavior
    }

    virtual StudentType getType() const {
        return type;
    }
};

// Class for regular students
class RegularStudent : public Student {
public:
    RegularStudent() : Student("", 0, StudentType::Regular) {}

    string getTypeName() const {
        return "Regular Student";
    }
};

// Class for graduate students
class GraduateStudent : public Student {
private:
    string thesisTitle;
    string supervisorName;

public:
    GraduateStudent() : Student("", 0, StudentType::Graduate) {}

    void inputDetails() override {
        Student::inputDetails(); // Reuse common input
        cout << "Enter thesis title: ";
        cin.ignore(); // Clear input buffer
        getline(cin, thesisTitle);
        cout << "Enter supervisor name: ";
        getline(cin, supervisorName);
    }

    void displayStudentDetails() const override {
        Student::displayStudentDetails(); // Reuse common display
        cout << "Thesis Title: " << thesisTitle << endl;
        cout << "Supervisor Name: " << supervisorName << endl;
    }

    string getTypeName() const {
        return "Graduate Student";
    }
};

// Factory for creating student objects
class StudentFactory {
public:
    static unique_ptr<Student> createStudent() {
        string type;
        cout << "Enter student type (Regular/Graduate): ";
        cin >> type;

        if (type == "Regular") {
            return make_unique<RegularStudent>();
        } else if (type == "Graduate") {
            return make_unique<GraduateStudent>();
        } else {
            cout << "Invalid choice. Defaulting to Regular Student." << endl;
            return make_unique<RegularStudent>();
        }
    }
};

// Class to manage students
class StudentManager {
private:
    vector<unique_ptr<Student>> students; // Polymorphic container

public:
    void addStudent() {
        unique_ptr<Student> student = StudentFactory::createStudent();
        student->inputDetails();
        students.push_back(move(student));
    }

    void displayAllStudents() const {
        for (size_t i = 0; i < students.size(); ++i) {
            cout << "\nDetails of student " << i + 1 << " (" 
                 << (students[i]->getType() == StudentType::Regular ? "Regular" : "Graduate") 
                 << "):" << endl;
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
