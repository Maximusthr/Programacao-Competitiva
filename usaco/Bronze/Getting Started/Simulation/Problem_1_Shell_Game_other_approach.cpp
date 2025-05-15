#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef struct{
    int a;
    int b;
    int g;
} pos;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    
    int n; cin >> n;
    vector<pos> arr;
    for (int i = 0; i < n; i++){
        int a, b, g; cin >> a >> b >> g;

        arr.push_back({a, b, g});
    }
    
    // 3 guesses
    int ans = 0;
    for (int i = 0; i < 3; i++){
        int pos = i + 1;
        int temp = 0;
        for (auto &s : arr){
            if (pos == s.a) pos = s.b;
            else if (pos == s.b) pos = s.a;
            
            if (s.g == pos) temp++;
        }

        ans = max(ans, temp);

    }

    cout << ans << "\n";
}
