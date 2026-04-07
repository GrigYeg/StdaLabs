#include <iostream>
#include <string>

using namespace std;

struct WeatherNode
{
    string recordDate;
    double temperatureValue;
    WeatherNode* nextNode;
    WeatherNode* prevNode;
} *firstOne=nullptr,*lastOne=nullptr,*firstTwo=nullptr,*lastTwo=nullptr;

WeatherNode* addLastOne(WeatherNode* firstNode,string date,double temp)
{
    WeatherNode* newNode;
    newNode=new WeatherNode;
    newNode->recordDate=date;
    newNode->temperatureValue=temp;
    newNode->nextNode=nullptr;
    newNode->prevNode=lastOne;
    if(firstNode==nullptr)
    {
        firstNode=newNode;
    }
    else
    {
        lastOne->nextNode=newNode;
    }
    lastOne=newNode;
    return firstNode;
}

WeatherNode* addLastTwo(WeatherNode* firstNode,string date,double temp)
{
    WeatherNode* newNode;
    newNode=new WeatherNode;
    newNode->recordDate=date;
    newNode->temperatureValue=temp;
    newNode->nextNode=nullptr;
    newNode->prevNode=lastTwo;
    if(firstNode==nullptr)
    {
        firstNode=newNode;
    }
    else
    {
        lastTwo->nextNode=newNode;
    }
    lastTwo=newNode;
    return firstNode;
}

void printList(WeatherNode* firstNode)
{
    WeatherNode* traverseNode;
    traverseNode=firstNode;
    while(traverseNode!=nullptr)
    {
        cout<<traverseNode->recordDate<<" "<<traverseNode->temperatureValue<<endl;
        traverseNode=traverseNode->nextNode;
    }
}

int main()
{
    WeatherNode* traverseNode;
    WeatherNode* tempNode;
    double maxTemp;
    double minTemp;
    
    firstOne=addLastOne(firstOne,"2026-05-01",15.5);
    firstOne=addLastOne(firstOne,"2026-05-02",18.2);
    
    firstTwo=addLastTwo(firstTwo,"2026-06-01",22.1);
    firstTwo=addLastTwo(firstTwo,"2026-06-02",25.4);
    
    if(firstOne==nullptr)
    {
        firstOne=firstTwo;
        lastOne=lastTwo;
    }
    else if(firstTwo!=nullptr)
    {
        lastOne->nextNode=firstTwo;
        firstTwo->prevNode=lastOne;
        lastOne=lastTwo;
    }
    firstTwo=nullptr;
    lastTwo=nullptr;
    
    cout<<"Merged list:"<<endl;
    printList(firstOne);
    
    if(firstOne!=nullptr)
    {
        maxTemp=firstOne->temperatureValue;
        minTemp=firstOne->temperatureValue;
        traverseNode=firstOne->nextNode;
        while(traverseNode!=nullptr)
        {
            if(traverseNode->temperatureValue>maxTemp)
            {
                maxTemp=traverseNode->temperatureValue;
            }
            if(traverseNode->temperatureValue<minTemp)
            {
                minTemp=traverseNode->temperatureValue;
            }
            traverseNode=traverseNode->nextNode;
        }
        cout<<"Max temp:"<<maxTemp<<endl;
        cout<<"Min temp:"<<minTemp<<endl;
    }
    
    while(firstOne!=nullptr)
    {
        tempNode=firstOne;
        firstOne=firstOne->nextNode;
        delete tempNode;
    }
    lastOne=nullptr;
    return 0;
}