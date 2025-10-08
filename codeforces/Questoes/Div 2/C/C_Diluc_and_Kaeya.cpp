#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    map<pair<int, int>, int> termos;

    int D = 0, K = 0;
    for (int i = 0; i < n; i++){
        D += s[i] == 'D';
        K += s[i] == 'K';

        int v_D = D / __gcd(D, K);
        int v_K = K / __gcd(D, K);

        cout << termos[{v_D, v_K}] + 1 << " \n"[i == n-1];

        termos[{v_D, v_K}]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}