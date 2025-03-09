
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
protected:
    int h, w, l;
public:
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
    void size(int dh, int dw, int dl) {
        h = h + dh;
        w = w + dw;
        l = l + dl;
    }
    void sizedouble();

};

void cube::sizedouble() {
    h = h * 2;
    w = w * 2;
    l = l * 2;
}

class Coloredcube:public cube {
protected:
    int color;
public:
    Coloredcube() : cube() {
        printf("Coloredcube()\n");
        color = 0;
    }
    Coloredcube(int h, int w, int l, int color) : cube(h, w, l) {
        printf("Coloredcube(int h, int w, int l, int color)\n");
        this->color = color;
    }
    Coloredcube(const Coloredcube& p) {
        printf("Coloredcube(const cube &p)\n");
        color = p.color;
        h = p.h;
        w = p.w;
        l = p.l;
    }
    ~Coloredcube() {
        printf("%d, %d, %d color=%d\n", h, w, l, color);
        printf("~Coloredcube()\n");
    }
    void chcolor(int new_color) {
        color = new_color;
    }   

};
int main()
{
    {
        ball b;
        ball b2(10, 1);
        ball b3(b2);
    }
    cube *c = new cube;
    cube *c2 = new cube(10, 20, 30);
    cube *c3 = new cube(*c2);

    //c->h = 5; protected, нельзя обратиться

    delete c;
    delete c2;
    delete c3;

    cube* c4 = new cube(10, 10, 10);
    c4->sizedouble();
    c4->size(1, -5, 4);

    delete c4;

    Coloredcube *p = new Coloredcube(10, 10, 10, 30);
    p->chcolor(45);
    
    delete p;

    cube *p1 = new Coloredcube(10, 10, 20, 45);
    Coloredcube* p2 = new Coloredcube(10, 10, 20, 45);

    delete p1;
    delete p2;

   
    _getch();
    return 0;
}

