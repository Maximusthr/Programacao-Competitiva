#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x, y, m; cin >> x >> y >> m;

    int temp = m/x * x;
    int ans = temp;

    int c = m/x;

    while (c >= 0){
        temp -= x;
        c--;

        if (temp + y > m) continue;
        else {
            temp += y;
            ans = max(ans, temp);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    solve();
}
