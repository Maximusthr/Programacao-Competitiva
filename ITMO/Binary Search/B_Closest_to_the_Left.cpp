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
        int aux = queries[i];

        int ans = 0;
        while(l <= r){
            int mid = r - (r-l)/2;

            if (arr[mid] <= aux){
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid-1;
            }
        }

        if (arr[ans] <= aux) cout << ans << "\n";
        else cout << 0 << "\n";
    }
}
