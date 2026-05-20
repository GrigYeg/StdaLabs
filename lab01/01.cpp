#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

class AlgorithmAnalyzer
{
private:
    int arraySize;
    double* oneDimensionalArray;
    double** twoDimensionalMatrix;
public:
    AlgorithmAnalyzer();
    ~AlgorithmAnalyzer();
    void setArraySize(int targetSize);
    int getArraySize() const;
    bool isSizeValid() const;
    void generateArray();
    void printArray() const;
    void createMatrix();
    void printMatrix() const;
    void sortArrayBubble(double* targetArray, int currentSize, bool isAscending);
    void sortMatrixRows();
    double findMaximumValue(double* targetArray, int currentSize) const;
    void findMaximumInAllColumns() const;
    void printMaximumInColumns() const;
    int calculateSpaceComplexity() const;
    void clearMemory();
};

AlgorithmAnalyzer::AlgorithmAnalyzer()
{
    arraySize=0;
    oneDimensionalArray=nullptr;
    twoDimensionalMatrix=nullptr;
}

AlgorithmAnalyzer::~AlgorithmAnalyzer()
{
    clearMemory();
}

void AlgorithmAnalyzer::clearMemory()
{
    int i;
    int rowCount;
    if(oneDimensionalArray!=nullptr)
    {
        delete[] oneDimensionalArray;
        oneDimensionalArray=nullptr;
    }
    if(twoDimensionalMatrix!=nullptr)
    {
        rowCount=arraySize/4;
        for(i=0;i<rowCount;i++)
        {
            delete[] twoDimensionalMatrix[i];
        }
        delete[] twoDimensionalMatrix;
        twoDimensionalMatrix=nullptr;
    }
}

void AlgorithmAnalyzer::setArraySize(int targetSize)
{
    arraySize=targetSize;
}

int AlgorithmAnalyzer::getArraySize() const
{
    return arraySize;
}

bool AlgorithmAnalyzer::isSizeValid() const
{
    if(arraySize%4==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void AlgorithmAnalyzer::generateArray()
{
    int i;
    if(oneDimensionalArray!=nullptr)
    {
        delete[] oneDimensionalArray;
    }
    oneDimensionalArray=new double[arraySize];
    for(i=0;i<arraySize;i++)
    {
        oneDimensionalArray[i]=(-150+rand()%601)/100.0;
    }
}

void AlgorithmAnalyzer::printArray() const
{
    int i;
    cout<<"Array A:"<<endl;
    for(i=0;i<arraySize;i++)
    {
        cout<<oneDimensionalArray[i]<<" ";
    }
    cout<<endl;
}

void AlgorithmAnalyzer::createMatrix()
{
    int rowCount;
    int i;
    int j;
    int elementIndex;
    rowCount=arraySize/4;
    twoDimensionalMatrix=new double*[rowCount];
    elementIndex=0;
    for(i=0;i<rowCount;i++)
    {
        twoDimensionalMatrix[i]=new double[4];
        for(j=0;j<4;j++)
        {
            twoDimensionalMatrix[i][j]=oneDimensionalArray[elementIndex];
            elementIndex=elementIndex+1;
        }
    }
}

void AlgorithmAnalyzer::printMatrix() const
{
    int rowCount;
    int i;
    int j;
    rowCount=arraySize/4;
    cout<<"Matrix B:"<<endl;
    for(i=0;i<rowCount;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<twoDimensionalMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void AlgorithmAnalyzer::sortArrayBubble(double* targetArray, int currentSize, bool isAscending)
{
    int i;
    int j;
    double tempValue;
    for(i=0;i<currentSize-1;i++)
    {
        for(j=0;j<currentSize-i-1;j++)
        {
            if(isAscending)
            {
                if(targetArray[j]>targetArray[j+1])
                {
                    tempValue=targetArray[j];
                    targetArray[j]=targetArray[j+1];
                    targetArray[j+1]=tempValue;
                }
            }
            else
            {
                if(targetArray[j]<targetArray[j+1])
                {
                    tempValue=targetArray[j];
                    targetArray[j]=targetArray[j+1];
                    targetArray[j+1]=tempValue;
                }
            }
        }
    }
}

void AlgorithmAnalyzer::sortMatrixRows()
{
    int rowCount;
    int i;
    rowCount=arraySize/4;
    for(i=0;i<rowCount;i++)
    {
        sortArrayBubble(twoDimensionalMatrix[i],4, i%2==0);
    }
}

double AlgorithmAnalyzer::findMaximumValue(double* targetArray, int currentSize) const
{
    int i;
    double maximumValue;
    maximumValue=targetArray[0];
    for(i=1;i<currentSize;i++)
    {
        if(targetArray[i]>maximumValue)
        {
            maximumValue=targetArray[i];
        }
    }
    return maximumValue;
}

void AlgorithmAnalyzer::findMaximumInAllColumns() const
{
    int rowCount;
    int j;
    int i;
    double* columnArray;
    double maximumValue;
    rowCount=arraySize/4;
    columnArray=new double[rowCount];
    for(j=0;j<4;j++)
    {
        for(i=0;i<rowCount;i++)
        {
            columnArray[i]=twoDimensionalMatrix[i][j];
        }
        maximumValue=findMaximumValue(columnArray,rowCount);
    }
    delete[] columnArray;
}

void AlgorithmAnalyzer::printMaximumInColumns() const
{
    int rowCount;
    int j;
    int i;
    double* columnArray;
    double maximumValue;
    rowCount=arraySize/4;
    columnArray=new double[rowCount];
    cout<<"Max elements:"<<endl;
    for(j=0;j<4;j++)
    {
        for(i=0;i<rowCount;i++)
        {
            columnArray[i]=twoDimensionalMatrix[i][j];
        }
        maximumValue=findMaximumValue(columnArray,rowCount);
        cout<<"Column "<<j<<": "<<maximumValue<<endl;
    }
    delete[] columnArray;
}

int AlgorithmAnalyzer::calculateSpaceComplexity() const
{
    int totalSpace;
    int rowCount;
    rowCount=arraySize/4;
    totalSpace=sizeof(*this);
    totalSpace=totalSpace+(arraySize*sizeof(double));
    totalSpace=totalSpace+(rowCount*sizeof(double*));
    totalSpace=totalSpace+(rowCount*4*sizeof(double));
    return totalSpace;
}

int main()
{
    int testSizes[3];
    int i;
    AlgorithmAnalyzer analyzerInstance;
    clock_t startTime;
    clock_t endTime;
    double timeElapsed;
    int spaceUsed;
    ofstream outputFile;

    testSizes[0]=20;
    testSizes[1]=100;
    testSizes[2]=1000;
    srand(time(0));
    outputFile.open("output.txt");
    if(!outputFile.is_open())
    {
        cout<<"File error"<<endl;
        return 1;
    }
    outputFile<<"N | n | Time, sec. | Space, byte"<<endl;
    for(i=0;i<3;i++)
    {
        analyzerInstance.clearMemory();
        analyzerInstance.setArraySize(testSizes[i]);
        if(analyzerInstance.isSizeValid())
        {
            startTime=clock();
            analyzerInstance.generateArray();
            analyzerInstance.createMatrix();
            analyzerInstance.sortMatrixRows();
            analyzerInstance.findMaximumInAllColumns();
            endTime=clock();
            timeElapsed=(double)(endTime-startTime)/CLOCKS_PER_SEC;
            spaceUsed=analyzerInstance.calculateSpaceComplexity();
            outputFile<<i+1<<" | "<<testSizes[i]<<" | "<<timeElapsed<<" | "<<spaceUsed<<endl;
            if(testSizes[i]==20)
            {
                cout<<"Size: "<<testSizes[i]<<endl;
                analyzerInstance.printArray();
                analyzerInstance.printMatrix();
                analyzerInstance.printMaximumInColumns();
            }
        }
        else
        {
            cout<<"Invalid size"<<endl;
        }
    }
    outputFile.close();
    cout<<"Done"<<endl;
    return 0;
}