#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg(int n) : seg(4*n) {};

    int build(vector<int> &arr, int p, int l, int r){
        if (l == r){
            return seg[p] = arr[l];
        }

        int mid = (l+r)/2;
        return seg[p] = min(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n, w; cin >> n >> w;
    
    n = (1 << n);

    vector<int> arr(n);

    iota(arr.begin(), arr.end(), 1);
    swap(arr[w-1], arr[n-1]);

    Seg seg(n);
    seg.build(arr, 1, 0, n-1);

    int pos = 0;
    for (int i = 1; i < 2*n; i++){
        if (w == seg.seg[i]) {
            pos = i;
            break;
        }
    }

    while(pos > 0){
        pos >>= 1;
        seg.seg[pos] = w;
    }

    for (int i = 1; i < 2*n; i++){
        cout << seg.seg[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}