#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    deque<string> requestQueue;
    deque<string>::iterator dequeIterator;
    int menuChoice;
    string requestName;

    menuChoice=0;
    while(menuChoice!=6)
    {
        cout<<"1. Add normal request"<<endl;
        cout<<"2. Add urgent request"<<endl;
        cout<<"3. Process request"<<endl;
        cout<<"4. View queue"<<endl;
        cout<<"5. Queue size"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>menuChoice;

        if(menuChoice==1)
        {
            cout<<"Request name:"<<endl;
            cin>>requestName;
            requestQueue.push_back(requestName);
        }
        else if(menuChoice==2)
        {
            cout<<"Request name:"<<endl;
            cin>>requestName;
            requestQueue.push_front(requestName);
        }
        else if(menuChoice==3)
        {
            if(requestQueue.empty()==false)
            {
                cout<<"Processing: "<<requestQueue.front()<<endl;
                requestQueue.pop_front();
            }
            else
            {
                cout<<"Queue is empty"<<endl;
            }
        }
        else if(menuChoice==4)
        {
            for(dequeIterator=requestQueue.begin();dequeIterator!=requestQueue.end();++dequeIterator)
            {
                cout<<*dequeIterator<<endl;
            }
        }
        else if(menuChoice==5)
        {
            cout<<"Total requests: "<<requestQueue.size()<<endl;
        }
    }
    return 0;
}