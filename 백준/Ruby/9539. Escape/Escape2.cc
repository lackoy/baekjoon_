include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll a[201010], b[201010];
int par[201010], p[201010], goal;
vector<int> e[201010];

void dfs(int now, int pre){
	p[now] = pre;
	for(auto nxt : e[now])
		if(nxt != pre) dfs(nxt, now);
}

struct Vertex{
	ll a; ll b;
    int v; int sz;
};

struct cmp{
	bool operator()(const Vertex& A, const Vertex& B){
		if(A.b-A.a >= 0 && B.b-B.a < 0) return 0;
		if(A.b-A.a < 0 && B.b-B.a >= 0) return 1;
		if(A.b-A.a >= 0) return A.a >= B.a;
		return A.b <= B.b;
	}
};

priority_queue<Vertex, vector<Vertex>, cmp> pq;

int f(int x){
	return par[x] < 0 ? x : par[x] = f(par[x]);
}

void Union(int v){
	v = f(v);
    p[v] = f(p[v]);
	ll aa = max(a[p[v]], a[p[v]]-b[p[v]]+a[v]);
	ll bb = b[p[v]]+b[v]-a[p[v]]-a[v]+aa;
	
	if(b[p[v]]-a[p[v]] >= bb-aa) return;
	
	a[p[v]] = aa;
	b[p[v]] = bb;
	par[p[v]] += par[v];
	par[v] = p[v];
	if(p[v] != 1) pq.push({a[p[v]], b[p[v]], p[v], par[p[v]]});
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
    cin >> T;
    while(T--){
		int n;
        cin >> n >> goal;

		for(int i = 1; i <= n; i++){
			par[i] = -1;
			a[i] = b[i] = 0;
			e[i].clear();
		}

		for(int i = 1; i <= n; i++){
			int x; cin >> x;
			if(x > 0) b[i] = x;
			else a[i] = -x;
			if(i == goal) b[i] += 1234123412341234LL;
			if(i != 1) pq.push({a[i], b[i], i, -1});
		}

		for(int i = 1; i < n; i++){
			int u, v;
            cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}

		dfs(1, 1);
		while(pq.size()){
			auto now = pq.top(); pq.pop();
			if(now.sz != par[now.v]) continue;
			Union(now.v);
		}

		cout << (a[1] > 0 ? "trapped\n" : "escaped\n");
	}
}
