//This is a Transportation problem, but the matrix can now change
//and the total warehouse stocks are not equal to the total store needs
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> baseSupply={2000,3000};
    vector<int> baseDemand={1000,1500,1000,1200};
    vector<vector<int>> baseCosts={{5,2,7,3},{3,6,4,2}};
    vector<int> supplyNW;
    vector<int> demandNW;
    vector<int> supplyMC;
    vector<int> demandMC;
    vector<vector<int>> costs;
    vector<vector<int>> planNW;
    vector<vector<int>> planMC;
    vector<int> dummyRow;
    vector<int> rowZero;
    int numW;
    int numS;
    int totalSupply;
    int totalDemand;
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

    numW=baseSupply.size();
    numS=baseDemand.size();
    totalSupply=0;
    totalDemand=0;

    for(i=0;i<numW;i++)
    {
        totalSupply=totalSupply+baseSupply[i];
    }
    for(j=0;j<numS;j++)
    {
        totalDemand=totalDemand+baseDemand[j];
    }

    if(totalSupply>totalDemand)
    {
        cout<<"Unbalanced! Supply > Demand. Adding dummy shop."<<endl<<endl;
        baseDemand.push_back(totalSupply-totalDemand);
        for(i=0;i<numW;i++)
        {
            baseCosts[i].push_back(0);
        }
        numS++;
    }
    else if(totalDemand>totalSupply)
    {
        cout<<"Unbalanced! Demand > Supply. Adding dummy warehouse."<<endl<<endl;
        baseSupply.push_back(totalDemand-totalSupply);
        for(j=0;j<numS;j++)
        {
            dummyRow.push_back(0);
        }
        baseCosts.push_back(dummyRow);
        numW++;
    }
    else
    {
        cout<<"Problem is balanced."<<endl<<endl;
    }

    supplyNW=baseSupply;
    demandNW=baseDemand;
    supplyMC=baseSupply;
    demandMC=baseDemand;
    costs=baseCosts;

    for(j=0;j<numS;j++)
    {
        rowZero.push_back(0);
    }
    for(i=0;i<numW;i++)
    {
        planNW.push_back(rowZero);
        planMC.push_back(rowZero);
    }

    r=0;
    c=0;
    while(r<numW&&c<numS)
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
        for(i=0;i<numW;i++)
        {
            for(j=0;j<numS;j++)
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
    for(i=0;i<numW;i++)
    {
        for(j=0;j<numS;j++)
        {
            totalCostNW=totalCostNW+planNW[i][j]*costs[i][j];
            totalCostMC=totalCostMC+planMC[i][j]*costs[i][j];
        }
    }

    cout<<"--- Northwest Corner Rule Plan ---"<<endl;
    for(i=0;i<numW;i++)
    {
        for(j=0;j<numS;j++)
        {
            cout<<planNW[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Total Cost: "<<totalCostNW<<endl<<endl;

    cout<<"--- Minimum Cost Method Plan ---"<<endl;
    for(i=0;i<numW;i++)
    {
        for(j=0;j<numS;j++)
        {
            cout<<planMC[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Total Cost: "<<totalCostMC<<endl;

    return 0;
}