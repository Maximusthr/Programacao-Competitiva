#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool is_Valid_one(string a, string b){
    if (a.size() != b.size()) return false;

    for (int l = 0; l < b.size(); l++){
        for (int m = 0; m < b.size(); m++){
            if (a[l] == a[m]) {
                if (b[l] != b[m]) return false;
            }
            else {
                if (b[l] == b[m]) return false;
            }
        }
    }

    return true;
}

bool isValid_string(string a, string b, string dig_A, string dig_B){
    for (int k = 0; k < a.size(); k++){
        for (int l = 0; l < b.size(); l++){
            if (a[k] == b[l]){
                if (dig_A[k] != dig_B[l]) return false;
            }
            else { 
                if (dig_A[k] == dig_B[l]) return false;
            }
        }
    }

    return true;
}

void solve(){
    string a, b, c; cin >> a >> b >> c;
    
    int ans = 0;
    array<int, 3> talvez = {-1, -1, -1};
    for (int i = 1; i <= 999; i++){
        string d = to_string(i);

        if (!is_Valid_one(a, d)) continue;

        for (int j = 1; j <= 999; j++){
            string e = to_string(j);

            if (!is_Valid_one(b, e)) continue;
            if (!isValid_string(a, b, d, e)) continue;

            int sum = i + j;

            string f = to_string(sum);

            if (!is_Valid_one(c, f)) continue;
            if (!isValid_string(a, c, d, f)) continue;
            if (!isValid_string(b, c, e, f)) continue;

            ans++;
            talvez[0] = i, talvez[1] = j, talvez[2] = sum;
        }
    }

    if (talvez[0] == -1){
        cout << 0 << "\n";
        return;
    }

    cout << ans << "\n";
    cout << talvez[0] << "\n" << talvez[1] << "\n" << talvez[2] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}