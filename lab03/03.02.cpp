#include <iostream>
#include <string>

using namespace std;

enum Faculty
{
    FACULTY_IT,
    FACULTY_ECONOMICS,
    FACULTY_LAW,
    FACULTY_MANAGEMENT
};

struct Student
{
    string lastName;
    int studyYear;
    double averageGrade;
    Faculty studentFaculty;
};

int main()
{
    Student studentArray[5];
    int i;
    double totalGrade;
    double groupAverage;

    studentArray[0].lastName="Hryhorets";
    studentArray[0].studyYear=1;
    studentArray[0].averageGrade=4.8;
    studentArray[0].studentFaculty=FACULTY_IT;

    studentArray[1].lastName="Yembryk";
    studentArray[1].studyYear=1;
    studentArray[1].averageGrade=3.5;
    studentArray[1].studentFaculty=FACULTY_ECONOMICS;

    studentArray[2].lastName="Samanyk";
    studentArray[2].studyYear=3;
    studentArray[2].averageGrade=4.6;
    studentArray[2].studentFaculty=FACULTY_IT;

    studentArray[3].lastName="Yeremiy";
    studentArray[3].studyYear=4;
    studentArray[3].averageGrade=4.7;
    studentArray[3].studentFaculty=FACULTY_LAW;

    studentArray[4].lastName="Naidysh";
    studentArray[4].studyYear=2;
    studentArray[4].averageGrade=4.3;
    studentArray[4].studentFaculty=FACULTY_MANAGEMENT;

    cout<<"IT Faculty Students:"<<endl;
    for(i=0;i<5;i++)
    {
        if(studentArray[i].studentFaculty==FACULTY_IT)
        {
            cout<<studentArray[i].lastName<<endl;
        }
    }

    totalGrade=0.0;
    for(i=0;i<5;i++)
    {
        totalGrade=totalGrade+studentArray[i].averageGrade;
    }
    groupAverage=totalGrade/5.0;

    cout<<"Group average grade:"<<groupAverage<<endl;

    return 0;
}