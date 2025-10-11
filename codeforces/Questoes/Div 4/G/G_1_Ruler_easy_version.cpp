#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void query(int mid){
    cout << "? 1 " << mid << endl;
}

void solve(){
    
    int l = 2, r = 999;
    while(l < r){
        int mid = l + (r-l)/2;

        query(mid);

        int x; cin >> x;
        if (x > mid){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << "! " << l << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}