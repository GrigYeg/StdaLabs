#include <iostream>
#include <vector>

using namespace std;

struct Activity
{
    int id;
    int start;
    int end;
};

int main()
{
    int n;
    int i;
    int j;
    int count;
    int lastEndTime;
    Activity temp;
    vector<Activity> list;
    vector<Activity> selected;

    cout<<"Enter number of activities: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        temp.id=i+1;
        cout<<"Activity "<<temp.id<<" (start end): ";
        cin>>temp.start>>temp.end;
        list.push_back(temp);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(list[j].end>list[j+1].end)
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }

    count=0;
    lastEndTime=-1;

    for(i=0;i<n;i++)
    {
        if(list[i].start>=lastEndTime)
        {
            selected.push_back(list[i]);
            lastEndTime=list[i].end;
            count++;
        }
    }

    cout<<endl;
    cout<<"Maximum number of activities: "<<count<<endl;
    cout<<"Selected activities:"<<endl;
    for(i=0;i<count;i++)
    {
        cout<<"Activity "<<selected[i].id<<" ["<<selected[i].start<<", "<<selected[i].end<<"]"<<endl;
    }

    return 0;
}