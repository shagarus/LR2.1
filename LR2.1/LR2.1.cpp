
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
        printf("ball(const gball &p)\n");
        m = p.m;
        r = p.r;
    }
    ~ball() {
        printf("%d, %d\n", m, r);
        printf("~ball()\n");
    }
};
int main()
{
    {
        ball b;
        ball b2(10, 1);
        ball b3(b2);
    }
    

    _getch();
    return 0;
}

