// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5 + 5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> a(MAX);
    vector<int> b(MAX);

    int v = 0;
    for (int i = 0; i < n; i++){
        if (a[arr[i]] == 0){
            v++;
        }
        a[arr[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (a[arr[i]] - 1 == 0){
            v--;
        }
        a[arr[i]]--;

        if (b[arr[i]] == 0){
            v++;
            b[arr[i]]++;
        }

        ans = max(ans, v);
    }

    cout << ans << "\n";
}