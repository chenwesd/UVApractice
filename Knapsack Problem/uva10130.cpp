#include<bits/stdc++.h>
using namespace std;

struct OBJ {
    int weight;
    int price;
};

int main(int argc, char**argv) {

    int n;
    cin >> n;
    OBJ obj[1200];
    int MW[200];

    while (n--) {
        int dp[40] = {0};
        
        int m;
        cin>>m;
        for (int i = 0; i < m; i++) {
            scanf("%d", &obj[i].price);
            scanf("%d", &obj[i].weight);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 39; j >= obj[i].weight; j--)
            {dp[j] = max(dp[j], dp[j - obj[i].weight] + obj[i].price);}
        }
        
        int people;
        scanf("%d",&people);
        
        int total = 0;
        for (int i = 0; i < people; i++) {
            scanf("%d", &MW[i]);
            total += dp[MW[i]];
        }
        
        printf("%d\n",total);
    }
    system("pause");
    return 0;
}
