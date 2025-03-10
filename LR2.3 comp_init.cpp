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
    Point pbeg;
    Point pend;
public:
    Section() : pbeg(), pend() {
        printf("Section()\n");
    }
    Section(int x1, int y1, int x2, int y2)
        : pbeg(x1, y1), pend(x2, y2) {
        printf("Section(int x1, int y1, int x2, int y2)\n");
    }
    Section(const Section &s)
        : pbeg(s.pbeg), pend(s.pend) {
        printf("Section(const Section &s)\n");
    }
    ~Section(){
        printf("~Section()\n");
    }
};

int main(){
    //Композиция объектов
    //Атрибут в наследнике не указатель, а объект, инициализируется в списке инициализации
    Section *s1 = new Section(1, 2, 3, 4);
    Section *s2 = new Section(*s1);

    delete s1;
    delete s2;

    return 0;
}