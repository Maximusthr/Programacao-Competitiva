#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int str, intel, v; cin >> str >> intel >> v;

    int l = 0, r = v;
    while (l < r){
        int mid = l + (r-l)/2;

        if (str + mid > intel + v - mid){
            r = mid;
        }
        else l = mid + 1;
    }

    if (str + l > intel + v - l) v++;

    cout << v - l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}