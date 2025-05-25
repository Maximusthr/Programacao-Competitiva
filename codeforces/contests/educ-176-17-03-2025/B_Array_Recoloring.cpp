#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for (auto &i : arr) cin >> i;
        
        vector<int> copy = arr;
        sort(copy.rbegin(), copy.rend());
        
        long long ans = 0;
        if (k == 1){
            int maior = 0;
            if (copy[0] == arr[0] || copy[0] == arr[n-1] && copy[1] == arr[n-1] || copy[1] == arr[0]){
                ans += copy[0] + copy[1];
            }
            else {
                for (int i = 0; i < (int)arr.size(); i++){
                    if (i != 0 && i != (int)arr.size()-1){
                        maior = max(maior, arr[i]);
                    }
                }
                int aux = max(arr[0], arr[arr.size()-1]);
                ans += aux + maior;
            }
        }
        else {    
            for (int i = 0; i < k+1; i++){
                ans += copy[i];
            }
        }
        cout << ans << "\n";

    }
}