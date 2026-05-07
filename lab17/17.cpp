#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product
{
    string name;
    double price;
    double nutrients[3];
    double calories;
};

Product calculateProductCalories(Product p)
{
    Product result;
    result=p;
    result.calories=4.0*result.nutrients[0]+9.0*result.nutrients[1]+4.0*result.nutrients[2];
    return result;
}

vector<Product> getSortedByCaloriesDesc(vector<Product> arr)
{
    int n;
    int i;
    int j;
    int maxIndex;
    Product tempSwap;
    n=arr.size();
    for(i=0;i<n-1;i++)
    {
        maxIndex=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j].calories>arr[maxIndex].calories)
            {
                maxIndex=j;
            }
        }
        if(maxIndex!=i)
        {
            tempSwap=arr[i];
            arr[i]=arr[maxIndex];
            arr[maxIndex]=tempSwap;
        }
    }
    return arr;
}

vector<Product> getSortedByPriceAsc(vector<Product> arr)
{
    int n;
    int index;
    Product tempSwap;
    n=arr.size();
    index=0;
    while(index<n)
    {
        if(index==0)
        {
            index++;
        }
        else if(arr[index].price>=arr[index-1].price)
        {
            index++;
        }
        else
        {
            tempSwap=arr[index];
            arr[index]=arr[index-1];
            arr[index-1]=tempSwap;
            index--;
        }
    }
    return arr;
}

vector<Product> getProductsByPrice(vector<Product> arr, double targetPrice)
{
    vector<Product> results;
    int n;
    int i;
    n=arr.size();
    for(i=0;i<n;i++)
    {
        if(arr[i].price==targetPrice)
        {
            results.push_back(arr[i]);
        }
    }
    return results;
}

int main()
{
    vector<Product> products={
        {"Apple",25.5,{0.3,0.2,13.8},0.0},
        {"Chicken",150.0,{27.0,14.0,0.0},0.0},
        {"Rice",60.0,{2.7,0.3,28.0},0.0},
        {"Pork",150.0,{16.0,21.0,0.0},0.0},
        {"Egg",60.0,{13.0,11.0,1.1},0.0},
        {"Milk",35.0,{3.2,3.2,4.8},0.0}
    };
    vector<Product> sortedByCalories;
    vector<Product> sortedByPrice;
    vector<Product> searchResults;
    int i;
    int resultsCount;
    double targetPrice;

    for(i=0;i<6;i++)
    {
        products[i]=calculateProductCalories(products[i]);
    }

    sortedByCalories=getSortedByCaloriesDesc(products);

    cout<<"Selection Sort by Calories (DESC):"<<endl;
    for(i=0;i<6;i++)
    {
        cout<<sortedByCalories[i].name<<" - Calories: "<<sortedByCalories[i].calories<<endl;
    }
    cout<<endl;

    sortedByPrice=getSortedByPriceAsc(products);

    cout<<"Gnome Sort by Price (ASC):"<<endl;
    for(i=0;i<6;i++)
    {
        cout<<sortedByPrice[i].name<<" - Price: "<<sortedByPrice[i].price<<endl;
    }
    cout<<endl;

    targetPrice=60.0;

    cout<<"Searching for products with price: "<<targetPrice<<endl;

    searchResults=getProductsByPrice(products,targetPrice);
    resultsCount=searchResults.size();

    if(resultsCount==0)
    {
        cout<<"No products found with price "<<targetPrice<<endl;
    }
    else
    {
        for(i=0;i<resultsCount;i++)
        {
            cout<<"- "<<searchResults[i].name<<" (Calories: "<<searchResults[i].calories<<")"<<endl;
        }
    }

    return 0;
}