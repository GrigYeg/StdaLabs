#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string baseAlphabet="АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
string keyAlphabet="ЯЮЬЩШЧЦХФУТСРПОНМЛКЙЇІИЗЖЄЕДҐГВБА";

string getSubstituteEncrypted(string text)
{
    string result;
    int i;
    int pos;
    char ch;
    char newCh;
    result="";
    for(i=0;i<text.length();i++)
    {
        ch=text[i];
        pos=(int)baseAlphabet.find(ch);
        if(pos!=-1)
        {
            newCh=keyAlphabet[pos];
            result+=newCh;
        }
        else
        {
            result+=ch;
        }
    }
    return result;
}

string getSubstituteDecrypted(string text)
{
    string result;
    int i;
    int pos;
    char ch;
    char newCh;
    result="";
    for(i=0;i<text.length();i++)
    {
        ch=text[i];
        pos=(int)keyAlphabet.find(ch);
        if(pos!=-1)
        {
            newCh=baseAlphabet[pos];
            result+=newCh;
        }
        else
        {
            result+=ch;
        }
    }
    return result;
}

int main()
{
    string original;
    string encrypted;
    string decrypted;
    int i;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    original="КРИПТОГРАФІЯ";

    encrypted=getSubstituteEncrypted(original);
    decrypted=getSubstituteDecrypted(encrypted);

    cout<<"Кроки простої заміни:"<<endl;
    for(i=0;i<original.length();i++)
    {
        cout<<original[i]<<" -> "<<encrypted[i]<<endl;
    }

    cout<<endl;
    cout<<"Оригінал: "<<original<<endl;
    cout<<"Зашифровано: "<<encrypted<<endl;
    cout<<"Дешифровано: "<<decrypted<<endl;

    return 0;
}