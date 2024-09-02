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
        void subjectDetails(){
            cout << "Enter your subject: ";
            cin >> subjectName;
            cout << "Enter marks obtained in " << subjectName << ": " ;
            cin >> marksObtained;
        }

        int getMarks(){
            return marksObtained;
        }

        void displaySubjectDetails(){
            cout<< subjectName << ": " << marksObtained << endl;
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
            cin >> name;
            cout << "Enter the rollnumber: ";
            cin >> id;

            for (int i = 0; i < 5; i++)
            {
                cout << "Enter the subject details: " << i+1 << endl;
                subjects[i].subjectDetails();
            }
            
        }
        void studentDetails(){
            cout<<"Student name: "<< name <<endl;
            cout << "Roll number: "<< id << endl;
            for (int i = 0; i < 5; i++)
            {
                subjects[i].displaySubjectDetails();
            }
            
        }
};
int main()
{
    Student student1;
    student1.inputDetails();
    student1.studentDetails();
    return 0;
}