#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    int maior = 0;

    if (k == 0){
        if (freq[1] > 0) {
            cout << -1 << "\n";
            return 0;
        }
        cout << 1 << "\n";
        return 0;
    }

    // k elementos menores ou iguais
    int aux = 0;
    for (auto [x, y] : freq){
        aux += y;
        maior = x;

        if (k == aux){
            cout << maior << "\n";
            return 0;
        }
        else if (aux > k){
            cout << -1 << "\n";
            return 0;
        }
    }   
}