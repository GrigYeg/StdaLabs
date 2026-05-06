#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Time
{
    int hours;
    int minutes;
};

struct Train
{
    int trainNumber;
    string destination;
    int distanceKm;
    Time departureTime;
    Time arrivalTime;
    int travelTimeMinutes;
};

void calculateTravelTime(Train& currentTrain)
{
    int depTotalMins;
    int arrTotalMins;
    depTotalMins=currentTrain.departureTime.hours*60+currentTrain.departureTime.minutes;
    arrTotalMins=currentTrain.arrivalTime.hours*60+currentTrain.arrivalTime.minutes;
    if(arrTotalMins<depTotalMins)
    {
        arrTotalMins=arrTotalMins+(24*60);
    }
    currentTrain.travelTimeMinutes=arrTotalMins-depTotalMins;
}

void selectionSortByTravelTimeDesc(vector<Train>& arr, int n)
{
    int i;
    int j;
    int maxIndex;
    Train tempSwap;
    for(i=0;i<n-1;i++)
    {
        maxIndex=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j].travelTimeMinutes>arr[maxIndex].travelTimeMinutes)
            {
                maxIndex=j;
            }
        }
        if(maxIndex!=i)
        {
            tempSwap=arr[i];
            arr[i]=arr[maxIndex];
            arr[maxIndex]=tempSwap;
        }
    }
}

int main()
{
    vector<Train> schedule(3);
    int maxTravelMins;
    int maxIndex;
    int i;

    schedule[0].trainNumber=101;
    schedule[0].destination="Kyiv";
    schedule[0].distanceKm=500;
    schedule[0].departureTime.hours=10;
    schedule[0].departureTime.minutes=30;
    schedule[0].arrivalTime.hours=16;
    schedule[0].arrivalTime.minutes=0;

    schedule[1].trainNumber=202;
    schedule[1].destination="Lviv";
    schedule[1].distanceKm=800;
    schedule[1].departureTime.hours=22;
    schedule[1].departureTime.minutes=15;
    schedule[1].arrivalTime.hours=8;
    schedule[1].arrivalTime.minutes=45;

    schedule[2].trainNumber=303;
    schedule[2].destination="Chernivtsi";
    schedule[2].distanceKm=550;
    schedule[2].departureTime.hours=14;
    schedule[2].departureTime.minutes=0;
    schedule[2].arrivalTime.hours=21;
    schedule[2].arrivalTime.minutes=10;

    maxTravelMins=-1;
    maxIndex=-1;

    for(i=0;i<3;i++)
    {
        calculateTravelTime(schedule[i]);
        if(schedule[i].travelTimeMinutes>maxTravelMins)
        {
            maxTravelMins=schedule[i].travelTimeMinutes;
            maxIndex=i;
        }
    }

    cout<<"a) Linear search longest route:"<<endl;
    cout<<"Train: "<<schedule[maxIndex].trainNumber<<" to "<<schedule[maxIndex].destination<<endl<<endl;

    selectionSortByTravelTimeDesc(schedule,3);

    cout<<"b) After Selection Sort (Longest first):"<<endl;
    cout<<"Train: "<<schedule[0].trainNumber<<endl;
    cout<<"Destination: "<<schedule[0].destination<<endl;
    cout<<"Travel Time: "<<schedule[0].travelTimeMinutes<<" mins"<<endl;

    return 0;
}