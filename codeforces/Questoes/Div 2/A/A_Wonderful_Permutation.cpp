#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        int ans = 0;
        int temp = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] > k) ans++;
            temp++;
            if (temp == k) break;
        }

        cout << ans << "\n";
    }
}
