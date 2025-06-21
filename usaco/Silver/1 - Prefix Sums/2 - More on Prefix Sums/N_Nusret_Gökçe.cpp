#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    // esquerda-direita
    bool maior = false;
    for (int i = 0; i < n-1; i++){
        if (arr[i] <= arr[i+1]) maior = true;
        int dif = abs(arr[i+1] - arr[i]);

        if (maior){
            if (dif > k) arr[i] = arr[i+1] - k;
        }
        else {
            if (dif > k) arr[i+1] = arr[i] - k;
        }

        maior = false;
    }

    // direita-esquerda
    for (int i = n-1; i > 0; i--){
        if (arr[i] <= arr[i-1]) maior = true;
        int dif = abs(arr[i-1] - arr[i]);

        if (maior){
            if (dif > k) arr[i] = arr[i-1] - k;
        }
        else {
            if (dif > k) arr[i-1] = arr[i] - k;
        }
        
        maior = false;
    }

    for (auto &i : arr) cout << i << " ";
    cout << "\n";
}