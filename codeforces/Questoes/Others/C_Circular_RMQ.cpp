#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<ll> seg, lazy;

    Seg (int n) : seg(4*n), lazy(4*n) {}

    ll build(vector<ll> &arr, int p, int l, int r){
        if (l == r) return seg[p] = arr[l];

        int mid = (l+r)/2;
        return seg[p] = min(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    void push(int p){
        seg[2*p] += lazy[p];
        lazy[2*p] += lazy[p];
        seg[2*p+1] += lazy[p];
        lazy[2*p+1] += lazy[p];
        lazy[p] = 0;
    }

    ll query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return LINF;
        if (l >= a && r <= b) return seg[p];

        int mid = (l+r)/2;
        push(p);
        return min(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }

    ll update(int a, int b, ll v, int p, int l, int r){
        if (l > b || a > r) return seg[p];
        if (l >= a && r <= b) {
            lazy[p] += v;
            return seg[p] += v;
        }
        
        int mid = (l+r)/2;
        push(p);
        return seg[p] = min(update(a, b, v, 2*p, l, mid), update(a, b, v, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n; cin >> n;
    
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);

    seg.build(arr, 1, 0, n-1);

    int q; cin >> q;
    cin.ignore();
    while(q--){
        string s; getline(cin, s);

        ll l = 0, r = 0, v = -LINF;
        bool ok = false;
        
        int espacos = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                espacos++;
                if (espacos == 2) v = 0;
                continue;
            }
            if (espacos == 0){
                int aux = s[i] - '0';
                l *= 10;
                l += aux;
            }
            else if (espacos == 1){
                int aux = s[i] - '0';
                r *= 10;
                r += aux;
            }
            else {
                int aux = s[i] - '0';

                if (s[i] == '-'){
                    ok = true;
                    aux = s[i+1] - '0';
                    v = aux;
                    v *= -1;
                    i++;
                    continue;
                }

                if (ok) aux *= -1;

                v *= 10;
                v += aux;
            }
        }

        if (v == -LINF){
            if (l > r) cout << min(seg.query(l, n-1, 1, 0, n-1), seg.query(0, r, 1, 0, n-1)) << "\n";
            else cout << seg.query(l, r, 1, 0, n-1) << "\n";
        }
        else {
            if (l > r){
                seg.update(l, n-1, v, 1, 0, n-1);
                seg.update(0, r, v, 1, 0, n-1);
            }
            else seg.update(l, r, v, 1, 0, n-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}