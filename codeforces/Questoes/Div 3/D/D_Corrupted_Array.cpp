#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    n += 2;

    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr.begin()+1, arr.end());

    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1] + arr[i];
    }

    pair<int, int> achou = {-1, -1};
    
    for (int i = 1; i < n; i++){
        if (i == n-1){
            ll sum = prefix[i-1];
            if (sum == arr.back() || sum == arr[n-1]) achou = {arr.back(), arr[n-1]};
        }
        else {
            ll sum = prefix[n-1] - prefix[i] + prefix[i-1];
            if (sum == arr.back()){
                achou = {arr.back(), arr[i]};
            }
        }
    }

    if (achou.first == -1){
        cout << -1 << "\n";
        return;
    }
    bool F = false, S = false;
    for (int i = 1; i <= n; i++){
        if (!F && arr[i] == achou.first){
            F = true;
            continue;
        }
        else if (!S && arr[i] == achou.second){
            S = true;
            continue;
        }

        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}