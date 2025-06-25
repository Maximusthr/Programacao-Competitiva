#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int l = 1, r = n;
    while(l < r){   
        int mid = l + (r-l)/2;

        int sum = 0;
        cout << "? " << mid-l+1 << " ";
        for (int i = l; i <= mid; i++){
            cout << i << " \n" [i == mid];
            sum += arr[i];
        }
        cout.flush();

        int x; cin >> x;

        if (x > sum){
            r = mid;
        }
        else l = mid+1;
    }

    cout << "! " << l << "\n";
    cout.flush();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}
