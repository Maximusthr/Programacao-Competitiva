#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg(int n) : seg(4*n) {}

    int update(int idx, int v, int p, int l, int r){
        if (idx > r || l > idx) return seg[p];
        if (l == r) return seg[p] = v;

        int mid = (l+r)/2;
        return seg[p] = update(idx, v, 2*p, l, mid) + update(idx, v, 2*p+1, mid+1, r);
    }

    int query(int a, int b, int p, int l, int r){
        if (l > b || a > r) return 0;
        if (l >= a && b >= r) return seg[p];
        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }

    void clear(){
        seg.assign((int)seg.size(), 0);
    }
};

void solve(){
    int n; cin >> n;
    
    n *= 2;

    vector<int> arr(n);
    for (auto &i : arr) {
        cin >> i; i--;
    }

    Seg seg(n);

    vector<pair<int, int>> s(n, {-1, -1});
    vector<int> ans(n/2);

    // x y x y
    for (int i = 0; i < n; i++){
        if (s[arr[i]].first == -1){
            s[arr[i]].first = i;
            seg.update(i, 1, 1, 0, n-1);
            continue;
        }

        if (s[arr[i]].first != -1){
            seg.update(s[arr[i]].first, 0, 1, 0, n-1);
            
            int v = seg.query(s[arr[i]].first, i, 1, 0, n-1);

            ans[arr[i]] = v;
        }   
    }

    reverse(arr.begin(), arr.end());

    // y x y x
    seg.clear();
    s.assign(n, {-1, -1});

    for (int i = 0; i < n; i++){
        if (s[arr[i]].first == -1){
            s[arr[i]].first = i;
            seg.update(i, 1, 1, 0, n-1);
            continue;
        }

        if (s[arr[i]].first != -1){
            seg.update(s[arr[i]].first, 0, 1, 0, n-1);
            
            int v = seg.query(s[arr[i]].first, i, 1, 0, n-1);

            ans[arr[i]] += v;
        }   
    }

    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}