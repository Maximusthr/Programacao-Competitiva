//WA

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    string a, b; cin >> a >> b;

    bool ok = false;
    string c;
    int cont = 0;
    for (int i = 0, j = 0; i < a.size(); i++){
        if (a[i] == '?') {
            ok = true;
            cont++;
        }
        if (ok){
            c += a[i];
        }
        if (cont == 4) break;
    }

    for (int i = c.size()-1, j = b.size()-1; i >= 0; i--){
        if (c[i] == '?') {
            c[i] = b[j];
            if (j == -1) c[i] = '0';
            else j--;
        }
        else {
            j--;
            continue;
        }
    }

    ok = false;
    cont = 0;
    for (int i = 0, j = 0; i < a.size(); i++){
        if (a[i] == '?') {
            ok = true;
            cont++;
        }
        if (ok){
            a[i] = c[j];
            j++;
        }
        if (cont == 4) break;
    }

    bool ans = false;
    for (int i = 0, j = 0; i < a.size(); i++){
        if (a[i] == b[j]){
            j++;
        }
        else {
            j = 0;
        }
        if (j == b.size()) ans = true;
    }

    if (ans) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}
