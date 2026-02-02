class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        int n = squares.size();
        if (!n)
            return 0;

        double l = INT_MAX, r = INT_MIN, delta = 1e-5;
        for (const auto &s : squares)
        {
            double y0 = s[1], len = s[2], y1 = y0 + len;
            l = min(l, y0);
            r = max(r, y1);
        }
        while (r - l > delta)
        {
            double mid = l + (r - l) / 2;
            if (validate(squares, mid))
                r = mid;
            else
                l = mid;
        }
        return l;
    }

    bool validate(const vector<vector<int>> &squares, double y)
    {
        double lo = 0, hi = 0;
        for (const auto &s : squares)
        {
            double y0 = s[1], len = s[2], y1 = y0 + len;
            lo += max(0.0, (min(y1, y) - y0) * len);
            hi += max(0.0, (y1 - max(y, y0)) * len);
        }
        return lo >= hi;
    }
};