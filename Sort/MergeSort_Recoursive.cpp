#include <bits/stdc++.h>
using namespace std;
#define inf 0x5fffffff
int arr[9] = {5, 4, 3, 7, 2, 1, 8, 9, 6};
void merge(int front,int mid,int end)
{
    vector<int> leftsub(arr+front,arr+mid+1);
    vector<int> rightsub(arr+mid+1,arr+end+1);
    
    leftsub.push_back(inf);
    rightsub.push_back(inf);
    int idxLeft=0,idxRight=0;
    for(int i=0;i<=end-front;i++)
    {
        if(leftsub[idxLeft]<rightsub[idxRight])
        {
            arr[front+i]=leftsub[idxLeft++];
        }
        else
        {
            arr[front+i]=rightsub[idxRight++];
        }
    }
    for(auto i:arr)
        cout<<i<<" ";
    cout<<endl;
}
void divide(int front,int end)
{
    int mid=(front+end)/2;
    if(front<end)
    {
        divide(front,mid);
        divide(mid+1,end);
        merge(front,mid,end);
    }
}
int notmain(int argc, char**argv) {

    divide(0,8);
    for(auto& i:arr)
    {
        cout<<i<<" ";
    }
    return 0;
}
