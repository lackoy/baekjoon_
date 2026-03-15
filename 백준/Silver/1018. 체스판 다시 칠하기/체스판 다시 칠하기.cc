#include <iostream>
#include <algorithm>
using namespace std;

int** arr;
int func(int x, int y) {
	int case1 = 0; int case2 = 0;

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == arr[i][j]) ++case1;
			else if ((i + j + 1) % 2 == arr[i][j]) ++case2;
		}
	}

	return min(case1, case2);
}

int main() {
	int N, M, min = 1250;
	char input;
	cin >> N >> M;
	arr = new int* [N];

	for (int i = 0; i <= N; ++i)
        arr[i] = new int[M];
    
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			if (input == 'B') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int minCount = func(i, j);
			if (min > minCount) min = minCount;
		}
	}

	cout << min;
}