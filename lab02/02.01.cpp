#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ArraySorter
{
private:
    int arraySize;
    int* dataArray;
public:
    ArraySorter();
    ~ArraySorter();
    void setArraySize(int targetSize);
    int getArraySize() const;
    void generateArray();
    void printArray() const;
    void bubbleSort(int* targetArray, int currentSize, bool isAscending);
    void processTask();
};

ArraySorter::ArraySorter()
{
    arraySize=0;
    dataArray=nullptr;
}

ArraySorter::~ArraySorter()
{
    if(dataArray!=nullptr)
    {
        delete[] dataArray;
        dataArray=nullptr;
    }
}

void ArraySorter::setArraySize(int targetSize)
{
    arraySize=targetSize;
}

int ArraySorter::getArraySize() const
{
    return arraySize;
}

void ArraySorter::generateArray()
{
    int index;
    if(dataArray!=nullptr)
    {
        delete[] dataArray;
    }
    dataArray=new int[arraySize];
    for(index=0;index<arraySize;index++)
    {
        dataArray[index]=rand()%100;
    }
}

void ArraySorter::printArray() const
{
    int index;
    for(index=0;index<arraySize;index++)
    {
        cout<<dataArray[index]<<" ";
    }
    cout<<endl;
}

void ArraySorter::bubbleSort(int* targetArray, int currentSize, bool isAscending)
{
    int outerIndex;
    int innerIndex;
    int tempValue;
    for(outerIndex=0;outerIndex<currentSize-1;outerIndex++)
    {
        for(innerIndex=0;innerIndex<currentSize-outerIndex-1;innerIndex++)
        {
            if(isAscending)
            {
                if(targetArray[innerIndex]>targetArray[innerIndex+1])
                {
                    tempValue=targetArray[innerIndex];
                    targetArray[innerIndex]=targetArray[innerIndex+1];
                    targetArray[innerIndex+1]=tempValue;
                }
            }
            else
            {
                if(targetArray[innerIndex]<targetArray[innerIndex+1])
                {
                    tempValue=targetArray[innerIndex];
                    targetArray[innerIndex]=targetArray[innerIndex+1];
                    targetArray[innerIndex+1]=tempValue;
                }
            }
        }
    }
}

void ArraySorter::processTask()
{
    int evenCount;
    int oddCount;
    int index;
    int evenIndex;
    int oddIndex;
    int* evenArray;
    int* oddArray;
    clock_t startTime;
    clock_t endTime;
    double timeAscending;
    double timeDescending;

    evenCount=0;
    oddCount=0;
    for(index=0;index<arraySize;index++)
    {
        if(dataArray[index]%2==0)
        {
            evenCount=evenCount+1;
        }
        else
        {
            oddCount=oddCount+1;
        }
    }
    evenArray=new int[evenCount];
    oddArray=new int[oddCount];
    evenIndex=0;
    oddIndex=0;
    for(index=0;index<arraySize;index++)
    {
        if(dataArray[index]%2==0)
        {
            evenArray[evenIndex]=dataArray[index];
            evenIndex=evenIndex+1;
        }
        else
        {
            oddArray[oddIndex]=dataArray[index];
            oddIndex=oddIndex+1;
        }
    }
    startTime=clock();
    bubbleSort(evenArray,evenCount,true);
    endTime=clock();
    timeAscending=((double)(endTime-startTime)/CLOCKS_PER_SEC)*1000;

    startTime=clock();
    bubbleSort(oddArray,oddCount,false);
    endTime=clock();
    timeDescending=((double)(endTime-startTime)/CLOCKS_PER_SEC)*1000;

    evenIndex=0;
    oddIndex=0;
    for(index=0;index<arraySize;index++)
    {
        if(index<evenCount)
        {
            dataArray[index]=evenArray[evenIndex];
            evenIndex=evenIndex+1;
        }
        else
        {
            dataArray[index]=oddArray[oddIndex];
            oddIndex=oddIndex+1;
        }
    }
    cout<<"Transformed array:"<<endl;
    printArray();
    cout<<"Ascending sort time (ms):"<<timeAscending<<endl;
    cout<<"Descending sort time (ms):"<<timeDescending<<endl;

    delete[] evenArray;
    delete[] oddArray;
}

int main()
{
    ArraySorter taskOne;
    srand(time(0));
    taskOne.setArraySize(15);
    taskOne.generateArray();
    cout<<"Original array:"<<endl;
    taskOne.printArray();
    taskOne.processTask();
    return 0;
}