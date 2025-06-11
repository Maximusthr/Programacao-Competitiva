#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while (t--){
        int n; cin >> n;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        vector<int> copy = arr;
        sort(copy.begin(), copy.end());

        bool par = false;
        bool impar = false;
        for (int i = 0; i < n; i++){
            if (arr[i] % 2) impar = true;
            else if (arr[i] % 2 == 0) par = true;
            if (par & impar) break;
        }

        if (par && !impar) cout << "YES" << "\n";
        else if (!par && impar) cout << "YES" << "\n";
        else {
            bool ok = false;
            for (int i = 0; i < n; i++){
                if (copy[i] % 2) ok = true;
                else if (copy[i] % 2 == 0 && !ok) break;  

            }
            if (ok) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}
