#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct fase {
    int vez, v;
};

void solve(){
    int n, q; cin >> n >> q;

    vector<fase> arr(n);
    ll ans = 0;
    for (int i = 0; i < n; i++){
        arr[i].vez = 0;
        cin >> arr[i].v;
        ans += arr[i].v;
    }

    fase secquery = {0, -1};

    int vez = 0;

    while(q--){
        int x; cin >> x;

        vez++;

        if (x == 1){
            int idx, y; cin >> idx >> y;
            idx--;

            if (arr[idx].vez >= secquery.vez){
                ans -= arr[idx].v;
                ans += y;
                arr[idx].vez = vez;
                arr[idx].v = y;
            }
            else {
                ans -= secquery.v;
                ans += y;
                arr[idx].vez = vez;
                arr[idx].v = y;
            }
        }
        else {
            int y; cin >> y;
            ans = 1ll * y * n;

            secquery.vez = vez;
            secquery.v = y;
        }

        cout << ans << "\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
