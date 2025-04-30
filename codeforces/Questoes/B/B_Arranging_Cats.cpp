#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while (t--){
        int n; cin >> n;

        string a, b; cin >> a >> b;

        int sum = 0;
        int dif = 0;
        for (int i = 0; i < n; i++){
            if (a[i] == '1' && b[i] == '0'){
                sum++;
            }
            else if (a[i] == '0' && b[i] == '1') {
                dif++;
            }
        }

        if (sum > dif){
            cout << dif + (sum-dif) << "\n";
        }
        else if (dif > sum){
            cout << sum + (dif-sum) << "\n";
        }
        else cout << sum << "\n";
        
    }
}
