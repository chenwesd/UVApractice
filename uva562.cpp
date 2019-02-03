#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    int coin[101];
    bool value[50000];
    cin>>n;
    while(n--)
    {
        int index=0;
        int maxx=0;
        int total=0;
        fill(value,value+50000,false);
        value[0]=true;
        int numofcoin;
        cin>>numofcoin;
        for(int i=0;i<numofcoin;i++)
        {
            cin>>coin[i];
            total+=coin[i];
            for(int j=index;j>=0;j--)
            {
                if(value[j]==true)
                {
                    value[j+coin[i]]=true;
                    if((j+coin[i])>maxx)
                    {
                        maxx=j+coin[i];
                    }
                }
            }
            index=maxx;
        }
        /*cout<<"index:"<<index<<endl;
        for(int i=0;i<=index;i++)
        {
            cout<<i<<":";
            if(value[i]==true)
            {
                cout<<"1"<<endl;
            }
            else
                cout<<"0"<<endl;
        }*/
        if(value[total/2]==true)
        {
            cout<<abs(total-total/2-total/2)<<endl;
        }
        else
        {
            for(int i=1;i<total;i++)
            {
                if(value[total/2+i]==true)
                {
                    cout<<abs(total/2+2*i-total+total/2)<<endl;
                    break;
                }
                else if(value[total/2-i]==true)
                {
                    cout<<abs(total/2-i-total+total/2-i)<<endl;
                    break;
                }
            }
        }

    }
}
