#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    n *= 2;

    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    int temp = 0;
    vector<int> ok(n);
    for (int i = 0; i < n; i++){
        ok[arr[i]]++;
        if (ok[arr[i]] == 1) temp++;
        else if (ok[arr[i]] == 2) temp--;

        ans = max(ans, temp);
    }

    cout << ans << "\n";
}