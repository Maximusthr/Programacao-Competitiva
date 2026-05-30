#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Upsolve

void solve(){
    int n, x, s; cin >> n >> x >> s;

    string arr; cin >> arr;

    int mesas = 0;
    ll cadeiras = 0;
    int A_E = 0;
    int sentados = 0;

    for (int i = 0; i < n; i++){
        if (arr[i] == 'A'){
            if (cadeiras > 0){
                A_E++;
                cadeiras--;
                sentados++;
            }
            else if (cadeiras == 0 && mesas < x){
                mesas++;
                cadeiras += s - 1;
                sentados++;
            }
        }
        else if (arr[i] == 'I'){
            if (mesas < x){
                mesas++;
                cadeiras += s - 1;
                sentados++;
            }
        }
        else {
            if (cadeiras > 0){
                cadeiras--;
                sentados++;
            }
            else if (cadeiras == 0 && A_E > 0 && mesas < x){
                A_E--;
                mesas++;
                cadeiras += s;
                sentados++;
                cadeiras--;
                
            }
        }
    }

    cout << sentados << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}