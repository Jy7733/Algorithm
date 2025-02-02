#include <bits/stdc++.h>

using namespace std;

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n = 0;
	string p = ""; //함수 
	string input = "";
	deque<int> dq;
	vector<string> result;
	
	cin>>t;
	
	for(int i=0; i<t; i++){
		cin>>p;
		cin>>n;
		cin>>input;

		bool flag = true; 
		bool error = false;

		//문자열 파싱 
		input = input.substr(1,input.size()-2);
		if (!input.empty()) { // 빈 배열이 아닌 경우만 파싱
            istringstream ss(input);
            string str;
            while (getline(ss, str, ',')) {
                dq.push_back(stoi(str));
            }
        }

		for(auto func : p){

			//R이면 flag만 바꿔줌
			if(func == 'R'){
				flag = !flag; //true면 false, false면 true로 변경
			}

			else if(func == 'D'){
				if(dq.empty()){
					error = true;
					break;
				}
				else if(flag == true){ 
					dq.pop_front();
				}
				else if(flag == false){
					dq.pop_back();
				}
			}
		}

		if(error) result.push_back("error");

		else {
            string tmp = "[";
            if (!flag) {
                while (!dq.empty()) {
                    tmp += to_string(dq.back());
                    dq.pop_back();
                    if (!dq.empty()) tmp += ",";
                }
            } else {
                while (!dq.empty()) {
                    tmp += to_string(dq.front());
                    dq.pop_front();
                    if (!dq.empty()) tmp += ",";
                }
            }
            tmp += "]";
            result.push_back(tmp);
        }
	}

	for(auto answer : result){
		cout<<answer<<"\n";
	}
}