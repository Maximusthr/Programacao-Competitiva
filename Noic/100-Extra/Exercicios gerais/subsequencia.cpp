#include <iostream>

using namespace std;

const int MAX = 1e5+1;

int a[MAX];
int b[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int x, y; cin >> x >> y;

    for (int i = 0; i < x; i++){
        int f; cin >> f;
        a[i] = f;
    }
    for (int i = 0; i < y; i++){
        int g; cin >> g;
        b[i] = g;
    }

    int ans = 0;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x; j++){
            if (b[i] == a[j]){
                ans++;
                break;
            };
        }
    }

    (ans == y) ? cout << "S" << "\n" : cout << "N" << "\n";
}
