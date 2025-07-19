#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    ll k; cin >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int x = 0;
    int maior = arr[0];
    for (int i = 1; i < n; i++){
        maior = max(maior, arr[i]);
        if (maior == arr[i]){
            x = 1;
        }
        else x++;

        if (x == k){
            cout << maior << "\n";
            return 0;
        }
    }

    cout << maior << "\n";
}