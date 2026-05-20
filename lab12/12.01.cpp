#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book
{
    string bookTitle;
    string bookGenre;
    double bookPrice;
    int bookPopularity;
    int arrivalDate;
};

struct ComparePrice
{
    bool operator()(const Book& firstBook,const Book& secondBook)
    {
        return firstBook.bookPrice<secondBook.bookPrice;
    }
};

struct ComparePopularity
{
    bool operator()(const Book& firstBook,const Book& secondBook)
    {
        return firstBook.bookPopularity>secondBook.bookPopularity;
    }
};

struct CompareDate
{
    bool operator()(const Book& firstBook,const Book& secondBook)
    {
        return firstBook.arrivalDate>secondBook.arrivalDate;
    }
};

int main()
{
    vector<Book> storeInventory;
    vector<Book>::iterator vectorIterator;
    Book tempBook;
    Book tempBookSwap;
    string searchTitle;
    string filterGenre;
    double filterMinPrice;
    double filterMaxPrice;
    int i, j;

    tempBook.bookTitle="Harry Potter";
    tempBook.bookGenre="Fantasy";
    tempBook.bookPrice=450.5;
    tempBook.bookPopularity=10;
    tempBook.arrivalDate=2023;
    storeInventory.push_back(tempBook);

    tempBook.bookTitle="Murder on the Orient Express";
    tempBook.bookGenre="Detective";
    tempBook.bookPrice=200.0;
    tempBook.bookPopularity=8;
    tempBook.arrivalDate=2021;
    storeInventory.push_back(tempBook);

    tempBook.bookTitle="The Lord of the Rings";
    tempBook.bookGenre="Fantasy";
    tempBook.bookPrice=320.0;
    tempBook.bookPopularity=9;
    tempBook.arrivalDate=2022;
    storeInventory.push_back(tempBook);

    cout<<"All books:"<<endl;
    for(vectorIterator=storeInventory.begin();vectorIterator!=storeInventory.end();++vectorIterator)
    {
        cout<<vectorIterator->bookTitle<<" - "<<vectorIterator->bookPrice<<" UAH"<<endl;
    }
    cout<<"---"<<endl;

    for(i=0;i<storeInventory.size()-1;i++)
    {
        for(j=0;j<storeInventory.size()-i-1;j++)
        {
            if(storeInventory[j].bookPrice>storeInventory[j+1].bookPrice)
            {
                tempBookSwap=storeInventory[j];
                storeInventory[j]=storeInventory[j+1];
                storeInventory[j+1]=tempBookSwap;
            }
        }
    }
    
    cout<<"Sorted by price:"<<endl;
    for(vectorIterator=storeInventory.begin();vectorIterator!=storeInventory.end();++vectorIterator)
    {
        cout<<vectorIterator->bookTitle<<" - "<<vectorIterator->bookPrice<<" UAH"<<endl;
    }
    cout<<"---"<<endl;

    filterGenre="Fantasy";
    filterMinPrice=300.0;
    filterMaxPrice=500.0;
    
    cout<<"Filtered ("<<filterGenre<<", "<<filterMinPrice<<"-"<<filterMaxPrice<<"):"<<endl;
    for(vectorIterator=storeInventory.begin();vectorIterator!=storeInventory.end();++vectorIterator)
    {
        if(vectorIterator->bookGenre==filterGenre&&vectorIterator->bookPrice>=filterMinPrice&&vectorIterator->bookPrice<=filterMaxPrice)
        {
            cout<<vectorIterator->bookTitle<<" - "<<vectorIterator->bookPrice<<" UAH"<<endl;
        }
    }
    cout<<"---"<<endl;

    searchTitle="Murder on the Orient Express";
    for(vectorIterator=storeInventory.begin();vectorIterator!=storeInventory.end();++vectorIterator)
    {
        if(vectorIterator->bookTitle==searchTitle)
        {
            cout<<"Found book: "<<vectorIterator->bookTitle<<" Pop: "<<vectorIterator->bookPopularity<<endl;
        }
    }
    cout<<"---"<<endl;

    vectorIterator=storeInventory.begin();
    while(vectorIterator!=storeInventory.end())
    {
        if(vectorIterator->bookTitle=="The Lord of the Rings")
        {
            vectorIterator=storeInventory.erase(vectorIterator);
        }
        else
        {
            ++vectorIterator;
        }
    }

    cout<<"After removing The Lord of the Rings:"<<endl;
    for(vectorIterator=storeInventory.begin();vectorIterator!=storeInventory.end();++vectorIterator)
    {
        cout<<vectorIterator->bookTitle<<endl;
    }

    return 0;
}