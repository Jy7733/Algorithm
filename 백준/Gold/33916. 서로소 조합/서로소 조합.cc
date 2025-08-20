#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime(5001,true);
vector<int> primeList; 
vector<vector<int>> prmCnt(5001, vector<int>(5001)); 

//소수 구하기 
void findPrime(){
    isPrime[0] = false;  
    isPrime[1] = false; 
    
    for(int i = 2; i * i <= 5000; i++){
        if(isPrime[i]){
            for(int k = i * i; k <= 5000; k += i){
                isPrime[k] = false; 
            }
        }
    }

    for(int i = 2; i <= 5000; i++){  
        if(isPrime[i]){
            primeList.push_back(i);
        }
    }
}


// 소인수분해 결과 누적 
void primeFact(){
    for(int num=2; num<=5000; num++){
        prmCnt[num] = prmCnt[num-1];
        int tmp = num;
        for(auto p : primeList){
            if(p > tmp) break;
            while(tmp % p ==0){
                prmCnt[num][p]++;
                tmp /= p;
            }
        }
    }
}

bool check(int n1, int r1, int n2, int r2){
    for(auto p : primeList){
        int result1 = prmCnt[n1][p] - prmCnt[n1-r1][p] - prmCnt[r1][p]; // C(n1,r1) 을 소인수 분해 했을 때 p의 개수  
        int result2 = prmCnt[n2][p] - prmCnt[n2-r2][p] - prmCnt[r2][p]; 
        if(result1>0 && result2>0) return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;

    findPrime();
    primeFact();

    for(int i=0; i<t; i++){
        int n1,r1,n2,r2;
        cin>>n1>>r1>>n2>>r2;

        cout<<check(n1,r1,n2,r2)<<"\n";
    }

    return 0;
}
