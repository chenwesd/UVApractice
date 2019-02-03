#include<iostream>
#include<sstream>
using namespace std;
struct evidance
{
    int score;
    int time;
    string description;
};
int main()
{
    stringstream ss;
    int n;
    cin>>n;
    char c;
    while(n--)
    {
        int time;
        cin>>time;
        cin.get();
        evidance cas[102];
        int num=0;
        string con;
        while(getline(cin,con))
        {
            if(con!="")
            {
                ss<<con;
                ss>>cas[num].score;
                ss>>cas[num].time;
                getline(ss,cas[num].description);
            }
            else
                break;
            num++;
            ss.clear();
            ss.str("");
        }
        int index;
        for(int i=0;i<num;i++)
        {
            int mintime=250;
            for(int j=i;j<num;j++)
            {
                if(cas[j].time<mintime)
                {
                    mintime=cas[j].time;
                    index=j;
                }
            }
            swap(cas[i],cas[index]);
        }
        int twoex=1;
        for(int i=0;i<num;i++)
        {
            twoex*=2;
        }
        //cout<<"num="<<num<<endl;
        //cout<<"num="<<twoex<<endl;
        int maxts=0;
        int maxx=0;
        int ts=0;
        int maxtsarr[num];
        int tsarr[num];
        while(1)
        {
            ts++;
            if(ts>twoex)
            {
                break;
            }
            int total=0;
            int temptime=0;
            int tempts=ts;
            for(int i=0;i<num;i++)
            {
                tsarr[i]=tempts%2;
                if(tsarr[i]==1)
                {
                    total+=cas[i].score;
                    temptime+=cas[i].time;
                }
                tempts/=2;
            }
            if(temptime>time)
            {
                continue;
            }
            //cout<<"total="<<total<<endl;
            if(total>maxx)
            {
                maxx=total;
                maxts=ts;
                copy(tsarr,tsarr+num,maxtsarr);
            }
        }
        cout<<ts<<endl;
        cout<<"Score Time Description"<<endl;
        cout<<"----- ---- -----------"<<endl;
        //cout<<"maxx="<<maxx<<endl;
        //cout<<"maxts="<<maxts<<endl;
        for(int i=0;i<num;i++)
        {
            if(maxtsarr[i]==1)
            {
                cout<<cas[i].score<<" ";
                cout<<cas[i].time;
                cout<<cas[i].description<<endl;
            }
        }
    }
}
//c(n, w) = max( c(n-1, w), c(n-1, w-weight[n]) + cost[n] )

