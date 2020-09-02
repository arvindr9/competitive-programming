// From Neal Wu's submission: https://codeforces.com/contest/1107/submission/49036431

template<typename T>
struct RMQ {
    int n = 0, levels = 0;
    vector<T> values;
    vector<vector<int>> range_high;
 
    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }
 
    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }
 
    int max_index(int a, int b) const {
        return values[a] > values[b] ? a : b;
    }
 
    void build(const vector<T> &_values) {
        values = _values;
        n = values.size();
        levels = largest_bit(n) + 1;
        range_high.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_high[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_high[0][i] = i;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_high[k][i] = max_index(range_high[k - 1][i], range_high[k - 1][i + (1 << (k - 1))]);
    }
 
    int rmq_index(int a, int b) const {
        assert(a < b);
        int level = largest_bit(b - a);
        return max_index(range_high[level][a], range_high[level][b - (1 << level)]);
    }
 
    T rmq_value(int a, int b) const {
        return values[rmq_index(a, b)];
    }
};
