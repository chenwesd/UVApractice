#include<iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
char input()
{
    char temp;
    scanf("%c",&temp);
    while(temp==' '||temp=='\n')
    {
        scanf("%c",&temp);
    }
    return temp;
}
int traversal(int value,int *leaf)
{
    int v;
    scanf("%d",&v);
    char temp=input();
    int l=0,r=0,max=0;
    if(temp=='(')
    {
        //cout<<"v1:"<<value<<" "<<"v2:"<<" "<<v<<"vv:"<<value-v<<endl;
        if(traversal(value-v,&l))max=1;
        temp=input();
        if(traversal(value-v,&r))max=1;
        temp=input();
        if(l&&r)
            max=(v==value);
    }
    else *leaf=1;
    return max;
}
int main()
{
    int value;
    int leaf=0;
    while(cin>>value)
    {
        input();
        if(traversal(value,&leaf))
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
}
