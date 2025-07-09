#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string n; cin >> n;
    int k; cin >> k;

    if ((int)n.size() < k+1) {
        cout << (int)n.size()-1 << "\n";
        return 0;
    }

    int zeros = 0;
    int ans = 0;
    for (int i = n.size()-1; i >= 0; i--){
        if (n[i] == '0'){
            zeros++;
            if (zeros == k){
                break;
            }
        }
        else if (n[i] != '0' && zeros < k){
            ans++;
        }
    }

    if (zeros < k){
        cout << (int) n.size()-1 << "\n";
    }
    else {
        cout << ans << "\n";
    }
}