#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    if (n == 1 || n >= 3) {
        cout << "S" << "\n";
        return;
    }

    int q1; cin >> q1;
    vector<int> a(q1);
    for (auto &i : a) cin >> i;

    reverse(a.begin(), a.end());

    int q2; cin >> q2;
    vector<int> b(q2);
    for (auto &i : b) cin >> i;

    reverse(b.begin(), b.end());
    
    // verificando a
    bool achou = false;
    int first = 0;
    if (q1 > 0){
        first = a[0];
        for (int i = 1; i < q1; i++){
            if (a[i] != first) {
                achou = true;
            }
            else if (achou && a[i] == first){
                cout << "N" << "\n";
                return;
            }
        }
        if ((achou || !achou) && q2 == 0) {
            cout << "S" << "\n";
            return;
        }
    }

    bool verif = false;
    int second = 0;
    if (q2 > 0){
        // verificando b
        second = b[0];
        for (int i = 1; i < q2; i++){
            if (b[i] != second){
                verif = true;
            }
            else if (verif && b[i] == second){
                cout << "N" << "\n";
                return;
            }
        }
        if ((verif || !verif) && q1 == 0){
            cout << "S" << "\n";
            return;
        }
    }

    if (q1 > 0 && q2 > 0){
        if (achou && verif) cout << "N" << "\n";
        else if ((achou && !verif) || (!achou && verif)){
            if (first == second) cout << "S" << "\n";
            else cout << "N" << "\n";
        }
        else if (!achou && !verif) cout << "S" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    solve();
}