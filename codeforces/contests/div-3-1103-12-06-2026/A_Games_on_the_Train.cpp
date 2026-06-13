#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    int maior = 0;
    int menor = 10;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        menor = min(arr[i], menor);
        maior = max(arr[i], maior);
    }

    cout << maior - menor + 1 << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}