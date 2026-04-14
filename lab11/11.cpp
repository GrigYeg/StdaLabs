#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct PersonTree
{
    int personHeight;
    string personName;
    PersonTree* leftNode;
    PersonTree* rightNode;
} *mainRoot=nullptr;

struct HeightTree
{
    int personHeight;
    HeightTree* leftNode;
    HeightTree* rightNode;
} *leftSubRoot=nullptr;

PersonTree* insertPerson(PersonTree* root,int height,string name)
{
    PersonTree* newNode;
    if(root==nullptr)
    {
        newNode=new PersonTree;
        newNode->personHeight=height;
        newNode->personName=name;
        newNode->leftNode=nullptr;
        newNode->rightNode=nullptr;
        return newNode;
    }
    if(height<root->personHeight)
    {
        root->leftNode=insertPerson(root->leftNode,height,name);
    }
    else if(height>root->personHeight)
    {
        root->rightNode=insertPerson(root->rightNode,height,name);
    }
    return root;
}

HeightTree* insertHeight(HeightTree* root,int height)
{
    HeightTree* newNode;
    if(root==nullptr)
    {
        newNode=new HeightTree;
        newNode->personHeight=height;
        newNode->leftNode=nullptr;
        newNode->rightNode=nullptr;
        return newNode;
    }
    if(height<root->personHeight)
    {
        root->leftNode=insertHeight(root->leftNode,height);
    }
    else if(height>root->personHeight)
    {
        root->rightNode=insertHeight(root->rightNode,height);
    }
    return root;
}

bool isHeightInTree(PersonTree* root,int searchHeight)
{
    if(root==nullptr)
    {
        return false;
    }
    if(root->personHeight==searchHeight)
    {
        return true;
    }
    if(searchHeight<root->personHeight)
    {
        return isHeightInTree(root->leftNode,searchHeight);
    }
    return isHeightInTree(root->rightNode,searchHeight);
}

void printPersonTree(PersonTree* root)
{
    if(root!=nullptr)
    {
        printPersonTree(root->leftNode);
        cout<<root->personName<<" - "<<root->personHeight<<" cm"<<endl;
        printPersonTree(root->rightNode);
    }
}

void printHeightTree(HeightTree* root)
{
    if(root!=nullptr)
    {
        printHeightTree(root->leftNode);
        cout<<root->personHeight<<" cm"<<endl;
        printHeightTree(root->rightNode);
    }
}

void countNameOccurrences(PersonTree* root,string searchName,int& totalCount)
{
    if(root!=nullptr)
    {
        if(root->personName==searchName)
        {
            totalCount=totalCount+1;
        }
        countNameOccurrences(root->leftNode,searchName,totalCount);
        countNameOccurrences(root->rightNode,searchName,totalCount);
    }
}

void extractLeftSubtree(PersonTree* root)
{
    if(root!=nullptr)
    {
        leftSubRoot=insertHeight(leftSubRoot,root->personHeight);
        extractLeftSubtree(root->leftNode);
        extractLeftSubtree(root->rightNode);
    }
}

int getPersonTreeDepth(PersonTree* root)
{
    int leftDepth;
    int rightDepth;
    if(root==nullptr)
    {
        return 0;
    }
    leftDepth=getPersonTreeDepth(root->leftNode);
    rightDepth=getPersonTreeDepth(root->rightNode);
    if(leftDepth>rightDepth)
    {
        return leftDepth+1;
    }
    return rightDepth+1;
}

int getHeightTreeDepth(HeightTree* root)
{
    int leftDepth;
    int rightDepth;
    if(root==nullptr)
    {
        return 0;
    }
    leftDepth=getHeightTreeDepth(root->leftNode);
    rightDepth=getHeightTreeDepth(root->rightNode);
    if(leftDepth>rightDepth)
    {
        return leftDepth+1;
    }
    return rightDepth+1;
}

void countPersonNodes(PersonTree* root,int& totalCount)
{
    if(root!=nullptr)
    {
        totalCount=totalCount+1;
        countPersonNodes(root->leftNode,totalCount);
        countPersonNodes(root->rightNode,totalCount);
    }
}

void countHeightNodes(HeightTree* root,int& totalCount)
{
    if(root!=nullptr)
    {
        totalCount=totalCount+1;
        countHeightNodes(root->leftNode,totalCount);
        countHeightNodes(root->rightNode,totalCount);
    }
}

PersonTree* clearPersonTree(PersonTree* root)
{
    if(root!=nullptr)
    {
        root->leftNode=clearPersonTree(root->leftNode);
        root->rightNode=clearPersonTree(root->rightNode);
        delete root;
    }
    return nullptr;
}

HeightTree* clearHeightTree(HeightTree* root)
{
    if(root!=nullptr)
    {
        root->leftNode=clearHeightTree(root->leftNode);
        root->rightNode=clearHeightTree(root->rightNode);
        delete root;
    }
    return nullptr;
}

int main()
{
    int nodesCount;
    int i;
    int randomHeight;
    int randomNameIndex;
    string randomNames[5]={"Yegor","Tanya","Misha","Lev","Kuzya"};
    string searchName;
    int nameCount;
    int mainNodeCount;
    int subNodeCount;

    srand(time(0));
    cout<<"Enter number of nodes:"<<endl;
    cin>>nodesCount;

    i=0;
    while(i<nodesCount)
    {
        randomHeight=rand()%101+120;
        if(isHeightInTree(mainRoot,randomHeight)==false)
        {
            randomNameIndex=rand()%5;
            mainRoot=insertPerson(mainRoot,randomHeight,randomNames[randomNameIndex]);
            i=i+1;
        }
    }

    cout<<"---"<<endl;
    cout<<"Main tree contents:"<<endl;
    printPersonTree(mainRoot);
    cout<<"---"<<endl;

    cout<<"Enter name to search (Yegor, Tanya, Misha, Lev, Kuzya):"<<endl;
    cin>>searchName;
    nameCount=0;
    countNameOccurrences(mainRoot,searchName,nameCount);
    if(nameCount>0)
    {
        cout<<"Name "<<searchName<<" found "<<nameCount<<" times."<<endl;
    }
    else
    {
        cout<<"Name "<<searchName<<" not found."<<endl;
    }
    cout<<"---"<<endl;

    if(mainRoot!=nullptr)
    {
        extractLeftSubtree(mainRoot->leftNode);
    }

    cout<<"New tree (left subtree heights only):"<<endl;
    printHeightTree(leftSubRoot);
    cout<<"---"<<endl;

    mainNodeCount=0;
    countPersonNodes(mainRoot,mainNodeCount);
    cout<<"Main tree nodes: "<<mainNodeCount<<endl;
    cout<<"Main tree depth: "<<getPersonTreeDepth(mainRoot)<<endl;

    subNodeCount=0;
    countHeightNodes(leftSubRoot,subNodeCount);
    cout<<"New tree nodes: "<<subNodeCount<<endl;
    cout<<"New tree depth: "<<getHeightTreeDepth(leftSubRoot)<<endl;

    mainRoot=clearPersonTree(mainRoot);
    leftSubRoot=clearHeightTree(leftSubRoot);

    return 0;
}