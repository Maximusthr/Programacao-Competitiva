#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x, y; cin >> x >> y;

        vector<int> arr(x);
        for (auto &i : arr) cin >> i;

        bool ok = false;
        for (int i = 0; i < x; i++){
            if (y == arr[i]) {
                ok = true;
                cout << "YES" << "\n";
                break;
            }
        }

        if (!ok) cout << "NO" << "\n";
    }
}
