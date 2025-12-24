#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;

    int ans = 0;
    int dist = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            i += k;
            continue;
        }
        if (s[i] == '0'){
            i++;
            while (i < n && s[i] == '0' && dist < k){
                dist++;
                i++;
            }
            if (dist == k || i == n) ans++;
            dist = 0;
            i--;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}