#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    // ai < ai+1 > ai+2 < ai+3 > ai+4

    vector<int> maiores(n);
    maiores[0] = arr[0];
    for (int i = 1; i < n; i++){
        maiores[i] = max(maiores[i-1], arr[i]);
    }

    // par é ai < ai+1
    // impar é ai > ai+1
    // tras para frente
    reverse(arr.begin(), arr.end());
    reverse(maiores.begin(), maiores.end());

    // size odd -> first < second
    ll ans = 0;
    if (n % 2){
        for (int i = 0; i < n; i++){
            if (i + 1 < n){
                if (i % 2 == 0){
                    if (arr[i] >= arr[i+1]){
                        arr[i+1] = max(maiores[i+1], arr[i+1]);
                        if (arr[i+1] > arr[i]) continue;
                        else {
                            ans += (arr[i] - arr[i+1] + 1);
                        }
                    }
                }
                else {
                    if (arr[i] > arr[i+1]) continue;
                    else {
                        arr[i] = max(maiores[i], arr[i]);
                        if (arr[i] > arr[i+1]) continue;
                        else {
                            ans += (arr[i+1] - arr[i] + 1);
                            arr[i+1] = arr[i]-1;
                        }
                    }
                }
            }
        }
    }
    else {
        for (int i = 0; i < n; i++){
            if (i + 1 < n){
                if (i % 2 == 1){
                    if (arr[i] >= arr[i+1]){
                        arr[i+1] = max(maiores[i+1], arr[i+1]);
                        if (arr[i+1] > arr[i]) continue;
                        else {
                            ans += (arr[i] - arr[i+1] + 1);
                        }
                    }
                }
                else {
                    if (arr[i] > arr[i+1]) continue;
                    else {
                        arr[i] = max(maiores[i], arr[i]);
                        if (arr[i] > arr[i+1]) continue;
                        else {
                            ans += (arr[i+1] - arr[i] + 1);
                            arr[i+1] = arr[i]-1;
                        }
                    }
                }
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