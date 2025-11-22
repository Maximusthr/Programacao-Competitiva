#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    
    vector<pair<int, int>> arr(n);
    for (auto &i : arr) cin >> i.first >> i.second;

    int X_max = 0, X_min = INF, Y_max = 0, Y_min = INF;

    // first = x;
    // second = y
    for (int i = 0; i < n; i++){
        X_max = max(arr[i].first, X_max);
        Y_max = max(arr[i].second, Y_max);

        X_min = min(arr[i].first, X_min);
        Y_min = min(arr[i].second, Y_min);
    }

    cout << 4 << "\n";
    cout << X_min << " " << Y_min << "\n";
    cout << X_max << " " << Y_min << "\n";
    cout << X_max << " " << Y_max << "\n";
    cout << X_min << " " << Y_max << "\n";
}