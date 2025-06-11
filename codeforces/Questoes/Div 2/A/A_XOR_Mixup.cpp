#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        if (n == 2) cout << arr[0] << "\n";
        else {
            if (n == 3){
                if (arr[0] ^ arr[1] == arr[2]) cout << arr[2] << "\n";
                else if (arr[0] ^ arr[2] == arr[1]) cout << arr[1] << "\n";
                else if (arr[1] ^ arr[2] == arr[0]) cout << arr[0] << "\n";
            }
            else {
                int aux = 0;
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (j == i) continue;
                        aux ^= arr[j];
                    }
                    if (aux == arr[i]) break;
                }
                cout << aux << "\n";
            }
        }
    }
}
