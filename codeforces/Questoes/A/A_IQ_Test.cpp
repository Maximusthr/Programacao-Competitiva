#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    vector<string> arr;

    for (int i = 0; i < 4; i++){
        string x; cin >> x;
        arr.push_back(x);
    }

    // solving #
    int aux = 0;
    bool ok = false;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (arr[i][j] == '#' || arr[i][j] == '.'){
                if (arr[i][j] == '#') aux++;
                if (arr[i][j+1] == '#') aux++;
                if (arr[i+1][j+1] == '#') aux++;
                if (arr[i+1][j] == '#') aux ++;
                if (aux >= 3) {
                    ok = true;
                    break;
                }
                aux = 0;
            }
        }
    }

    if (!ok) {
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (arr[i][j] == '.' || arr[i][j] == '#'){
                    if (arr[i][j] == '.') aux++;;
                    if (arr[i][j+1] == '.') aux++;
                    if (arr[i+1][j+1] == '.') aux++;
                    if (arr[i+1][j] == '.') aux ++;
                    if (aux >= 3) {
                        ok = true;
                        break;
                    }
                    aux = 0;
                }
            }
        }
    }

    cout << (ok ? "YES" : "NO") << "\n";
}
