#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n+1);
    vector<bool> val(n+1);
    int maior_k = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x > k) maior_k++;
        arr[x]++;
        val[x] = true;
    }

    //sort(arr.begin(), arr.end());

    int ans = 0;
    // ate o mex todos os valores do bool tem que ser verdade, menos o mex
    for (int i = 0; i <= n; i++){
        if (i == k){
            if (val[i]){
                ans += arr[i];
            }
            break;
        }
        else {
            if (!val[i]){
                if (arr[k] > 0){
                    ans++;
                    arr[k]--;
                    val[i] = true;
                }
                else if(maior_k > 0){
                    ans++;
                    maior_k--;
                    val[i] = true;
                }
                else {
                    ans++;
                    val[i] = true;
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