#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3000;

int n; 
vector<double> arr;
double memo[MAX][MAX];

double dp(int pos, int qtd){
    if (pos > n){
        if (qtd < (n/2) + 1) return 0;
        return 1;
    }

    if (memo[pos][qtd] != -1) return memo[pos][qtd];

    double ans = dp(pos+1, qtd) * (1 - arr[pos]) + dp(pos+1, qtd+1) * (arr[pos]);

    return memo[pos][qtd] = ans;
}

void solve(){
    cin >> n;

    arr.resize(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            memo[i][j] = -1;
        }
    }

    cout << fixed << setprecision(10);
    cout << dp(1, 0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}