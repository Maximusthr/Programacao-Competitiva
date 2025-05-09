#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        vector<int> arr(n);
        map<int, int> val;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            val[arr[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            if (val[k-arr[i]] >= 1 && val[arr[i]] >= 1){
                if (k-arr[i] == arr[i] && val[arr[i]] < 2) continue;
                ans++;
                val[k-arr[i]]--;
                val[arr[i]]--;
            }
        }

        cout << ans << "\n";
    }
}