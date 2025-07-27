#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, x, k; cin >> n >> x >> k;
    string s; cin >> s;

    ll ans = 0;
    for (int i = 0; i < n; i++){
        k--;

        if (s[i] == 'L') x--;
        else if (s[i] == 'R') x++;

        if (x == 0){
            ans++;
            break;
        }

        if (k == 0 || i == n-1){
            cout << ans << "\n";
            return;
        }
    }

    int temp = 0;
    int restante = 0;
    for (int i = 0; i < n; i++){
        temp += (s[i] == 'L');
        temp -= (s[i] == 'R');
        if (temp == 0){
            restante = i+1;
            break;
        }
    }

    if (temp > 0 || restante == 0){
        cout << ans << "\n";
        return;
    }

    ans += (k/restante);
    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}