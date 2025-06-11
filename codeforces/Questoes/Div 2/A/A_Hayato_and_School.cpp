#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        int even = 0;
        int odd = 0;
        vector<pair<int, int>> pos;
        for (int i = 0; i < n; i++){
            if (arr[i] % 2 == 0) {
                even++;
                pos.push_back({i, arr[i]});
            }
            else {
                odd++;
                pos.push_back({i, arr[i]});
            }
        }
        if (odd >= 3){
            cout << "YES" << "\n";
            int aux = 0;
            for (int i = 0; i < (int)pos.size(); i++){
                if (pos[i].second % 2 == 1) {
                    cout << pos[i].first + 1 << " ";
                    aux++;
                    if (aux == 3) break;
                }
            }
            cout << "\n";
        }
        else if (odd >= 1 && even >= 2){
            cout << "YES" << "\n";
            int aux_even = 0;
            bool ok_even = false;
            bool ok_odd = false;

            for (int i = 0; i < (int)pos.size(); i++){
                if (!ok_odd && pos[i].second % 2 == 1) {
                    cout << pos[i].first + 1 << " ";
                    ok_odd = true;
                }
                else if (!ok_even && pos[i].second % 2 == 0){
                    cout << pos[i].first + 1 << " ";
                    aux_even++;
                    if (aux_even == 2) ok_even = true;
                }
            }
            cout << "\n";
        }
        else cout << "NO" << "\n";
    }
}
