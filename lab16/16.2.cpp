#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Food
{
    string name;
    double proteins;
    double fats;
    double carbs;
    double calories;
};

int main()
{
    vector<Food> foods(5);
    int i;
    double maxCalories;
    int maxCount;
    double rangeA;
    double rangeB;
    bool isFoundInRange;

    foods[0].name="Apple"; foods[0].proteins=0.3; foods[0].fats=0.2; foods[0].carbs=13.8;
    foods[1].name="Chicken"; foods[1].proteins=27.0; foods[1].fats=14.0; foods[1].carbs=0.0;
    foods[2].name="Rice"; foods[2].proteins=2.7; foods[2].fats=0.3; foods[2].carbs=28.0;
    foods[3].name="Egg"; foods[3].proteins=13.0; foods[3].fats=11.0; foods[3].carbs=1.1;
    foods[4].name="Pork"; foods[4].proteins=27.0; foods[4].fats=14.0; foods[4].carbs=0.0;

    for(i=0;i<5;i++)
    {
        foods[i].calories=4.0*foods[i].proteins+9.0*foods[i].fats+4.0*foods[i].carbs;
    }

    maxCalories=foods[0].calories;
    for(i=1;i<5;i++)
    {
        if(foods[i].calories>maxCalories)
        {
            maxCalories=foods[i].calories;
        }
    }

    maxCount=0;
    cout<<"Max calories value: "<<maxCalories<<endl;
    cout<<"Foods with max calories at indices: ";
    for(i=0;i<5;i++)
    {
        if(foods[i].calories==maxCalories)
        {
            cout<<i<<" ";
            maxCount=maxCount+1;
        }
    }
    cout<<endl<<"Total count with max calories: "<<maxCount<<endl<<endl;

    cout<<"Enter range [A; B] for calories search:"<<endl;
    cin>>rangeA>>rangeB;

    cout<<"Foods in range ["<<rangeA<<"; "<<rangeB<<"]:"<<endl;
    isFoundInRange=false;
    for(i=0;i<5;i++)
    {
        if(foods[i].calories>=rangeA&&foods[i].calories<=rangeB)
        {
            cout<<"- "<<foods[i].name<<" ("<<foods[i].calories<<" kcal)"<<endl;
            isFoundInRange=true;
        }
    }

    if(isFoundInRange==false)
    {
        cout<<"No foods found in the specified range."<<endl;
    }

    return 0;
}