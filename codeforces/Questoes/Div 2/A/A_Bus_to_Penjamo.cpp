#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, r; cin >> n >> r;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        int ans = 0;
        int sobra = 0;
        for (int i = 0; i < (int)arr.size(); i++){
            ans += (arr[i]/2)*2;
            r -= arr[i]/2;
            sobra += arr[i] % 2;
        }

        if (sobra > r) ans += r*2 - sobra;
        else ans += sobra;

        cout << ans << "\n";
    }
}
