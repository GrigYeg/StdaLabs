#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string extAlphabet="АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ.,-";

string getPolybiusEncrypted(string text)
{
    string result;
    int i;
    int pos;
    int row;
    int col;
    char ch;
    result="";
    for(i=0;i<text.length();i++)
    {
        ch=text[i];
        pos=(int)extAlphabet.find(ch);
        if(pos!=-1)
        {
            row=pos/6+1;
            col=pos%6+1;
            result+=to_string(row)+to_string(col)+" ";
        }
    }
    return result;
}

string getPolybiusDecrypted(string text)
{
    string result;
    int i;
    int row;
    int col;
    int index;
    result="";
    for(i=0;i<text.length();i=i+3)
    {
        if(text[i]>='1'&&text[i]<='6'&&text[i+1]>='1'&&text[i+1]<='6')
        {
            row=text[i]-'1';
            col=text[i+1]-'1';
            index=row*6+col;
            result+=extAlphabet[index];
        }
    }
    return result;
}

void printPolybiusTable()
{
    int i;
    int j;
    int k;
    k=0;
    cout<<"--- Квадрат Полібія (6x6) ---"<<endl;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            cout<<extAlphabet[k]<<" ";
            k++;
        }
        cout<<endl;
    }
}

int main()
{
    string original;
    string encrypted;
    string decrypted;
    int i;
    int j;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    original="ПОЛІБІЙ";

    printPolybiusTable();

    encrypted=getPolybiusEncrypted(original);
    decrypted=getPolybiusDecrypted(encrypted);

    cout<<endl;
    cout<<"Кроки квадрата Полібія:"<<endl;
    j=0;
    for(i=0;i<original.length();i++)
    {
        cout<<original[i]<<" -> "<<encrypted[j]<<encrypted[j+1]<<endl;
        j=j+3;
    }

    cout<<endl;
    cout<<"Оригінал: "<<original<<endl;
    cout<<"Зашифровано: "<<encrypted<<endl;
    cout<<"Дешифровано: "<<decrypted<<endl;

    return 0;
}