#include <iostream>

using namespace std;

int adjacencyMatrix[6][6]={
    {0,0,2,0,8,0},
    {0,0,6,4,0,0},
    {2,6,0,0,0,9},
    {0,4,0,0,4,0},
    {8,0,0,4,0,0},
    {0,0,9,0,0,0}
};

struct AdjacencyNode
{
    int targetNode;
    int edgeWeight;
    AdjacencyNode* nextNode;
} *adjacencyList[6]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};

bool isCompleteGraph()
{
    int i;
    int j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(i!=j&&adjacencyMatrix[i][j]==0)
            {
                return false;
            }
        }
    }
    return true;
}

AdjacencyNode* addNode(AdjacencyNode* root,int target,int weight)
{
    AdjacencyNode* newNode;
    newNode=new AdjacencyNode;
    newNode->targetNode=target;
    newNode->edgeWeight=weight;
    newNode->nextNode=root;
    return newNode;
}

bool findHamiltonianPath(int currentNode,int visitedCount,bool visitedNodes[])
{
    int i;
    if(visitedCount==6)
    {
        return true;
    }
    for(i=0;i<6;i++)
    {
        if(adjacencyMatrix[currentNode][i]>0&&visitedNodes[i]==false)
        {
            visitedNodes[i]=true;
            if(findHamiltonianPath(i,visitedCount+1,visitedNodes)==true)
            {
                return true;
            }
            visitedNodes[i]=false;
        }
    }
    return false;
}

int main()
{
    int i;
    int j;
    int k;
    int totalWeight;
    int edgeCount;
    double averageLength;
    int isolatedCount;
    int connectionCount;
    int lastConnectedNode;
    int lastConnectedWeight;
    int maxRouteWeight;
    int bestStartNode;
    int bestMidNode;
    int bestEndNode;
    int currentRouteWeight;
    bool hasHamiltonian;
    bool visitedNodes[6];
    AdjacencyNode* traverseNode;
    AdjacencyNode* tempNode;

    cout<<"1. Adjacency Matrix:"<<endl;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            cout<<adjacencyMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"---"<<endl;

    cout<<"2. Is graph complete? ";
    if(isCompleteGraph()==true)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    cout<<"---"<<endl;

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(adjacencyMatrix[i][j]>0)
            {
                adjacencyList[i]=addNode(adjacencyList[i],j,adjacencyMatrix[i][j]);
            }
        }
    }

    cout<<"3. Adjacency List:"<<endl;
    for(i=0;i<6;i++)
    {
        cout<<"Node "<<(i+1)<<": ";
        traverseNode=adjacencyList[i];
        while(traverseNode!=nullptr)
        {
            cout<<"-> ["<<(traverseNode->targetNode+1)<<" (w:"<<traverseNode->edgeWeight<<")] ";
            traverseNode=traverseNode->nextNode;
        }
        cout<<endl;
    }
    cout<<"---"<<endl;

    totalWeight=0;
    edgeCount=0;
    for(i=0;i<6;i++)
    {
        for(j=i+1;j<6;j++)
        {
            if(adjacencyMatrix[i][j]>0)
            {
                totalWeight=totalWeight+adjacencyMatrix[i][j];
                edgeCount=edgeCount+1;
            }
        }
    }
    averageLength=0.0;
    if(edgeCount>0)
    {
        averageLength=(double)totalWeight/edgeCount;
    }
    cout<<"4. Average path length: "<<averageLength<<endl;
    cout<<"---"<<endl;

    isolatedCount=0;
    cout<<"5. Isolated settlements:"<<endl;
    for(i=0;i<6;i++)
    {
        connectionCount=0;
        for(j=0;j<6;j++)
        {
            if(adjacencyMatrix[i][j]>0)
            {
                connectionCount=connectionCount+1;
                lastConnectedNode=j;
                lastConnectedWeight=adjacencyMatrix[i][j];
            }
        }
        if(connectionCount==1)
        {
            isolatedCount=isolatedCount+1;
            cout<<"Node "<<(i+1)<<" is isolated. Distance to nearest node "<<(lastConnectedNode+1)<<" is "<<lastConnectedWeight<<endl;
        }
    }
    cout<<"Total isolated nodes: "<<isolatedCount<<endl;
    cout<<"---"<<endl;

    maxRouteWeight=0;
    bestStartNode=0;
    bestMidNode=0;
    bestEndNode=0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(adjacencyMatrix[i][j]>0)
            {
                for(k=0;k<6;k++)
                {
                    if(adjacencyMatrix[j][k]>0&&i!=k)
                    {
                        currentRouteWeight=adjacencyMatrix[i][j]+adjacencyMatrix[j][k];
                        if(currentRouteWeight>maxRouteWeight)
                        {
                            maxRouteWeight=currentRouteWeight;
                            bestStartNode=i;
                            bestMidNode=j;
                            bestEndNode=k;
                        }
                    }
                }
            }
        }
    }
    cout<<"6. Max route between three cities:"<<endl;
    cout<<"("<<(bestStartNode+1)<<") --- "<<adjacencyMatrix[bestStartNode][bestMidNode]<<" --- ("<<(bestMidNode+1)<<") --- "<<adjacencyMatrix[bestMidNode][bestEndNode]<<" --- ("<<(bestEndNode+1)<<")"<<endl;
    cout<<"Total distance: "<<maxRouteWeight<<endl;
    cout<<"---"<<endl;

    hasHamiltonian=false;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            visitedNodes[j]=false;
        }
        visitedNodes[i]=true;
        if(findHamiltonianPath(i,1,visitedNodes)==true)
        {
            hasHamiltonian=true;
        }
    }
    cout<<"7. Visit all cities exactly once? ";
    if(hasHamiltonian==true)
    {
        cout<<"Yes, it is possible."<<endl;
    }
    else
    {
        cout<<"No, it is not possible."<<endl;
    }

    for(i=0;i<6;i++)
    {
        traverseNode=adjacencyList[i];
        while(traverseNode!=nullptr)
        {
            tempNode=traverseNode;
            traverseNode=traverseNode->nextNode;
            delete tempNode;
        }
        adjacencyList[i]=nullptr;
    }

    return 0;
}