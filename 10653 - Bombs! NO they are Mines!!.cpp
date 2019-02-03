#include<iostream>
#include <string.h>
using namespace std;
short int mapp[1005][1005];
short int smapp[1005][1005];
typedef struct nodep {
    int x,y,s;
    nodep( int X, int Y, int S ){x = X;y= Y;s = S;}
    nodep(){}
}point;
point queuee[1000005];
int mov[4][2] = {1,0,-1,0,0,1,0,-1};
int BFS( int sx, int sy, int ex, int ey, int R, int C )
{
    int movee = 0,save = 0;
    queuee[save ++] = point( sx, sy, 0 );
    smapp[sx][sy] = 1;
    while ( movee < save ) {
        point q,p = queuee[movee ++];
        for ( int i = 0 ; i < 4 ; ++ i ) {
            q.x = p.x + mov[i][0];
            q.y = p.y + mov[i][1];
            q.s = p.s + 1;
            if ( q.x >= 0 && q.x < R && q.y >= 0 && q.y < C )
            if ( !smapp[q.x][q.y] && !mapp[q.x][q.y] ) {
                smapp[q.x][q.y] = 1;
                queuee[save ++] = q;
            }
            if ( q.x == ex && q.y == ey ) return q.s;
        }
    }
}
int main()
{
    int m,n;
    int numofrow,column,row,numofcolumn;
    while(1)
    {
        cin>>m>>n;
        memset( mapp, 0, sizeof(mapp) );
        memset( smapp, 0, sizeof(smapp) );
        if(m==0&&n==0)
        {
            return 0;
        }
        cin>>numofrow;
        for(int i=0;i<numofrow;i++)
        {
            cin>>row>>numofcolumn;
            for(int j=0;j<numofcolumn;j++)
            {
                cin>>column;
                mapp[row][column]=1;
            }
        }
        int startx,starty,destinationx,destinationy;
        cin>>startx>>starty>>destinationx>>destinationy;
        cout<<BFS(startx,starty,destinationx,destinationy,m,n)<<endl;
    }
}
