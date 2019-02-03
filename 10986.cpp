#include<iostream>
using namespace std;
short int ad[20001][20001];
int road[50000];
bool r[20001][20001];
int server;
void dikstra(int s,int e)
{
        if(s==e)
        {
            return ;
        }
        for(int i=0;i<server;i++)
        {
            if(road[i]==-1&&ad[s][i]!=-1&&r[s][i]==false)
            {
                road[i]=road[s]+ad[s][i];
                r[s][i]=true;
                dikstra(i,e);
            }
            else if(road[i]!=-1&&ad[s][i]!=-1&&r[s][i]==false)
            {
                if(road[s]+ad[s][i]<road[i])
                {
                    road[i]=road[s]+ad[s][i];
                    r[s][i]=true;
                    dikstra(i,e);
                }
            }

        }
}
int main()
{
    int n;
    int cable,start,endd;
    int column,row,value;
    cin>>n;
    int y=n;
    while(n--)
    {

        cin>>server>>cable>>start>>endd;
        for(int i=0;i<server;i++)
        {
            for(int j=0;j<server;j++)
            {
                ad[i][j]=-1;
            }
        }
        for(int i=0;i<server;i++)
        {
            for(int j=0;j<server;j++)
            {
                r[i][j]=false;
            }
        }
        for(int i=0;i<server;i++)
        {
            road[i]=-1;
        }
        for(int i=0;i<cable;i++)
        {
            cin>>column>>row>>value;
            ad[column][row]=value;
            ad[row][column]=value;
        }
        road[start]=0;
        dikstra(start,endd);
        if(road[endd]==-1)
        {
            cout<<"Case #"<<y-n<<": unreachable"<<endl;
        }
        else
            cout<<"Case #"<<y-n<<":"<<" "<<road[endd]<<endl;
        /*for(int i=0;i<server;i++)
        {
            if(road[i]==-1&&ad[start][i]!=-1)
            {
                road[i]=ad[start][i];
                r[start][i]=true;
            }
            else if(road[i]!=-1&&ad[start][i]!=-1)
            {
                if(road[start]+ad[start][i]<road[i])
                {
                    road[i]=road[start]+ad[start][i];
                    r[start][i]=true;
                }
            }

        }*/
    }
}
