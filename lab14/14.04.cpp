#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <ctime>

using namespace std;

int main()
{
    set<string> orderedSet;
    unordered_set<string> unorderedSet;
    int wordsCount;
    int searchCount;
    int i;
    string currentWord;
    clock_t startTime;
    clock_t endTime;
    double durationTime;

    cout<<"Enter N (words to generate and insert):"<<endl;
    cin>>wordsCount;

    startTime=clock();
    for(i=0;i<wordsCount;i++)
    {
        currentWord="Word"+to_string(i);
        orderedSet.insert(currentWord);
    }
    endTime=clock();
    durationTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"Set insert time: "<<durationTime<<" sec"<<endl;

    startTime=clock();
    for(i=0;i<wordsCount;i++)
    {
        currentWord="Word"+to_string(i);
        unorderedSet.insert(currentWord);
    }
    endTime=clock();
    durationTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"Unordered set insert time: "<<durationTime<<" sec"<<endl;

    cout<<"Enter K (words to search):"<<endl;
    cin>>searchCount;

    startTime=clock();
    for(i=0;i<searchCount;i++)
    {
        currentWord="Word"+to_string(i);
        orderedSet.find(currentWord);
    }
    endTime=clock();
    durationTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"Set search time: "<<durationTime<<" sec"<<endl;

    startTime=clock();
    for(i=0;i<searchCount;i++)
    {
        currentWord="Word"+to_string(i);
        unorderedSet.find(currentWord);
    }
    endTime=clock();
    durationTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"Unordered set search time: "<<durationTime<<" sec"<<endl;

    return 0;
}