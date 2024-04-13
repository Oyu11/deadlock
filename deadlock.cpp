#include <iostream>
using namespace std;

pair<bool, int*> checkRequest(int requestProcessIndex, int requestResource[], int Need[][4], int Available[], int n, int m) {
    bool canAllocate = true;
    int* sequence = new int[n];
    int ind = 0;

    for (int j = 0; j < m; j++) {
        if (requestResource[j] > Need[requestProcessIndex][j]) {
            canAllocate = false;
            break;
        }
    }

    if (canAllocate) {
        for (int j = 0; j < m; j++) {
            if (requestResource[j] > Available[j]) {
                canAllocate = false;
                break;
            }
        }
    }
    if (canAllocate) {
        for (int i = 0; i < n; i++) {
            sequence[ind++] = i;
        }
    }

    return make_pair(canAllocate, sequence);
}

int main() {
    int n = 5; 
    int m = 4; 

    int Need[5][4] = {{0}}; 

    int Allocation[5][4] = {{0, 0, 1, 2}, {1, 0, 0, 0}, {1, 3, 5, 4}, {0, 6, 3, 2}, {0, 0, 1, 4}};
    int Max[5][4] = {{0, 0, 1, 2}, {1, 7, 5, 0}, {2, 3, 5, 6}, {0, 6, 5, 2}, {0, 6, 5, 6}};
    int Available[4] = {1, 5, 2, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    cout << "Need Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++) {
            cout << Need[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int requestProcessIndex = 1; 
    int requestResource[4] = {0, 4, 2, 0}; 

    pair<bool, int*> result = checkRequest(requestProcessIndex, requestResource, Need, Available, n, m);

    if (result.first) {
        cout << "shuud uurchluh bolomjtoi." << endl;
        cout << "daraalal: ";
        for (int i = 0; i < n; i++) {
            cout << "P" << result.second[i] << " ";
        }
        cout << endl;
    } else {
        cout << "shuud uurchluh bolomjgui." << endl;
    }

    delete[] result.second;

    return 0;
}
