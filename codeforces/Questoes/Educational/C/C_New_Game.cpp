#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    int aux = 0;

    int l = 0, r = 0;
    int dif = 1;
    bool entrou = false;
    bool first = false;
    while (l < n && r < n){
        while(l < n && r < n && dif > k){
            if (!first){
                if (l > 0 && arr[l] != arr[l-1]) {
                    dif--;
                    if (dif <= k) break;
                }
            }
            else first = false;
            l++;
            aux--;
            entrou = true;
        }

        while(l < n && r < n && dif <= k){
            
            
            if (!entrou) {
                if (r > 0 && arr[r] != arr[r-1]) dif++;
            }
            else entrou = false;

            if (dif > k) {
                first = true;
                break;
            }
            
            if (r > 0 && arr[r] - arr[r-1] > 1){
                while(arr[r] - arr[l] > 1){
                    l++;
                    aux--;
                    if (arr[l] != arr[l-1]) dif--;
                }
            }

            r++;
            aux++;
            ans = max(ans, aux);
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