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
        
        vector<int> arr(n);
        for(auto &i : arr) cin >> i;

        bool ok = true;
        for (int i = 1; i < n; i++){
            int val = abs(arr[i] - arr[i-1]);
            if ((val != 5) && (val != 7)) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }   
}
