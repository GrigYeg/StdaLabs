#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string,int> wordCount;
    map<string,int>::iterator mapIterator;
    string currentWord;

    cout<<"Enter text (type STOP to finish):"<<endl;
    while(cin>>currentWord)
    {
        if(currentWord=="STOP")
        {
            break;
        }
        wordCount[currentWord]=wordCount[currentWord]+1;
    }

    cout<<"Word count (alphabetical order):"<<endl;
    for(mapIterator=wordCount.begin();mapIterator!=wordCount.end();++mapIterator)
    {
        cout<<mapIterator->first<<" - "<<mapIterator->second<<endl;
    }

    return 0;
}