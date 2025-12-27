#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = s.size();
    int ans = 0;

    if (s[0] == 'u') {
        ans++;
        s[0] = 's';
    }
    if (s.back() == 'u'){
        ans++;
        s.back() = 's';
    }

    for (int i = 1; i < n-1; i++){
        if (s[i] == 'u'){
            if (s[i-1] == 'u' && s[i+1] == 'u'){
                s[i] = 's';
                ans++;
            }
        }
    }

    for (int i = 1; i < n-1; i++){
        if (s[i] == 'u'){
            if (s[i-1] == 'u' || s[i+1] == 'u'){
                s[i] = 's';
                ans++;
            }
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