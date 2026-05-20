#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string ukrAlphabet="АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";

string getCaesarEncrypted(string text,int shift)
{
    string result;
    int i;
    int pos;
    char ch;
    char newCh;
    result="";
    shift=(shift%33+33)%33;
    for(i=0;i<text.length();i++)
    {
        ch=text[i];
        pos=(int)ukrAlphabet.find(ch);
        if(pos!=-1)
        {
            newCh=ukrAlphabet[(pos+shift)%33];
            result+=newCh;
        }
        else
        {
            result+=ch;
        }
    }
    return result;
}

string getCaesarDecrypted(string text,int shift)
{
    return getCaesarEncrypted(text,33-shift);
}

bool getFrequencyCrackedShift(string text,string keyword,int& outShift)
{
    int i;
    string attempt;
    for(i=1;i<33;i++)
    {
        attempt=getCaesarEncrypted(text,33-i);
        if((int)attempt.find(keyword)!=-1)
        {
            outShift=i;
            return true;
        }
    }
    return false;
}

int main()
{
    string original;
    string encrypted;
    string decrypted;
    int shift;
    int crackedShift;
    int i;
    bool isCracked;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    original="ЦЕЗАРЬ";
    shift=2;

    encrypted=getCaesarEncrypted(original,shift);
    decrypted=getCaesarDecrypted(encrypted,shift);

    cout<<"Кроки шифрування Цезаря:"<<endl;
    for(i=0;i<original.length();i++)
    {
        cout<<original[i]<<" -> "<<encrypted[i]<<endl;
    }

    cout<<endl<<"Оригінал: "<<original<<endl;
    cout<<"Зашифровано: "<<encrypted<<endl;
    cout<<"Дешифровано: "<<decrypted<<endl;

    isCracked=getFrequencyCrackedShift(encrypted,"ЦЕЗ",crackedShift);
    if(isCracked==true)
    {
        cout<<endl<<"Злам успішний. Зсув: "<<crackedShift<<endl;
    }
    else
    {
        cout<<endl<<"Ключове слово не знайдено."<<endl;
    }

    return 0;
}