    #include <bits/stdc++.h>

    using namespace std;
    using ll = long long;
    const int INF = 0x3f3f3f3f;
    const ll LINF = 0x3f3f3f3f3f3f3f3fll;

    void solve(){
        int n, k; cin >> n >> k;

        vector<int> arr(k);

        for (auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end(), greater<int>());

        ll dif = 0;
        int ans = 0;
        for (int i = 0; i < k; i++){
            if (dif >= arr[i]){
                break;
            }
            ans++;
            dif += n-arr[i];
        }

        cout << ans << "\n";
    }

    int main() {
        ios_base::sync_with_stdio(0); cin.tie(NULL);

        int t; cin >> t;

        while(t--){
            solve();
        }
    }