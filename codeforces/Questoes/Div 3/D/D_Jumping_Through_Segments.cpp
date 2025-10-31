#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    auto ok = [&](int mid) -> bool {
        pair<int, int> w;
        w.first = 0;
        w.second = mid;

        for (int i = 0; i < n; i++){
            auto [l, r] = arr[i];
            // l ------ r

            if (l < w.first && r > w.second){

            }
            else if (l > w.first && r < w.second){
                w.first = l;
                w.second = r;
            }
            else if (l > w.second || r < w.first) return false;
            else if (l > w.first)  w.first = l;
            else if (r < w.second) w.second = r;

            w.first -= mid;
            w.second += mid;
        }   

        return true;
    };

    int l = 0, r = 1e9;
    while (l < r){
        int mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
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