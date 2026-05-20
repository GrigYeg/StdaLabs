#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class MatrixReducer
{
private:
    int matrixSize;
    int** dataMatrix;
public:
    MatrixReducer();
    ~MatrixReducer();
    void setMatrixSize(int targetSize);
    int getMatrixSize() const;
    void generateMatrix();
    void printMatrix() const;
    void processTask();
};

MatrixReducer::MatrixReducer()
{
    matrixSize=0;
    dataMatrix=nullptr;
}

MatrixReducer::~MatrixReducer()
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

void MatrixReducer::setMatrixSize(int targetSize)
{
    matrixSize=targetSize;
}

int MatrixReducer::getMatrixSize() const
{
    return matrixSize;
}

void MatrixReducer::generateMatrix()
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

void MatrixReducer::printMatrix() const
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

void MatrixReducer::processTask()
{
    int rowIndex;
    int colIndex;
    int maxRowIndex;
    int maximumValue;
    int newRowIndex;
    int** newMatrix;

    for(rowIndex=0;rowIndex<matrixSize;rowIndex++)
    {
        for(colIndex=rowIndex;colIndex<matrixSize-1;colIndex++)
        {
            dataMatrix[rowIndex][colIndex]=dataMatrix[rowIndex][colIndex+1];
        }
    }

    maximumValue=dataMatrix[0][0];
    maxRowIndex=0;
    for(rowIndex=0;rowIndex<matrixSize;rowIndex++)
    {
        for(colIndex=0;colIndex<matrixSize-1;colIndex++)
        {
            if(dataMatrix[rowIndex][colIndex]>maximumValue)
            {
                maximumValue=dataMatrix[rowIndex][colIndex];
                maxRowIndex=rowIndex;
            }
        }
    }

    newMatrix=new int*[matrixSize-1];
    newRowIndex=0;
    for(rowIndex=0;rowIndex<matrixSize;rowIndex++)
    {
        if(rowIndex!=maxRowIndex)
        {
            newMatrix[newRowIndex]=dataMatrix[rowIndex];
            newRowIndex=newRowIndex+1;
        }
        else
        {
            delete[] dataMatrix[rowIndex];
        }
    }

    delete[] dataMatrix;
    dataMatrix=newMatrix;
    matrixSize=matrixSize-1;

    cout<<"Final matrix:"<<endl;
    printMatrix();
}

int main()
{
    MatrixReducer taskFour;
    srand(time(0));
    taskFour.setMatrixSize(5);
    taskFour.generateMatrix();
    cout<<"Original square matrix:"<<endl;
    taskFour.printMatrix();
    taskFour.processTask();
    return 0;
}