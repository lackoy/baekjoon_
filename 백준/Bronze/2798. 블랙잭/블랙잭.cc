#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, i, max_sum;
int main() {
    cin >> n >> m;
    vector<int> cards(n);

    for (i = 0; i < n; i++)
        cin >> cards[i];

    vector<int> selector(n, 0);
    for (i = n - 3; i < n; i++)
        selector[i] = 1;

    do {
        int current_sum = 0;
        for (i = 0; i < n; i++) {
            if (selector[i] == 1) {
                current_sum += cards[i];
            }
        }

        if (current_sum <= m) {
            max_sum = max(max_sum, current_sum);
        }
    } while (next_permutation(selector.begin(), selector.end()));

    cout << max_sum << endl;

    return 0;
}