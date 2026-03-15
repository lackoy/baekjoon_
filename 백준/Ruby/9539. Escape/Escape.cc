#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAXn = 200005;

struct Segment {
    ll min_req;
    ll gain;
    bool operator>(const Segment& other) const {
        if (min_req != other.min_req) return min_req > other.min_req;
        return gain < other.gain;
    }
};

vector<int> adj[MAXn];
ll H[MAXn];
bool is_on_path[MAXn];
priority_queue<Segment, vector<Segment>, greater<Segment>> pq[MAXn];

void dfs_sub(int u, int p) {
    for (int v : adj[u]) {
        if (v == p || is_on_path[v]) continue;
        dfs_sub(v, u);
        
        if (pq[u].size() < pq[v].size()) swap(pq[u], pq[v]);
        while (!pq[v].empty()) {
            pq[u].push(pq[v].top());
            pq[v].pop();
        }
    }

    ll cur_req = (H[u] < 0) ? -H[u] : 0;
    ll cur_gain = H[u];

    while (!pq[u].empty()) {
        Segment top = pq[u].top();
        if (cur_gain <= 0 || top.min_req <= cur_req) {
            pq[u].pop();
            cur_req = max(cur_req, top.min_req - cur_gain);
            cur_gain += top.gain;
        } else break;
    }

    if (cur_gain > 0) pq[u].push({cur_req, cur_gain});
    else while (!pq[u].empty()) pq[u].pop();
}

void solve() {
    int n, t;
    if (!(cin >> n >> t)) return;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        while (!pq[i].empty()) pq[i].pop();
        is_on_path[i] = false;
    }

    for (int i = 1; i <= n; i++) cin >> H[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    queue<int> q;
    q.push(1);
    parent[1] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) break;
        for (int v : adj[u]) {
            if (parent[v] == 0) {
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    int curr = t;
    while (curr != -1) {
        path.push_back(curr);
        is_on_path[curr] = true;
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());

    ll current_hp = 0;
    priority_queue<Segment, vector<Segment>, greater<Segment>> total_pq;

    for (int node : path) {
        current_hp += H[node];
        if (current_hp < 0) {
            cout << "trapped\n";
            return;
        }

        for (int v : adj[node]) {
            if (is_on_path[v]) continue;
            dfs_sub(v, node);
            while (!pq[v].empty()) {
                total_pq.push(pq[v].top());
                pq[v].pop();
            }
        }

        while (!total_pq.empty() && current_hp >= total_pq.top().min_req) {
            current_hp += total_pq.top().gain;
            total_pq.pop();
        }
    }

    cout << "escaped\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    if (cin >> tc) {
        while (tc--) solve();
    }
    return 0;
}