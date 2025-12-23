#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    if (n <= 2){ 
        cout << "Bob" << "\n";
        return;
    }

    // simular?
    // alice precisa forçar a resposta de bob
    // daí aquele elemento removido por bob nao existirá mais
    // e alice vence

    int i = 0, j = n-1;
    int k = 0, l = n-1;
    while(i < j){
        if (a[i] != b[k] && a[i] != b[l] && a[j] != b[k] && a[j] != b[l]){
            cout << "Alice" << "\n";
            return;
        }

        if (a[i] == b[k] || a[i] == b[l]){
            if (a[j] != b[k] && a[j] != b[l]){
                cout << "Alice" << "\n";
                return;
            }
            else {
                if (a[i] == b[k]) k++;
                else l--;
                i++;
            }
        }
        else if (a[j] == b[k] || a[j] == b[l]){
            if (a[i] != b[k] && a[i] != b[l]){
                cout << "Alice" << "\n";
                return;
            }
            else {
                if (a[j] == b[k]) k++;
                else l--;
                j--;
            }
        }
    }

    cout << "Bob" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}