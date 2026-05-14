#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Node {
    int big = 0;
    int seg = 0;

    int ocur_big = 0;
    int ocur_seg = 0;
};

struct Seg{
    vector<Node> seg;

    Seg(int n) : seg(4*n) {}

    Node merge(Node a, Node b){
        if (a.big == b.big){
            if (a.seg > b.seg){
                return {a.big, a.seg, a.ocur_big + b.ocur_big, a.ocur_seg};
            }
            else if (b.seg > a.seg){
                return {b.big, b.seg, a.ocur_big + b.ocur_big, b.ocur_seg};
            }
            return {a.big, a.seg, a.ocur_big + b.ocur_big, a.ocur_seg + b.ocur_seg};
        }

        if (a.big > b.big){
            if (a.seg > b.big){
                return {a.big, a.seg, a.ocur_big, a.ocur_seg};
            }
            else if (b.big > a.seg){
                return {a.big, b.big, a.ocur_big, b.ocur_big};
            }
            return {a.big, a.seg, a.ocur_big, a.ocur_seg + b.ocur_big};
        }
        else if (b.big > a.big){
            if (b.seg > a.big){
                return {b.big, b.seg, b.ocur_big, b.ocur_seg};
            }
            else if (a.big > b.seg){
                return {b.big, a.big, b.ocur_big, a.ocur_big};
            }
            return {b.big, b.seg, b.ocur_big, b.ocur_seg + a.ocur_big};
        }
    }

    Node build(vector<int> &arr, int p, int l, int r){
        if (l == r){
            Node x = {arr[l], 0, 1, 0};
            return seg[p] = x;
        }

        int mid = (l+r)/2;
        return seg[p] = merge(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    Node query(int a, int b, int p, int l, int r){
        if (l > b || a > r) return {0, 0, 0, 0};
        if (l >= a && r <= b) return seg[p];

        int mid = (l+r)/2;
        return merge(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }

    Node update(int i, int v, int p, int l, int r){
        if (l > i || r < i) return seg[p];
        if (l == r){
            Node x = {v, 0, 1, 0};
            return seg[p] = x;
        }

        int mid = (l+r)/2;
        return seg[p] = merge(update(i, v, 2*p, l, mid), update(i, v, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    seg.build(arr, 1, 0, n-1);

    while(q--){
        int x, y, z; cin >> x >> y >> z;

        if (x == 1){
            y--;
            seg.update(y, z, 1, 0, n-1);
        }
        else {
            y--, z--;
            cout << seg.query(y, z, 1, 0, n-1).ocur_seg << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}