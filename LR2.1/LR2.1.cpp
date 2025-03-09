
#include <iostream>
#include <conio.h>

class ball {
public:
    int m, r;
    ball() {
        printf("ball()\n");
        m = 0;
        r = 0;
    }
    ball(int m, int r) {
        printf("ball(int m, int r)\n");
        this->m = m;
        this->r = r;
    }
    ball(const ball &p) {
        printf("ball(const ball &p)\n");
        m = p.m;
        r = p.r;
    }
    ~ball() {
        printf("%d, %d\n", m, r);
        printf("~ball()\n");
    }
};
class cube {
public:
    int h, w, l;
    cube() {
        printf("cube()\n");
        h = 0;
        w = 0;
        l = 0;
    }
    cube(int h, int w, int l) {
        printf("cube(int h, int w, int l)\n");
        this->h = h;
        this->w = w;
        this->l = l;
    }
    cube(const cube& p) {
        printf("cube(const cube &p)\n");
        h = p.h;
        w = p.w;
        l = p.l;
    }
    ~cube() {
        printf("%d, %d, %d\n", h, w, l);
        printf("~cube()\n");
    }
};
int main()
{
    {
        ball b;
        ball b2(10, 1);
        ball b3(b2);
    }
    cube *p = new cube;
    cube *p2 = new cube(10, 20, 30);
    cube *p3 = new cube(*p2);

    delete p;
    delete p2;
    delete p3;

    _getch();
    return 0;
}

