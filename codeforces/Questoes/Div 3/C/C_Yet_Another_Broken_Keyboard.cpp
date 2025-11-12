#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    string s; cin >> s;

    set<char> ss;
    for (int i = 0; i < m; i++){
        char c; cin >> c;
        ss.insert(c);
    }

    ll ans = 0;
    int pode = 0;
    for (int i = 0; i < n; i++){
        if (ss.count(s[i])){
            pode++;
        }
        else {
            ans += 1ll * pode * (pode + 1)/2;
            pode = 0;
        }
        if (i == n-1 && pode > 0) ans += 1ll * pode * (pode + 1)/2;
    }

    cout << ans << "\n";
}