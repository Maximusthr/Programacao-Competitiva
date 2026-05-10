#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Seg {
    vector<int> seg;

    Seg (int n) : seg(4*n) {};

    int update(int i, int v, int p, int l, int r){
        if (i < l || r < i) return seg[p];
        if (l == r) return seg[p] = v;

        int mid = (l+r)/2;
        return seg[p] = max(update(i, v, 2*p, l, mid), update(i, v, 2*p+1, mid+1, r));
    }

    int query(int a, int b, int p, int l, int r){
        if (l > b || r < a) return 0;
        if (l >= a && b >= r) return seg[p];

        int mid = (l+r)/2;
        return max(query(a, b, 2*p, l, mid), query(a, b, 2*p+1, mid+1, r));
    }
};

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    stack<int> st;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        
        if (st.empty()) left[i] = i+1;
        else left[i] = i - st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    for (int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        
        if (st.empty()) right[i] = n - i;
        else right[i] = st.top() - i;
        st.push(i);
    }
    
    Seg seg(n+5);
    for (int i = 0; i < n; i++){
        int cont = left[i] + right[i] - 1;

        int q = seg.query(cont, cont, 1, 0, n);
        if (arr[i] > q) seg.update(cont, arr[i], 1, 0, n);
    }

    for (int i = 0; i < n; i++){
        cout << seg.query(i+1, n, 1, 0, n) << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}