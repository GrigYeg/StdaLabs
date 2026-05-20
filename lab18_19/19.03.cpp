#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string ukrAlphabet="АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";

string getVigenereEncrypted(string text,string key)
{
    string result;
    int i;
    int keyIndex;
    int textPos;
    int keyPos;
    char ch;
    char newCh;
    result="";
    keyIndex=0;
    for(i=0;i<text.length();i++)
    {
        ch=text[i];
        textPos=(int)ukrAlphabet.find(ch);
        if(textPos!=-1)
        {
            keyPos=(int)ukrAlphabet.find(key[keyIndex%key.length()]);
            newCh=ukrAlphabet[(textPos+keyPos)%33];
            result+=newCh;
            keyIndex++;
        }
        else
        {
            result+=ch;
        }
    }
    return result;
}

string getVigenereDecrypted(string text,string key)
{
    string result;
    int i;
    int keyIndex;
    int textPos;
    int keyPos;
    char ch;
    char newCh;
    result="";
    keyIndex=0;
    for(i=0;i<text.length();i++)
    {
        ch=text[i];
        textPos=(int)ukrAlphabet.find(ch);
        if(textPos!=-1)
        {
            keyPos=(int)ukrAlphabet.find(key[keyIndex%key.length()]);
            newCh=ukrAlphabet[(textPos-keyPos+33)%33];
            result+=newCh;
            keyIndex++;
        }
        else
        {
            result+=ch;
        }
    }
    return result;
}

void printVigenereTable()
{
    int i;
    int j;
    cout<<"--- Таблиця Віженера ---"<<endl;
    for(i=0;i<33;i++)
    {
        for(j=0;j<33;j++)
        {
            cout<<ukrAlphabet[(i+j)%33]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    string original;
    string key;
    string encrypted;
    string decrypted;
    int i;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    original="ВІЖЕНЕР";
    key="КЛЮЧ";

    printVigenereTable();

    encrypted=getVigenereEncrypted(original,key);
    decrypted=getVigenereDecrypted(encrypted,key);

    cout<<endl;
    cout<<"Кроки шифру Віженера:"<<endl;
    for(i=0;i<original.length();i++)
    {
        cout<<original[i]<<" -> "<<encrypted[i]<<endl;
    }

    cout<<endl;
    cout<<"Оригінал: "<<original<<endl;
    cout<<"Ключ: "<<key<<endl;
    cout<<"Зашифровано: "<<encrypted<<endl;
    cout<<"Дешифровано: "<<decrypted<<endl;

    return 0;
}