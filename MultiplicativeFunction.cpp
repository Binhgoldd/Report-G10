// Bùi Thế Thanh Bình
// 25119058
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 11;
int sieve[MN];
pair<int, int> pk[MN];
int ndiv[MN];
long long binh[1000001];
int dem, l, r;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> r;
    for (int i = 2; i <= r; ++i)
        if (!sieve[i])
        {
            for (int j = i; j <= r / i; ++j)
                sieve[i * j] = i;
        }
    ndiv[1] = 1;
    binh[1] = 1;
    for (int i = 2; i <= r; ++i)
    {
        if (!sieve[i])
        {
            pk[i] = make_pair(i, 1);
            ndiv[i] = 2;     // số lượng ước
            binh[i] = i + 1; // tổng ước
        }
        else
        {
            int p = sieve[i];
            if (pk[i / p].first == p)
            {
                pk[i] = make_pair(p, pk[i / p].second + 1);
                ndiv[i] = pk[i].second + 1;
                binh[i] = ((long long)pow(p, pk[i].second + 1) - 1) / (p - 1);
            }
            else
            {
                pk[i] = make_pair(-1, 0);
                int u = i, v = 1;
                while (u % p == 0)
                {
                    u /= p;
                    v = v * p;
                }
                binh[i] = binh[u] * binh[v];
            }
        }
    }
    for (int i = l; i <= r; ++i)
    {
        if (binh[i] - i > i)
            ++dem;
    }
    cout << dem;
    return 0;
}
