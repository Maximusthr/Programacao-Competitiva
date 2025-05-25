#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    while(qtd--){
        int x, k, p; cin >> x >> k >> p;

        vector<int> arr(x, p);

        bool ok = false;
        if (k == 0) ok = true;
        int sum = 0, oper = 0;
        if (k > 0){
            for (int i = 0; i < x; i++){
                sum += arr[i];
                oper++;
                if (sum >= k) {
                    ok = true;
                    break;
                }
            }
        }
        else if (k < 0){
            for (int i = 0; i < x; i++){
                sum -= arr[i];
                oper++;
                if (sum <= k) {
                    ok = true;
                    break;
                }

            }
        }

        if (ok) cout << oper << "\n";
        else cout << -1 << "\n"; 
    }
}