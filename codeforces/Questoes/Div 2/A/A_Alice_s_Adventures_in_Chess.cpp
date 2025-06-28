#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, x, y; cin >> n >> x >> y;

    string s; cin >> s;

    // N = (x, y+1);
    // E = (x+1, y);
    // S = (x, y-1);
    // W = (x-1, y);

    int a = 0, b = 0;
    int i = 0;
    bool ok = true;
    while (a != x || b != y){
        if (s[i%n] == 'N') b += 1;
        else if (s[i%n] == 'E') a += 1;
        else if (s[i%n] == 'S') b -= 1;
        else if (s[i%n] == 'W') a -= 1;
        i++;
        if (a > x+50 && b > y+50) {
            ok = false;
            break;
        }
        if (i == 500000) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}