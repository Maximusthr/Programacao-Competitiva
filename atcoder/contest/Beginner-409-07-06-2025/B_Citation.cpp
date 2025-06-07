#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    map<int, int> v;
    set<int> duplicata;

    vector<int> valores(102);

    for (int i = 0; i < 102; i++){
        for (int j = 0; j < n; j++){
            if (arr[j] >= i){
                valores[i]++;
            }
        }
    }     
        
    int ans = 0;
    for (int i = 0; i < 102; i++){
        if (valores[i] >= i) ans = i;
    }

    cout << ans << "\n";
}
