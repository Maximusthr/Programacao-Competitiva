#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> arr(n+1);
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            arr[x]++;
        }

        int soma = 0;
        bool ok = false;
        for (int i = 1; i <= n; i++){
            if (arr[i] == 1 && !ok){
                soma += 2;
                ok = true;
            }
            else if (arr[i] == 1 && ok){
                ok = false;
                continue;
            }
            else if (arr[i] >= 2) soma++;
        }

        cout << soma << "\n";
    }
}
