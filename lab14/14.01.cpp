#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int,10> studentGrades;
    int i;
    int j;
    int sumGrades;
    double averageGrade;
    int maxGrade;
    int minGrade;
    int aboveAverageCount;
    int tempSwap;

    cout<<"Enter 10 grades:"<<endl;
    for(i=0;i<10;i++)
    {
        cin>>studentGrades[i];
    }

    sumGrades=0;
    maxGrade=studentGrades[0];
    minGrade=studentGrades[0];

    for(i=0;i<10;i++)
    {
        sumGrades=sumGrades+studentGrades[i];
        if(studentGrades[i]>maxGrade)
        {
            maxGrade=studentGrades[i];
        }
        if(studentGrades[i]<minGrade)
        {
            minGrade=studentGrades[i];
        }
    }

    averageGrade=(double)sumGrades/10;
    aboveAverageCount=0;

    for(i=0;i<10;i++)
    {
        if(studentGrades[i]>averageGrade)
        {
            aboveAverageCount=aboveAverageCount+1;
        }
    }

    cout<<"Average: "<<averageGrade<<endl;
    cout<<"Max: "<<maxGrade<<endl;
    cout<<"Min: "<<minGrade<<endl;
    cout<<"Above average count: "<<aboveAverageCount<<endl;

    for(i=0;i<9;i++)
    {
        for(j=0;j<9-i;j++)
        {
            if(studentGrades[j]>studentGrades[j+1])
            {
                tempSwap=studentGrades[j];
                studentGrades[j]=studentGrades[j+1];
                studentGrades[j+1]=tempSwap;
            }
        }
    }

    cout<<"Sorted ascending:"<<endl;
    for(i=0;i<10;i++)
    {
        cout<<studentGrades[i]<<" ";
    }
    cout<<endl;

    for(i=0;i<9;i++)
    {
        for(j=0;j<9-i;j++)
        {
            if(studentGrades[j]<studentGrades[j+1])
            {
                tempSwap=studentGrades[j];
                studentGrades[j]=studentGrades[j+1];
                studentGrades[j+1]=tempSwap;
            }
        }
    }

    cout<<"Sorted descending:"<<endl;
    for(i=0;i<10;i++)
    {
        cout<<studentGrades[i]<<" ";
    }
    cout<<endl;

    return 0;
}