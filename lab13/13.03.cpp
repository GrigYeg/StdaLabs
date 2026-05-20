#include <iostream>
#include <string>
#include <map>

using namespace std;

void updateGrade(map<string,int>& studentGrades,string studentName,int newGrade)
{
    studentGrades[studentName]=newGrade;
}

int main()
{
    map<string,int> journal;
    map<string,int>::iterator mapIterator;
    string targetName;
    int targetGrade;

    journal["Yegor"]=95;
    journal["Lev"]=82;

    cout<<"Enter student name:"<<endl;
    cin>>targetName;
    cout<<"Enter new grade:"<<endl;
    cin>>targetGrade;

    updateGrade(journal,targetName,targetGrade);

    cout<<"Updated journal:"<<endl;
    for(mapIterator=journal.begin();mapIterator!=journal.end();++mapIterator)
    {
        cout<<mapIterator->first<<" - "<<mapIterator->second<<endl;
    }

    return 0;
}