#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    stack<int> st;
    vector<ll> left(n), right(n);

    for (int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if (st.empty()) left[i] = i + 1;
        else left[i] = i - st.top();

        st.push(i);
    }

    while(!st.empty()) st.pop();

    for (int i = n-1; i >= 0; i--){
        while (!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if (st.empty()) right[i] = n - i;
        else right[i] = st.top() - i;

        st.push(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += arr[i] * left[i] * right[i];
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}