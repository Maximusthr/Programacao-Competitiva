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
        for (auto &i : arr) cin >> i;

        bool ok = true;

        int c = 0;
        for (int i = 0 ; i < n; i++){   
            if (arr[i] == 1) c++;
        }

        if (c == n) ok = false;
        else {
            for (int i = 0; i < n-1; i++){
                if (arr[i] == 0 && arr[i+1] == 0){
                    ok = false;
                    break;
                }
            }
        }

        if (ok) cout << "NO" << "\n";
        if (!ok) cout << "YES" << "\n";
    }
}
