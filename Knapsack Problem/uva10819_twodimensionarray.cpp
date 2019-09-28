#include<bits/stdc++.h>
using namespace std;
struct Ob {
    short int wet;
    short int favor;
};
short int wet[10220][555];
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
            short int cost=object[i].favor;
            for(int j=0; j<=wt; j++) {
                int left=wet[j][i];
                int right=wet[j - weight][i] + cost;
                if (j - weight < 0)
                    // 耐重能力不足，故只能不放。
                    wet[j][i+1] = wet[j][i];
                else
                    // 耐重能力足夠，可以放或不放。
                    wet[j][i+1] = max(left,right);
            }
        }
        int w=wt;
        //找到實際用多少錢
        while(w>0&&wet[w][n]==wet[w-1][n])
            w--;
        if(w<=2000&&wt>2000)
            cout<<wet[wt-200][n]<<endl;
        else
            cout<<wet[wt][n]<<endl;
    }
    return 0;
}

