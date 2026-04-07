#include <iostream>
#include <string>

using namespace std;

struct EmployeeNode
{
    string employeeSurname;
    string employeeDepartment;
    double employeeSalary;
    EmployeeNode* nextNode;
    EmployeeNode* prevNode;
} *firstMain=nullptr,*lastMain=nullptr,*firstHigh=nullptr,*lastHigh=nullptr,*firstLow=nullptr,*lastLow=nullptr;

EmployeeNode* addMain(EmployeeNode* firstNode,string surname,string department,double salary)
{
    EmployeeNode* newNode;
    newNode=new EmployeeNode;
    newNode->employeeSurname=surname;
    newNode->employeeDepartment=department;
    newNode->employeeSalary=salary;
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

EmployeeNode* addHigh(EmployeeNode* firstNode,string surname,string department,double salary)
{
    EmployeeNode* newNode;
    newNode=new EmployeeNode;
    newNode->employeeSurname=surname;
    newNode->employeeDepartment=department;
    newNode->employeeSalary=salary;
    newNode->nextNode=nullptr;
    newNode->prevNode=lastHigh;
    if(firstNode==nullptr)
    {
        firstNode=newNode;
    }
    else
    {
        lastHigh->nextNode=newNode;
    }
    lastHigh=newNode;
    return firstNode;
}

EmployeeNode* addLow(EmployeeNode* firstNode,string surname,string department,double salary)
{
    EmployeeNode* newNode;
    newNode=new EmployeeNode;
    newNode->employeeSurname=surname;
    newNode->employeeDepartment=department;
    newNode->employeeSalary=salary;
    newNode->nextNode=nullptr;
    newNode->prevNode=lastLow;
    if(firstNode==nullptr)
    {
        firstNode=newNode;
    }
    else
    {
        lastLow->nextNode=newNode;
    }
    lastLow=newNode;
    return firstNode;
}

void printForward(EmployeeNode* firstNode)
{
    EmployeeNode* traverseNode;
    traverseNode=firstNode;
    while(traverseNode!=nullptr)
    {
        cout<<traverseNode->employeeSurname<<" "<<traverseNode->employeeDepartment<<" "<<traverseNode->employeeSalary<<endl;
        traverseNode=traverseNode->nextNode;
    }
}

void printBackward(EmployeeNode* lastNode)
{
    EmployeeNode* traverseNode;
    traverseNode=lastNode;
    while(traverseNode!=nullptr)
    {
        cout<<traverseNode->employeeSurname<<" "<<traverseNode->employeeDepartment<<" "<<traverseNode->employeeSalary<<endl;
        traverseNode=traverseNode->prevNode;
    }
}

int main()
{
    EmployeeNode* traverseNode;
    EmployeeNode* tempNode;
    double totalSalary;
    int employeeCount;
    double averageSalary;

    firstMain=addMain(firstMain,"Yegor","IT",5000.0);
    firstMain=addMain(firstMain,"Tanya","HR",3000.0);
    firstMain=addMain(firstMain,"Lev","IT",6000.0);
    firstMain=addMain(firstMain,"Misha","Sales",3500.0);
    firstMain=addMain(firstMain,"Yura","Sales",4000.0);

    totalSalary=0.0;
    employeeCount=0;
    traverseNode=firstMain;
    while(traverseNode!=nullptr)
    {
        totalSalary=totalSalary+traverseNode->employeeSalary;
        employeeCount=employeeCount+1;
        traverseNode=traverseNode->nextNode;
    }
    
    averageSalary=0.0;
    if(employeeCount>0)
    {
        averageSalary=totalSalary/employeeCount;
    }
    cout<<"Average salary:"<<averageSalary<<endl;

    traverseNode=firstMain;
    while(traverseNode!=nullptr)
    {
        if(traverseNode->employeeSalary>averageSalary)
        {
            firstHigh=addHigh(firstHigh,traverseNode->employeeSurname,traverseNode->employeeDepartment,traverseNode->employeeSalary);
        }
        else
        {
            firstLow=addLow(firstLow,traverseNode->employeeSurname,traverseNode->employeeDepartment,traverseNode->employeeSalary);
        }
        traverseNode=traverseNode->nextNode;
    }

    cout<<"---"<<endl;
    cout<<"High salary list forward:"<<endl;
    printForward(firstHigh);
    cout<<endl<<"High salary list backward:"<<endl;
    printBackward(lastHigh);

    cout<<"---"<<endl;
    cout<<"Low salary list forward:"<<endl;
    printForward(firstLow);
    cout<<endl<<"Low salary list backward:"<<endl;
    printBackward(lastLow);

    cout<<"---"<<endl;
    cout<<"Adding new employee to high salary list:"<<endl;
    firstHigh=addHigh(firstHigh,"Kuzya","Management",8000.0);
    printForward(firstHigh);

    while(firstMain!=nullptr)
    {
        tempNode=firstMain;
        firstMain=firstMain->nextNode;
        delete tempNode;
    }
    lastMain=nullptr;

    while(firstHigh!=nullptr)
    {
        tempNode=firstHigh;
        firstHigh=firstHigh->nextNode;
        delete tempNode;
    }
    lastHigh=nullptr;

    while(firstLow!=nullptr)
    {
        tempNode=firstLow;
        firstLow=firstLow->nextNode;
        delete tempNode;
    }
    lastLow=nullptr;

    return 0;
}