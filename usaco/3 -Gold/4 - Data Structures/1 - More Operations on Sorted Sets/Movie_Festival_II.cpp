#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<pair<int, int>> arr(n);
    for (auto &i : arr) cin >> i.first >> i.second;

    sort(arr.begin(), arr.end(), [&](pair<int, int> x, pair<int, int> y){
        if (x.second != y.second) return x.second < y.second;
        return x.first < y.first;
    });

    int ans = 0;
    multiset<int> tempos;
    for (int i = 0; i < n; i++){
        auto it = tempos.upper_bound(arr[i].first);

        if (it == tempos.begin()){
            if (k > 0){
                ans++;
                tempos.insert(arr[i].second);
                k--;
            }
            continue;
        } 

        it--;

        if (*it <= arr[i].first){
            ans++;
            tempos.insert(arr[i].second);
            tempos.erase(tempos.find(*it));
        }
    }

    cout << ans << "\n";
}