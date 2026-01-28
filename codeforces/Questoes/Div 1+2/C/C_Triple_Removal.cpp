#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg (int n) : seg (4*n){};

    int update(int v, int idx, int p, int l, int r){
        if (idx > r || idx < l) return seg[p];
        if (l == r){
            return seg[p] = v;
        }

        int mid = (l+r)/2;
        return seg[p] = min(update(v, idx, 2*p, l, mid), update(v, idx, 2*p+1, mid+1, r));
    }

    int query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return INF;
        if (l >= a && r <= b) return seg[p];

        int mid = (l+r)/2;
        return min(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n), um(n+1), zero(n+1);
    for (auto &i : arr) cin >> i;

    for (int i = 1; i <= n; i++){
        if (arr[i-1] == 0) zero[i]++;
        else um[i]++;
        zero[i] += zero[i-1];
        um[i] += um[i-1];
    }

    Seg seg(n);
    for (int i = 0; i < n; i++){
        if (i == 0){
            if (arr[i] == arr[i+1]) seg.update(1, i, 1, 0, n-1);
            else seg.update(2, i, 1, 0, n-1);
        }
        else if (i == n-1){
            if (arr[i] == arr[i-1]) seg.update(1, i, 1, 0, n-1);
            else seg.update(2, i, 1, 0, n-1);
        }
        else {
            if (arr[i] == arr[i-1] || arr[i] == arr[i+1]) seg.update(1, i, 1, 0, n-1);
            else seg.update(2, i, 1, 0, n-1);
        }
    }

    while(q--){
        int l, r; cin >> l >> r;

        int Z = zero[r] - zero[l-1];
        int U = um[r] - um[l-1];

        if (Z % 3 != 0 || U % 3 != 0){
            cout << -1 << "\n";
            continue;
        }

        int sum = Z/3 + U/3;    

        l--, r--;

        if (arr[l] != arr[l+1]) seg.update(2, l, 1, 0, n-1);

        if (arr[r-1] != arr[r]) seg.update(2, r, 1, 0, n-1);

        int v = seg.query(l, r, 1, 0, n-1);
        if (v == 2) sum++;

        cout << sum << "\n";

        if (l > 0){
            if (arr[l] == arr[l-1]) seg.update(1, l, 1, 0, n-1);
        }
        if (r+1 < n){
            if (arr[r] == arr[r+1]) seg.update(1, r, 1, 0, n-1);
        }
    }       
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}