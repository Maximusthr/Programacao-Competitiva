#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;

vector<string> move(vector<string> &a, int x, int y){
    vector<string> aux = a;

    for (int k = 0; k < x; k++){
        for (int i = 0; i < n-1; i++){
            swap(aux[i], aux[i+1]);
        }

    }

    // swap das verticais
    for (int k = 0; k < y; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m-1; j++){
                swap(aux[i][j], aux[i][j+1]);
            }
        }
    }

    return aux;
}

void solve(){
    cin >> n >> m;
    
    vector<string> a(n);
    for (auto &i : a) cin >> i;

    vector<string> b(n);
    for (auto &i : b) cin >> i;

    int count = 0;
    int v1 = 0, v2 = 0;
    while (count < n * m){  
        if (v1 == n){
            v1 = 0;
            v2++;
        }

        vector<string> aux = move(a, v1, v2);

        bool foi = true;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (aux[i][j] != b[i][j]){
                    foi = false;
                    break;
                }
            }
            if (!foi) break;
        }

        if (foi){
            cout << "Yes" << "\n";
            return;
        }

        count++;
        v1++;
    }

    cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}