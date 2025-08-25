#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


const int MAX = 1000001;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> valor;
    valor.resize(n);
    for (auto &i : valor) cin >> i;
    
    bool dp[MAX];
    
    memset(dp, false, sizeof(dp));
    
    dp[0] = true;
    
    for (int i = 0; i < n; i++){
        for (int j = MAX-1; j >= valor[i]; j--){
            if (dp[j - valor[i]]){
                dp[j] = true;
            }
        }
    }
    
    set<int> ans;
    for (int i = 1; i < MAX; i++){
        if (dp[i]) ans.insert(i);
    }

    cout << ans.size() << "\n";
    for (auto it : ans) cout << it << " ";
    cout << "\n";
}