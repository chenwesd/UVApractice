#include <bits/stdc++.h>
using namespace std;
vector<int> edge[206];
int n;
int m;
bool bfs(int Start)
{
    int visit[206]={0};
    queue<int> Qi;
    Qi.push(Start);
    while(!Qi.empty())
    {
        int now=Qi.front();
        Qi.pop();
        for(auto& next:edge[now])
        {
            if(!visit[next])
            {
                Qi.push(next);
                visit[next]=visit[now]==1?2:1;
            }
            else if(visit[next]==visit[now])
                return false;
        }
    }
    return true;
}
int main(int argc, char** argv) {
    while(cin>>n && n)
    {
        for (auto &v : edge) v.clear();
        cin>>m;
        int a1,a2;
        for(int i=0;i<m;i++)
        {
            cin>>a1>>a2;
            edge[a1].push_back(a2);
            edge[a2].push_back(a1);
        }
        string s=bfs(a1)?"BICOLORABLE.":"NOT BICOLORABLE.";
        cout<<s<<endl;
    }
    return 0;
}

