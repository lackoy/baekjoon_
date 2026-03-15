#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
vector<pair<int, string>> v;
int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back(make_pair(s.length(), s));
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(const auto& i : v)
        cout << i.second << "\n";

    return 0;
}