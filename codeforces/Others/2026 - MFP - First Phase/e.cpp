#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, pit, s;
array<int, 3> t, d;
    // voltas | dur | tipo | trocas
int memo[1005][1005][3][6];
int dp(int volta, int dur, int tipo, int trocas){
    if (trocas > s) return INF;
    if (volta == n) return 0;

    auto &p = memo[volta][dur][tipo][trocas];
    if (p != -1) return p;

    int ans = 0;
    if (dur == d[tipo]){
        ans += min({dp(volta, 0, 0, trocas + 1), dp(volta, 0, 1, trocas + 1), dp(volta, 0, 2, trocas + 1) }) + pit;
    }
    else ans += dp(volta + 1, dur + 1, tipo, trocas) + t[tipo];
    return p = ans;
}

void solve(){
    cin >> n >> pit >> s;

    cin >> t[0] >> t[1] >> t[2];
    cin >> d[0] >> d[1] >> d[2];

    memset(memo, -1, sizeof(memo));
    int ans = min({dp(0, 0, 0, 0), dp(0, 0, 1, 0), dp(0, 0, 2, 0)});
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}