#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void bubbleSort(vector<int>& arr, int n)
{
    int i;
    int j;
    int tempSwap;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                tempSwap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tempSwap;
            }
        }
    }
}

void insertionSort(vector<int>& arr, int n)
{
    int i;
    int j;
    int keyItem;
    for(i=1;i<n;i++)
    {
        keyItem=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>keyItem)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=keyItem;
    }
}

void selectionSort(vector<int>& arr, int n)
{
    int i;
    int j;
    int minIndex;
    int tempSwap;
    for(i=0;i<n-1;i++)
    {
        minIndex=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i)
        {
            tempSwap=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=tempSwap;
        }
    }
}

void gnomeSort(vector<int>& arr, int n)
{
    int index;
    int tempSwap;
    index=0;
    while(index<n)
    {
        if(index==0)
        {
            index++;
        }
        else if(arr[index]>=arr[index-1])
        {
            index++;
        }
        else
        {
            tempSwap=arr[index];
            arr[index]=arr[index-1];
            arr[index-1]=tempSwap;
            index--;
        }
    }
}

int main()
{
    int testSizes[3]={1000,10000,100000};
    int i;
    int j;
    int currentSize;
    vector<int> originalArray;
    vector<int> testArray;
    clock_t startTime;
    clock_t endTime;
    double durationTime;

    srand(time(0));

    for(i=0;i<3;i++)
    {
        currentSize=testSizes[i];
        cout<<"--- Testing N = "<<currentSize<<" ---"<<endl;
        
        originalArray.clear();
        for(j=0;j<currentSize;j++)
        {
            originalArray.push_back(rand()%10000);
        }

        testArray=originalArray;
        startTime=clock();
        bubbleSort(testArray,currentSize);
        endTime=clock();
        durationTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
        cout<<"Bubble Sort: "<<durationTime<<" sec"<<endl;

        testArray=originalArray;
        startTime=clock();
        insertionSort(testArray,currentSize);
        endTime=clock();
        durationTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
        cout<<"Insertion Sort: "<<durationTime<<" sec"<<endl;

        testArray=originalArray;
        startTime=clock();
        selectionSort(testArray,currentSize);
        endTime=clock();
        durationTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
        cout<<"Selection Sort: "<<durationTime<<" sec"<<endl;

        testArray=originalArray;
        startTime=clock();
        gnomeSort(testArray,currentSize);
        endTime=clock();
        durationTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
        cout<<"Gnome Sort: "<<durationTime<<" sec"<<endl<<endl;
    }

    return 0;
}