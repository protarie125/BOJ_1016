#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll Min, Max;
    cin >> Min >> Max;
    auto k = Max - Min + 1;
    vb memo(k, true);

    int count{ 0 };
    ll d = 2;
    ll d2 = d * d;
    while (d2 <= Max) {
        auto i = (Min / d2) * d2;
        if (i < Min)
            i += d2;

        auto j = i;
        while (j - Min < k) {
            if (memo[j - Min]) {
                memo[j - Min] = false;
                count += 1;
            }

            j += d2;
        }

        d += 1;
        d2 = d * d;
    }

    cout << k - count;

    return 0;
}