    #include <bits/stdc++.h>

    using namespace std;
    using ll = long long;
    const int INF = 0x3f3f3f3f;
    const ll LINF = 0x3f3f3f3f3f3f3f3fll;

    const int MOD = 998244353;
    const int MAX = 1e6+5;

    vector<ll> fat;

    ll binpow(ll a, ll b){
        ll x = 1;
        while(b > 0){
            if (b & 1) x = x * a % MOD;
            b >>= 1;
            a = a * a % MOD;
        }
        return x;
    }

    ll Arr(ll n, ll x){
        if (x > n || x < 0) return 0;
        return (fat[n] * binpow(fat[n-x], MOD-2)) % MOD;
    }

    void solve(){
        int n; cin >> n;

        vector<ll> arr(n+1);
        for (auto &i : arr) cin >> i;

        ll sum = accumulate(arr.begin(), arr.end(), 0ll);
        ll qtd = sum/n;
        ll rest = sum % n;

        ll extra = 0;
        for (int i = 1; i <= n; i++){
            if (arr[i] > qtd + 1){
                cout << 0 << "\n";
                return;
            }
            else extra += (arr[i] == qtd + 1);
        }

        ll ans = Arr(rest, extra) % MOD;

        ll normal = n - extra;
        ans = (ans * fat[normal]) % MOD;
        
        cout << ans << "\n";
    }

    int main(){
        ios_base::sync_with_stdio(0); cin.tie(NULL);

        fat.resize(MAX);

        fat[0] = 1;
        fat[1] = 1;
        for (int i = 1; i < MAX; i++){
            fat[i] = (i * fat[i-1]) % MOD;
        }

        int t; cin >> t;
        while(t--){
            solve();
        }
    }