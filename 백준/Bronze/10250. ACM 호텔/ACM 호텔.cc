#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    //test case 수만큼 반복하기 
    for(int i=0; i<t; i++){

        int h,w,n;
        cin>>h>>w>>n;

        //호수 & 층수 계산 
        int num = 0;
        int floor = 0;
        if(n % h == 0){
            num = n / h;
            floor = h;
        }
        else{
            num = (n/h) + 1;
            floor = n - (h * (n/h));
        }

        cout<<floor;
        if(num < 10) cout<<"0"<<num<<"\n";
        else cout<<num<<"\n";
    }

    
}