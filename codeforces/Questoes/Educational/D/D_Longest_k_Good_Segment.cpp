#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int l = 1, r = 1;
    int dif = 0;
    map<int, int> val;
    pair<int, int> v = {1, 1};
    while(r <= n){
        while(r <= n && dif <= k){
            val[arr[r]]++;
            if (val[arr[r]] == 1)  dif++;
            if (dif > k) break;
            if (r - l + 1 > v.second - v.first + 1){
                v.first = l;
                v.second = r;
            }
            r++;
        }
        if (r > n) break;
        while(l < r && dif > k){
            val[arr[l]]--;
            if (val[arr[l]] == 0) dif--;
            l++;
        }
        
        // sei la??
        val[arr[r]]--;
        if (val[arr[r]] == 0) dif--;
    }
    cout << v.first << " " << v.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}