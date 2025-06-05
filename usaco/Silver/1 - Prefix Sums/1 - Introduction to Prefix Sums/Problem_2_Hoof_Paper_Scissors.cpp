#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n; cin >> n;

    vector<char> c;
    for (int i = 0; i < n; i++){
        char carac; cin >> carac;
        c.push_back(carac);
    }

    vector<int> h(n+1);
    vector<int> p(n+1);
    vector<int> s(n+1);

    for (int i = 0; i < n; i++){
        if (c[i] == 'H') h[i+1]++;
        else if (c[i] == 'P') p[i+1]++;
        else s[i+1]++;
    }

    for (int i = 1; i <= n; i++){
        h[i] = h[i] + h[i-1];
        p[i] = p[i] + p[i-1];
        s[i] = s[i] + s[i-1];
    }

    int ans = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 1; j <= n; j++){
            if (i == 0){
                ans = max(ans, h[n]-h[j-1]);
                ans = max(ans, h[j] + p[n]-p[j-1]);
                ans = max(ans, h[j] + s[n]-s[j-1]);
            }
            else if (i == 1){
                ans = max(ans, p[n]-p[j-1]);
                ans = max(ans, p[j] + h[n]-h[j-1]);
                ans = max(ans, p[j] + s[n]-s[j-1]);
            }
            else {
                ans = max(ans, s[n]-s[j-1]);
                ans = max(ans, s[j] + p[n]-p[j-1]);
                ans = max(ans, s[j] + h[n]-h[j-1]);
            }
        }
    }

    cout << ans << "\n";
}