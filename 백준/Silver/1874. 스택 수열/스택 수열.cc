#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std; 

int n, a, number = 1;
int main() {
    cin >> n; 
	
	stack <int> st; 
	vector <char> answer; 
	vector <int> input(n); 
	
    for(int i = 0; i < n; i++){
        cin >> a; 

		if(!st.empty() && st.top() == a){
			st.pop(); 
			answer.push_back('-'); 
		}else if(number <= a){
			while(number <= a){
				st.push(number++);
				answer.push_back('+'); 
			}

			st.pop(); 
			answer.push_back('-'); 
		}else if(!st.empty() && st.top() > a){
			cout << "NO"; 
			return 0; 
		}
		
	}

	for (auto x : answer)
		cout << x << "\n"; 
	
	return 0; 
}