#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<ll> arr(n);
        for (auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end());

        ll min = arr[0];
        vector<ll> div;

        for (int i = 1; i < n; i++){
            if (arr[i] % min == 0) div.push_back(arr[i]);
        }

        if ((int)div.size() == 1 && div[0] == min) cout << "Yes" << "\n";
        else if (div.size() >= 2) {
            ll maior = __gcd(div[0], div[1]);
            for (int i = 0; i < (int)div.size(); i++){
                maior = __gcd(maior, div[i]);
            }
            if (maior == min) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
        else cout << "No" << "\n";
    }
}
