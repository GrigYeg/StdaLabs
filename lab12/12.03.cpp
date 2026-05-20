#include <iostream>
#include <string>
#include <deque>

using namespace std;

struct Order
{
    int orderNumber;
    string clientSurname;
    string deliveryAddress;
    double orderCost;
    bool isUrgent;
    int orderTime;
    string orderStatus;
};

struct CompareCost
{
    bool operator()(const Order& firstOrder,const Order& secondOrder)
    {
        return firstOrder.orderCost<secondOrder.orderCost;
    }
};

int main()
{
    deque<Order> deliveryQueue;
    deque<Order>::iterator dequeIterator;
    Order tempOrder;
    Order tempOrderSwap;
    int targetNumber;
    int i, j;

    tempOrder.orderNumber=1;
    tempOrder.clientSurname="Yegor";
    tempOrder.deliveryAddress="Chernivtsi";
    tempOrder.orderCost=300.0;
    tempOrder.isUrgent=false;
    tempOrder.orderTime=1400;
    tempOrder.orderStatus="Processing";
    deliveryQueue.push_back(tempOrder);

    tempOrder.orderNumber=2;
    tempOrder.clientSurname="Lev";
    tempOrder.deliveryAddress="Lviv";
    tempOrder.orderCost=800.5;
    tempOrder.isUrgent=true;
    tempOrder.orderTime=1415;
    tempOrder.orderStatus="New";
    if(tempOrder.isUrgent==true)
    {
        deliveryQueue.push_front(tempOrder);
    }
    else
    {
        deliveryQueue.push_back(tempOrder);
    }

    cout<<"All orders (Urgent first):"<<endl;
    for(dequeIterator=deliveryQueue.begin();dequeIterator!=deliveryQueue.end();++dequeIterator)
    {
        cout<<"#"<<dequeIterator->orderNumber<<" "<<dequeIterator->clientSurname<<" - "<<dequeIterator->orderCost<<endl;
    }
    cout<<"---"<<endl;



    for(i=0;i<deliveryQueue.size()-1;i++)
    {
        for(j=0;j<deliveryQueue.size()-i-1;j++)
        {
            if(deliveryQueue[j].orderCost>deliveryQueue[j+1].orderCost)
            {
                tempOrderSwap=deliveryQueue[j];
                deliveryQueue[j]=deliveryQueue[j+1];
                deliveryQueue[j+1]=tempOrderSwap;
            }
        }
    }

    cout<<"Sorted by cost:"<<endl;
    for(dequeIterator=deliveryQueue.begin();dequeIterator!=deliveryQueue.end();++dequeIterator)
    {
        cout<<"#"<<dequeIterator->orderNumber<<" "<<dequeIterator->clientSurname<<" - "<<dequeIterator->orderCost<<endl;
    }
    cout<<"---"<<endl;

    targetNumber=1;
    for(dequeIterator=deliveryQueue.begin();dequeIterator!=deliveryQueue.end();++dequeIterator)
    {
        if(dequeIterator->orderNumber==targetNumber)
        {
            dequeIterator->orderStatus="Completed";
        }
    }

    dequeIterator=deliveryQueue.begin();
    while(dequeIterator!=deliveryQueue.end())
    {
        if(dequeIterator->orderStatus=="Completed"||dequeIterator->orderStatus=="Cancelled")
        {
            dequeIterator=deliveryQueue.erase(dequeIterator);
        }
        else
        {
            ++dequeIterator;
        }
    }

    cout<<"After removing completed:"<<endl;
    for(dequeIterator=deliveryQueue.begin();dequeIterator!=deliveryQueue.end();++dequeIterator)
    {
        cout<<"#"<<dequeIterator->orderNumber<<" "<<dequeIterator->clientSurname<<" - "<<dequeIterator->orderStatus<<endl;
    }

    return 0;
}