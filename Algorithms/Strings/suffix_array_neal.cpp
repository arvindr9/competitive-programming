// Source: https://codeforces.com/contest/1314/submission/71724665

template<typename T_string = string>
struct suffix_array {
    int n = 0;
    T_string str;
    vector<int> suffix;
    vector<int> rank;
    vector<int> lcp;
    RMQ<int> rmq;
 
    suffix_array() {}
 
    suffix_array(const T_string &_str, bool build_rmq = true) {
        build(_str, build_rmq);
    }
 
    void build(const T_string &_str, bool build_rmq = true) {
        str = _str;
        n = str.size();
        suffix.resize(n);
 
        for (int i = 0; i < n; i++)
            suffix[i] = i;
 
        bool large_alphabet = false;
 
        for (int i = 0; i < n; i++)
            if (str[i] < 0 || str[i] >= 128)
                large_alphabet = true;
 
        // Sort each suffix by the first character.
        if (large_alphabet) {
            sort(suffix.begin(), suffix.end(), [&](int a, int b) {
                return str[a] < str[b];
            });
        } else {
            vector<int> freq(128, 0);
 
            for (int i = 0; i < n; i++)
                freq[str[i]]++;
 
            for (int c = 1; c < 128; c++)
                freq[c] += freq[c - 1];
 
            for (int i = 0; i < n; i++)
                suffix[--freq[str[i]]] = i;
        }
 
        // Compute the rank of each suffix. Tied suffixes share the same rank.
        rank.resize(n);
        rank[suffix[0]] = 0;
 
        for (int i = 1; i < n; i++)
            rank[suffix[i]] = str[suffix[i]] == str[suffix[i - 1]] ? rank[suffix[i - 1]] : i;
 
        vector<int> next_index(n);
        vector<int> values(n);
        bool done = false;
 
        for (int len = 1; len < n && !done; len *= 2) {
            // next_index[i] = the next index to use for a suffix of rank i. We insert them in order of the rank of the
            // suffix that comes len characters after the current suffix.
            for (int i = 0; i < n; i++)
                next_index[i] = i;
 
            // Compute the suffix array for 2 * len. Suffixes of length <= len are prioritized first.
            for (int i = n - len; i < n; i++)
                values[next_index[rank[i]]++] = i;
 
            for (int i = 0; i < n; i++) {
                int prev = suffix[i] - len;
 
                if (prev >= 0)
                    values[next_index[rank[prev]]++] = prev;
            }
 
            swap(suffix, values);
 
            // Compute the rank array for 2 * len.
            values[suffix[0]] = 0;
            done = true;
 
            for (int i = 1; i < n; i++) {
                int s = suffix[i], prev = suffix[i - 1];
 
                if (s + len < n && prev + len < n && rank[s] == rank[prev] && rank[s + len] == rank[prev + len]) {
                    values[s] = values[prev];
                    done = false;
                } else {
                    values[s] = i;
                }
            }
 
            swap(rank, values);
        }
 
        compute_lcp();
 
        if (build_rmq)
            rmq.build(lcp);
    }
 
    void compute_lcp() {
        lcp.assign(n, 0);
        int match = 0;
 
        for (int i = 0; i < n; i++) {
            if (rank[i] == 0)
                continue;
 
            int a = suffix[rank[i]] + match;
            int b = suffix[rank[i] - 1] + match;
 
            while (a < n && b < n && str[a++] == str[b++])
                match++;
 
            // lcp[r] = the longest common prefix length of the suffixes starting at suffix[r] and at suffix[r - 1].
            lcp[rank[i]] = match;
            match = max(match - 1, 0);
        }
    }
 
    int get_lcp_from_ranks(int a, int b) const {
        if (a == b)
            return n - suffix[a];
 
        if (a > b)
            swap(a, b);
 
        return rmq.query_value(a + 1, b + 1);
    }
 
    int get_lcp(int a, int b) const {
        if (a >= n || b >= n)
            return 0;
 
        if (a == b)
            return n - a;
 
        return get_lcp_from_ranks(rank[a], rank[b]);
    }
 
    // Compares the substrings starting at `a` and `b` up to `length`.
    int compare(int a, int b, int length = -1) const {
        if (length < 0)
            length = n;
 
        if (a == b)
            return 0;
 
        int common = get_lcp(a, b);
 
        if (common >= length)
            return 0;
 
        if (a + common >= n || b + common >= n)
            return a + common >= n ? -1 : 1;
 
        return str[a + common] < str[b + common] ? -1 : (str[a + common] == str[b + common] ? 0 : 1);
    }
};
 