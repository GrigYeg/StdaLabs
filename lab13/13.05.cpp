#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    map<int,int> orderedMap;
    unordered_map<int,int> unorderedMap;
    int insertCount;
    int deleteCount;
    int searchCount;
    int i;
    time_point<high_resolution_clock> startTime;
    time_point<high_resolution_clock> endTime;
    microseconds durationTime;

    cout<<"Enter N (insert), M (delete), K (search):"<<endl;
    cin>>insertCount>>deleteCount>>searchCount;

    startTime=high_resolution_clock::now();
    for(i=0;i<insertCount;i++)
    {
        orderedMap.insert({i,i});
    }
    endTime=high_resolution_clock::now();
    durationTime=duration_cast<microseconds>(endTime-startTime);
    cout<<"Map insert time: "<<durationTime.count()<<" us"<<endl;

    startTime=high_resolution_clock::now();
    for(i=0;i<insertCount;i++)
    {
        unorderedMap.insert({i,i});
    }
    endTime=high_resolution_clock::now();
    durationTime=duration_cast<microseconds>(endTime-startTime);
    cout<<"Unordered map insert time: "<<durationTime.count()<<" us"<<endl;

    startTime=high_resolution_clock::now();
    for(i=0;i<deleteCount;i++)
    {
        orderedMap.erase(i);
    }
    endTime=high_resolution_clock::now();
    durationTime=duration_cast<microseconds>(endTime-startTime);
    cout<<"Map delete time: "<<durationTime.count()<<" us"<<endl;

    startTime=high_resolution_clock::now();
    for(i=0;i<deleteCount;i++)
    {
        unorderedMap.erase(i);
    }
    endTime=high_resolution_clock::now();
    durationTime=duration_cast<microseconds>(endTime-startTime);
    cout<<"Unordered map delete time: "<<durationTime.count()<<" us"<<endl;

    startTime=high_resolution_clock::now();
    for(i=0;i<searchCount;i++)
    {
        orderedMap.find(i);
    }
    endTime=high_resolution_clock::now();
    durationTime=duration_cast<microseconds>(endTime-startTime);
    cout<<"Map search time: "<<durationTime.count()<<" us"<<endl;

    startTime=high_resolution_clock::now();
    for(i=0;i<searchCount;i++)
    {
        unorderedMap.find(i);
    }
    endTime=high_resolution_clock::now();
    durationTime=duration_cast<microseconds>(endTime-startTime);
    cout<<"Unordered map search time: "<<durationTime.count()<<" us"<<endl;

    return 0;
}