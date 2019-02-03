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
    int n;
    int c=0;
    for(int i=2;i<100000;i++)
    {
        if(primenum[i]==true)
        {
            prime[c]=i;
            c++;
            for(int j=i+i;j<100000;j+=i)
            {
                primenum[j]=false;
            }
        }
    }
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        if(n<0)
        {
            cout<<n<<" "<<"="<<" "<<"-1"<<" "<<"x"<<" ";
            n=n*-1;
        }
        else if(n>0)
            cout<<n<<" "<<"="<<" ";
        if(n==1)
        {
            cout<<"1"<<endl;
        }


        int i=0;
        while(n>1&&i<c)
        {
            if(n%prime[i]==0&&n!=prime[i])
            {
                cout<<prime[i]<<" "<<"x"<<" ";
                n/=prime[i];
            }
            else if(n%prime[i]==0&&n==prime[i])
            {
                cout<<prime[i]<<endl;
                n/=prime[i];
            }
            else
                i++;
            if(i==c)
            {
                cout<<n<<endl;
            }
        }

    }
    return 0;
}
