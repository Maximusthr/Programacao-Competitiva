#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    auto transf = [&](string s) -> int {
        return (s[0] - '0') * 10 + (s[1] - '0');
    };

    int ans = INF;
    for (int i = 0; i < n-1; i++){
        int res = 0;
        int v = transf(s.substr(i, 2));
        res += v;
        for (int j = 0; j < n; j++){
            if (j == i){
                j++;
                continue;
            }
            if (s[j] == '0') {
                res = 0;
                break;
            }
            else if (s[j] == '1');
            else {
                if (res == 1) res = (s[j]-'0');
                else res += (s[j]-'0');
            }
        }

        ans = min(res, ans);
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