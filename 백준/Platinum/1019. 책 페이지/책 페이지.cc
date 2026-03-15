#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int n;
long long cnt[10];

int LastIsNine(int num){
	while(1){
		if(num%10 == 9) break;
		num--;
	}

	return num;
}

void AtoB(int A, int B, int digit){
	if(B < 10){
		for(int i = A; i <= B; i++)
			cnt[i] += (long long)digit;
		
            return;
	}

	int tmp = LastIsNine(B);

	for(int i = tmp+1; i <= B; i++){
		string s = to_string(i);
		for(int j = 0; j < s.size(); j++){
			int idx = s[j]-'0';
			cnt[idx] += (long long)digit;
		}
	}

	for (int i = 0; i < 10; i++)
		cnt[i] += (long long)((tmp/10-A/10+1)*digit);

	AtoB(A/10, tmp/10, digit*10);
	
    return;
}

int main(){
	cin >> n;
	memset(cnt, 0, sizeof(cnt));

	if(n < 10){
		for (int i = 1; i <= n; i++)
			cnt[i] += 1;

		for (int i = 0; i < 10; i++)
			cout << cnt[i] << ' ';

		return 0;
    }
	
	int len = to_string(n).size(), A = (int)pow(10, len-1);

	if(A > LastIsNine(n)){
		for(int i = LastIsNine(n)+1; i <= n; i++){
			string s = to_string(i);
			for(int j = 0; j < s.size(); j++){
				int idx = s[j]-'0';
				cnt[idx] += 1;
			}
		}

		A /= 10;
		AtoB(A, LastIsNine(n), 1);
		while(1){
			if(A == 1) break;
			AtoB(A/10, A-1, 1);
			A /= 10;
		}
	}else{
		AtoB(A, n, 1);
		while(1){
			if(A == 1) break;
			AtoB(A/10, A-1, 1);
			A /= 10;
		}
	}

	for (int i = 0; i < 10; i++)
		cout << cnt[i] << ' ';

    return 0;
}