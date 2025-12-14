#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int menor = 1, maior = n;
    int l = 0, r = n-1;

    while(l <= r){
        if (arr[l] == menor){
            l++;
            menor++;
        }
        else if (arr[l] == maior){
            l++;
            maior--;
        }
        else if (arr[r] == menor){
            r--;
            menor++;
        }
        else if (arr[r] == maior){
            r--;
            maior--;
        }
        else break;
    }

    if (l <= r) cout << l + 1 << " " << r + 1 << "\n";
    else cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}