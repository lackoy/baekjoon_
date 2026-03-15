#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m, a;
unordered_map<int, int> v;
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        v[a]++;
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a;
        cout << v[a] << " ";
    }

    return 0;
}