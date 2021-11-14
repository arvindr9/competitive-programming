const int maxn = 1001;
int t[4*maxn][4*maxn], a[maxn][maxn];

template<class T> struct segtree_2d {
    int n, m;
    T deft;
    segtree_2d() {}
    segtree_2d(int _n, int _m): n(_n), m(_m), deft(inf) {
        for (int i = 0; i < 4 * maxn; i++) {
            for (int j =0; j < 4 * maxn; j++) {
                t[i][j] = inf;
            }
        }
    }

    T f(int a, int b) {
        return min(a, b);
    }

    void pullx(int vx, int vy) {
        t[vx][vy] = f(t[2*vx][vy], t[2*vx+1][vy]);
    }

    void pully(int vx, int vy) {
        t[vx][vy] = f(t[vx][2*vy], t[vx][2*vy+1]);
    }

    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, T new_val) {
        if (ly == ry) {
            if (lx == rx) {
                t[vx][vy] = new_val;
            } else {
                pullx(vx, vy);
            }
        } else {
            int my = (ly + ry) / 2;
            if (y <= my) update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
            else update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
            pully(vx, vy);
        }
    }

    void update_x(int vx, int lx, int rx, int x, int y, T new_val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx) update_x(vx * 2, lx, mx, x, y, new_val);
            else update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
        }
        update_y(vx, lx, rx, 1, 0, m, x, y, new_val);
    }

    T query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) {
            return deft;
        }
        if (ly == tly and ry == try_) {
            // cout << "ly: " << ly << ", ry: " << ry << ", vx: " << vx << "\n";
            // cout << "t: " << t[vx][vy] << "\n";
            return t[vx][vy];
        }
        int tmy = (tly + try_) / 2;
        return f(
            query_y(vx,  vy*2, tly, tmy, ly, min(tmy, ry)),
            query_y(vx, vy*2 + 1, tmy+1, try_, max(tmy+1, ly), ry)
        );
    }

    T query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx) return deft;
        if (lx == tlx and rx == trx) {
            return query_y(vx, 1, 0, m, ly, ry);
        }
        int tmx = (tlx + trx) / 2;
        return f(
            query_x(2*vx, tlx, tmx, lx, min(rx, tmx), ly, ry),
            query_x(2*vx+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry)
        );
    }

    void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx)
                t[vx][vy] = a[lx][ly];
            else
                pullx(vx, vy);
        } else {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, vy*2, ly, my);
            build_y(vx, lx, rx, vy*2+1, my+1, ry);
            pully(vx, vy);
        }
    }

    void build_x(int vx, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(vx*2, lx, mx);
            build_x(vx*2+1, mx+1, rx);
        }
        build_y(vx, lx, rx, 1, 0, m);
    }

    void update(int x, int y, T new_val) {
        update_x(1, 0, n, x, y, new_val);
    }

    T query(int lx, int rx, int ly, int ry) {
        return query_x(1, 0, n, lx, rx, ly, ry);
    }
    void build() {
        build_x(1, 0, n);
    }
};