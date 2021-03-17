struct point
{
    int x;
    int y;
    void (*print)(const struct point*);
};

void print_x(const struct point* p)
{
    cout << "x =" << p->x << endl;
}

void print_y(const struct point* p)
{
    cout << "y =" << p->y << endl;
}

void solve() {
	struct point p1 = { 2, 4, print_x };
    struct point p2 = { 7, 1, print_y };

    p1.print(&p1);
    p2.print(&p2);
}
