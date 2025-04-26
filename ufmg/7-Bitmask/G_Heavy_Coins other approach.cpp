#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, s; cin >> n >> s;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;
        
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++){
            int sum = 0, aux = 0;
            vector<int> elem; 
            for (int i = 0; i < n; i++){
                if (mask & (1 << i)){
                    elem.push_back(arr[i]);
                    sum += arr[i];
                    aux++;
                }
            }

            for (int i = 0; i < (int)elem.size(); i++){
                if (sum - elem[i] >= s) {
                    aux--;
                    sum -= elem[i];
                }
            }
            if (sum >= s) ans = max(ans, aux);
        }

        cout << ans << "\n";
    }
}
