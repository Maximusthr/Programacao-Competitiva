#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct seg_impar {
    vector<ll> seg;

    seg_impar(int n) : seg (4 * n) {};

    ll build(vector<ll> &arr, int p, int l, int r){
        if (l == r) {
            if ((arr[l] & 1) && (arr[l] != 1)){
                return seg[p] = arr[l];
            }
            return seg[p] = 0;
        }

        int mid = (l + r) >> 1;
        return seg[p] = build(arr, 2*p, l, mid) + build(arr, 2*p+1, mid+1, r);
    }

    ll query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return 0;
        if (l >= a && r <= b){
            return seg[p];
        }

        int mid = (l + r) >> 1;

        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }
};

struct seg_pot {
    vector<ll> seg;

    seg_pot(int n) : seg (4*n) {};

    ll build(vector<ll> &arr, int p, int l, int r){
        if (l == r) {
            if (((arr[l] & (arr[l]-1)) == 0) && arr[l] != 1){
                return seg[p] = arr[l];
            }
            return seg[p] = 0;
        }

        int mid = (l + r) >> 1;
        return seg[p] = build(arr, 2*p, l, mid) + build(arr, 2*p+1, mid+1, r);
    }

    ll query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return 0;
        if (l >= a && r <= b){
            return seg[p];
        }

        int mid = (l + r) >> 1;

        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }
};

struct seg_um {
    vector<ll> seg;

    seg_um(int n) : seg (4*n) {};

    ll build(vector<ll> &arr, int p, int l, int r){
        if (l == r) {
            if (arr[l] == 1){
                return seg[p] = arr[l];
            }
            return seg[p] = 0;
        }

        int mid = (l + r) >> 1;
        return seg[p] = build(arr, 2*p, l, mid) + build(arr, 2*p+1, mid+1, r);
    }

    ll query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return 0;
        if (l >= a && r <= b){
            return seg[p];
        }

        int mid = (l + r) >> 1;

        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    // seg pra contar a quantidade de 1 no intervalo do segmento

    seg_impar impar(n);
    impar.build(arr, 1, 0, n-1);

    seg_pot pot(n);
    pot.build(arr, 1, 0, n-1);

    seg_um um(n);
    um.build(arr, 1, 0, n-1);

    while(q--){
        int l, r; cin >> l >> r;
        l--, r--;

        int A = pot.query(l, r, 1, 0, n-1);
        int B = impar.query(l, r, 1, 0, n-1);
        int U = um.query(l, r, 1, 0, n-1);

        A += (U + 1)/2;
        B += U/2;

        if (A > B){
            cout << "A" << "\n";
        }
        else if (B > A){
            cout << "B" << "\n";
        }
        else cout << "E" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}