#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<ll> coprime;
    for (int i = 1; i < n; i++){
        if (__gcd(1ll*i, 1ll*n) == 1){
            coprime.push_back(i);
        }
    }

    int v = 1, sub = 1;
    for (int i = 1; i < coprime.size(); i++){
        v = (v * coprime[i]) % n;
        if (v == 1) sub = i + 1;
    }

    cout << sub << "\n";
    for (int i = 0; i < sub; i++){
        cout << coprime[i] << " \n"[i == sub-1];
    }
}