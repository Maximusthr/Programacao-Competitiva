#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef struct{
    int a;
    int b;
    int g;
} pos;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    
    int n; cin >> n;
    vector<pos> arr;
    for (int i = 0; i < n; i++){
        int a, b, g; cin >> a >> b >> g;

        arr.push_back({a, b, g});
    }
    
    // 3 guesses
    int ans = 0;
    bool a, b, c;
    for (int j = 0; j < 3; j++){
        if (j == 0) a = true, b = false, c = false;
        if (j == 1) a = false, b = true, c = false;
        if (j == 2) a = false, b = false, c = true;
        
        int temp = 0;
        for (int i = 0; i < n; i++){
            if (((arr[i].a == 1 && arr[i].b == 2) || (arr[i].a == 2 && arr[i].b == 1)) && a){
                a = false;
                b = true;
                if (arr[i].g == 2) temp++;
            }
            else if (((arr[i].a == 1 && arr[i].b == 3) || (arr[i].a == 3 && arr[i].b == 1)) && a){
                a = false;
                c = true;
                if (arr[i].g == 3) temp++;
            }
            else if (((arr[i].a == 2 && arr[i].b == 1) || (arr[i].a == 1 && arr[i].b == 2)) && b){
                b = false;
                a = true;
                if (arr[i].g == 1) temp++;
            }
            else if (((arr[i].a == 2 && arr[i].b == 3) || (arr[i].a == 3 && arr[i].b == 2)) && b){
                b = false;
                c = true;
                if (arr[i].g == 3) temp++;
            }
            else if (((arr[i].a == 3 && arr[i].b == 1) || (arr[i].a == 1 && arr[i].b == 3)) && c){
                c = false;
                a = true;
                if (arr[i].g == 1) temp++;
            }
            else if (((arr[i].a == 3 && arr[i].b == 2) || (arr[i].a == 2 && arr[i].b == 3)) && c){
                c = false;
                b = true;
                if (arr[i].g == 2) temp++;
            }
            else {
                if (a && arr[i].g == 1) temp++;
                if (b && arr[i].g == 2) temp++;
                if (c && arr[i].g == 3) temp++;
            }
        }
        
        ans = max(ans, temp);
    }

    cout << ans << "\n";
}
