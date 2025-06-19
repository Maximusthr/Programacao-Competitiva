#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> arr(n+1);
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
        }

        vector<int> pref(n+1);
        vector<int> suff(n+1);

        for (int i = 1; i <= n; i++){
            pref[i] = arr[i] + i;
            suff[i] = arr[i] - i;
        }

        for (int i = 2; i <= n; i++) pref[i] = max(pref[i], pref[i-1]);
        for (int i = n-1; i > 0; i--) suff[i] = max(suff[i], suff[i+1]);

        int ans = 0;
        for (int i = 2; i <= n-1; i++){
            ans = max(ans, arr[i] + pref[i-1] + suff[i+1]);
        }

        cout << ans << "\n";
    }
}