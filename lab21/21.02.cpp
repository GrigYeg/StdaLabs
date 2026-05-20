#include <iostream>

using namespace std;

int main()
{
    int supplyNW[3]={1500,1900,1600};
    int demandNW[3]={1800,1200,2000};
    int supplyMC[3]={1500,1900,1600};
    int demandMC[3]={1800,1200,2000};
    int costs[3][3]={{7,8,2},{1,4,3},{1,5,6}};
    int planNW[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    int planMC[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    int i;
    int j;
    int r;
    int c;
    int minCost;
    int minR;
    int minC;
    int allocation;
    int totalCostNW;
    int totalCostMC;
    bool stepsDone;

    r=0;
    c=0;
    while(r<3&&c<3)
    {
        if(supplyNW[r]<demandNW[c])
        {
            allocation=supplyNW[r];
        }
        else
        {
            allocation=demandNW[c];
        }
        planNW[r][c]=allocation;
        supplyNW[r]=supplyNW[r]-allocation;
        demandNW[c]=demandNW[c]-allocation;
        if(supplyNW[r]==0)
        {
            r++;
        }
        else
        {
            c++;
        }
    }

    while(true)
    {
        stepsDone=true;
        minCost=999999;
        minR=-1;
        minC=-1;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(supplyMC[i]>0&&demandMC[j]>0)
                {
                    if(costs[i][j]<minCost)
                    {
                        minCost=costs[i][j];
                        minR=i;
                        minC=j;
                        stepsDone=false;
                    }
                }
            }
        }
        if(stepsDone==true)
        {
            break;
        }
        if(supplyMC[minR]<demandMC[minC])
        {
            allocation=supplyMC[minR];
        }
        else
        {
            allocation=demandMC[minC];
        }
        planMC[minR][minC]=allocation;
        supplyMC[minR]=supplyMC[minR]-allocation;
        demandMC[minC]=demandMC[minC]-allocation;
    }

    totalCostNW=0;
    totalCostMC=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            totalCostNW=totalCostNW+planNW[i][j]*costs[i][j];
            totalCostMC=totalCostMC+planMC[i][j]*costs[i][j];
        }
    }

    cout<<"--- Northwest Corner Rule Plan ---"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<planNW[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Total Cost (Northwest): "<<totalCostNW<<endl<<endl;

    cout<<"--- Minimum Cost Method Plan ---"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<planMC[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Total Cost (Minimum Cost): "<<totalCostMC<<endl;

    return 0;
}