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
        buy BUY[102];
        for(int i=0; i<n; i++) {
            cin>>BUY[i].num>>BUY[i].price;
            //如果j數量的物品以BUY[i]替換其中一部分而價錢會變少的話則更新
            for(int j=BUY[i].num; j<1000; j++) {
                double t=BUY[i].price+BW[j-BUY[i].num];
                if(t<BW[j]) {
                    BW[j]=t;
                }
            }
        }
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
            //因題目可以買超過數量，故往後尋找最小錢
            for(int j=num; j<1000; j++) {
                if(mn>BW[j]) {
                    mn=BW[j];
                }
            }
            cout<<"Buy "<<num<<" for "<<"$"<<fixed <<  setprecision(2) <<mn<<endl;
            fs<<"Buy "<<num<<" for "<<"$"<<fixed <<  setprecision(2) <<mn<<endl;
            num=0;
        }
        Case++;
    }
    fs.close();
}
