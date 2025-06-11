#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        if (n <= 2) {
            cout << "YES" << "\n";
            continue;
        }

        sort(arr.begin(), arr.end());

        int distint = 1;
        
        map<int, int> aux;
        bool ok = true;

        aux[arr[0]]++;
        for (int i = 1; i < n; i++){
            aux[arr[i]]++;
            if (arr[i] != arr[i-1]) {
                distint++;
                if (distint == 3) {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) cout << "NO" << "\n";
        else if (distint == 1) cout << "YES" << "\n";
        else {
            vector<int> val;
            for (auto [x, y] : aux){
                val.push_back(y);
            }
            if (abs(val[0] - val[1]) > 1) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }
    }
}
