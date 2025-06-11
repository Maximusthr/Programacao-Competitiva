#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x; cin >> x;

        vector<int> arr(x);
        for (auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end());

        int ans = 0;
        for (int i = 0; i < x; i++){
            if (arr[i] < 0) arr[i] *= -1;
            ans += arr[i];
        }

        cout << ans << "\n";
    }

}
