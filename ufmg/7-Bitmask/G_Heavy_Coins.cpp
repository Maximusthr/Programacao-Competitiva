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
            int minval = INF;
            //vector<int> elem; 
            for (int i = 0; i < n; i++){
                if (mask & (1 << i)){
                    //elem.push_back(arr[i]);
                    sum += arr[i];
                    aux++;
                    minval = min(minval, arr[i]);
                }
            }

            // int copy = sum;
            // for (int i = 0; i < (int)elem.size(); i++){
            //     if (copy - elem[i] >= s) {
            //         aux--;
            //         copy -= elem[i];
            //     }
            // }
            if (sum >= s && minval > sum - s) ans = max(ans, aux);
        }

        cout << ans << "\n";
    }
}
