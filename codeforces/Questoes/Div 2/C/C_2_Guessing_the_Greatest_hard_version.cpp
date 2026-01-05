#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int cont = 1;
int query(int l, int r){
    cout << "? " << l << " " << r << endl;
    // cout << cont++ << endl;

    int x; cin >> x;
    return x;
}

void solve(){
    int n; cin >> n;

    int seg = query(1, n);

    int l = 1, r = n;
    if (seg != 1 && seg != n){
        int left = query(1, seg);
        if (left == seg) r = seg;
        else l = seg;
    }

    if (l == seg){
        // minimizar o mid
        while(r - l > 1){
            int mid = l + (r-l)/2;
            
            int v = query(seg, mid);
            if (v == seg) r = mid;
            else l = mid;
        }
        
        cout << "! " << r << endl;
    }
    else {
        // maximizar o mid
        while(r - l > 1){
            int mid = l + (r-l)/2;
            
            int v = query(mid, seg);
            if (v == seg) l = mid;
            else r = mid;
        }

        cout << "! " << l << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}