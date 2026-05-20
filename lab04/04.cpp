#include <iostream>
#include <string>

using namespace std;

struct STUDENT
{
    string studentName;
    int groupNumber;
    int gradesArr[5];
};

double calculateAverageGrade(STUDENT currentStudent)
{
    double gradesSum;
    int i;
    
    gradesSum=0.0;
    for(i=0;i<5;i++)
    {
        gradesSum=gradesSum+currentStudent.gradesArr[i];
    }
    return gradesSum/5.0;
}

void printHighAchievers(STUDENT* studentArr,int arrSize)
{
    int i;
    bool hasFound;
    
    hasFound=false;
    cout<<"Average > 4.0:"<<endl;
    for(i=0;i<arrSize;i++)
    {
        if(calculateAverageGrade(studentArr[i])>4.0)
        {
            cout<<studentArr[i].studentName<<" "<<studentArr[i].groupNumber<<endl;
            hasFound=true;
        }
    }
    if(hasFound==false)
    {
        cout<<"No such students"<<endl;
    }
}


void printStudentsStartingVowel(STUDENT* studentArr,int arrSize)
{
    int studentI;
    int gradeI;
    int vowelI;
    char firstLetter;
    string vowels;
    bool isVowel;
    
    vowels="aeiouy";
    cout<<"Vowel names:"<<endl;
    for(studentI=0;studentI<arrSize;studentI++)
    {
        firstLetter=tolower(studentArr[studentI].studentName[0]);
        isVowel=false;
        for(vowelI=0;vowelI<6;vowelI++)
        {
            if(firstLetter==vowels[vowelI])
            {
                isVowel=true;
            }
        }
        if(isVowel==true)
        {
            cout<<studentArr[studentI].studentName<<" "<<studentArr[studentI].groupNumber<<" Grades:";
            for(gradeI=0;gradeI<5;gradeI++)
            {
                cout<<studentArr[studentI].gradesArr[gradeI]<<" ";
            }
            cout<<endl;
        }
    }
}

void sortStudentsByAverage(STUDENT* studentArr,int arrSize)
{
    int outerI;
    int innerI;
    STUDENT temporaryStudent;
    
    for(outerI=0;outerI<arrSize-1;outerI++)
    {
        for(innerI=0;innerI<arrSize-outerI-1;innerI++)
        {
            if(calculateAverageGrade(studentArr[innerI])>calculateAverageGrade(studentArr[innerI+1]))
            {
                temporaryStudent=studentArr[innerI];
                studentArr[innerI]=studentArr[innerI+1];
                studentArr[innerI+1]=temporaryStudent;
            }
        }
    }
}

void printAllStudents(STUDENT* studentArr,int arrSize)
{
    int studentI;
    int gradeI;
    
    for(studentI=0;studentI<arrSize;studentI++)
    {
        cout<<studentArr[studentI].studentName<<" "<<studentArr[studentI].groupNumber<<" Avg:"<<calculateAverageGrade(studentArr[studentI])<<" Grades:";
        for(gradeI=0;gradeI<5;gradeI++)
        {
            cout<<studentArr[studentI].gradesArr[gradeI]<<" ";
        }
        cout<<endl;
    }
}

void deleteElementAfterMinimum(STUDENT* studentArr,int& arrSize)
{
    int i;
    int minimumI;
    double minimumAverage;
    double currentAverage;
    
    if(arrSize<=1)
    {
        return;
    }
    minimumI=0;
    minimumAverage=calculateAverageGrade(studentArr[0]);
    for(i=1;i<arrSize;i++)
    {
        currentAverage=calculateAverageGrade(studentArr[i]);
        if(currentAverage<minimumAverage)
        {
            minimumAverage=currentAverage;
            minimumI=i;
        }
    }
    if(minimumI<arrSize-1)
    {
        for(i=minimumI+1;i<arrSize-1;i++)
        {
            studentArr[i]=studentArr[i+1];
        }
        arrSize=arrSize-1;
    }
    else
    {
        cout<<"Min is last, nothing to delete"<<endl;
    }
}

int main()
{
    int sz;
    STUDENT* arr;
    
    sz=4;
    arr=new STUDENT[sz];
    
    
    arr[0].studentName="Yehor";
    arr[0].groupNumber=101;
    arr[0].gradesArr[0]=5; arr[0].gradesArr[1]=5; arr[0].gradesArr[2]=4; arr[0].gradesArr[3]=4; arr[0].gradesArr[4]=4;
    
    arr[1].studentName="Volodymr";
    arr[1].groupNumber=102;
    arr[1].gradesArr[0]=3; arr[1].gradesArr[1]=5; arr[1].gradesArr[2]=3; arr[1].gradesArr[3]=4; arr[1].gradesArr[4]=4;
    
    arr[2].studentName="Nestor";
    arr[2].groupNumber=101;
    arr[2].gradesArr[0]=4; arr[2].gradesArr[1]=4; arr[2].gradesArr[2]=3; arr[2].gradesArr[3]=5; arr[2].gradesArr[4]=4;
    
    arr[3].studentName="Stas";
    arr[3].groupNumber=102;
    arr[3].gradesArr[0]=4; arr[3].gradesArr[1]=4; arr[3].gradesArr[2]=4; arr[3].gradesArr[3]=5; arr[3].gradesArr[4]=4;
    
    cout<<"Initial array:"<<endl;
    printAllStudents(arr,sz);
    cout<<"---"<<endl;
    
    printHighAchievers(arr,sz);
    cout<<"---"<<endl;
    
    printStudentsStartingVowel(arr,sz);
    cout<<"---"<<endl;
    
    sortStudentsByAverage(arr,sz);
    cout<<"Sorted array:"<<endl;
    printAllStudents(arr,sz);
    cout<<"---"<<endl;
    
    deleteElementAfterMinimum(arr,sz);
    cout<<"After deletion:"<<endl;
    printAllStudents(arr,sz);
    
    delete[] arr;
    return 0;
}