#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    multimap<char,string> wordDictionary;
    multimap<char,string>::iterator mapIterator;
    string currentWord;
    char firstLetter;

    cout<<"Enter words (type STOP to finish):"<<endl;
    while(cin>>currentWord)
    {
        if(currentWord=="STOP")
        {
            break;
        }
        firstLetter=currentWord[0];
        wordDictionary.insert({firstLetter,currentWord});
    }

    cout<<"Grouped words:"<<endl;
    for(mapIterator=wordDictionary.begin();mapIterator!=wordDictionary.end();++mapIterator)
    {
        cout<<mapIterator->first<<": "<<mapIterator->second<<endl;
    }

    return 0;
}