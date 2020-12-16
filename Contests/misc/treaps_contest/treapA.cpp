// based off kactl's template

#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second

struct Node {
    Node *l = 0, *r = 0;
    int val, y, c = 1;
    Node(int val): val(val), y(rand()) {}
    void recalc();
};

int cnt(Node *n) {
    return n ? n->c : 0;
}

void Node::recalc() {
    c = cnt(l) + cnt(r) + 1;
}

template<class F> void each(Node *n, F f) {
    if (n) { each(n -> l, f); f(n->val), each(n->r, f);}
}

pair<Node*, Node*> split(Node* n, int k) {
    if (!n) return {};
    if (cnt(n->l) >= k) {
        auto pa = split(n->l, k);
        n->l = pa.s;
        n->recalc();
        return {pa.f, n};
    } else {
        auto pa = split(n->r, k - cnt(n->l) - 1);
        n->r = pa.f;
        n->recalc();
        return {n, pa.s};
    }
}

Node* merge(Node* l, Node *r) {
    if (!l) return r;
    if (!r) return l;
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        l->recalc();
        return l;
    } else {
        r->l = merge(l, r->l);
        r->recalc();
        return r;
    }
}

Node* ins(Node *t, Node* n, int pos) {
    auto pa = split(t, pos);
    return merge(merge(pa.f, n), pa.s);
}

void move(Node* &t, int l, int r, int pos) {
    Node *a, *b, *c;
    tie(a, b) = split(t, l);
    tie(b, c) = split(b, r - l);
    if (pos <= l) {
        t = merge(ins(a, b, pos), c);
    } else {
        t = merge(a, ins(c, b, pos - r));
    }
}

void print(int x) {
    cout << x << " ";
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    Node* t = 0;
    for (int i = 0; i < n; i++) {
        t = ins(t, new Node(i + 1), i);
        // each(t, print);
        // cout << "\n";
    }


    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a >= b) continue;
        int l1 = a;
        int interval_length = min(n - b, b - a);
        int r1 = l1 + interval_length;
        int l2 = b;
        int r2 = b + interval_length;
        // cout << "l1: " << l1 << ", r1: " << r1 << ", l2: " << l2 << ", r2: " << r2 << "\n";
        // idea: swap [l1, r1) with [l2, r2)
        move(t, l1, r1, l2);
        move(t, l2, r2, l1);

        // idea: swap [a, b) with [b, b + b - a), i.e. move [b, b + b - a) to a
        // move(t, b, b + b - a, a);
        // each(t, print);
        // cout << "\n";
    }

    each(t, print);
    cout << "\n";


}