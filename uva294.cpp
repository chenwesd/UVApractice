#include<iostream>
#include<string.h>
using namespace std;
bool primenum[100000];
int prime[100000];
int main()
{
    memset(primenum,true,sizeof(primenum));
    memset(prime,0,sizeof(prime));
    primenum[0]=false;
    primenum[1]=false;
    int numofprime=0;
    for(int i=2;i<100000;i++)
    {
        if(primenum[i]==true)
        {
            prime[numofprime]=i;
            numofprime++;
            for(int j=i+i;j<100000;j+=i)
            {
                primenum[j]=false;
            }
        }
    }
    int n;
    cin>>n;
    while(n--)
    {

        int a,b;
        int indexofprime=0;
        int maxx=0;
        int num=0;
        cin>>a>>b;
        for(int i=a;i<b+1;i++)
        {
            int eachprime=0;
            int numoffactor=1;
            int temp=i;
            while(temp>1)
            {
                if(temp%prime[indexofprime]==0)
                {
                    eachprime++;
                    temp/=prime[indexofprime];
                    if(temp==1)
                    {
                        if(eachprime!=0)
                        {
                            numoffactor*=(eachprime+1);
                        }
                    }
                }
                else
                {
                    if(eachprime!=0)
                    {
                        numoffactor*=(eachprime+1);
                    }
                    indexofprime++;
                    eachprime=0;
                }
                if(indexofprime==numofprime)
                {
                    if(temp>1)numoffactor*=2;
                    break;
                }
            }
            if(numoffactor>maxx)
            {
                maxx=numoffactor;
                num=i;
            }
            indexofprime=0;
        }
        cout<<"Between "<<a<<" and "<<b<<", "<<num<<" has a maximum of "<<maxx<<" divisors."<<endl;
    }
}
