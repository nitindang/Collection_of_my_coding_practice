#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 3;

struct Point {
    int x;
    int y;

    Point() = default;

    Point(int a, int b) : x(a), y(b) {}
};

bool operator==(const Point &a, const Point &b) {
    return (a.x == b.x && a.y == b.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    vector<Point> A(MAXN);
    for (int i = 0; i < MAXN; ++i) {
        cin >> A[i].x >> A[i].y;
    }

    sort(A.begin(), A.end(), [](const Point &A, const Point &B) -> bool {
        return A.x < B.x;
    });
    int a = A[0].x;
    int h = A[2].x - a;

    sort(A.begin(), A.end(), [](const Point &A, const Point &B) -> bool {
        return A.y < B.y;
    });
    int b = A[0].y;
    int w = A[2].y - b;

    vector<Point> rec(MAXN + 1);
    rec[0] = Point(a, b);
    rec[1] = Point(a, b + w);
    rec[2] = Point(a + h, b);
    rec[3] = Point(a + h, b + w);

    bool hasIt = false;
    for (int i = 0; i < MAXN + 1; ++i) {
        hasIt = false;
        for (int j = 0; j < MAXN; ++j) {
            if (rec[i] == A[j]) {
                hasIt = true;
                break;
            }
        }
        if (!hasIt) {
            cout << rec[i].x << ' ' << rec[i].y << endl;
            break;
        }
    }

    return 0;
}
