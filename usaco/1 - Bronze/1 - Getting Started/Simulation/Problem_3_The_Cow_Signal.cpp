#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;

    vector<string> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }

    int c = 0;
    for (int i = 0, aux = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            while (c != k){
                cout << s[i][j] << "";
                c++;
            }
            c = 0;
        }
        cout << "\n";
        if (aux < k-1){
            i--;
            aux++;
        }
        else aux = 0;
    }
}
