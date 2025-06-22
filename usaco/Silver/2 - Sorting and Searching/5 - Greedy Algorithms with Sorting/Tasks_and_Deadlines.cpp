#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int, int>> arr(n);

    for (auto &[x, y] : arr) cin >> x >> y;

    sort(arr.begin(), arr.end());

    ll tempo = 0, ans = 0;
    for (int i = 0; i < n; i++){
        tempo += arr[i].first;

        ans += arr[i].second - tempo;
    }
    cout << ans << "\n";
}