#include<iostream>
using namespace std;
int main()
{
    int one,two,four,ten,twenty,fourty;
    float money;
    int intmoney;
    bool moneylist[10100];
    bool sellerlist[10100];
    int buynumofcoin[10100];
    int sellnumofcoin[10100];
    while(1)
    {
        int index=0;
        int sellerindex=0;
        int maxx=0;
        fill(moneylist,moneylist+10100,false);
        fill(sellerlist,sellerlist+10100,false);
        fill(buynumofcoin,buynumofcoin+10100,0);
        fill(sellnumofcoin,sellnumofcoin+10100,0);
        cin>>one>>two>>four>>ten>>twenty>>fourty;

        //cout<<intmoney<<endl;
        int total=one+two*2+four*4+ten*10+twenty*20+fourty*40;
        if(one==0&&two==0&&four==0&&ten==0&&twenty==0&&fourty==0)
        {
            break;
        }
        cin>>money;
        intmoney=money*100;
        if(intmoney%5!=0)
        {
            intmoney+=1;
        }
        intmoney/=5;
        moneylist[0]=true;
        for(int i=1;i<=one;i++) //buyerlist
        {
            for(int j=index;j>=0;j--)
            {
                if(moneylist[j]==true)
                {
                    buynumofcoin[j+i*1]=buynumofcoin[j]+i;
                    moneylist[j+i*1]=true;
                    if(j==index)
                    {
                        maxx=j+i*1;
                    }
                }
            }
        }
        index=maxx;
        for(int i=1;i<=two;i++)
        {
            for(int j=index;j>=0;j--)
            {
                if(moneylist[j]==true)
                {
                    moneylist[j+i*2]=true;
                    buynumofcoin[j+i*2]=buynumofcoin[j]+i;
                    if(j==index)
                    {
                        maxx=j+i*2;
                    }
                }
            }
        }
        index=maxx;
        for(int i=1;i<=four;i++)
        {
            for(int j=index;j>=0;j--)
            {
                if(moneylist[j]==true)
                {
                    moneylist[j+i*4]=true;
                    buynumofcoin[j+i*4]=buynumofcoin[j]+i;
                    if(j==index)
                    {
                        maxx=j+i*4;
                    }
                }
            }
        }
        index=maxx;
        for(int i=1;i<=ten;i++)
        {
            for(int j=index;j>=0;j--)
            {
                if(moneylist[j]==true)
                {
                    moneylist[j+i*10]=true;
                    buynumofcoin[j+i*10]=buynumofcoin[j]+i;
                    if(j==index)
                    {
                        maxx=j+i*10;
                    }
                }
            }
        }
        index=maxx;
        for(int i=1;i<=twenty;i++)
        {
            for(int j=index;j>=0;j--)
            {
                if(moneylist[j]==true)
                {
                    moneylist[j+i*20]=true;
                    buynumofcoin[j+i*20]=buynumofcoin[j]+i;
                    if(j==index)
                    {
                        maxx=j+i*20;
                    }
                }
            }
        }
        index=maxx;
        for(int i=1;i<=fourty;i++)
        {
            for(int j=index;j>=0;j--)
            {
                if(moneylist[j]==true)
                {
                    moneylist[j+i*40]=true;
                    buynumofcoin[j+i*40]=buynumofcoin[j]+i;
                    if(j==index)
                    {
                        maxx=j+i*40;
                    }
                }
            }
        }
        index=maxx;//buyerlist
        //sellerlist
        maxx=0;
        sellerlist[0]=true;
        for(int i=1;i<=100;i++) //buyerlist
        {
            for(int j=sellerindex;j>=0;j--)
            {
                if(sellerlist[j]==true)
                {
                    sellerlist[j+i*1]=true;
                    sellnumofcoin[j+i*1]=sellnumofcoin[j]+i;
                    if(j==sellerindex)
                    {
                        maxx=j+i*1;
                    }
                }
            }
        }
        sellerindex=maxx;
        for(int i=1;i<=50;i++)
        {
            for(int j=sellerindex;j>=0;j--)
            {
                if(sellerlist[j]==true)
                {
                    sellerlist[j+i*2]=true;
                    sellnumofcoin[j+i*2]=sellnumofcoin[j]+i;
                    if(j==sellerindex)
                    {
                        maxx=j+i*2;
                    }
                }
            }
        }
        sellerindex=maxx;
        for(int i=1;i<=25;i++)
        {
            for(int j=sellerindex;j>=0;j--)
            {
                if(sellerlist[j]==true)
                {
                    sellerlist[j+i*4]=true;
                    sellnumofcoin[j+i*4]=sellnumofcoin[j]+i;
                    if(j==sellerindex)
                    {
                        maxx=j+i*4;
                    }
                }
            }
        }
        sellerindex=maxx;
        for(int i=1;i<=10;i++)
        {
            for(int j=sellerindex;j>=0;j--)
            {
                if(sellerlist[j]==true)
                {
                    sellerlist[j+i*10]=true;
                    sellnumofcoin[j+i*10]=sellnumofcoin[j]+i;
                    if(j==sellerindex)
                    {
                        maxx=j+i*10;
                    }
                }
            }
        }
        sellerindex=maxx;
        for(int i=1;i<=5;i++)
        {
            for(int j=sellerindex;j>=0;j--)
            {
                if(sellerlist[j]==true)
                {
                    sellerlist[j+i*20]=true;
                    sellnumofcoin[j+i*20]=sellnumofcoin[j]+i;
                    if(j==sellerindex)
                    {
                        maxx=j+i*20;
                    }
                }
            }
        }
        sellerindex=maxx;
        for(int i=1;i<=3;i++)
        {
            for(int j=sellerindex;j>=0;j--)
            {
                if(sellerlist[j]==true)
                {
                    sellerlist[j+i*40]=true;
                    sellnumofcoin[j+i*40]=sellnumofcoin[j]+i;
                    if(j==sellerindex)
                    {
                        maxx=j+i*40;
                    }
                }
            }
        }
        sellerindex=maxx;
        //sellerlist

        int minn=1e9;
        for(int i=intmoney;i<=index;i++)
        {
            if(moneylist[i]==true)
            {
                if(buynumofcoin[i]+sellnumofcoin[i-intmoney]<minn)
                {
                    minn=buynumofcoin[i]+sellnumofcoin[i-intmoney];
                }
            }
        }
        if(minn>100)
        {
            cout<<minn<<endl;
        }
        else if(minn>10)
        {
            cout<<" "<<minn<<endl;
        }
        else
            cout<<"  "<<minn<<endl;
    }
}
