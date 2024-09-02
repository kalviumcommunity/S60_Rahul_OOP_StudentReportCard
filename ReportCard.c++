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
    string subjectName;
    int marksObtained;
    public:

        void setSubjectDetails(string name, int marks){
            this->subjectName = name;
            this->marksObtained = marks;
        }

        void subjectDetails(){
            cout << "Enter your subject: ";
            cin >> this->subjectName;
            cout << "Enter marks obtained in " << this->subjectName << ": " ;
            cin >> this->marksObtained;
        }

        int getMarks(){
            return this->marksObtained;
        }

        void displaySubjectDetails(){
            cout<< this->subjectName << ": " << this->marksObtained << endl;
        }
};
class Student
{
    private:
        long long id;
        string name;
        Subject subjects[5];
        float CGPA;
    public:
        void inputDetails(){
            cout << "Enter student name: ";
            cin >> this->name;
            cout << "Enter the rollnumber: ";
            cin >> this->id;

            for (int i = 0; i < 5; i++)
            {
                cout << "Enter the subject details: " << i+1 << endl;
                subjects[i].subjectDetails();
            }
            
        }
        void studentDetails(){
            cout<<"Student name: "<< this->name <<endl;
            cout << "Roll number: "<< this->id << endl;
            for (int i = 0; i < 5; i++)
            {
                subjects[i].displaySubjectDetails();
            }
            
        }
};
int main()
{
    const int numberOfStudents = 2;
    Student students[numberOfStudents];

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout<< "Enter the details of the student " <<i+1 << ": "<< endl;
        students[i].inputDetails();
    }

    cout << "\nstudentDetails: " << endl;
    for (int i = 0; i < numberOfStudents; i++)
    {
        cout<< "'\nDetails of the student " << i+1 << ": " <<endl;
        students[i].studentDetails();
    }
    
    return 0;
}