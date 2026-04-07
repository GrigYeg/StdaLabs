#include <iostream>

using namespace std;

struct GradeNode
{
    int gradeValue;
    GradeNode* nextNode;
} *root=nullptr;

GradeNode* push(GradeNode* root,int newValue)
{
    GradeNode* newNode;
    newNode=new GradeNode;
    newNode->gradeValue=newValue;
    newNode->nextNode=root;
    root=newNode;
    return root;
}

GradeNode* pull(GradeNode* root)
{
    GradeNode* tempNode;
    if(root==nullptr)
    {
        return nullptr;
    }
    tempNode=root;
    root=root->nextNode;
    delete tempNode;
    return root;
}

void printStack(GradeNode* root)
{
    GradeNode* traverseNode;
    traverseNode=root;
    while(traverseNode!=nullptr)
    {
        cout<<traverseNode->gradeValue<<" ";
        traverseNode=traverseNode->nextNode;
    }
    cout<<endl;
}

int main()
{
    int elementsCount;
    double elementsSum;
    GradeNode* traverseNode;
    
    root=push(root,85);
    root=push(root,90);
    root=push(root,78);
    root=push(root,92);
    root=push(root,88);
    
    cout<<"Test results stack:"<<endl;
    printStack(root);
    
    elementsSum=0.0;
    elementsCount=0;
    traverseNode=root;
    while(traverseNode!=nullptr)
    {
        elementsSum=elementsSum+traverseNode->gradeValue;
        elementsCount=elementsCount+1;
        traverseNode=traverseNode->nextNode;
    }
    
    if(elementsCount>0)
    {
        cout<<"Average grade:"<<elementsSum/elementsCount<<endl;
    }
    
    while(root!=nullptr)
    {
        root=pull(root);
    }
    
    return 0;
}