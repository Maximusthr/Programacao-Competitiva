#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 5;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    vector<int> freq(MAX);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    vector<bool> foi(MAX);
    for (int i = 0; i < n; i++){
        if (foi[arr[i]]) continue;
        foi[arr[i]] = true;
        if (freq[arr[i]] != 0 && freq[arr[i]] % arr[i] != 0) {
            cout << -1 << "\n";
            return;
        }
    }

    map<int, queue<int>> mapa;
    int last = 1, qtd = 0;

    foi.assign(MAX, false);

    for (int i = 0; i < n; i++){
        if (foi[arr[i]]) continue;
        foi[arr[i]] = true;
        int aux = freq[arr[i]];
        while(aux--){
            mapa[arr[i]].push(last);
            qtd++;
            if (qtd == arr[i]){
                qtd = 0;
                last++;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << mapa[arr[i]].front() << " \n"[i == n-1];
        mapa[arr[i]].pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}