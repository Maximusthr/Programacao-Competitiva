#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, t; cin >> n >> t;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = 0;
    int aux = arr[0];

    int i = 0, j = 0;
    for (; i < n;){
        if (aux <= t){
            ans = max(ans, j-i+1);
            j++;
            aux += arr[j];
            if (j == n) break;
        }
        else {
            aux -= arr[i];
            i++;
        }
    }

    cout << ans << "\n";
}
