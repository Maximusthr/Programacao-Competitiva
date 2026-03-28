#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    map<int, int> freq;
    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    bool ok = true;
    vector<int> idx;
    vector<int> perm(n+1, -1);
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        if (b[i] == -1){
            idx.push_back(i);
        }
        else {
            perm[b[i]] = i;
            freq[b[i]]++;
            if (freq[b[i]] > 1) ok = false;
        }
    }

    if (!ok){
        cout << "NO" << "\n";
        return;
    }

    if (n == k){
        cout <<"YES" << "\n";
        return;
    }

    for (int i = 1, j = 0; i <= n && j < idx.size(); i++){
        if (perm[a[i]] == -1){
            b[idx[j]] = a[i];
            perm[a[i]] = idx[j];
            j++;
        }
    }

    // formar a primeira janela
    int cont = 0;
    int menor = 1;
    int maior = k;
    int i = 1;
    while(cont < k){
        if (i <= n && perm[a[i]] < menor || perm[a[i]] > maior){
            cout << "NO" << "\n";
            return;
        }
        cont++;
        i++;
    }
    // cheguei no k
    // vamos olhar esquerda e dir
    int j = 2;
    menor = 2;
    maior++;
    while (cont < n){
        if (i <= n && perm[a[i]] < menor || perm[a[i]] > maior){
            cout << "NO" << "\n";
            return;
        }
        if (j <= n && perm[a[j]] < menor || perm[a[j]] > maior){
            cout << "NO" << "\n";
            return;
        }
        cont++;
        maior++;
        menor++;
        j++;
        i++;
    }
    menor--;
    while(j < n){
        if (perm[a[j]] < menor || perm[a[j]] > maior){
            cout << "NO" << "\n";
            return;
        }
        j++;
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}