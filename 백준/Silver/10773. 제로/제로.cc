#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int K, num, stack_size, sum = 0;
int main(){
	cin >> K;

	for(int i = 0; i < K; i++){
		cin >> num;
		if(num == 0) s.pop();
		else s.push(num);
	}

	stack_size = s.size();
	for(int i = 0; i < stack_size; i++){
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}