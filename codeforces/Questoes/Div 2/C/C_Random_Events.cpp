#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<pair<int, double>> prob(m);
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        double y; cin >> y;
        prob[i] = {x, y};
    }

    cout << fixed << setprecision(10);

    if (is_sorted(arr.begin(), arr.end())){
        cout << 1.0 << "\n";
        return;
    }

    int pos = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] != i+1){
            pos = i+1;
        }
    }

    double ans = 0;
    double last = 1;
    for (int i = 0; i < m; i++){
        if (prob[i].first >= pos){
            ans += last * prob[i].second;
            last *= (1 - prob[i].second);
        }
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
