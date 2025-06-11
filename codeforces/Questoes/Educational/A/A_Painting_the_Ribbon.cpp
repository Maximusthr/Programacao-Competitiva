#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, m, k; cin >> n >> m >> k;

        vector<int> arr(n);
        int aux = 1;
        for (int i = 0; i < n; i++){
            arr[i] = aux;
            aux++;
            if (aux > m) aux = 1;
        }

        for (int i = 0; i < n; i++){
            if (arr[i] == 1) continue;
            arr[i] = 1;
            k--;
            if (k == 0) break;
        }

        bool ok = true;
        for (int i = 0; i < n-1; i++){
            if (arr[i] != arr[i+1]){
                ok = false;
                break;
            }
        }

        cout << (!ok ? "YES" : "NO") << "\n";

    }
}
