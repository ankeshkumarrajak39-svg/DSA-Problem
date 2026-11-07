
#include <iostream>
using namespace std;

// Function to check bad version
int badVersion = 4;  // First bad version

bool isBadVersion(int version) {
    return version >= badVersion;
}

int firstBadVersion(int n) {
    int low = 1;
    int high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isBadVersion(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n = 5;

    cout << "First Bad Version: " << firstBadVersion(n);

    return 0;
}
