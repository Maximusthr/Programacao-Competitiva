#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n-1; i++){
        if (i % 2){
            if (arr[i] > arr[i+1]){
                ans += arr[i]-arr[i+1];
                arr[i] = arr[i+1];
            }
        }
        else if (i % 2 == 0){
            if (arr[i] < arr[i+1]){
                ans += arr[i+1] - arr[i];
                arr[i+1] = arr[i]; 
            }
        }
    }

    for (int i = 1; i <= n-2; i++){
        if (i % 2){
            if (arr[i] + arr[i+2] > arr[i+1]){
                ans += arr[i] + arr[i+2] - arr[i+1];
                int v = arr[i] + arr[i+2] - arr[i+1];

                arr[i+2] = max(0, arr[i+2] - v);
                v -= arr[i+2];
                arr[i] = max(0, arr[i] - v);
            }
        }
        else if (i % 2){
            if (arr[i] + arr[i+2] < arr[i+1]){
                ans += arr[i+1] - arr[i] - arr[i+2];
                arr[i+1] -= (arr[i] + arr[i+2]);
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}