#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct TreeNode
{
    int nodeValue;
    TreeNode* leftNode;
    TreeNode* rightNode;
} *mainRoot=nullptr,*evenRoot=nullptr,*oddRoot=nullptr;

TreeNode* insertNode(TreeNode* root,int newValue)
{
    TreeNode* newNode;
    if(root==nullptr)
    {
        newNode=new TreeNode;
        newNode->nodeValue=newValue;
        newNode->leftNode=nullptr;
        newNode->rightNode=nullptr;
        return newNode;
    }
    if(newValue<root->nodeValue)
    {
        root->leftNode=insertNode(root->leftNode,newValue);
    }
    else if(newValue>root->nodeValue)
    {
        root->rightNode=insertNode(root->rightNode,newValue);
    }
    return root;
}

bool isValueInTree(TreeNode* root,int searchValue)
{
    if(root==nullptr)
    {
        return false;
    }
    if(root->nodeValue==searchValue)
    {
        return true;
    }
    if(searchValue<root->nodeValue)
    {
        return isValueInTree(root->leftNode,searchValue);
    }
    return isValueInTree(root->rightNode,searchValue);
}

void printTree(TreeNode* root)
{
    if(root!=nullptr)
    {
        printTree(root->leftNode);
        cout<<root->nodeValue<<" ";
        printTree(root->rightNode);
    }
}

int getTreeDepth(TreeNode* root)
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

void splitTree(TreeNode* sourceRoot)
{
    if(sourceRoot!=nullptr)
    {
        if(sourceRoot->nodeValue%2==0)
        {
            evenRoot=insertNode(evenRoot,sourceRoot->nodeValue);
        }
        else
        {
            oddRoot=insertNode(oddRoot,sourceRoot->nodeValue);
        }
        splitTree(sourceRoot->leftNode);
        splitTree(sourceRoot->rightNode);
    }
}

TreeNode* clearTree(TreeNode* root)
{
    if(root!=nullptr)
    {
        root->leftNode=clearTree(root->leftNode);
        root->rightNode=clearTree(root->rightNode);
        delete root;
    }
    return nullptr;
}

int main()
{
    int nodesCount;
    int inputMethod;
    int rangeA;
    int rangeB;
    int i;
    int generatedValue;
    int manualValue;

    srand(time(0));
    cout<<"Enter number of nodes:"<<endl;
    cin>>nodesCount;
    cout<<"Select input method (1 - manual, 2 - random):"<<endl;
    cin>>inputMethod;

    if(inputMethod==1)
    {
        i=0;
        while(i<nodesCount)
        {
            cout<<"Enter value:"<<endl;
            cin>>manualValue;
            if(isValueInTree(mainRoot,manualValue)==false)
            {
                mainRoot=insertNode(mainRoot,manualValue);
                i=i+1;
            }
            else
            {
                cout<<"Value already exists"<<endl;
            }
        }
    }
    else if(inputMethod==2)
    {
        cout<<"Enter range limits A and B:"<<endl;
        cin>>rangeA>>rangeB;
        if(nodesCount<=(rangeB-rangeA))
        {
            i=0;
            while(i<nodesCount)
            {
                generatedValue=rand()%(rangeB-rangeA+1)+rangeA;
                if(isValueInTree(mainRoot,generatedValue)==false)
                {
                    mainRoot=insertNode(mainRoot,generatedValue);
                    i=i+1;
                }
            }
        }
        else
        {
            cout<<"Invalid range"<<endl;
            return 0;
        }
    }

    cout<<"Main tree:"<<endl;
    printTree(mainRoot);
    cout<<endl;

    splitTree(mainRoot);

    cout<<"Even tree:"<<endl;
    printTree(evenRoot);
    cout<<endl;

    cout<<"Odd tree:"<<endl;
    printTree(oddRoot);
    cout<<endl;

    cout<<"Main tree depth:"<<getTreeDepth(mainRoot)<<endl;
    cout<<"Even tree depth:"<<getTreeDepth(evenRoot)<<endl;
    cout<<"Odd tree depth:"<<getTreeDepth(oddRoot)<<endl;

    mainRoot=clearTree(mainRoot);
    evenRoot=clearTree(evenRoot);
    oddRoot=clearTree(oddRoot);

    return 0;
}