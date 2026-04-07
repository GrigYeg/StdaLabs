#include <iostream>
#include <string>

using namespace std;

struct CourseNode
{
    string courseName;
    int courseHours;
    int studentCount;
    CourseNode* nextNode;
    CourseNode* prevNode;
} *firstMain=nullptr,*lastMain=nullptr,*firstPop=nullptr,*lastPop=nullptr,*firstReg=nullptr,*lastReg=nullptr;

CourseNode* addMain(CourseNode* firstNode,string name,int hours,int students)
{
    CourseNode* newNode;
    newNode=new CourseNode;
    newNode->courseName=name;
    newNode->courseHours=hours;
    newNode->studentCount=students;
    newNode->nextNode=nullptr;
    newNode->prevNode=lastMain;
    if(firstNode==nullptr)
    {
        firstNode=newNode;
    }
    else
    {
        lastMain->nextNode=newNode;
    }
    lastMain=newNode;
    return firstNode;
}

CourseNode* addPop(CourseNode* firstNode,string name,int hours,int students)
{
    CourseNode* newNode;
    newNode=new CourseNode;
    newNode->courseName=name;
    newNode->courseHours=hours;
    newNode->studentCount=students;
    newNode->nextNode=nullptr;
    newNode->prevNode=lastPop;
    if(firstNode==nullptr)
    {
        firstNode=newNode;
    }
    else
    {
        lastPop->nextNode=newNode;
    }
    lastPop=newNode;
    return firstNode;
}

CourseNode* addReg(CourseNode* firstNode,string name,int hours,int students)
{
    CourseNode* newNode;
    newNode=new CourseNode;
    newNode->courseName=name;
    newNode->courseHours=hours;
    newNode->studentCount=students;
    newNode->nextNode=nullptr;
    newNode->prevNode=lastReg;
    if(firstNode==nullptr)
    {
        firstNode=newNode;
    }
    else
    {
        lastReg->nextNode=newNode;
    }
    lastReg=newNode;
    return firstNode;
}

void printForward(CourseNode* firstNode)
{
    CourseNode* traverseNode;
    traverseNode=firstNode;
    while(traverseNode!=nullptr)
    {
        cout<<traverseNode->courseName<<" - "<<traverseNode->studentCount<<" students"<<endl;
        traverseNode=traverseNode->nextNode;
    }
}

void printBackward(CourseNode* lastNode)
{
    CourseNode* traverseNode;
    traverseNode=lastNode;
    while(traverseNode!=nullptr)
    {
        cout<<traverseNode->courseName<<" - "<<traverseNode->studentCount<<" students"<<endl;
        traverseNode=traverseNode->prevNode;
    }
}

int main()
{
    CourseNode* traverseNode;
    CourseNode* tempNode;
    double totalStudents;
    int courseCount;
    double averageStudents;

    firstMain=addMain(firstMain,"Math",120,50);
    firstMain=addMain(firstMain,"Computer Graphics",90,30);
    firstMain=addMain(firstMain,"Programming",150,80);
    firstMain=addMain(firstMain,"History",60,20);
    
    totalStudents=0.0;
    courseCount=0;
    traverseNode=firstMain;
    while(traverseNode!=nullptr)
    {
        totalStudents=totalStudents+traverseNode->studentCount;
        courseCount=courseCount+1;
        traverseNode=traverseNode->nextNode;
    }

    averageStudents=0.0;
    if(courseCount>0)
    {
        averageStudents=totalStudents/courseCount;
    }
    cout<<"Average students:"<<averageStudents<<endl;

    traverseNode=firstMain;
    while(traverseNode!=nullptr)
    {
        if(traverseNode->studentCount>averageStudents)
        {
            firstPop=addPop(firstPop,traverseNode->courseName,traverseNode->courseHours,traverseNode->studentCount);
        }
        else
        {
            firstReg=addReg(firstReg,traverseNode->courseName,traverseNode->courseHours,traverseNode->studentCount);
        }
        traverseNode=traverseNode->nextNode;
    }

    cout<<"---"<<endl;
    cout<<"Popular courses forward:"<<endl;
    printForward(firstPop);
    cout<<"Popular courses backward:"<<endl;
    printBackward(lastPop);
    
    cout<<"---"<<endl;
    cout<<"Regular courses forward:"<<endl;
    printForward(firstReg);
    cout<<"Regular courses backward:"<<endl;
    printBackward(lastReg);

    while(firstMain!=nullptr)
    {
        tempNode=firstMain;
        firstMain=firstMain->nextNode;
        delete tempNode;
    }
    lastMain=nullptr;
    
    while(firstPop!=nullptr)
    {
        tempNode=firstPop;
        firstPop=firstPop->nextNode;
        delete tempNode;
    }
    lastPop=nullptr;
    
    while(firstReg!=nullptr)
    {
        tempNode=firstReg;
        firstReg=firstReg->nextNode;
        delete tempNode;
    }
    lastReg=nullptr;

    return 0;
}