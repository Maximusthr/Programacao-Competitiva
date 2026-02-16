#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> copy = arr;
    sort(copy.begin()+1, copy.end());

    for (int i = 1; i <= n/2; i++){
        if (arr[i] != copy[i]){
            int j = 2*i;
            while(j <= n){
                if (arr[j] == copy[i]) swap(arr[i], arr[j]);
                j *= 2;
            }
            if (arr[i] != copy[i]){
                cout << "NO" << "\n";
                return;
            }
        }
    }

    if (is_sorted(arr.begin(), arr.end())){
        cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}