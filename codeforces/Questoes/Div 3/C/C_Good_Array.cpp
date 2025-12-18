#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<pair<int, int>> arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;

        sum += arr[i].first;
    }

    sort(arr.begin(), arr.end());

    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (i == n-1){
            sum -= arr[i].first;
            sum -= arr[n-2].first;

            if (sum == arr[n-2].first){
                ans.push_back(arr[i].second + 1);
            }

            sum += arr[i].first;
            sum += arr[n-2].first;
        }
        else {
            sum -= arr[i].first;
            sum -= arr[n-1].first;

            if (sum == arr[n-1].first){
                ans.push_back(arr[i].second + 1);
            }

            sum += arr[i].first;
            sum += arr[n-1].first;
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i == ans.size()-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}