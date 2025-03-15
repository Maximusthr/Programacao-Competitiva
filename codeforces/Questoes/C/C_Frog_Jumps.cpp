#include <bits/stdc++.h>

using namespace std;

bool isValid(int d, string &s){
    // inicio precisa ser vazio
    string new_s = "S";
    new_s += s;

    int aux = d;
    for (int i = 0; i < (int)new_s.size(); i++){
        if (aux >= (int)new_s.size()) {
            // chegamos no final
            return true;
        }
        if (new_s[aux] == 'L'){
            aux--;
        } else if (new_s[aux] == 'R'){
            aux += d;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        string s; cin >> s;

        int l = 1;
        int r = (int)s.size()+1; // +1, because the lenght of the string is x. We want x+1.

        int ans = 0;
        while (l <= r){
            int mid = l + (r-l)/2;

            if (isValid(mid, s)){
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        cout << ans << "\n";
    }
}