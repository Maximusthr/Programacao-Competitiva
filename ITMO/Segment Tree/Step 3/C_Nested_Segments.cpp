#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg (int n) : seg(4*n) {}

    int update(int idx, int p, int l, int r){
        if (idx < l || idx > r) return seg[p];
        if (l == r) return seg[p] = 1;
        
        int mid = (l+r)/2;
        return seg[p] = update(idx, 2*p, l, mid) + update(idx, 2*p+1, mid+1, r);
    }

    int query(int a, int b, int p, int l, int r){
        if (l > b || a > r) return 0;
        if (l >= a && b >= r){
            return seg[p];
        }

        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid) + query(a, b, 2*p+1, mid+1, r);
    }
};

void solve(){
    int n; cin >> n;

    n *= 2;

    vector<int> arr(n);
    for (auto &i : arr) {
        cin >> i;
        i--;
    }

    Seg seg(n);
    vector<pair<int, int>> segm(n, {-1, -1});
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++){
        if (segm[arr[i]].first == -1){
            segm[arr[i]].first = i;
            continue;
        }

        if (segm[arr[i]].first != -1){
            int q = seg.query(segm[arr[i]].first, i, 1, 0, n-1);
            ans.push_back({arr[i], q});
            segm[arr[i]].second = i;
            seg.update(segm[arr[i]].first, 1, 0, n-1);
        }
    }

    sort(ans.begin(), ans.end());
    for (auto &i : ans) cout << i.second << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}