#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
struct buy {
    int num;
    double price;
};
double BW[1000];
int main() {

    fstream fs;
    fs.open("write.txt", ios::out);
    double base;
    int Case=1;
    while(cin>>base) {

        BW[0]=0;
        for(int i=1; i<1000; i++) {
            BW[i]=BW[i-1]+base;
        }
        int n;
        cin>>n;
        //cout<<n<<endl;
        buy BUY[102];
        for(int i=0; i<n; i++) {
            cin>>BUY[i].num>>BUY[i].price;
            //cout<<BUY[i].num<<BUY[i].price<<endl;
            for(int j=BUY[i].num; j<1000; j++) {
                double t=BUY[i].price+BW[j-BUY[i].num];
                if(t<BW[j]) {
                    BW[j]=t;
                }
            }
        }
//        for(int i=0;i<100;i++)
//        {
//            cout<<BW[i]<<endl;
//        }
        string s;
        cin.get();
        getline(cin,s);
        int num=0;

        cout<<"Case "<<Case<<":"<<endl;
        fs<<"Case "<<Case<<":"<<endl;
        for(int i=0; i<s.length(); i++) {
            if(s[i]!=32&&i!=s.length()-1) {
                num*=10;
                num+=s[i]-48;
                continue;
            } else if(i==s.length()-1) {
                num*=10;
                num+=s[i]-48;
            }
            double mn=1000000;
            for(int j=num; j<1000; j++) {
                if(mn>BW[j]) {
                    mn=BW[j];
                }
            }

            //cout<<num<<endl;

                cout<<"Buy "<<num<<" for "<<"$"<<fixed <<  setprecision(2) <<mn<<endl;
                fs<<"Buy "<<num<<" for "<<"$"<<fixed <<  setprecision(2) <<mn<<endl;

            num=0;
        }
        //cout<<endl;
        Case++;
    }
    fs.close();

}
