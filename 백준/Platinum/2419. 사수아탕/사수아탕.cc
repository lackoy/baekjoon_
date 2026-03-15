#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 300;
const int MAX = 987654321;

vector<int> X;
int N, M, dp[MAX_N][MAX_N][2];
void input(){
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        X.push_back(x);
    }

    X.push_back(0);
}

int func(int l, int r, int lr, int k){
    if(!k) return 0;
    if(l > r) return MAX;
    int &ret = dp[l][r][lr];
    if(ret != -1) return ret;
    
    ret = MAX;

    if(lr){
        if(r != N) ret = min(ret, func(l, r+1, 1, k-1) + k*(X[r+1] - X[r]));
        if(l) ret = min(ret, func(l-1, r, 0, k-1) + k*(X[r] - X[l-1]));
    }else {
        if(r != N) ret = min(ret, func(l, r+1, 1, k-1) + k*(X[r+1] - X[l]));
        if(l) ret = min(ret, func(l-1, r, 0, k-1) + k*(X[l] - X[l-1]));
    }
    
    return ret;
}

void solve() {
    sort(X.begin(), X.end());
    int zeroloc = lower_bound(X.begin(), X.end(), 0)-X.begin();
    
    int res = 0;
    for(int i = 1; i <= N; i++) {
        memset(dp, -1, sizeof dp);
        res = max(res, i*M-func(zeroloc, zeroloc, 0, i));
    }
    
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    input();
    solve();
    
    return 0;
}