#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x; cin >> x;

        vector<int> arr(x);

        for (auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end(), greater<int> ());
        int ans = 0;

        for (int i = 0, j = x-1; i < x/2; i++, j--){
            ans += arr[i] - arr[j];
        }

        cout << ans << "\n";
    }
}
