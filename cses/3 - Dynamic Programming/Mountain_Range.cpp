#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg{
    vector<int> seg;

    Seg (int n) : seg(4*n) {};

    int query(int a, int b, int p, int l, int r){
        if (l > b || a > r) return 0;
        if (l >= a && b >= r) return seg[p];
        int mid = (l+r)/2;
        return max(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }

    int update(int idx, int v, int p, int l, int r){
        if (r < idx || l > idx) return seg[p];
        if (l == r) return seg[p] = v;
        int mid = (l+r)/2;
        return seg[p] = max(update(idx, v, 2*p, l, mid), update(idx, v, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> left_idx(n), right_idx(n);
    stack<int> st;

    for (int i = 0; i < n; i++){
        while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
        if (!st.empty()) left_idx[i] = st.top() + 1;
        else left_idx[i] = 0;
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for (int i = n-1; i >= 0; i--){
        while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
        if (!st.empty()) right_idx[i] = st.top() - 1;
        else right_idx[i] = n-1;
        st.push(i);
    }

    vector<pair<int, int>> range;
    for (int i = 0; i < n; i++){
        range.push_back({arr[i], i});
    }
    sort(range.begin(), range.end());

    Seg dp(n);
    for (int i = 0; i < n; i++){
        int idx = range[i].second;
        int l = left_idx[idx];
        int r = right_idx[idx];

        int mx = dp.query(l, r, 1, 0, n-1) + 1;
        dp.update(idx, mx, 1, 0, n-1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, dp.query(i, i, 1, 0, n-1));
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}