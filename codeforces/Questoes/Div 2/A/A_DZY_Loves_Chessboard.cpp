#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<string> arr;

int pos_X[] = {0, -1, 1, 0};
int pos_Y[] = {-1, 0, 0, 1};

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '-');
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;

    arr.resize(n);
    for (auto &i : arr) cin >> i;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i % 2 == 0){
                // j % 2 == 0 eh black
                if (arr[i][j] == '.' && j % 2 == 0) arr[i][j] = 'B';
                else if (arr[i][j] == '.') arr[i][j] = 'W';
            }
            else {
                if (arr[i][j] == '.' && j % 2) arr[i][j] = 'B';
                else if (arr[i][j] == '.') arr[i][j] = 'W';
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }


}