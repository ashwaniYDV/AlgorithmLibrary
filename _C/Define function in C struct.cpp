struct point
{
    int x;
    int y;
    void (*print)(const struct point*);
};

void sum(const struct point* p)
{
    cout << "x + y = " << p->x + p->y << endl;
}

void dif(const struct point* p)
{
    cout << "x - y = " << p->x - p->y << endl;
}

void solve() {
	struct point p1 = { 2, 4, sum };
    struct point p2 = { 7, 3, dif };

    p1.print(&p1);
    p2.print(&p2);
}
