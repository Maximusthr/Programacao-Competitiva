#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<ll, int>> arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;

        sum += arr[i].first;
    }

    sort(arr.begin(), arr.end());

    vector<int> ans;
    reverse(arr.begin(), arr.end());

    ans.push_back(arr[0].second);
    sum -= arr[0].first;

    map<bool, int> ganhou;
    ganhou[arr[0].first] = true;

    for (int i = 1; i < n; i++){
        sum -= arr[i].first;

        if (ganhou[arr[i-1].first] && arr[i].first + sum >= arr[i-1].first){
            ans.push_back(arr[i].second);
            ganhou[arr[i].first] = true;
        }
        else break;
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i + 1 << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}