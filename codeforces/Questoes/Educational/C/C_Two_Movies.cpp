#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> aa(n+1), bb(n+1);
    for (int i = 1; i <= n; i++) cin >> aa[i];
    for (int i = 1; i <= n; i++) cin >> bb[i];

    int a = 0, b = 0, c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++){
        if (aa[i] > bb[i] && aa[i]) a++;
        else if (bb[i] > aa[i] && bb[i]) b++;
        else if (aa[i] == bb[i] && aa[i] == 1) c1++;
        else if (aa[i] == bb[i] && aa[i] == -1) c2++;
    }

    while (c1 + c2 > 0){
        if (a >= b && c1){
            b++;
            c1--;
        }
        else if (b >= a && c1){
            a++;
            c1--;
        }
        else if (a >= b && c2){
            a--;
            c2--;
        }
        else {
            b--;
            c2--;
        }
    }

    cout << min(a, b) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}