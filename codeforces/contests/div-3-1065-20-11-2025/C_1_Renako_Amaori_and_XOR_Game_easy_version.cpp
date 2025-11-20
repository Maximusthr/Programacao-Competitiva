#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> a(n+1), b(n+1);
    int par = 0;
    int impar = 0;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i]) impar++;
    }

    for (int i = 1; i <= n; i++){
        cin >> b[i];
        if (b[i]) par++;
    }

    for (int i = 1; i <= n; i++){
        if ((a[i] && b[i]) || (a[i] == 0 && b[i] == 0) ) continue;

        if (i % 2){
            // vez do b[i]
            if (impar % 2 == 0){
                swap(a[i], b[i]);
                if (a[i]) {
                    par--;
                    impar++;
                }
                else {
                    impar--;
                    par++;
                }
            }
        }
        else {
            if (par % 2 == 0){
                swap(a[i], b[i]);
                if (a[i]) {
                    impar++;
                    par--;
                }
                else {
                    impar--;
                    par++;
                }
            }
        }
    }

    int A = 0, B = 0;
    for (int i = 1; i <= n; i++){
        A = (a[i] ^ A);
        B = (b[i] ^ B);
    }

    if (A > B) cout << "Ajisai" << "\n";
    else if (A < B) cout << "Mai" << "\n";
    else cout << "Tie" << "\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}