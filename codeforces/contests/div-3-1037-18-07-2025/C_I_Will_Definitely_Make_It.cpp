#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> aux;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        aux.push_back(x);
    }
    k--;
    int alvo = aux[k];

    set<int> val;
    int maior = 0;
    for (int i = 0; i < n; i++){
        val.insert(aux[i]);
    }

    vector<int> arr;
    for (auto it = val.begin(); it != val.end(); it++){
        arr.push_back(*it);
    }
    int tam = arr.size();

    maior = arr[tam-1];

    if (alvo == maior){
        cout << "YES" << "\n";
        return;
    }

    int tempo = 0;

    int j = find(arr.begin(), arr.end(), alvo) - arr.begin();
    for (int i = j; i < n-1; i++){
        tempo += abs(arr[i] - arr[i+1]);

        if (tempo > alvo) {
            cout << "NO" << "\n";
            return;
        }

        alvo = arr[i+1];

        if (alvo == maior){
            cout << "YES" << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}