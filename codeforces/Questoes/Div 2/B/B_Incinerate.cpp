#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++){
        cin >> arr[i].second;
    }

    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());

    sort(arr.begin(), arr.end(), [&](pair<int, int> x, pair<int, int> y){
        if (x.second != y.second) return x.second < y.second;
        return x.first < y.first;
    });

    n = arr.size();

    ll sum = k;
    for (int i = 0; i < n; i++){
        arr[i].first -= sum;
        while (arr[i].first > 0 && k > 0){
            k -= arr[i].second;
            arr[i].first -= k;
            sum += k;
        }
        if (k <= 0){
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}