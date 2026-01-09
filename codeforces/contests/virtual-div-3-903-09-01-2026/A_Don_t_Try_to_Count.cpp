#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    string s, a; cin >> s >> a;

    int ans = 0;
    while(s.size() <= 100){
        if (s.size() >= a.size()){
            for (int i = 0; i <= s.size()-m; i++){
                string v = s.substr(i, m);
                if (v == a){
                    cout << ans << "\n";
                    return;
                }
            }
        }
        s += s;
        ans++;
    }

    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}