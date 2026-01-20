#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;
    
    string s, t; cin >> s >> t;

    s = '#' + s;
    t = '#' + t;

    vector<int> diff(n+2);

    while(q--){
        int l, r; cin >> l >> r;

        diff[l]++;
        diff[r+1]--;
    }

    for (int i = 1; i <= n; i++){
        diff[i] += diff[i-1];
    }

    for (int i = 1; i <= n; i++){
        if (diff[i] & 1){
            swap(s[i], t[i]);
        }
    }

    for (int i = 1; i <= n; i++){
        cout << s[i];
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}