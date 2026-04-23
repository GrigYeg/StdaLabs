#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    multimap<string,string> phoneBook;
    multimap<string,string>::iterator mapIterator;
    pair<multimap<string,string>::iterator,multimap<string,string>::iterator> searchRange;
    int menuChoice;
    string targetName;
    string targetPhone;
    bool isDeleted;

    menuChoice=0;
    while(menuChoice!=6)
    {
        cout<<"1. Add record"<<endl;
        cout<<"2. View numbers for name"<<endl;
        cout<<"3. Delete specific number"<<endl;
        cout<<"4. Delete all numbers for name"<<endl;
        cout<<"5. View all directory"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>menuChoice;

        if(menuChoice==1)
        {
            cout<<"Name Phone:"<<endl;
            cin>>targetName>>targetPhone;
            phoneBook.insert({targetName,targetPhone});
        }
        else if(menuChoice==2)
        {
            cout<<"Enter Name:"<<endl;
            cin>>targetName;
            searchRange=phoneBook.equal_range(targetName);
            if(searchRange.first==searchRange.second)
            {
                cout<<"No records found"<<endl;
            }
            else
            {
                for(mapIterator=searchRange.first;mapIterator!=searchRange.second;++mapIterator)
                {
                    cout<<mapIterator->second<<endl;
                }
            }
        }
        else if(menuChoice==3)
        {
            cout<<"Name Phone to delete:"<<endl;
            cin>>targetName>>targetPhone;
            searchRange=phoneBook.equal_range(targetName);
            isDeleted=false;
            mapIterator=searchRange.first;
            while(mapIterator!=searchRange.second)
            {
                if(mapIterator->second==targetPhone)
                {
                    mapIterator=phoneBook.erase(mapIterator);
                    isDeleted=true;
                }
                else
                {
                    ++mapIterator;
                }
            }
            if(isDeleted==true)
            {
                cout<<"Number deleted"<<endl;
            }
        }
        else if(menuChoice==4)
        {
            cout<<"Enter Name:"<<endl;
            cin>>targetName;
            phoneBook.erase(targetName);
            cout<<"All numbers deleted"<<endl;
        }
        else if(menuChoice==5)
        {
            for(mapIterator=phoneBook.begin();mapIterator!=phoneBook.end();++mapIterator)
            {
                cout<<mapIterator->first<<" - "<<mapIterator->second<<endl;
            }
        }
    }
    return 0;
}