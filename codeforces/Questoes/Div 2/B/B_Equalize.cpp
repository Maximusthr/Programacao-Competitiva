#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    set<int> arr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr.insert(x);
    }

    vector<int> a = {arr.begin(), arr.end()};
    int tam = a.size();

    
    int ans = 1;

    int aux = 1;
    int l = 0, r = 1;
    while (l < tam && r < tam){
        while (r < tam && a[r] - a[l] + 1 <= n){
            r++;
            aux++;
        }

        ans = max(aux, ans);

        while (l < r && a[r] - a[l] + 1 > n){
            l++;
            aux--;
        }
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