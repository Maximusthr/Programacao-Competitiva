// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    string s; cin >> s;

    vector<int> idx_a;
    for (int i = 0; i < n*2; i++){
        if (s[i] == 'A') idx_a.push_back(i);
    }

    ll start_a = 0;
    for (int i = 0; i < n; i++){
        ll alvo = i*2;
        start_a += abs(idx_a[i] - alvo);
    }

    ll start_b = 0;
    for (int i = 0; i < n; i++){
        ll alvo = i*2 + 1;
        start_b += abs(idx_a[i] - alvo);
    }

    cout << min(start_a, start_b) << "\n";
}
