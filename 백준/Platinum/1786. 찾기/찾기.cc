#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string T, P;
vector<int>pi;
vector<int>result;

void make_text(){
	getline(cin, T);
	getline(cin, P);
}

void get_pi(string p){
	int m = p.size(), j = 0;

	pi.resize(m, 0);

	for(int i = 1; i < m; i++){
		while((j > 0) && (p[i] != p[j]))
			j = pi[j-1];
		
		if(p[i] == p[j]){
			j++;
			pi[i] = j;
		}
	}
}

void kmp(string t, string p){
	int n = t.size(), m = p.size(), j = 0;

	for(int i = 0; i < n; i++){
		while((j > 0) && (t[i] != p[j]))
			j = pi[j-1];
		
		if(t[i] == p[j]){
			if(j == (m-1)){
				result.push_back(i-m+1);
				j = pi[j];
			}else j++;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	make_text();
	get_pi(P);
	kmp(T, P);

	cout << result.size() << '\n';

	for (int i = 0; i < result.size(); i++)
		cout << result[i]+1 << '\n';

    return 0;
}