#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ArrayFilter
{
private:
    int arraySize;
    int* dataArray;
public:
    ArrayFilter();
    ~ArrayFilter();
    void setArraySize(int targetSize);
    int getArraySize() const;
    void generateUniqueArray();
    void printArray() const;
    void removeElement(int removalIndex);
    void processTask(int thresholdValue);
};

ArrayFilter::ArrayFilter()
{
    arraySize=0;
    dataArray=nullptr;
}

ArrayFilter::~ArrayFilter()
{
    if(dataArray!=nullptr)
    {
        delete[] dataArray;
        dataArray=nullptr;
    }
}

void ArrayFilter::setArraySize(int targetSize)
{
    arraySize=targetSize;
}

int ArrayFilter::getArraySize() const
{
    return arraySize;
}

void ArrayFilter::generateUniqueArray()
{
    int index;
    int checkIndex;
    bool isUnique;
    int randomValue;
    if(dataArray==nullptr)
    {
        dataArray=new int[arraySize];
    }
    for(index=0;index<arraySize;index++)
    {
        isUnique=false;
        while(!isUnique)
        {
            randomValue=rand()%100;
            isUnique=true;
            for(checkIndex=0;checkIndex<index;checkIndex++)
            {
                if(dataArray[checkIndex]==randomValue)
                {
                    isUnique=false;
                }
            }
        }
        dataArray[index]=randomValue;
    }
}

void ArrayFilter::printArray() const
{
    int index;
    for(index=0;index<arraySize;index++)
    {
        cout<<dataArray[index]<<" ";
    }
    cout<<endl;
}

void ArrayFilter::removeElement(int removalIndex)
{
    int index;
    for(index=removalIndex;index<arraySize-1;index++)
    {
        dataArray[index]=dataArray[index+1];
    }
    dataArray[arraySize-1]=0;
}

void ArrayFilter::processTask(int thresholdValue)
{
    int index;
    int validElementsCount;
    int calculatedSpace;
    validElementsCount=arraySize;
    index=0;
    while(index<validElementsCount)
    {
        if(dataArray[index]<=thresholdValue)
        {
            removeElement(index);
            validElementsCount=validElementsCount-1;
        }
        else
        {
            index=index+1;
        }
    }
    cout<<"Array after removal:"<<endl;
    printArray();
    calculatedSpace=sizeof(*this)+(arraySize*sizeof(int));
    cout<<"Space complexity:"<<calculatedSpace<<endl;
}

int main()
{
    ArrayFilter taskTwo;
    srand(time(0));
    taskTwo.setArraySize(15);
    taskTwo.generateUniqueArray();
    cout<<"Original array:"<<endl;
    taskTwo.printArray();
    taskTwo.processTask(50);
    return 0;
}