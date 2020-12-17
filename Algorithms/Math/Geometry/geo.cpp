struct pt {
    T x, y;
    pt(T x, T y): x(x), y(y) {}
};

T dist2(pt p1, pt p2) {
    T dx = p1.x - p2.x;
    T dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}