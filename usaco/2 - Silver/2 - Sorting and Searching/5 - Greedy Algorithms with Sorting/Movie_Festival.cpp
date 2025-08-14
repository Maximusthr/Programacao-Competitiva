#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &i : a){
        cin >> i.first >> i.second;
    }

    sort(a.begin(), a.end(), [&](pair<int, int> &x, pair<int, int> &y){
        if (x.second != y.second) return x.second < y.second;
        return x.first < y.first;
    });

    int final = a[0].second;
    int ans = 1;
    for (int i = 1; i < n; i++){
        if (final <= a[i].first){
            final = a[i].second;
            ans++;
        }
    }
    cout << ans << "\n";
}
