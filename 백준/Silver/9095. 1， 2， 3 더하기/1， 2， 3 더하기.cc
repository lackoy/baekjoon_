#include<iostream>
using namespace std;

int test_case, N, cnt = 0;
void solve(int sum) {
	if(sum == N){
		cnt++;
		return;
	}if(sum > N) return;

	for(int i = 1; i <= 3; i++)
		solve(sum+i);
}

int main(){
	cin >> test_case;

	for(int i = 0; i < test_case; i++){
		cin >> N;
		solve(0);
		cout << cnt << endl;
		cnt = 0;
	}

	return 0;
}