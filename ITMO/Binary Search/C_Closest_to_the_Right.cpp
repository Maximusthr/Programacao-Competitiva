#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, k; cin >> n >> k;

    int arr[n+1];
    int queries[k+1];

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    for (int i = 1; i <= k; i++)
        cin >> queries[i];

    for (int i = 1; i <= k; i++){
        int l = 1;
        int r = n;

        int ans = -1;
        int aux = queries[i];

        while(l <= r){
            int mid = r - (r-l)/2;

            if (arr[mid] >= aux){
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid + 1;
            }
        }

        if (ans != -1 && arr[ans] >= aux) cout << ans << "\n";
        else cout << n+1 << "\n";
    }
}
