#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string x; cin >> x;

    sort(x.begin(), x.end(), greater<char>());
    string ans;
    
    for (int i = 0; i < n; i++){
        if (x[i] == '1' || x[i] == '0') break;
        else if (x[i] == '4') {
            ans.push_back('3');
            ans.push_back('2');
            ans.push_back('2');
        }
        else if (x[i] == '6'){
            ans.push_back('5');
            ans.push_back('3');
        }
        else if (x[i] == '8'){
            ans.push_back('7');
            ans.push_back('2');
            ans.push_back('2');
            ans.push_back('2');
        }
        else if (x[i] == '9'){
            ans.push_back('7');
            ans.push_back('3');
            ans.push_back('3');
            ans.push_back('2');
        }
        else ans.push_back(x[i]);

    }

    sort(ans.begin(), ans.end(), greater<char> ());

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    solve();
}