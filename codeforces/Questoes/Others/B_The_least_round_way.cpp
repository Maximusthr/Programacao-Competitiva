#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int dois(int x){
    int v = 0;
    while(x % 2 == 0){
        v++;
        x /= 2;
    }
    return v;
}
int cinco(int x){
    int v = 0;
    while(x % 5 == 0){
        v++;
        x /= 5;
    }
    return v;
}

string pathh(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &p, int tipo){
    string ans;

    while (i != 0 || j != 0){
        if (i == 0){
            while (j > 0){
                ans.push_back('R');
                j--;
            }
        }
        else if (j == 0){
            while (i > 0){
                ans.push_back('D');
                i--;
            }
        }
        if (i == 0 && j == 0) break;

        int pos = p[i][j];
        int x = pos - p[i][j-1];

        if (tipo == 2){
            if (dois(arr[i][j]) == x){
                ans.push_back('R');
                j--;
            }
            else {
                ans.push_back('D');
                i--;
            }
        }
        else {
            if (cinco(arr[i][j]) == x){
                ans.push_back('R');
                j--;
            }
            else {
                ans.push_back('D');
                i--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(){
    int n; cin >> n;

    vector<vector<int>> arr(n, vector<int> (n));
    bool zero = false;  
    pair<int, int> pos;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            zero |= (arr[i][j] == 0);
            if (!arr[i][j]){
                pos = {i, j};
            }
        }
    }

    vector<vector<int>> p2(n, vector<int> (n, INF));
    vector<vector<int>> p5(n, vector<int> (n, INF));

    string path;
    if (zero){
        int d = 0;
        while (d < pos.first){
            path.push_back('D');
            d++;
        }
        int righ = 0;
        while (righ < n-1){
            path.push_back('R');
            righ++;
        }
        while (d < n-1){
            path.push_back('D');
            d++;
        } 

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (arr[i][j] == 0){
                    arr[i][j] = 10;
                }
            }
        }

    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 && j == 0){
                p2[i][i] = dois(arr[i][i]);
                continue;
            }
            
            if (j-1 >= 0) p2[i][j] = min(p2[i][j], p2[i][j-1] + dois(arr[i][j]));
            if (i-1 >= 0) p2[i][j] = min(p2[i][j], p2[i-1][j] + dois(arr[i][j]));
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 && j == 0){
                p5[i][i] = cinco(arr[i][i]);
                continue;
            }

            if (j-1 >= 0) p5[i][j] = min(p5[i][j], p5[i][j-1] + cinco(arr[i][j]));
            if (i-1 >= 0) p5[i][j] = min(p5[i][j], p5[i-1][j] + cinco(arr[i][j]));
        }
    }
    
    if (zero && (p2[n-1][n-1] == 0 || p5[n-1][n-1] == 0)){
        if (p2[n-1][n-1] == 0){
            int i = n-1, j = n-1;

            string ans = pathh(i, j, arr, p2, 2);

            cout << 0 << "\n";
            cout << ans << "\n";
        }
        else {
            int i = n-1, j = n-1;

            string ans = pathh(i, j, arr, p5, 5);

            cout << 0 << "\n";
            cout << ans << "\n";
        }
        return;
    }
    else if (zero){
        cout << 1 << "\n";
        cout << path << "\n";
        return;
    }


    if (p2[n-1][n-1] < p5[n-1][n-1]){
        int i = n-1, j = n-1;

        string ans = pathh(i, j, arr, p2, 2);

        cout << p2[n-1][n-1] << "\n";
        cout << ans << "\n";

    }
    else {
        int i = n-1, j = n-1;

        string ans = pathh(i, j, arr, p5, 5);

        cout << p5[n-1][n-1] << "\n";
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}