#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int c = 1;
int n, m;     
vector<int> digit;

int memo[11][11][11][2];
int dp(int idx, int number, int last, bool ok){
    if (ok && last > 2){
        return 0;
    }

    if (idx == m){
        return 1;
    }

    auto &p = memo[idx][number][last][ok];
    if (p != -1) return p;

    int ans = 0;
    for (int i = 0; i < digit.size(); i++){
        if (!ok) ok = true;
        ans += dp(idx+1, digit[i], abs(number - digit[i]), ok);
    }

    return p = ans;
}

void solve(){
    cin >> n >> m;  

    digit.resize(n);
    for (auto &i : digit) cin >> i;

    memset(memo, -1, sizeof(memo));
    
    int ans = 0;
    for (int i = 0; i < digit.size(); i++){
        ans += dp(1, digit[i], digit[i], false);
    }

    cout << "Case " << c++ << ": ";
    cout << ans << "\n";
    digit.clear();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}