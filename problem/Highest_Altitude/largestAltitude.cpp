#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int alt = 0;
        int best = 0;

        for (int g : gain)
        {
            alt += g;
            if (alt > best)
                best = alt;
        }
        return best;
    }
};