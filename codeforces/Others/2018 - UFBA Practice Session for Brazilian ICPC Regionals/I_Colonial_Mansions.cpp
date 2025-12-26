// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg (int n) : seg(4*n) {}

    int update(int i, int v, int p, int l, int r){
        if (l > i || r < i) return seg[p];
        if (l == r) return seg[p] = v;
        
        int mid = (l+r)/2;
        return seg[p] = max(update(i, v, 2*p, l, mid), update(i, v, 2*p+1, mid+1, r));
    }

    int query(int start, int end, int p, int l, int r){
        if (r < start || l > end) return 0;
        if (start <= l && r <= end) return seg[p];
        
        int mid = (l+r)/2;
        return max(query(start, end, 2*p, l, mid), query(start, end, 2*p+1, mid+1, r));
    }

};

void solve(){
    int n, q; cin >> n >> q;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    Seg seg(n);
    for (int i = 0; i < n-1; i++){
        seg.update(i, abs(arr[i] - arr[i+1]), 1, 0, n-1);
    }

    while(q--){
        int x; cin >> x;

        if (x == 1){
            int y, v; cin >> y >> v;
            y--;
            
            arr[y] = v;
            if (y > 0){
                seg.update(y-1, abs(arr[y] - arr[y-1]), 1, 0, n-1);
            }
            if (y + 1 < n){
                seg.update(y, abs(arr[y] - arr[y+1]), 1, 0, n-1);
            }
        }
        else {
            int y, H; cin >> y >> H;
            y--;

            int l = 0, r = y;
            while(l < r){
                int mid = l + (r-l)/2;

                int max_diff = (mid == y ? 0 : seg.query(mid, y-1, 1, 0, n-1));
                
                if (max_diff <= H){
                    r = mid;
                }
                else l = mid + 1;
            }
            int left_limit = l;

            l = y, r = n-1;
            while(l < r){
                int mid = l + (r-l+1)/2;

                int max_diff = (mid == y ? 0 : seg.query(y, mid-1, 1, 0, n-1));

                if (max_diff <= H){
                    l = mid;
                }
                else r = mid - 1;
            }

            int right_limit = l;

            cout << (right_limit - left_limit + 1) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}