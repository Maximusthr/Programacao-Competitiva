#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> arr;
int tam_heap;

int left_child(int v){
    return 2 * v + 1;
}
int right_child(int v){
    return 2 * v + 2;
}

void MaxHeapify(int idx){
    int L = left_child(idx);
    int R = right_child(idx);

    int maior = idx;
    if (L < tam_heap && arr[L] > arr[maior]) maior = L; // no slide está L <= tam_heap (errado)
    if (R < tam_heap && arr[R] > arr[maior]) maior = R; // no slide está R <= tam_heap (errado)

    if (maior != idx){
        swap(arr[idx], arr[maior]);
        MaxHeapify(maior);
    }
}

void BuildMaxHeap(){
    // corto todas as folhas
    for (int i = tam_heap/2 - 1; i >= 0; i--){
        MaxHeapify(i);
    }
}

void heapsort(){
    BuildMaxHeap();
    for (int i = arr.size()-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        tam_heap--;
        MaxHeapify(0);
    }
}

void solve(){
    int n; cin >> n;

    arr.resize(n);
    tam_heap = n;

    for (auto &i : arr) cin >> i;

    heapsort();

    for (int i = 0; i < n; i++){
        cout << arr[i] << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}