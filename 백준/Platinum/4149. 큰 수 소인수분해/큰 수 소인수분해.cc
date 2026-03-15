#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll unsigned long long
using namespace std;

ll N;
vector<ll> factors;
ll gcd(ll a, ll b){
    while(true){
        ll temp = a % b;
        a = b; b = temp;
        if(b == 0) return a;
    }
}

ll power(__int128 a, __int128 b, __int128 mod){
    a %= mod;
    __int128 ret = 1;
    while(b > 0){
        if(b % 2 == 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return (ll)ret;
}

bool millerRabin(ll n, ll a){
    if(a % n == 0) return true;
    ll k = n - 1;

    while(true){
        ll temp = power(a, k, n);
        if(temp == n - 1) return true;
        if(k % 2) return (temp == 1 || temp == n - 1);
        k /= 2;
    }
}

bool isPrime(ll n){
    if(n == 2) return true;
    else if(n % 2 == 0) return false;
    else{
        ll base[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for(int i = 0; i < 12; i++){
            if(n == base[i]) return true;
            if(!millerRabin(n, base[i])) return false;
        }

        return true;
    }
}

__int128 abs128(__int128 x){
    if(x < 0) return -x;
    else return x;
}

void factorize(ll n){
    if(n == 1) return;
    if(n % 2 == 0){
        factors.push_back(2);
        factorize(n / 2);
        return;
    }if(isPrime(n)){
        factors.push_back(n);
        return;
    }
    
    __int128 x, y, c, g = n;
    
    do{
        if(g == n){
            x = y = rand() % (n - 2);
            c = rand() % 10 + 1;
            g = 1;
        }
        x = ((x * x) % n + c + n) % n;
        y = ((y * y) % n + c + n) % n;
        y = ((y * y) % n + c + n) % n;
        g = gcd(abs128(x - y), n);
    } while(g == 1);
    
    factorize(g);
    factorize(n / g);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    factorize(N);
    sort(factors.begin(), factors.end());
    for(int i = 0; i < factors.size(); i++)
        cout << factors[i] << '\n';
}