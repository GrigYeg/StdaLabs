#include <iostream>
#include <string>

using namespace std;

enum MediaFormat
{
    MEDIA_VINYL,
    MEDIA_CASSETTE,
    MEDIA_CD
};

struct MusicRecord
{
    MediaFormat recordFormat;
    string recordTitle;
    string artistName;
    int playTimeSeconds;
    int trackCount;
    double itemPrice;
    MusicRecord* nextNode;
} *initialRoot=nullptr,*cassetteRoot=nullptr;

MusicRecord* push(MusicRecord* root,MediaFormat format,string title,string artist,int time,int tracks,double price)
{
    MusicRecord* newNode;
    newNode=new MusicRecord;
    newNode->recordFormat=format;
    newNode->recordTitle=title;
    newNode->artistName=artist;
    newNode->playTimeSeconds=time;
    newNode->trackCount=tracks;
    newNode->itemPrice=price;
    newNode->nextNode=root;
    root=newNode;
    return root;
}

MusicRecord* pull(MusicRecord* root)
{
    MusicRecord* tempNode;
    if(root==nullptr)
    {
        return nullptr;
    }
    tempNode=root;
    root=root->nextNode;
    delete tempNode;
    return root;
}

void printMusicStack(MusicRecord* root)
{
    MusicRecord* traverseNode;
    traverseNode=root;
    if(traverseNode==nullptr)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    while(traverseNode!=nullptr)
    {
        cout<<traverseNode->recordTitle<<" - "<<traverseNode->artistName<<" ("<<traverseNode->itemPrice<<" USD)"<<endl;
        traverseNode=traverseNode->nextNode;
    }
}

MusicRecord* clearStack(MusicRecord* root)
{
    while(root!=nullptr)
    {
        root=pull(root);
    }
    return root;
}

int main()
{
    string targetArtist;
    int totalPlayTime;
    double totalCassettePrice;
    int cassetteCount;
    MusicRecord* traverseNode;

    initialRoot=push(initialRoot,MEDIA_CASSETTE,"Born This Way","Lady Gaga",3668,14,18.50);
    initialRoot=push(initialRoot,MEDIA_VINYL,"Mayhem","Lady Gaga",3192,14,55.00);
    initialRoot=push(initialRoot,MEDIA_CD,"Abbey Road","The Beatles",2823,17,15.99);
    initialRoot=push(initialRoot,MEDIA_CASSETTE,"Born to Die","Lana Del Rey",2968,12,12.50);

    cout<<"Initial music stack:"<<endl;
    printMusicStack(initialRoot);
    cout<<"---"<<endl;

    targetArtist="Lady Gaga";
    totalPlayTime=0;

    while(initialRoot!=nullptr)
    {
        if(initialRoot->artistName==targetArtist)
        {
            totalPlayTime=totalPlayTime+initialRoot->playTimeSeconds;
        }
        if(initialRoot->recordFormat==MEDIA_CASSETTE)
        {
            cassetteRoot=push(cassetteRoot,initialRoot->recordFormat,initialRoot->recordTitle,initialRoot->artistName,initialRoot->playTimeSeconds,initialRoot->trackCount,initialRoot->itemPrice);
        }
        initialRoot=pull(initialRoot);
    }

    cout<<"Total playtime for "<<targetArtist<<":"<<totalPlayTime<<" seconds"<<endl;

    cout<<"---"<<endl;
    cout<<"Cassette stack contents:"<<endl;
    printMusicStack(cassetteRoot);
    cout<<"---"<<endl;
    
    totalCassettePrice=0.0;
    cassetteCount=0;
    traverseNode=cassetteRoot;
    while(traverseNode!=nullptr)
    {
        totalCassettePrice=totalCassettePrice+traverseNode->itemPrice;
        cassetteCount=cassetteCount+1;
        traverseNode=traverseNode->nextNode;
    }
    
    if(cassetteCount>0)
    {
        cout<<"Average cassette price:"<<totalCassettePrice/cassetteCount<<endl;
    }
    else
    {
        cout<<"No cassettes found"<<endl;
    }
    
    initialRoot=clearStack(initialRoot);
    cassetteRoot=clearStack(cassetteRoot);
    return 0;
}