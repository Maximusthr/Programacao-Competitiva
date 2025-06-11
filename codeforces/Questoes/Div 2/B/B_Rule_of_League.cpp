#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, x, y; cin >> n >> x >> y;

        if (x < y) swap(x, y);

        if (x > 0 && y > 0 || x == 0 && y == 0) cout << -1;
        else if (n % 2 == 0){
            if (x == n-1 && y == 0) {
                for (int i = 0; i < n-1; i++){
                    cout << 1 << " ";
                }
            }
            else if (x == 1 && y == 0){
                for (int i = 0; i < n-1; i++){
                    cout << 2 + i << " ";
                }
            }
            // numero anterior pode ser divisivel ex: 10 -> 10 - 1 = 9 OK
            else if ((n-1) % x == 0){
                int troca = 0;
                int val = 2;

                for (int i = 0; i < n-1; i++){
                    cout << val << " ";
                    troca++;
                    if (troca == x){
                        val += x;
                        troca = 0;
                    }
                }
            }
            else cout << -1;
        }
        else if (n % 2 == 1){
            if (x == 1 && y == 0){
                for (int i = 0; i < n-1; i++){
                    cout << 2 + i << " ";
                }
            }
            else if (x == 2 && y == 0){
                int troca = 0;
                int val = 2;

                for (int i = 0; i < n-1; i++){
                    cout << val << " ";
                    troca++;
                    if (troca == 2){
                        val += 2;
                        troca = 0;
                    }
                }
            }
            else if (x == n/2 && y == 0){
                int troca = 0 ;
                int val = 1;
                for (int i = 0; i < n-1; i++){
                    cout << val << " ";
                    troca++;
                    if (troca == n/2){
                        val = n/2 + 2;
                        troca = 0;
                    }
                }
            }
            else if (x == n-1 && y == 0) {
                for (int i = 0; i < n-1; i++){
                    cout << 1 << " ";
                }
            }
            else cout << -1;
        }

        cout << "\n";
    }
}
