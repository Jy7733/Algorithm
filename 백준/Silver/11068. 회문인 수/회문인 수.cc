#include <bits/stdc++.h>

using namespace std;

vector<int> intoB; 


int main(void){
    int t; cin>>t;

    while(t--){
        int n;
        cin>>n;

        int result = 0;

        for(int i=2; i<=64; i++){

            intoB.clear();
            int number = n;

            //B진수로 변환 
            while(true){
                if(number == 0){
                    break;
                }

                intoB.push_back(number % i);
                number = number / i;
                
            }


            vector<int> tmp = intoB;
            reverse(intoB.begin(), intoB.end());

            //B진수로 변환한 값이 거꾸로해도 동일하면 result =1 로 갱신 
            if(tmp == intoB){
                result = 1;
                break;
            }

        }
    
        if(result == 0) cout<<"0\n";
        else cout<<"1\n";
    }
}
