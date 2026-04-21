#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Node {
    int ab, fec, par;
};  

struct Seg {
    vector<Node> seg;

    Seg (int n) : seg(4*n) {}

    Node combine(Node a, Node b){
        Node c;

        int uso = min(a.ab, b.fec);
        c.par = a.par + b.par + uso;
        c.ab = a.ab + b.ab - uso;
        c.fec = a.fec + b.fec - uso;

        return c;
    }

    Node build(string &s, int p, int l, int r){
        if (l == r) {
            if (s[l] == '(') seg[p].ab = 1;
            else seg[p].fec = 1;
            return seg[p];
        }

        int mid = (l+r)/2;
        return seg[p] = combine(build(s, 2*p, l, mid), build(s, 2*p+1, mid+1, r));
    }

    Node query(int a, int b, int p, int l, int r){
        if (a > r || b < l) return {0, 0, 0};
        if (l >= a && b >= r) return seg[p];

        int mid = (l+r)/2;
        return combine(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }
};


void solve(){
    string s; cin >> s;

    int n = s.size();

    Seg seg(n);
    seg.build(s, 1, 0, n-1);

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        l--, r--;
        
        cout << 2 * seg.query(l, r, 1, 0, n-1).par << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}