#include <iostream>
using namespace std;

int pascal(int row, int col) {
    if (col == 0 || col == row) {
        return 1;
    }
    else {
        return pascal(row - 1, col - 1) + pascal(row - 1, col);
    }
}

int main() {
    int n;
    cout << "Vvedite n(kol-vo strok v treyg Paskalia)";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << pascal(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
