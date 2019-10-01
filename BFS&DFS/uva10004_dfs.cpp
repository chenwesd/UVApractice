#include <bits/stdc++.h>
using namespace std;
vector<int> edge[206];
int n;
int m;
bool dfs(int Start)
{
    int visit[206]={0};
    stack <int> Si;
    Si.push(Start);
    while(!Si.empty())
    {
        int now=Si.top();
        Si.pop();
        for(auto& next:edge[now])
        {
            if(!visit[next])
            {
                Si.push(next);
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
        string s=dfs(a1)?"BICOLORABLE.":"NOT BICOLORABLE.";
        cout<<s<<endl;
    }
    return 0;
}
