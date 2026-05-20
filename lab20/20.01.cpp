#include <iostream>
#include <vector>

using namespace std;

int main()
{
    double volumeLimit;
    double weightLimit;
    double currentVolume;
    double currentWeight;
    double meat;
    double flour;
    double milk;
    double sugar;
    double calories;
    double step;

    volumeLimit=45.0;
    weightLimit=35.0;
    currentVolume=0.0;
    currentWeight=0.0;
    meat=0.0;
    flour=0.0;
    milk=0.0;
    sugar=0.0;
    step=0.01;

    while(currentVolume+step*45.0<=volumeLimit&&currentWeight+step*33.0<=weightLimit)
    {
        sugar=sugar+step;
        milk=milk+step*8.0;
        flour=flour+step*8.0;
        meat=meat+step*16.0;
        currentVolume=sugar*1.0+milk*2.0+flour*1.5+meat*1.0;
        currentWeight=sugar+milk+flour+meat;
    }

    calories=meat*1500.0+flour*5000.0+milk*5000.0+sugar*4000.0;

    cout<<"Greedy algorithm results:"<<endl;
    cout<<"Meat: "<<meat<<" kg"<<endl;
    cout<<"Flour: "<<flour<<" kg"<<endl;
    cout<<"Milk powder: "<<milk<<" kg"<<endl;
    cout<<"Sugar: "<<sugar<<" kg"<<endl;
    cout<<endl;
    cout<<"Total volume: "<<currentVolume<<" dm3"<<endl;
    cout<<"Total weight: "<<currentWeight<<" kg"<<endl;
    cout<<"Total calories: "<<calories<<" kcal"<<endl;

    return 0;
}