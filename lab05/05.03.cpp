#include <iostream>
#include <string>

using namespace std;

struct CarNode
{
    string carName;
    int manufactureYear;
    double carPrice;
    CarNode* nextNode;
} *firstNode=nullptr,*lastNode=nullptr;

CarNode* addLast(CarNode* firstNode,string name,int year,double price)
{
    CarNode* newNode;
    newNode=new CarNode;
    newNode->carName=name;
    newNode->manufactureYear=year;
    newNode->carPrice=price;
    newNode->nextNode=nullptr;
    if(firstNode==nullptr)
    {
        firstNode=newNode;
        lastNode=newNode;
        return firstNode;
    }
    lastNode->nextNode=newNode;
    lastNode=newNode;
    return firstNode;
}

void printFilteredCars(CarNode* firstNode,int currentYear)
{
    CarNode* currentNode;
    bool hasFound;
    currentNode=firstNode;
    hasFound=false;
    cout<<"Cars older than 10 years and under 5000 USD:"<<endl;
    while(currentNode!=nullptr)
    {
        if((currentYear-currentNode->manufactureYear)>10&&currentNode->carPrice<5000.0)
        {
            cout<<currentNode->carName<<" "<<currentNode->manufactureYear<<" "<<currentNode->carPrice<<" USD"<<endl;
            hasFound=true;
        }
        currentNode=currentNode->nextNode;
    }
    if(hasFound==false)
    {
        cout<<"No cars found"<<endl;
    }
}

void printCarList(CarNode* firstNode)
{
    CarNode* currentNode;
    currentNode=firstNode;
    while(currentNode!=nullptr)
    {
        cout<<currentNode->carName<<" "<<currentNode->manufactureYear<<" "<<currentNode->carPrice<<" USD"<<endl;
        currentNode=currentNode->nextNode;
    }
}

CarNode* clearList(CarNode* firstNode)
{
    CarNode* currentNode;
    while(firstNode!=nullptr)
    {
        currentNode=firstNode;
        firstNode=firstNode->nextNode;
        delete currentNode;
    }
    lastNode=nullptr;
    return firstNode;
}

int main()
{
    firstNode=addLast(firstNode,"Toyota Camry",2012,4500.0);
    firstNode=addLast(firstNode,"Honda Civic",2018,12000.0);
    firstNode=addLast(firstNode,"Nissan Leaf",2015,6000.0);
    firstNode=addLast(firstNode,"Mazda 3",2008,4200.0);

    cout<<"All cars:"<<endl;
    printCarList(firstNode);
    cout<<"---"<<endl;

    printFilteredCars(firstNode,2026);

    firstNode=clearList(firstNode);
    return 0;
}