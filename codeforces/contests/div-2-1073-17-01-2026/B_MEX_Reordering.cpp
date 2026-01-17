#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    vector<bool> mat(101);
    
    for (int i = 0; i < n-1; i++){
        // 0 até i
        int pref = 0;
        mat[arr[i]] = 1;
        
        while(mat[pref]){
            pref++;
        }
        
        vector<bool> mat2(101);
        for (int j = i+1; j < n; j++){
            mat2[arr[j]] = 1;
        }

        int suf = 0;
        while(mat2[suf]){
            suf++;
        }

        if (pref == suf){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}