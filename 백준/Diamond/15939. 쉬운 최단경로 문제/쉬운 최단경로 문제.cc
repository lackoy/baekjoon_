#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
istream& operator >> (istream &in, p &t){
    in >> t.first >> t.second;
    return in;
}

ostream& operator << (ostream &out, p t){
    out << t.first << " " << t.second;
    return out;
}

p a[10101];
int n, q;
int nxt[2][20202];

int ccw(const p &a, const p &b, const p &c){
    ll dx1 = b.first-a.first, dy1 = b.second-a.second;
    ll dx2 = c.first-b.first, dy2 = c.second-b.second;
    ll res = dx1*dy2-dx2*dy1;

    if(!res) return 0;
    return res > 0 ? 1 : -1;
}

int out_of_polygon(p pt){
    for(int i = 0; i < n; i++)
        if(ccw(a[i], a[i+1], pt) != 1) return 1;
    
    return 0;
}

void get_next(int *arr, p pt){
    int curr = 0;
    while(ccw(a[0], a[curr + 1], pt) == 1) curr++;
    arr[0] = curr;

    for(int i = 1; i < n; i++){
        arr[i] = max(arr[i-1], i + 1);
        while(ccw(a[i], a[arr[i] + 1], pt) == 1) arr[i]++;
    }
}

int move_inside(){
    int ret = 0;
    for(int i = 0; i < n; i++)
        ret += abs(nxt[0][i]-nxt[1][i]);
    
    return ret >> 1;
}

int sum1[20202], sum2[20202];
int move_outside(int *arr){
    fill(sum1, sum1+2*n+2, 0); 
    fill(sum2, sum2+2*n+2, 0);

    for(int i = 0; i < n; i++){
        int j = arr[i];

        sum1[i] += j-i-1;
        sum1[i+1] -= j-i-1;
        sum1[i-1+n] += n+i-j-2;
        sum1[i+n] -= n+i-j-2;
        sum1[j] -= j;
        sum1[i-1+n] += j;
        sum2[j]++;
        sum2[i-1+n]--;
        sum1[i+1] += j;
        sum1[j] -= j;
        sum2[i+1]--;
        sum2[j]++;
    }
    
    for(int i=1; i<n+n; i++)
        sum1[i] += sum1[i-1], sum2[i] += sum2[i-1];
    
    int ret = 1e9;

    for(int i = 0; i < n; i++){
        int now = sum1[i]+i*sum2[i];
        now += sum1[i+n]+(i+n)*sum2[i+n];
        ret = min(ret, now);
    }

    return (ret >> 1) + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i+n] = a[i];
    }
    a[2*n] = a[0];

    cin >> q;
    while(q--){
        p p1, p2;
        cin >> p1 >> p2;
        int out1 = out_of_polygon(p1), t1 = 0;
        int out2 = out_of_polygon(p2), t2 = 0;

        if(out1 && out2){
            cout << "0\n";
            continue;
        }
        if(out1 && !out2){
            swap(p1, p2);
            swap(out1, out2);
        }
        if(!out1) get_next(nxt[0], p1), t1 = move_outside(nxt[0]);
        if(!out2) get_next(nxt[1], p2), t2 = move_outside(nxt[1]);

        if(!out1 && out2) cout << t1 << "\n";
        else cout << min(move_inside(), t1+t2) << "\n";
    }
}