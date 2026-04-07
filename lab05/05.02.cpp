#include <iostream>
#include <string>

using namespace std;

struct CityNode
{
    string cityName;
    int distanceToKyiv;
    CityNode* nextNode;
} *firstNode=nullptr,*lastNode=nullptr;

CityNode* addLast(CityNode* firstNode,string name,int distance)
{
    CityNode* newNode;
    newNode=new CityNode;
    newNode->cityName=name;
    newNode->distanceToKyiv=distance;
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

void findTwoMostDistant(CityNode* firstNode)
{
    CityNode* traverseNode;
    CityNode* firstMaxNode;
    CityNode* secondMaxNode;
    int maxDistance;
    int secondMaxDistance;
    
    if(firstNode==nullptr||firstNode->nextNode==nullptr)
    {
        cout<<"Not enough cities"<<endl;
        return;
    }
    firstMaxNode=nullptr;
    secondMaxNode=nullptr;
    maxDistance=-1;
    secondMaxDistance=-1;
    traverseNode=firstNode;
    while(traverseNode!=nullptr)
    {
        if(traverseNode->distanceToKyiv>maxDistance)
        {
            secondMaxDistance=maxDistance;
            secondMaxNode=firstMaxNode;
            maxDistance=traverseNode->distanceToKyiv;
            firstMaxNode=traverseNode;
        }
        else if(traverseNode->distanceToKyiv>secondMaxDistance)
        {
            secondMaxDistance=traverseNode->distanceToKyiv;
            secondMaxNode=traverseNode;
        }
        traverseNode=traverseNode->nextNode;
    }
    cout<<"Two most distant cities:"<<endl;
    cout<<"1."<<firstMaxNode->cityName<<" "<<firstMaxNode->distanceToKyiv<<" km"<<endl;
    cout<<"2."<<secondMaxNode->cityName<<" "<<secondMaxNode->distanceToKyiv<<" km"<<endl;
}

void printList(CityNode* firstNode)
{
    CityNode* traverseNode;
    traverseNode=firstNode;
    while(traverseNode!=nullptr)
    {
        cout<<traverseNode->cityName<<" "<<traverseNode->distanceToKyiv<<" km"<<endl;
        traverseNode=traverseNode->nextNode;
    }
}

CityNode* clearList(CityNode* firstNode)
{
    CityNode* currentNode;
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
    firstNode=addLast(firstNode,"Chernivtsi",510);
    firstNode=addLast(firstNode,"Lviv",540);
    firstNode=addLast(firstNode,"Odesa",480);
    firstNode=addLast(firstNode,"Zaporozhye",560);
    firstNode=addLast(firstNode,"Kryvyi Rih",420);

    printList(firstNode);
    cout<<"---"<<endl;
    
    findTwoMostDistant(firstNode);
    cout<<"---"<<endl;
    
    cout<<"Adding foreign city:"<<endl;
    firstNode=addLast(firstNode,"Bucharest",1060);
    printList(firstNode);
    
    firstNode=clearList(firstNode);
    return 0;
}