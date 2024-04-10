#include <iostream>
using namespace std;

int main() {
    int n = 5; // processes too
    int m = 4; // resources too
    int f[5] = {0}; // N-hemjeetei 0 matrix
    int ans[5] = {0}; // N-hemjeetei 0 matrix
    int ind = 0;
    int Need[5][4] = {{0}};
    int Allocation[5][4] = {{0, 0, 1, 2}, {1, 0, 0, 0}, {1, 3, 5, 4}, {0, 6, 3, 2}, {0, 0, 1, 4}};
    int max[5][4] = {{0, 0, 1, 2}, {1, 7, 5, 0}, {2, 3, 5, 6}, {0, 6, 5, 2}, {0, 6, 5, 6}};
    int Available[4] = {1, 5, 2, 0};

    cout << "Process buriin need martix ni:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++) {
            Need[i][j] = max[i][j] - Allocation[i][j];
            cout << Need[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


       // Check if P1 process can make the request
    int requestProcessIndex = 1; // Process P1
    int requestResource[4] = {0, 4, 2, 0}; // Requested resources

    bool canAllocate = true;

    // Хүссэн нөөц нь process хэрэгцээнээс давсан эсэхийг шалгана уу
    for (int j = 0; j < m; j++) {
        if (requestResource[j] > Need[requestProcessIndex][j]) {
            canAllocate = false;
            break;
        }
    }

    if (canAllocate) {
        // Хүссэн нөөц боломжит нөөцөөс хэтэрсэн эсэхийг шалгана уу
        for (int j = 0; j < m; j++) {
            if (requestResource[j] > Available[j]) {
                canAllocate = false;
                break;
            }
        }
    }

    // deadlock uusghiin tuld Allocation matrix iig uurchlunu
    Allocation[0][2] = 0; // P0 процесс нь С нөөцийг гаргадаг

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Need[i][j] = max[i][j] - Allocation[i][j];
        }
    }

    int y = 0;

    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (Need[i][j] > Available[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind] = i;
                    ind += 1;
                    for (int y = 0; y < m; y++) {
                        Available[y] += Allocation[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    cout << "Deadlock oldloo, daraalal n :\n";

    for (int i = 0; i < n - 1; i++) {
        cout << " P" << ans[i] << " ->";
    }
    cout << " P" << ans[n - 1] << endl;

    return 0;
}
