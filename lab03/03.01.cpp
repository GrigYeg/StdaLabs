#include <iostream>
#include <string>

using namespace std;

struct Worker
{
    string workerName;
    string workerPosition;
    int employmentYear;
    double rawSalary;

    int calculateExperience(int currentYear);
    double calculateNetSalary();
};

int Worker::calculateExperience(int currentYear)
{
    return currentYear-employmentYear;
}

double Worker::calculateNetSalary()
{
    return rawSalary-(rawSalary*0.33);
}

int main()
{
    int arraySize;
    int i;
    Worker* teamArray;

    arraySize=3;
    teamArray=new Worker[arraySize];

    teamArray[0].workerName="Lev R.A.";
    teamArray[0].workerPosition="CEO";
    teamArray[0].employmentYear=2017;
    teamArray[0].rawSalary=70000.0;

    teamArray[1].workerName="Yehor G.M.";
    teamArray[1].workerPosition="Developer";
    teamArray[1].employmentYear=2020;
    teamArray[1].rawSalary=65000.0;

    teamArray[2].workerName="Tetiana S.Y.";
    teamArray[2].workerPosition="Designer";
    teamArray[2].employmentYear=2022;
    teamArray[2].rawSalary=50000.0;

    cout<<"Worker details:"<<endl;
    for(i=0;i<arraySize;i++)
    {
        cout<<teamArray[i].workerName<<endl;
        cout<<"Position:"<<teamArray[i].workerPosition<<endl;
        cout<<"Experience:"<<teamArray[i].calculateExperience(2026)<<" years"<<endl;
        cout<<"Net salary:"<<teamArray[i].calculateNetSalary()<<endl;
        cout<<"---"<<endl;
    }

    delete[] teamArray;
    return 0;
}