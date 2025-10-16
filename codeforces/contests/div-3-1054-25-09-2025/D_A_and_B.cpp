// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll custo(vector<int> c){
    if (c.size() == 0) return 0;

    int pos = c.size()/2;
    ll v = 0;

    for (int i = 0; i < c.size(); i++){
        v += abs(c[pos] - c[i]) - abs(pos - i);
    }

    return v;
}

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    vector<int> a, b;
    for (int i = 0; i < n; i++){
        if (s[i] == 'a') a.push_back(i);
        else b.push_back(i);
    }

    cout << min(custo(a), custo(b)) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}