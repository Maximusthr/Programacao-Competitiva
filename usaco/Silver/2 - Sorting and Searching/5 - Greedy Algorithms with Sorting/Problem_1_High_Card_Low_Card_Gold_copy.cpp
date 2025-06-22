#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    int n; cin >> n;

    vector<bool> values(n*2 + 1);

    vector<int> arr(n);
    for (auto &i : arr) {
        cin >> i;
        values[i] = true;
    }

    vector<int> low_half;
    vector<int> high_half;

    bool half = false;

    for (int i = 0; i < n; i++){
        if (i == n/2) half = true;

        if (!half) high_half.push_back(arr[i]);
        else low_half.push_back(arr[i]);
    }

    sort(low_half.begin(), low_half.end());
    sort(high_half.begin(), high_half.end(), greater<int>());

    vector<int> todo;
    for (int i = 1; i <= n*2; i++){
        if (!values[i]) todo.push_back(i);
    }

    vector<int> bessie_low;
    vector<int> bessie_high;

    half = false;
    for (int i = 0; i < n; i++){
        if (i == n/2) half = true;

        if (!half) bessie_low.push_back(todo[i]);
        else bessie_high.push_back(todo[i]);
    }
    sort(bessie_low.begin(), bessie_low.end());
    sort(bessie_high.begin(), bessie_high.end(), greater<int> ());

    int ans = 0;
    int i = 0, j = 0;
    while (i < n/2 && j < n/2){
        if (bessie_high[i] > high_half[j]){
            i++;
            ans++;
        }
        j++;
    }
    i = 0, j = 0;
    while (i < n/2 && j < n/2){
        if (bessie_low[i] < low_half[j]){
            i++;
            ans++;
        }
        j++;
    }

    cout << ans << "\n";
}