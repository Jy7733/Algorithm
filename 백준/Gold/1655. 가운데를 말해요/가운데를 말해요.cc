#include <bits/stdc++.h>

using namespace std;

priority_queue<int> L;
priority_queue<int, vector<int>, greater<int>>R;

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;

	vector<int> result;

	for(int i=0; i<n; i++){
		int input; cin>>input;

		if(L.empty() || input < L.top()){
			L.push(input);
		}
		else if(input >= L.top()){
			R.push(input);
		}
		if(L.size() > R.size() + 1){
			R.push(L.top());
			L.pop();
		}
		else if(L.size() < R.size()){
			L.push(R.top());
			R.pop();
		}

		result.push_back(L.top());
	}

	for(auto answer : result){
		cout<<answer<<"\n";
	}
}