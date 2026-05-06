#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    string lastName;
    int exam1;
    int exam2;
    int exam3;
    double averageScore;
};

int main()
{
    vector<Student> students(5);
    int i;
    int j;
    Student tempStudent;
    double maxAvg;
    int maxCount;
    double targetAvg;
    int low;
    int high;
    int mid;
    bool isFound;
    int searchIndex;

    students[0].lastName="Hryhorets"; students[0].exam1=90; students[0].exam2=80; students[0].exam3=95;
    students[1].lastName="Homra"; students[1].exam1=95; students[1].exam2=95; students[1].exam3=85;
    students[2].lastName="Yashchuk"; students[2].exam1=70; students[2].exam2=75; students[2].exam3=95;
    students[3].lastName="Rusnak"; students[3].exam1=95; students[3].exam2=95; students[3].exam3=85;
    students[4].lastName="Samanik"; students[4].exam1=60; students[4].exam2=65; students[4].exam3=80;

    for(i=0;i<5;i++)
    {
        students[i].averageScore=(double)(students[i].exam1+students[i].exam2+students[i].exam3)/3.0;
    }

    maxAvg=students[0].averageScore;
    for(i=1;i<5;i++)
    {
        if(students[i].averageScore>maxAvg)
        {
            maxAvg=students[i].averageScore;
        }
    }

    maxCount=0;
    cout<<"Linear Search - Max Average: "<<maxAvg<<endl;
    cout<<"Students with max average at indices: ";
    for(i=0;i<5;i++)
    {
        if(students[i].averageScore==maxAvg)
        {
            cout<<i<<" ";
            maxCount=maxCount+1;
        }
    }
    cout<<endl<<"Total count with max average: "<<maxCount<<endl<<endl;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4-i;j++)
        {
            if(students[j].averageScore>students[j+1].averageScore)
            {
                tempStudent=students[j];
                students[j]=students[j+1];
                students[j+1]=tempStudent;
            }
        }
    }

    cout<<"Enter target average score for binary search: ";
    cin>>targetAvg;

    low=0;
    high=4;
    isFound=false;
    while(low<=high&&isFound==false)
    {
        mid=(low+high)/2;
        if(students[mid].averageScore==targetAvg)
        {
            isFound=true;
            searchIndex=mid;
        }
        else if(students[mid].averageScore<targetAvg)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    if(isFound==true)
    {
        cout<<"Found student: "<<students[searchIndex].lastName<<endl;
        i=searchIndex-1;
        while(i>=0&&students[i].averageScore==targetAvg)
        {
            cout<<"Found student: "<<students[i].lastName<<endl;
            i=i-1;
        }
        i=searchIndex+1;
        while(i<5&&students[i].averageScore==targetAvg)
        {
            cout<<"Found student: "<<students[i].lastName<<endl;
            i=i+1;
        }
    }
    else
    {
        cout<<"Student with average score "<<targetAvg<<" not found."<<endl;
    }

    return 0;
}