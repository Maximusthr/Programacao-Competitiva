#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<ll> arr(n);
        for (auto &i : arr) cin >> i;

        ll ans = 0;
        vector<ll> temp;
        for (int i = 0; i < n; i++){
            if (arr[i] > 0) temp.push_back(arr[i]);
            else {
                int maior = 0;
                int pos = 0;
                for (int i = 0; i < temp.size(); i++){
                    if (temp[i] > maior) {
                        maior = temp[i];
                        pos = i;
                    }
                }
                if (temp.size() > 0) temp[pos] = 0;
                ans += maior;
            }
        }

        
        cout << ans << "\n";
    }
}