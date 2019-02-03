#include<iostream>
using namespace std;
const int N = 35;
int n, k;
long long black[N][N * N], white[N][N * N];

int main()
{
    while (cin>>n>>k&& n)
    {
        black[0][0] = white[1][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int length = (i + 1) / 2 * 2 - 1;
            black[i][0] = black[i - 1][0];
            for (int j = 1; j <= length; j++)
            {
                black[i][j] = black[i - 1][j] + (length - j + 1) * black[i - 1][j - 1];
            }
        }
        for (int i = 2; i <= n; i++)
        {
            int length = i / 2 * 2;
            white[i][0] = white[i - 1][0];
            for (int j = 1; j <= length; j++)
            {
                white[i][j] = white[i - 1][j] + (length - j + 1) * white[i - 1][j - 1];
            }
        }
        long long ans = 0;
        for (int i = 0; i <= k; i++)
            ans += black[n][i] * white[n][k - i];
        cout<<ans<<endl;
    }
    return 0;
}
