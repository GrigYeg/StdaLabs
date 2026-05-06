#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tv
{
    string manufacturer;
    int screenSize;
    double priceUah;
};

void sortTvs(vector<Tv>& arr, int n)
{
    int i;
    int j;
    Tv tempTv;
    int startIndex;
    int endIndex;
    int index;

    for(i=1;i<n;i++)
    {
        tempTv=arr[i];
        j=i-1;
        while(j>=0&&arr[j].screenSize>tempTv.screenSize)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=tempTv;
    }

    startIndex=0;
    for(i=1;i<=n;i++)
    {
        if(i==n||arr[i].screenSize!=arr[i-1].screenSize)
        {
            endIndex=i;
            index=startIndex;
            while(index<endIndex)
            {
                if(index==startIndex)
                {
                    index++;
                }
                else if(arr[index].priceUah<=arr[index-1].priceUah)
                {
                    index++;
                }
                else
                {
                    tempTv=arr[index];
                    arr[index]=arr[index-1];
                    arr[index-1]=tempTv;
                    index--;
                }
            }
            startIndex=i;
        }
    }
}

int main()
{
    vector<Tv> store(6);
    int i;

    store[0].manufacturer="Samsung"; store[0].screenSize=60; store[0].priceUah=25000;
    store[1].manufacturer="LG";      store[1].screenSize=32; store[1].priceUah=8000;
    store[2].manufacturer="Sony";    store[2].screenSize=45; store[2].priceUah=15000;
    store[3].manufacturer="Philips"; store[3].screenSize=32; store[3].priceUah=9500;
    store[4].manufacturer="Kivi";    store[4].screenSize=60; store[4].priceUah=18000;
    store[5].manufacturer="TCL";     store[5].screenSize=45; store[5].priceUah=12000;

    cout<<"Before sorting:"<<endl;
    for(i=0;i<6;i++)
    {
        cout<<store[i].manufacturer<<" - "<<store[i].screenSize<<"\" - "<<store[i].priceUah<<" UAH"<<endl;
    }
    cout<<endl;

    sortTvs(store,6);

    cout<<"After sorting (Size ASC, Price DESC):"<<endl;
    for(i=0;i<6;i++)
    {
        cout<<store[i].manufacturer<<" - "<<store[i].screenSize<<"\" - "<<store[i].priceUah<<" UAH"<<endl;
    }

    return 0;
}