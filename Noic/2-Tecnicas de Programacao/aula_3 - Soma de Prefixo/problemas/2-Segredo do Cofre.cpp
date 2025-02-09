#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m; cin >> n >> m;

    vector<vector<int>> matriz (n, vector<int> (10));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 1; j++){
            int x; cin >> x;
            matriz[i][x]++;
        }
    }

    // soma de prefixo em matriz
    vector<vector<int>> aux = matriz;

    for (int i = 1; i < n; i++){
        for (int j = 0; j < 10; j++){
            aux[i][j] += aux[i-1][j];
        }
    }

    vector<int> num(10);

    vector<int> queues;
    for (int i = 0; i < m; i++){
        int q; cin >> q;
        queues.push_back(q-1);
    }

    for (int i = 1; i < (int)queues.size(); i++){
        for (int j = 0; j < 10; j++){
            if (i == 1) num[j] += aux[queues[i]][j];
            else if (queues[i] > queues[i-1]) num[j] += abs(aux[queues[i]][j] - aux[queues[i-1]][j]);
            else if (queues[i] == 0) num[j] += aux[queues[i-1]-1][j];
            else num[j] += aux[queues[i-1]-1][j] - aux[queues[i]-1][j];
        }
    } 

    for (int i = 0; i < 10; i++){
        if (i == 9) cout << num[i] << "\n";
        else cout << num[i] << " ";
    }

}
