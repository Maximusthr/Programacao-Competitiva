#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string s;  cin >> s;

    reverse(s.begin(), s.end());

    int ans = 0;    
    for (int i = 0; i < n-1; i++){
        if (s[i] == s[i+1]) continue;
        else {
            ans++;
            s[i+1] = s[i];
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