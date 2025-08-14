#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m, k; cin >> n >> m >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    sort(arr.begin(), arr.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, ans = 0;
    while(i < n && j < m){
        if (arr[i] <= b[j]){
            if (b[j] - arr[i] <= k) {
                ans++;
                j++;
            }
            i++;
        }
        else if (arr[i] > b[j]){
            if (arr[i] - b[j] <= k){
                ans++;
                i++;
            }
            j++;
        }
    }

    cout << ans << "\n";
}