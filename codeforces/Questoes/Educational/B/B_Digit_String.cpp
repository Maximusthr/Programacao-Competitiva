    #include <bits/stdc++.h>

    using namespace std;
    using ll = long long;
    const int INF = 0x3f3f3f3f;
    const ll LINF = 0x3f3f3f3f3f3f3f3fll;

    void solve(){
        string s; cin >> s;
        int n = s.size();

        int ans = count(s.begin(), s.end(), '4');

        string ss;
        for (int i = 0; i < n; i++){
            if (s[i] == '4') continue;
            ss.push_back(s[i]);
        }

        n = ss.size();
        
        vector<int> odd(n+2), even(n+1);
        for (int i = 0; i < n; i++){
            if (ss[i] == '2') even[i+1]++;
        }
        for (int i = n-1; i >= 0; i--){
            if (ss[i] == '1' || ss[i] == '3') odd[i+1]++;
        }

        for (int i = 1; i <= n; i++){
            even[i] += even[i-1];
        }
        for (int i = n; i >= 0; i--){
            odd[i] += odd[i+1];
        }

        int maxi = 0;
        for (int i = 1; i <= n; i++){
            maxi = max(even[i] + odd[i], maxi);
        }

        cout << ans + n - maxi << "\n";
    }

    int main(){
        ios_base::sync_with_stdio(0); cin.tie(NULL);
        int t; cin >> t;
        while(t--){
            solve();
        }
    }