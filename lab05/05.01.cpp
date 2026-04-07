#include <iostream>

using namespace std;

struct IntNode
{
    int nodeValue;
    IntNode* nextNode;
} *firstNode=nullptr,*lastNode=nullptr;

IntNode* addFirst(IntNode* firstNode,int newValue)
{
    IntNode* newNode;
    newNode=new IntNode;
    newNode->nodeValue=newValue;
    newNode->nextNode=firstNode;
    firstNode=newNode;
    if(lastNode==nullptr)
    {
        lastNode=firstNode;
    }
    return firstNode;
}

IntNode* addLast(IntNode* firstNode,int newValue)
{
    IntNode* newNode;
    newNode=new IntNode;
    newNode->nodeValue=newValue;
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

IntNode* addAfter(IntNode* firstNode,int afterValue,int newValue)
{
    IntNode* traverseNode;
    IntNode* newNode;
    traverseNode=firstNode;
    while(traverseNode!=nullptr&&traverseNode->nodeValue!=afterValue)
    {
        traverseNode=traverseNode->nextNode;
    }
    if(traverseNode==nullptr)
    {
        cout<<"Value not found"<<endl;
        return firstNode;
    }
    newNode=new IntNode;
    newNode->nodeValue=newValue;
    newNode->nextNode=traverseNode->nextNode;
    traverseNode->nextNode=newNode;
    if(traverseNode==lastNode)
    {
        lastNode=newNode;
    }
    return firstNode;
}

double calculateAverage(IntNode* firstNode)
{
    double sumOfElements;
    int countOfElements;
    IntNode* traverseNode;
    if(firstNode==nullptr)
    {
        return 0.0;
    }
    sumOfElements=0.0;
    countOfElements=0;
    traverseNode=firstNode;
    while(traverseNode!=nullptr)
    {
        sumOfElements=sumOfElements+traverseNode->nodeValue;
        countOfElements=countOfElements+1;
        traverseNode=traverseNode->nextNode;
    }
    return sumOfElements/countOfElements;
}

IntNode* deleteFirstEven(IntNode* firstNode)
{
    IntNode* currentNode;
    IntNode* previousNode;
    if(firstNode==nullptr)
    {
        return firstNode;
    }
    if(firstNode->nodeValue%2==0)
    {
        currentNode=firstNode;
        firstNode=firstNode->nextNode;
        if(firstNode==nullptr)
        {
            lastNode=nullptr;
        }
        delete currentNode;
        return firstNode;
    }
    previousNode=firstNode;
    currentNode=firstNode->nextNode;
    while(currentNode!=nullptr&&currentNode->nodeValue%2!=0)
    {
        previousNode=currentNode;
        currentNode=currentNode->nextNode;
    }
    if(currentNode!=nullptr)
    {
        previousNode->nextNode=currentNode->nextNode;
        if(currentNode==lastNode)
        {
            lastNode=previousNode;
        }
        delete currentNode;
    }
    return firstNode;
}

void printList(IntNode* firstNode)
{
    IntNode* traverseNode;
    traverseNode=firstNode;
    while(traverseNode!=nullptr)
    {
        cout<<traverseNode->nodeValue<<" ";
        traverseNode=traverseNode->nextNode;
    }
    cout<<endl;
}

IntNode* clearList(IntNode* firstNode)
{
    IntNode* currentNode;
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
    double averageValue;
    firstNode=addFirst(firstNode,5);
    firstNode=addLast(firstNode,10);
    firstNode=addLast(firstNode,20);
    firstNode=addAfter(firstNode,10,15);

    cout<<"Initial list:"<<endl;
    printList(firstNode);
    
    averageValue=calculateAverage(firstNode);
    cout<<"Average value:"<<averageValue<<endl;
    
    firstNode=deleteFirstEven(firstNode);
    cout<<"List after deleting first even element:"<<endl;
    printList(firstNode);
    
    firstNode=clearList(firstNode);
    return 0;
}