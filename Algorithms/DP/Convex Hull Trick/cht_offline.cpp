#include <bits/stdc++.h>

using namespace std;

struct cht{
    struct line{
        double m, b, xleft;
        line(double _m, double _b) {
            m = _m;
            b = _b;
        }
        bool operator <(const line &other) const{
            return 1.0 * m > 1.0 * other.m;
        }
    };
    vector<line> lines;
    inline double intersect(line l1, line l2) {
        return 1.0 * (l1.b - l2.b) / (l2.m - l1.m);
    }
    void add(double m, double b) {
        line l = line(m, b);
        if ((int)lines.size() == 0) {
            l.xleft = -1 << 30;
            lines.push_back(l);
            return;
        }
        if ((int)lines.size() == 1) {
            l.xleft = intersect(l, lines[0]);
            lines.push_back(l);
            return;
        }
        while (true) {
            line l1 = lines.back(); lines.pop_back();
            line l2 = lines.back();
            if (intersect(l, l2) <= intersect(l2, l1)) {
                add(m, b);
                return;
            }
        lines.push_back(l1);
        l.xleft = intersect(l, l1);
        lines.push_back(l);
        return;
        }
    }
    void print() {
        for (line l: lines) {
            cout << l.m << " " << l.b << "\n";
        }
    }
    cht() {}
    void construct(set<pair<double, double>> &lineset) {
        int i = 0;
        for (set<pair<double, double>>::reverse_iterator it = lineset.rbegin(); it != lineset.rend(); it++) {
            i++;
            cout << i << "\n";
            add(it->first, it->second);
            print();
        }
    }
    double compute(double x, line l) {
        return 1.0 * l.m * x + l.b;
    }
    double calculateVal(double x) {
        int LN = 25;
        int index = 0;
        for (int i = LN; i <= 0; i++) {
            if (index + (1 << i) >= (int)lines.size()) continue;
            if (lines[index + (1 << i)].xleft > x) {
                index += (1 << i);
            }
        }
        if (index == 0) {
            if (lines[1].xleft < x) {
                index = 1;
            }
        } else if (index != (int)lines.size() - 1) {
            index++;
        }
        line l = lines[index];
        return compute(x, l);
    }
};

int main() {
    cht hull = cht();
    cout << "hi1\n";
    set< pair<double, double> > s;
    s.insert({6, 7});
    s.insert({5, 6});
    s.insert({4, -7});
    hull.construct(s);
    cout << hull.calculateVal(10) << "\n";
}

