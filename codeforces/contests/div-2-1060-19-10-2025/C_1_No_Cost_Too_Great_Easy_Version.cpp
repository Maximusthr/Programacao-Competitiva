#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 5;

vector<int> crivo(MAX);

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
    }

    vector<bool> fatores(MAX);

    for (int i = 0; i < n; i++){
        int aux = arr[i];
        set<int> foi;
        while (aux > 1){
            if (!foi.count(crivo[aux])) {
                if (fatores[crivo[aux]]){
                    cout << 0 << "\n";
                    return;
                }
            }
            fatores[crivo[aux]] = 1;
            foi.insert(crivo[aux]);
            aux /= crivo[aux];
        }
    }

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] % 2 == 0) even++;
        else odd++;
    }

    if (even > 0){
        cout << 1 << "\n";
    }
    else {
        // cout << 2 << "\n";
        // mas e se ocorrer 5 com 9?
        // ou 3 11

        // testo os fatores de i+1 e vejo se bate com algum.
        for (int i = 0; i < n; i++){
            int aux = arr[i]+1;
            set<int> foi;
                while (aux > 1){
                if (!foi.count(crivo[aux])) {
                    if (fatores[crivo[aux]]){
                        cout << 1 << "\n";
                        return;
                    }
                }
                // fatores[crivo[aux]] = 1;
                foi.insert(crivo[aux]);
                aux /= crivo[aux];
            }
        }
        
        cout << 2 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    crivo[0] = 0;
    crivo[1] = 1;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i] == 0){
            crivo[i] = i;
            for (ll j = i * i; j < MAX; j += i){
                if (crivo[j] == 0){
                    crivo[j] = i;
                }
            }
        }
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}