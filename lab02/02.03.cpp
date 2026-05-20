#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class MatrixSwapper
{
private:
    int matrixSize;
    int** dataMatrix;
public:
    MatrixSwapper();
    ~MatrixSwapper();
    void setMatrixSize(int targetSize);
    int getMatrixSize() const;
    void generateMatrix();
    void printMatrix() const;
    void swapRows(int firstRow, int secondRow);
    void swapColumns(int firstCol, int secondCol);
    void processTask();
};

MatrixSwapper::MatrixSwapper()
{
    matrixSize=0;
    dataMatrix=nullptr;
}

MatrixSwapper::~MatrixSwapper()
{
    int rowIndex;
    if(dataMatrix!=nullptr)
    {
        for(rowIndex=0;rowIndex<matrixSize;rowIndex++)
        {
            delete[] dataMatrix[rowIndex];
        }
        delete[] dataMatrix;
        dataMatrix=nullptr;
    }
}

void MatrixSwapper::setMatrixSize(int targetSize)
{
    matrixSize=targetSize;
}

int MatrixSwapper::getMatrixSize() const
{
    return matrixSize;
}

void MatrixSwapper::generateMatrix()
{
    int rowIndex;
    int colIndex;
    if(dataMatrix==nullptr)
    {
        dataMatrix=new int*[matrixSize];
        for(rowIndex=0;rowIndex<matrixSize;rowIndex++)
        {
            dataMatrix[rowIndex]=new int[matrixSize];
        }
    }
    for(rowIndex=0;rowIndex<matrixSize;rowIndex++)
    {
        for(colIndex=0;colIndex<matrixSize;colIndex++)
        {
            dataMatrix[rowIndex][colIndex]=rand()%100;
        }
    }
}

void MatrixSwapper::printMatrix() const
{
    int rowIndex;
    int colIndex;
    for(rowIndex=0;rowIndex<matrixSize;rowIndex++)
    {
        for(colIndex=0;colIndex<matrixSize;colIndex++)
        {
            cout<<dataMatrix[rowIndex][colIndex]<<"\t";
        }
        cout<<endl;
    }
}

void MatrixSwapper::swapRows(int firstRow, int secondRow)
{
    int* tempRow;
    tempRow=dataMatrix[firstRow];
    dataMatrix[firstRow]=dataMatrix[secondRow];
    dataMatrix[secondRow]=tempRow;
}

void MatrixSwapper::swapColumns(int firstCol, int secondCol)
{
    int rowIndex;
    int tempValue;
    for(rowIndex=0;rowIndex<matrixSize;rowIndex++)
    {
        tempValue=dataMatrix[rowIndex][firstCol];
        dataMatrix[rowIndex][firstCol]=dataMatrix[rowIndex][secondCol];
        dataMatrix[rowIndex][secondCol]=tempValue;
    }
}

void MatrixSwapper::processTask()
{
    int rowIndex;
    int colIndex;
    int maxRowIndex;
    int maxColIndex;
    int maximumValue;
    clock_t startTime;
    clock_t endTime;
    double executionTime;

    startTime=clock();
    maximumValue=dataMatrix[0][0];
    maxRowIndex=0;
    maxColIndex=0;

    for(rowIndex=0;rowIndex<matrixSize;rowIndex++)
    {
        for(colIndex=0;colIndex<matrixSize;colIndex++)
        {
            if(dataMatrix[rowIndex][colIndex]>maximumValue)
            {
                maximumValue=dataMatrix[rowIndex][colIndex];
                maxRowIndex=rowIndex;
                maxColIndex=colIndex;
            }
        }
    }

    if(maxRowIndex!=0)
    {
        swapRows(0,maxRowIndex);
        cout<<"Matrix after row swap:"<<endl;
        printMatrix();
    }

    if(maxColIndex!=0)
    {
        swapColumns(0,maxColIndex);
        cout<<"Matrix after column swap:"<<endl;
        printMatrix();
    }

    endTime=clock();
    executionTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"Execution time:"<<executionTime<<endl;
}

int main()
{
    MatrixSwapper taskThree;
    srand(time(0));
    taskThree.setMatrixSize(5);
    taskThree.generateMatrix();
    cout<<"Original 5x5 matrix:"<<endl;
    taskThree.printMatrix();
    taskThree.processTask();
    return 0;
}