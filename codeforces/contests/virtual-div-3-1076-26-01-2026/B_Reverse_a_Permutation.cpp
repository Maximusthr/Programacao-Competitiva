#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> aux = arr;
    sort(aux.begin(), aux.end(), greater<int> ());
    
    int pos = 0;
    int alvo = 0;
    int start = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] != aux[i]){
            alvo = aux[i];
            start = i;
            break;
        }
    }
    
    for (int i = 0; i < n; i++){
        if (arr[i] == alvo){
            pos = i;
            break;
        }
    }

    reverse(arr.begin() + start, arr.begin() + pos + 1);

    for (auto &i : arr) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}