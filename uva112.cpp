#include<iostream>
using namespace std;
struct tree
{
    tree *parent;
    tree *left;
    tree *right;
    int number;
};
long long int n;
bool ans=false;
int backtracking(tree *now,long long int total)
{
    if(now->number==-0x3f3f3f3f)
    {
        return -0x3f3f3f3f;
    }
    //cout<<now->number<<" ";
    total+=now->number;
    //cout<<"total:"<<total<<endl;
    int l,r;
    if(now->left!=NULL)
    {
        l=backtracking(now->left,total);
    }
    if(now->right!=NULL)
    {
        r=backtracking(now->right,total);
    }
    if(l==-0x3f3f3f3f&&r==-0x3f3f3f3f&&ans==false)
    {
        //cout<<endl;
        if(total==n)
        {
            ans=true;
            cout<<"yes"<<endl;
        }
    }
    return now->number;
}
int main()
{
    tree TREE[10000];

    while(cin>>n)
    {
        for(int i=0; i<10000; i++)
        {
            TREE[i].parent=NULL;
            TREE[i].left=NULL;
            TREE[i].right=NULL;
            TREE[i].number=0;
        }
        int index=0;
        char ch[10000];
        int c=0;
        int leftsign=0;
        tree *now=&TREE[0];
        ans=false;
        bool negative=false;
        while(cin>>ch[c])
        {
            if(ch[c]==' ')
            {
                continue;
            }
            if(ch[c]=='-')
            {
                negative=true;
            }
            if(ch[c]>='0'&&ch[c]<='9')
            {
                now->number*=10;
                if(negative==true)
                {
                    now->number-=ch[c]-48;
                }
                else
                    now->number+=ch[c]-48;
            }
            if(ch[c]=='(')
            {
                negative=false;
                if(leftsign>=1)
                {
                    bool complete=false;
                    while(complete==false)
                    {
                        if(now->left==NULL)
                        {
                            now->left= &TREE[index+1];
                            TREE[index+1].parent=now;
                            now=now->left;
                            index++;
                            complete=true;
                        }
                        else if(now->right==NULL)
                        {
                            now->right= &TREE[index+1];
                            TREE[index+1].parent=now;
                            now=now->right;
                            index++;
                            complete=true;
                        }
                        else
                        {
                            now=now->parent;
                        }
                    }
                }
                leftsign++;
            }

            if(ch[c]==')')
            {
                leftsign--;
                if(ch[c-1]=='(')
                {
                    now->number=-0x3f3f3f3f;

                    //                    index++;
                }
                now=now->parent;
            }
            c++;
            if(leftsign==0)
            {
                break;
            }

        }
//        for(int i=0; i<20; i++)
//        {
//            cout<<TREE[i].number<<" ";
//            if(TREE[i].left!=NULL)
//                cout<<TREE[i].left->number<<" ";
//            if(TREE[i].right!=NULL)
//                cout<<TREE[i].right->number<<" ";
//            cout<<endl;
//        }
        if(index==0)
        {
            cout<<"no"<<endl;
            continue;
        }
        now=&TREE[0];
        int dd=backtracking(now,0);
        if(ans==false)
        {
            cout<<"no"<<endl;
        }
    }
}
