#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	if(n == 0){
		cout << 0;
		return 0;
	}

	vector<int> numbers(n);
	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	sort(numbers.begin(), numbers.end());

	int idx = round(n*0.15);
	double sum = 0;

	for (int i = idx; i < n-idx; i++)
		sum += numbers[i];

	cout << round(sum/(n-idx*2));

	return 0;
}