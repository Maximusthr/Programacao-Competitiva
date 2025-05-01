// CS IN TIME

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

        for (auto &i: arr) cin >> i;

        if (n == 1 && arr[0] == 1) cout << "YES" << "\n";
        else {
            sort(arr.begin(), arr.end());

            if (arr[0] != 1) cout << "NO" << "\n";
            else {
                ll sum = arr[0];
                bool ok = true;
                for (int i = 1; i < n; i++){
                    if (sum < arr[i]) {
                        ok = false;
                        break;
                    }
                    sum += arr[i];
                }

                cout << (ok ? "YES" : "NO") << "\n";
            }
        }
    }
}
