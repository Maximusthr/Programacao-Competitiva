#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;
vector<int> divs(MAX);

struct Seg_sum {
    vector<ll> seg;

    Seg_sum(int n) : seg(4*n) {};

    ll build(vector<ll> &arr, int p, int l, int r){
        if (l == r) return seg[p] = arr[l];
        int mid = (l+r)/2;
        return seg[p] = build(arr, 2*p, l, mid) + build(arr, 2*p+1, mid+1, r);
    }

    ll query(int a, int b, int p, int l, int r){
        if (a > r || b < l) return 0;
        if (l >= a && b >= r) return seg[p];

        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }

    ll update(int idx, int p, int l, int r){
        if (idx < l || idx > r) return seg[p];
        if (l == r) return seg[p] = divs[seg[p]];

        int mid = (l+r)/2;
        return seg[p] = update(idx, 2*p, l, mid) + update(idx, 2*p+1, mid+1, r);
    }
};

void solve(){
    int n, q; cin >> n >> q;

    set<int> remov;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] > 2) remov.insert(i);
    }
    
    Seg_sum sum(n);
    sum.build(arr, 1, 0, n-1);

    while(q--){
        int x; cin >> x;
        if (x == 1){
            int l, r; cin >> l >> r;
            l--, r--;
    
            vector<int> tr;
            auto it = remov.lower_bound(l);
            while(*it <= r && it != remov.end()){
                sum.update(*it, 1, 0, n-1);
                arr[*it] = divs[arr[*it]];
                if (arr[*it] <= 2) tr.push_back(*it);
                it++;
            }

            for (auto z : tr) remov.erase(z);
        }
        else {
            int l, r; cin >> l >> r;
            l--, r--;

            cout << sum.query(l, r, 1, 0, n-1) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    for (int i = 1; i < MAX; i++){
        for (int j = i; j < MAX; j += i){
            divs[j]++;
        }
    }
    
    solve();
}