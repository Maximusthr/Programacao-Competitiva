#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        arr[i] = {x, y};
    }

    sort(arr.begin(), arr.end(), [&](pair<int, int> &x, pair<int, int> &y){
        if (x.first == y.first) return x.second > y.second;
        return x.first < y.first;        
    });

    int ans = 1;
    pair<int, int> x_m;
    x_m = arr[0];

    for (int i = 1; i < n; i++){
        if (arr[i].first > x_m.first){
            if (arr[i].second < x_m.second){
                ans++;
                x_m = arr[i];
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}