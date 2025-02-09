#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;
    
    while(qtd--){
        int n, m; cin >> n >> m;

        vector<long long> arr(n);
        for (long long &i : arr) cin >> i;

        vector<long long> aux = arr;

        long long b; cin >> b;
        bool ok = true;
        
        if (is_sorted(arr.begin(), arr.end())) cout << "YES" << "\n";
        else {
            for (int i = 0; i < n-1; i++){
                // if (i > 0 && b - arr[i] > arr[i-1]){
                //     arr[i] = b - arr[i];
                //     continue;
                // }
                if (arr[i] > arr[i+1]){
                    arr[i] = b - arr[i];
                }
            }


            if (is_sorted(arr.begin(), arr.end())) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}
