#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n; cin >> n;

    string a, b; cin >> a >> b;

    int ans = 0;

    bool ok = false;
    for (int i = 0; i < n; i++){
        if (b[i] != a[i]) ok = true;
        else if (ok && b[i] == a[i]){
            ans++;
            ok = false;
        }
    }

    if (ok) ans++;

    cout << ans << "\n";
}
