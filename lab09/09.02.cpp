#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct DeviceNode
{
    int deviceCode;
    string deviceName;
    double devicePrice;
    DeviceNode* leftNode;
    DeviceNode* rightNode;
} *deviceRoot=nullptr;

DeviceNode* insertNode(DeviceNode* root,int code,string name,double price)
{
    DeviceNode* newNode;
    if(root==nullptr)
    {
        newNode=new DeviceNode;
        newNode->deviceCode=code;
        newNode->deviceName=name;
        newNode->devicePrice=price;
        newNode->leftNode=nullptr;
        newNode->rightNode=nullptr;
        return newNode;
    }
    if(code<root->deviceCode)
    {
        root->leftNode=insertNode(root->leftNode,code,name,price);
    }
    else if(code>root->deviceCode)
    {
        root->rightNode=insertNode(root->rightNode,code,name,price);
    }
    return root;
}

void calculateTotal(DeviceNode* root,double& totalPrice,int& deviceCount)
{
    if(root!=nullptr)
    {
        totalPrice=totalPrice+root->devicePrice;
        deviceCount=deviceCount+1;
        calculateTotal(root->leftNode,totalPrice,deviceCount);
        calculateTotal(root->rightNode,totalPrice,deviceCount);
    }
}

int getTreeDepth(DeviceNode* root)
{
    int leftDepth;
    int rightDepth;
    if(root==nullptr)
    {
        return 0;
    }
    leftDepth=getTreeDepth(root->leftNode);
    rightDepth=getTreeDepth(root->rightNode);
    if(leftDepth>rightDepth)
    {
        return leftDepth+1;
    }
    return rightDepth+1;
}

int countNodesAtLevel(DeviceNode* root,int currentLevel,int targetLevel)
{
    int leftCount;
    int rightCount;
    if(root==nullptr)
    {
        return 0;
    }
    if(currentLevel==targetLevel)
    {
        return 1;
    }
    leftCount=countNodesAtLevel(root->leftNode,currentLevel+1,targetLevel);
    rightCount=countNodesAtLevel(root->rightNode,currentLevel+1,targetLevel);
    return leftCount+rightCount;
}

DeviceNode* clearTree(DeviceNode* root)
{
    if(root!=nullptr)
    {
        root->leftNode=clearTree(root->leftNode);
        root->rightNode=clearTree(root->rightNode);
        delete root;
    }
    return nullptr;
}

void deleteChildren(DeviceNode* root,int targetCode)
{
    if(root!=nullptr)
    {
        if(root->deviceCode==targetCode)
        {
            root->leftNode=clearTree(root->leftNode);
            root->rightNode=clearTree(root->rightNode);
        }
        else if(targetCode<root->deviceCode)
        {
            deleteChildren(root->leftNode,targetCode);
        }
        else
        {
            deleteChildren(root->rightNode,targetCode);
        }
    }
}

void printTree(DeviceNode* root)
{
    if(root!=nullptr)
    {
        printTree(root->leftNode);
        cout<<root->deviceCode<<" "<<root->deviceName<<" "<<root->devicePrice<<endl;
        printTree(root->rightNode);
    }
}

int main()
{
    ifstream inputFile;
    int currentCode;
    string currentName;
    double currentPrice;
    double totalPrice;
    int deviceCount;
    int treeDepth;
    int i;
    int nodesAtLevel;
    int codeToDelete;

    inputFile.open("computers.txt");
    if(inputFile.is_open()==false)
    {
        cout<<"File error"<<endl;
        return 0;
    }

    while(inputFile>>currentCode>>currentName>>currentPrice)
    {
        deviceRoot=insertNode(deviceRoot,currentCode,currentName,currentPrice);
    }
    inputFile.close();

    cout<<"Computer list:"<<endl;
    printTree(deviceRoot);
    cout<<"---"<<endl;

    totalPrice=0.0;
    deviceCount=0;
    calculateTotal(deviceRoot,totalPrice,deviceCount);
    if(deviceCount>0)
    {
        cout<<"Average price:"<<totalPrice/deviceCount<<endl;
    }

    treeDepth=getTreeDepth(deviceRoot);
    cout<<"Nodes per level:"<<endl;
    i=1;
    while(i<=treeDepth)
    {
        nodesAtLevel=countNodesAtLevel(deviceRoot,1,i);
        cout<<"Level "<<i<<":"<<nodesAtLevel<<" nodes"<<endl;
        i=i+1;
    }
    cout<<"---"<<endl;

    cout<<"Enter device code to delete children:"<<endl;
    cin>>codeToDelete;

    deleteChildren(deviceRoot,codeToDelete);

    cout<<"Tree after deletion:"<<endl;
    printTree(deviceRoot);

    deviceRoot=clearTree(deviceRoot);

    return 0;
}