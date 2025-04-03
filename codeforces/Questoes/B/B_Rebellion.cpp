#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x; cin >> x;
        vector<int> arr(x);

        for (auto &i : arr) cin >> i;

        int ans = 0;
        
        int i = 0, j = x-1;
        for (; i < j; ){
            if (arr[j] == 0){
                if (arr[i] == 1) {
                    ans++;
                    i++;
                    j--;
                }
                else i++;
            }
            else j--;
        }

        cout << ans << "\n";
    }
}
