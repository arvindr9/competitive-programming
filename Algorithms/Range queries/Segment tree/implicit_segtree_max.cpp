/*
Modified version of implicit segtree from cp-algorithms

Supports point update, range update, range query. Cannot decrease the value of any elements. Not tested!

*/
#include <bits/stdc++.h>

struct Vertex {
    int left, right, mx, lazy;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(int lb, int rb, int _lazy = 0) {
        left = lb;
        right = rb;
        mx = 0;
        lazy = _lazy;
    }

    void pull() {
        if (left_child) mx = max(left_child->mx, right_child->mx);
    }

    void extend() {
        if (!left_child && left < right) {
            int t = (left + right) / 2;
            left_child = new Vertex(left, t, lazy);
            right_child = new Vertex(t + 1, right, lazy);
        }
        if (left_child) {
            left_child->lazy = max(lazy, left_child->lazy);
            right_child->lazy = max(lazy, right_child->lazy);
            left_child->mx = max(left_child->mx, left_child->lazy);
            right_child->mx = max(left_child->mx, left_child->lazy);
            lazy = 0;
        }
    }

    void update(int k, int x) {
        extend();
        mx = max(mx, x);
        if (left_child) {
            if (k <= left_child->right)
                left_child->update(k, x);
            else
                right_child->update(k, x);
        }
    }

    void update(int l, int r, int x) {
        if (l > r) return;
        if (l > right or r < left) return;
        if (l <= left and r >= right) {
            lazy = max(x, lazy);
            mx = max(mx, lazy);
        } else {
            mx = max(mx, x);

            extend();
            int t = ((left + right) / 2);
            left_child->update(l, min(r, t), x);
            right_child->update(max(l, t + 1), r, x);
            pull();
        }
    }

    int get_max(int lq, int rq) {
        if (lq <= left && right <= rq) {
            return max(mx, lazy);
        }
        if (max(left, lq) > min(right, rq))
            return 0;
        extend();
        return max(left_child->get_max(lq, rq), right_child->get_max(lq, rq));
    }

};

void printupd(int l, int r, int x) {
    cout << "setting " << l << "--" << r << " to " << x << "\n";
}

void printresult(int x, int res) {
    cout << "result at " << x << ": " << res << "\n";
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 30;
    Vertex* v = new Vertex(0, n);
    v->update(9, 12, 3);
    printupd(9, 12, 3);
    int res = v->get_max(12, 12);
    printresult(12, res);

}