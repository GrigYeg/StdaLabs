#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string morseLetters="АБВГДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
string morseCodes[32]={".-","-...",".--","--.","-..",".","..-..","...-","--..","..","..",".---.",".---","-.-",".-..","--","-.","---",".--.",".-.","...","-","..-","..-.","....","-.-.","---.","----","--.-","-..-","..--",".-.-"};

string getMorseEncrypted(string text)
{
    string result;
    int i;
    int pos;
    char ch;
    result="";
    for(i=0;i<text.length();i++)
    {
        ch=text[i];
        pos=(int)morseLetters.find(ch);
        if(pos!=-1)
        {
            result+=morseCodes[pos]+" ";
        }
    }
    return result;
}

string getMorseDecrypted(string text)
{
    string result;
    string currentCode;
    int i;
    int j;
    result="";
    currentCode="";
    text+=" ";
    for(i=0;i<text.length();i++)
    {
        if(text[i]==' '&&currentCode!="")
        {
            for(j=0;j<32;j++)
            {
                if(morseCodes[j]==currentCode)
                {
                    result+=morseLetters[j];
                    break;
                }
            }
            currentCode="";
        }
        else
        {
            currentCode+=text[i];
        }
    }
    return result;
}

void playMorseSound(string text)
{
    int i;
    for(i=0;i<text.length();i++)
    {
        if(text[i]=='.')
        {
            Beep(800,200);
            Sleep(100);
        }
        else if(text[i]=='-')
        {
            Beep(800,600);
            Sleep(100);
        }
        else if(text[i]==' ')
        {
            Sleep(300);
        }
    }
}

void printMorseTable()
{
    int i;
    cout<<"--- Таблиця азбуки Морзе ---"<<endl;
    for(i=0;i<32;i++)
    {
        cout<<morseLetters[i]<<" : "<<morseCodes[i]<<endl;
    }
}

int main()
{
    string original;
    string encrypted;
    string decrypted;
    int i;
    int pos;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    original="ПРИВІТ";

    printMorseTable();

    encrypted=getMorseEncrypted(original);
    decrypted=getMorseDecrypted(encrypted);

    cout<<endl;
    cout<<"Кроки коду Морзе:"<<endl;
    for(i=0;i<original.length();i++)
    {
        pos=(int)morseLetters.find(original[i]);
        if(pos!=-1)
        {
            cout<<original[i]<<" -> "<<morseCodes[pos]<<endl;
        }
    }

    cout<<endl;
    cout<<"Оригінал: "<<original<<endl;
    cout<<"Зашифровано (код): "<<encrypted<<endl;
    cout<<"Дешифровано: "<<decrypted<<endl;

    cout<<endl;
    cout<<"Відтворення звуку..."<<endl;
    playMorseSound(encrypted);

    return 0;
}