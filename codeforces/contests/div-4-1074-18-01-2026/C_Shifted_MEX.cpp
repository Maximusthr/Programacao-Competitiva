#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5;
vector<int> arr;
int n;

int find_mex(int v){
    map<int, bool> aux;

    for (int i = 0; i < n; i++){
        aux[arr[i] + v] = 1;
    }

    int a = 0;
    while(aux[a]){
        a++;
    }

    return a;
}

void solve(){
    cin >> n;

    arr.resize(n);
    map<int, bool> x;
    for (auto &i : arr){
        cin >> i;
        x[i] = 1;
    } 

    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; i++){
        // quanto falta pro atual chegar a 0?

        int v = -arr[i];
        ans = max(ans, find_mex(v));
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}