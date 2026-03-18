#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = 0; j < x; j++){
            int y; cin >> y;

            arr[i].push_back(y);
        }
    }

    vector<pair<ll, int>> sum(n);
    for (int i = 0; i < n; i++){
        ll aux = 0;
        ll acumulado = 0;
        for (int j = 0; j < arr[i].size(); j++){
            if (j > 0) acumulado++;
            if (arr[i][j] >= acumulado){
                aux = arr[i][j] + 1 - j;
                acumulado = aux + j;
            }
        }
        sum[i] = {aux, (int)arr[i].size()};
    }

    sort(sum.begin(), sum.end(), [&](pair<ll, int> x, pair<ll, int> y){
        if (x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });

    auto ok = [&](ll mid) -> bool {
        for (int i = 0; i < n; i++){
            if (sum[i].first > mid) return false;
            mid += sum[i].second;
        }

        return true;
    };

    ll l = sum[0].first, r = 1e15;
    while(l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}