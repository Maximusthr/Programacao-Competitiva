#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        vector<int> arr(n+1);
        for (int i = 1; i <= n; i++){
            arr[i] = i;
        }

        if (k % 2 == 0){
            for (int i = 1; i <= n; i++){
                if (i == n-1) arr[i] = n;
                else arr[i] = n-1;
            }
        }
        else if (k % 2 == 1){
            for (int i = 1; i <= n; i++){
                if (i == n) arr[i] = n-1;
                else arr[i] = n;
            }

        }
        
        for (int i = 1; i <= n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
