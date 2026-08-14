#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, a, b; cin >> n >> a >> b;

    pair<int, int> ans = {25, 61};

    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;

        int temp_a = a, temp_b = b;

        pair<int, int> v = {0, 0};
        while(temp_a != x || temp_b != y){
            v.second++;
            temp_b++;
            if (temp_b == 60){
                temp_b = 0;
                temp_a++;
                if (temp_a == 24){
                    temp_a = 0;
                }
            }
            if (v.second == 60){
                v.second = 0;
                v.first++;
                if (v.first == 24){
                    v.first = 0;
                }
            }
        }
        int aux = 60*v.first + v.second;
        if (aux < 60*ans.first + ans.second){
            ans = v;
        }
    }

    cout << ans.first << " " << ans.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
