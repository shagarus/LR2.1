#include <iostream>


class Point{
protected:
    int x, y;
public:
    Point(){
        printf("Point()\n");
        x = 0;
        y = 0;
    }
    Point(int x, int y){
        printf("Point(int x, int y)\n");
        this->x = x;
        this->y = y;
    }
    Point(const Point &p){
        printf("Point(const Point &p)\n");
        x = p.x;
        y = p.y;
    }
    ~Point(){
        printf("%d, %d\n", x, y);
        printf("~Point()\n");
    }
    void change(int dx, int dy){
        x = dx;
        y = dy;
    }
    void reset();
};

void Point::reset(){
    x = 0;
    y = 0;
}

class Section{
protected:
    Point *pbeg;
    Point *pend;
public:
    Section(){
        printf("Section()\n");
        pbeg = new Point;
        pend = new Point;
    }
    Section(int x1, int y1, int x2, int y2){
        printf("Section(int x1, int y1, int x2, int y2)\n");
        pbeg = new Point(x1, y1);
        pend = new Point(x2, y2);
    }
    Section(const Section &s){
        printf("Section(const Section &s)\n");
        pbeg = new Point(*(s.pbeg));
        pend = new Point(*(s.pend));
    }
    ~Section(){
        printf("~Section()\n");
        delete pbeg;
        delete pend;
    }
};

int main(){
    //Композиция с глубоким копированием
    Section *s1 = new Section;
    Section *s2 = new Section(*s1);

    delete s1;
    delete s2;

    return 0;
}