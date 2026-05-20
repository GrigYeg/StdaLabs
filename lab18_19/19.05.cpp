#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string extAlphabet="АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ.,-";

string getPlayfairMatrix(string key)
{
    string matrix;
    int i;
    char ch;
    matrix="";
    for(i=0;i<key.length();i++)
    {
        ch=key[i];
        if((int)matrix.find(ch)==-1&&(int)extAlphabet.find(ch)!=-1)
        {
            matrix+=ch;
        }
    }
    for(i=0;i<extAlphabet.length();i++)
    {
        ch=extAlphabet[i];
        if((int)matrix.find(ch)==-1)
        {
            matrix+=ch;
        }
    }
    return matrix;
}

string getPreparedText(string text)
{
    string res;
    int i;
    res="";
    for(i=0;i<text.length();i++)
    {
        if((int)extAlphabet.find(text[i])!=-1)
        {
            res+=text[i];
        }
    }
    for(i=0;i<res.length()-1;i=i+2)
    {
        if(res[i]==res[i+1])
        {
            res.insert(i+1,"Х");
        }
    }
    if(res.length()%2!=0)
    {
        res+="Х";
    }
    return res;
}

string getPlayfairProcessed(string text,string matrix,int shift)
{
    string result;
    int i;
    int r1;
    int c1;
    int r2;
    int c2;
    int pos1;
    int pos2;
    result="";
    for(i=0;i<text.length();i=i+2)
    {
        pos1=(int)matrix.find(text[i]);
        pos2=(int)matrix.find(text[i+1]);
        r1=pos1/6;
        c1=pos1%6;
        r2=pos2/6;
        c2=pos2%6;
        if(r1==r2)
        {
            result+=matrix[r1*6+(c1+shift)%6];
            result+=matrix[r2*6+(c2+shift)%6];
        }
        else if(c1==c2)
        {
            result+=matrix[((r1+shift)%6)*6+c1];
            result+=matrix[((r2+shift)%6)*6+c2];
        }
        else
        {
            result+=matrix[r1*6+c2];
            result+=matrix[r2*6+c1];
        }
    }
    return result;
}

void printPlayfairMatrix(string matrix)
{
    int i;
    int j;
    int k;
    k=0;
    cout<<"--- Матриця Плейфера (6x6) ---"<<endl;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            cout<<matrix[k]<<" ";
            k++;
        }
        cout<<endl;
    }
}

int main()
{
    string original;
    string prepared;
    string key;
    string matrix;
    string encrypted;
    string decrypted;
    int i;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    original="МАТРИЦЯ";
    key="КЛЮЧ";

    matrix=getPlayfairMatrix(key);
    printPlayfairMatrix(matrix);

    prepared=getPreparedText(original);
    encrypted=getPlayfairProcessed(prepared,matrix,1);
    decrypted=getPlayfairProcessed(encrypted,matrix,5);

    cout<<endl;
    cout<<"Кроки шифру Плейфера:"<<endl;
    for(i=0;i<prepared.length();i=i+2)
    {
        cout<<prepared[i]<<prepared[i+1]<<" -> "<<encrypted[i]<<encrypted[i+1]<<endl;
    }

    cout<<endl;
    cout<<"Оригінал: "<<original<<endl;
    cout<<"Зашифровано: "<<encrypted<<endl;
    cout<<"Дешифровано: "<<decrypted<<endl;

    return 0;
}