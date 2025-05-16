#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1001;
vector<bool> vis(MAX);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = 0;

    for (int i = 0; i < n; i++){
        int sum = 0;
        int elem = 0;
        for (int j = i; j < n; j++){
            vis[arr[j]] = true;
            sum += arr[j];
            elem++;
            if ((sum % elem) == 0) if (vis[sum/elem]) ans++;
        }
        vis.assign(MAX, false);
    }

    cout << ans << "\n";
}
