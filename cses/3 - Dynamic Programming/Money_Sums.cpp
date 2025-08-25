#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<int> v;
set<int> ans;
bool memo[101][1000001];

void dp(int index, int valor){
    if (index == n){
        if (valor > 0){
            ans.insert(valor);
        }
        return;
    }

    if (memo[index][valor]) return;

    memo[index][valor] = true;

    dp(index + 1, valor); // nao incluo a moeda
    dp(index + 1, valor + v[index]); // incluo a moeda
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n;

    v.resize(n);
    for (auto &i : v) cin >> i;

    dp(0, 0);

    cout << ans.size() << "\n";
    for (auto it : ans) cout << it << " ";
    cout << "\n";
}