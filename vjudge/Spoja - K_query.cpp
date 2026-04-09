#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<vector<int>> seg;

    Seg(int n) : seg(4*n) {}

    vector<int> merge(vector<int> &a, vector<int> &b){
        int n = a.size();
        int m = b.size();

        vector<int> ans;

        ans.reserve(n+m);

        int i = 0, j = 0;
        while(i < n && j < m){
            if (a[i] <= b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }

        while (i < n){
            ans.push_back(a[i]);
            i++;
        }

        while(j < m){
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }

    vector<int> &build(vector<int> &arr, int p, int l, int r){
        if (l == r) {
            seg[p].push_back(arr[l]);
            return seg[p];
        }
        int mid = (l+r)/2;
        return seg[p] = merge(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    int query(int a, int b, int p, int l, int r, int k){
        if (l > b || r < a) return 0;
        if (l >= a && r <= b){
            return r - l + 1 - (upper_bound(seg[p].begin(), seg[p].end(), k) - seg[p].begin());
        }   
        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid, k) + query(a, b, 2*p+1, mid+1, r, k);
    }
};

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    seg.build(arr, 1, 0, n-1);

    int q; cin >> q;
    while(q--){
        int x, y, v; cin >> x >> y >> v;
        x--, y--;

        cout << seg.query(x, y, 1, 0, n-1, v) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}