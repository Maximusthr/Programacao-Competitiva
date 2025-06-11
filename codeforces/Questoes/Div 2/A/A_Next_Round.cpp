#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> arr(n+1);

    int ans = 0;
    int aux = 0;

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        if (i == k)
            aux = arr[i];
    }

    for (int i = 1; i <= n; i++){
        if (arr[i] >= aux && arr[i] > 0) ans++;
    }


    cout << ans << "\n";
}
