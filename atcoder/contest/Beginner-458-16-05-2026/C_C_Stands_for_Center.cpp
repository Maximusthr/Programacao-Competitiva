#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    s = '#' + s;

    int n = s.size();

    ll ans = count(s.begin(), s.end(), 'C');
    for (int i = 2; i <= n-1; i++){
        if (s[i] == 'C'){
            ans += min(i-1, n-i-1);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}