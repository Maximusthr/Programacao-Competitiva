#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int i = 0;
    int dist_menor = 0;
    int pos = 0;
    while (i < n && arr[i] < m){
        dist_menor = m - arr[i];
        i++;
    }
    pos = i;

    int dist_maior = 0;
    i = n-1;
    int pos2 = n-1;
    while (i >= 0 && arr[i] > m){
        dist_maior = arr[i] - m;
        i--;
    }
    pos2 = i;

    // é melhor do meio pro inicio ou do meio pro final?

    if (pos >= n - pos2){
        cout << m-1 << "\n";
    }
    else {
        cout << m+1 << "\n";
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}