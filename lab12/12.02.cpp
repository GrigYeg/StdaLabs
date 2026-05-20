#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Car
{
    string carName;
    int releaseYear;
    int mileageKm;
};

int main()
{
    list<Car> carList;
    list<Car>::iterator listIterator;
    int menuChoice;
    Car newCar;
    string targetName;
    int targetYear;
    bool isFound;

    menuChoice=0;
    while(menuChoice!=9)
    {
        cout<<"LIST OPERATIONS MENU"<<endl;
        cout<<"1. Enter first element into the list"<<endl;
        cout<<"2. Insert element at the beginning"<<endl;
        cout<<"3. Insert element at the end"<<endl;
        cout<<"4. Insert element after a specific element"<<endl;
        cout<<"5. Insert element before a specific element"<<endl;
        cout<<"6. Search for a specific node"<<endl;
        cout<<"7. Delete node by specified value"<<endl;
        cout<<"8. View list"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Enter operation number:"<<endl;
        cin>>menuChoice;

        if(menuChoice==1)
        {
            carList.clear();
            cout<<"Name Year Mileage:"<<endl;
            cin>>newCar.carName>>newCar.releaseYear>>newCar.mileageKm;
            carList.push_back(newCar);
        }
        else if(menuChoice==2)
        {
            cout<<"Name Year Mileage:"<<endl;
            cin>>newCar.carName>>newCar.releaseYear>>newCar.mileageKm;
            carList.push_front(newCar);
        }
        else if(menuChoice==3)
        {
            cout<<"Name Year Mileage:"<<endl;
            cin>>newCar.carName>>newCar.releaseYear>>newCar.mileageKm;
            carList.push_back(newCar);
        }
        else if(menuChoice==4)
        {
            cout<<"Target car name:"<<endl;
            cin>>targetName;
            cout<<"New car Name Year Mileage:"<<endl;
            cin>>newCar.carName>>newCar.releaseYear>>newCar.mileageKm;
            for(listIterator=carList.begin();listIterator!=carList.end();++listIterator)
            {
                if(listIterator->carName==targetName)
                {
                    ++listIterator;
                    carList.insert(listIterator,newCar);
                    break;
                }
            }
        }
        else if(menuChoice==5)
        {
            cout<<"Target car name:"<<endl;
            cin>>targetName;
            cout<<"New car Name Year Mileage:"<<endl;
            cin>>newCar.carName>>newCar.releaseYear>>newCar.mileageKm;
            for(listIterator=carList.begin();listIterator!=carList.end();++listIterator)
            {
                if(listIterator->carName==targetName)
                {
                    carList.insert(listIterator,newCar);
                    break;
                }
            }
        }
        else if(menuChoice==6)
        {
            cout<<"Target car name:"<<endl;
            cin>>targetName;
            isFound=false;
            for(listIterator=carList.begin();listIterator!=carList.end();++listIterator)
            {
                if(listIterator->carName==targetName)
                {
                    isFound=true;
                    break;
                }
            }
            if(isFound==true)
            {
                cout<<"Car named "<<targetName<<" is in the list"<<endl;
            }
            else
            {
                cout<<"Car named "<<targetName<<" is not in the list"<<endl;
            }
        }
        else if(menuChoice==7)
        {
            cout<<"Delete if year is less than:"<<endl;
            cin>>targetYear;
            listIterator=carList.begin();
            while(listIterator!=carList.end())
            {
                if(listIterator->releaseYear<targetYear)
                {
                    listIterator=carList.erase(listIterator);
                }
                else
                {
                    ++listIterator;
                }
            }
        }
        else if(menuChoice==8)
        {
            cout<<"Current list:"<<endl;
            for(listIterator=carList.begin();listIterator!=carList.end();++listIterator)
            {
                cout<<listIterator->carName<<" - "<<listIterator->releaseYear<<" ("<<listIterator->mileageKm<<" km)"<<endl;
            }
        }
    }
    return 0;
}