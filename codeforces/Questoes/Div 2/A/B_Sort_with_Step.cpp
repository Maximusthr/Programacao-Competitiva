#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x, k; cin >> x >> k;

        vector<int> arr(x+1);
        arr[0] = 0;
        for (int i = 1; i <= x; i++){
            cin >> arr[i];
        }

        int troca = 0;

        for (int i = 1; i <= x; i++){
            if (arr[i] - i == 0) continue;
            else if (abs(arr[i] - i) % k == 0) continue;
            else {
                troca++;
            }
        }

        if (troca == 0) cout << 0 << "\n";
        else if (troca == 2) cout << 1 << "\n";
        else cout << -1 << "\n";

    }
}
