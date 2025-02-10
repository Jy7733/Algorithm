#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	ll num;
	int result = 0;

	cin>>n;
	ll input[n];
	map<ll, ll> sumMap;
	
	for(int i=0; i<n; i++){
		cin>>num;
		input[i] = num;
	}

	sort(input, input+n);

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			ll sum = input[i] + input[j];
			if(sum == input[j] && j+1 < n){
				if(input[j+1] == sum) sumMap[sum] +=1;
			}
			else if(sum == input[i] && i-1 >= 0){
				if(input[i-1] == sum) sumMap[sum] +=1;
			}
			else if(sum != input[j] && sum != input[i]) sumMap[sum] +=1;
		}
	}

	for(int i=0; i<n; i++){
		if(sumMap[input[i]] > 0 ) result+=1;
	}

	cout<<result<<"\n";

}