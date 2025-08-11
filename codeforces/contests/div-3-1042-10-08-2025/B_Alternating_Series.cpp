    #include <bits/stdc++.h>

    using namespace std;
    using ll = long long;
    const int INF = 0x3f3f3f3f;
    const ll LINF = 0x3f3f3f3f3f3f3f3fll;

    void solve(){
        int n; cin >> n;

        if (n <= 3){
            for (int i = 0; i < n; i++){
                if (i % 2 == 0) cout << -1 << " ";
                else cout << n << " ";
            }
        }
        else if (n % 2 == 0) {
            for (int i = 0; i < n; i++){
                if (i == n-1){
                    cout << 2 << " ";
                    break;
                }
                if (i % 2 == 0) cout << -1 << " ";
                else cout << 3 << " ";
            }
        }
        else {
            for (int i = 0; i < n; i++){
                if (i % 2 == 0) cout << -1 << " ";
                else cout << 3 << " ";
            }
        }
        cout << "\n";
    }

    int main(){
        ios_base::sync_with_stdio(0); cin.tie(NULL);
        int t; cin >> t;
        while(t--){
            solve();
        }
    }