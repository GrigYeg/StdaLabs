#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string,string> phoneBook;
    map<string,string>::iterator mapIterator;
    int menuChoice;
    string targetName;
    string targetPhone;

    menuChoice=0;
    while(menuChoice!=4)
    {
        cout<<"1. Add record"<<endl;
        cout<<"2. Search record"<<endl;
        cout<<"3. Delete record"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>menuChoice;

        if(menuChoice==1)
        {
            cout<<"Enter Name and Phone:"<<endl;
            cin>>targetName>>targetPhone;
            phoneBook[targetName]=targetPhone;
        }
        else if(menuChoice==2)
        {
            cout<<"Enter Name:"<<endl;
            cin>>targetName;
            mapIterator=phoneBook.find(targetName);
            if(mapIterator!=phoneBook.end())
            {
                cout<<"Phone: "<<mapIterator->second<<endl;
            }
            else
            {
                cout<<"Not found"<<endl;
            }
        }
        else if(menuChoice==3)
        {
            cout<<"Enter Name:"<<endl;
            cin>>targetName;
            phoneBook.erase(targetName);
        }

    }
    return 0;
}