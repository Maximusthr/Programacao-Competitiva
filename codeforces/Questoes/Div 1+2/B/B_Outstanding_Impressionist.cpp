#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg (int n) : seg(4*n) {};

    int update(int idx, int p, int l, int r){
        if (idx > r || idx < l) return seg[p];
        if (l == r) return seg[p] = 1;

        int mid = (l+r)/2;
        return seg[p] = min(update(idx, 2*p, l, mid), update(idx, 2*p+1, mid+1, r));
    }
    int query(int a, int b, int p, int l, int r){
        if (b < l || a > r) return INF;
        if (l >= a && b >= r) return seg[p];

        int mid = (l+r)/2;
        return min(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n; cin >> n;

    vector<int> unico(2*n+1);
    vector<pair<int, int>> arr(n);
    
    Seg seg(2*n+1);

    for (auto &i : arr){
        cin >> i.first >> i.second;
        if (i.second - i.first == 0) {
            unico[i.first]++;
            seg.update(i.first, 1, 0, 2*n);
        }
    }

    string ans;

    for (int i = 0; i < n; i++){
        if (arr[i].second - arr[i].first == 0){
            if (unico[arr[i].first] == 1) ans.push_back('1');
            else ans.push_back('0');
        }
        else {
            int x = seg.query(arr[i].first, arr[i].second, 1, 0, 2*n);
            if (x == 0) ans.push_back('1');
            else ans.push_back('0');
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}