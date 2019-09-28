#include<bits/stdc++.h>
using namespace std;
struct Ob {
    int wet;
    int favor;
};
int wet[10220];
Ob object[115];
int main() {

    int wt;
    int n;

    while(cin>>wt) {
        cin>>n;

        for(int i=1; i<=n; i++) {
            cin>>object[i].wet;
            cin>>object[i].favor;
        }
        memset(wet, 0, sizeof(wet));
        if(wt>1800)
            wt+=200;
        for(int i=1; i<=n; i++) {
            int weight=object[i].wet;
            int cost=object[i].favor;
            for(int j=wt; j>=weight; --j) {
                if(wet[j]<wet[j-weight]+cost){
                    wet[j]=wet[j-weight]+cost;
                }
            }
        }
        int w=wt;
        //找到實際用多少錢
        while(w>0&&wet[w]==wet[w-1])
            w--;
        if(w<=2000&&wt>2000)
            cout<<wet[wt-200]<<endl;
        else
            cout<<wet[wt]<<endl;
    }
    return 0;
}
