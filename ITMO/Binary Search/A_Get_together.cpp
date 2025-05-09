#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool ok(double t, vector<pair<int, int>> &arr){
    // max(left) e min(right)
    double left = -2e18;
    double right = 2e18;

    for (int i = 0; i < (int)arr.size(); i++){
        left = max(left, (double)arr[i].first - t * arr[i].second);
        right = min(right, (double)arr[i].first + t * arr[i].second);
    }

    return (right - left >= 0);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++){
        int x, v; cin >> x >> v;
        arr.push_back({x, v});
    }

    double l = 0, r = 1e9;
    // will time limit
    // while (abs(l-r) > 1e-8){
    //     double mid = l + (r-l)/2;

    //     if (ok(mid, arr)){
    //         r = mid;
    //     }
    //     else l = mid;
    // }

    for (int i = 0; i < 100; i++){
        double mid = l + (r-l)/2;

        if (ok(mid, arr)){
            r = mid;
        }
        else l = mid;
    }

   cout << fixed << setprecision(10) << l << "\n";
}
