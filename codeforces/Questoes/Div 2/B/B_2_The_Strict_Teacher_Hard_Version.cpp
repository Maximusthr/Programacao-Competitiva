#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, m, q; cin >> n >> m >> q;

        vector<int> arr(m);
        for (auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end());

        while(q--){
            int loc; cin >> loc;
            auto it = upper_bound(arr.begin(), arr.end(), loc) - arr.begin();
            
            if (it == 0){
                cout << arr[0] - 1 << "\n";
            }
            else if (it == m){
                cout << n - arr[m-1] << "\n";
            }
            else {
                cout << (arr[it] - arr[it-1]) / 2 << "\n";
            }
        }
    }
}
