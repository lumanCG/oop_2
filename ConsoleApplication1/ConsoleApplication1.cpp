#include <iostream>
#include <conio.h>



using namespace std;



class Point {
protected:
    int x;
    int y;
public:
    Point() : x(0), y(0) {
        printf("Point()\n");
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;

        printf("Point(int x, int y)\n");
    }
    Point(const Point& p) : x(p.x), y(p.y) {
        printf("Point(Point &p)\n");
    }
    ~Point() {
        printf("%d, %d\n", x, y);
        printf("~Point()\n");
    }

    void reset()
    {
        x = 0;
        y = 0;
    }
    void showCord();
};

void Point::showCord() {
    printf("Point coord: (%d, %d)\n", x, y);
}



class Name : public Point {
protected:
    char name;
public:
    Name() : Point(), name(0) {
        printf("Name()\n");
    }
    Name(int x, int y, char name) : Point(x, y), name(name) {
        printf("Name(int x, int y)\n");
        //this->name = name;
    }
    Name(const Name& p) : Point(p), name(p.name) {
        printf("Name(Name &p)\n");
        /*x = p.x;
        y = p.y;
        name = p.name;*/
    }
    ~Name() {
        printf("%d, %d; name = %c\n", x, y, name);
        printf("~Name()\n");
    }

    void changeName(char newName) {
        name = newName;
    }
};


class Otrezok {
protected:
    Point* p1;
    Point* p2;
public:
    Otrezok() {
        printf("Otrezok()\n");
    }
    Otrezok(int x1, int y1, int x2, int y2) : p1(new Point(x1, y1)), p2(new Point(x2, y2)) {
        printf("Otrezok(int x1, int y1, int x2, int y2)\n");
        //p1 = new Point(x1, y1))
    }
    Otrezok(const Otrezok& s) : p1(new Point(*(s.p1))), p2(new Point(*(s.p2))) {
        printf("Otrezok(Otrezok &p)\n");
        //p1 = new Point(*(s.p1));
        //p2 = new Point(*(s.p2));
    }
    ~Otrezok() {
        delete p1;
        delete p2;
        printf("~Otrezok()\n");
    }
};


class Triangle {
protected:
    Point p1;
    Point p2;
    Point p3;
public:
    Triangle() {
        printf("Triangle()\n");
    }
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : p1(x1, y1), p2(x2, y2), p3(x3, y3) {
        printf("Triangle(int x1, int y1, int x2, int y2, int x3, int y3)\n");
    }
    Triangle(const Triangle& p) : p1(p.p1), p2(p.p2), p3(p.p3) {
        printf("Triangle(Triangle &p)\n");
        // p1 = p.p1
    }
    ~Triangle() {
        printf("~Triangle()\n");
    }

};


int main() {
    setlocale(LC_ALL, "RU");

    cout << endl << "[Static Point]" << endl;
    {
        Point p1;
        Point p2(2, 28);
        Point p3(p2);

        p2.showCord();
        p2.reset();
        p2.showCord();
    }
    cout << endl << "[Dynamic Point]" << endl;
    Point* p1 = new Point();
    Point* p2 = new Point(1, 2);
    Point* p3 = new Point(*p2);
    delete p1;
    delete p2;
    delete p3;

    cout << endl << "[Name :: Point]" << endl;
    Name* n = new Name(1, 2, 'A');
    n->changeName('B');
    delete n;

    cout << endl << "[Otrezok (dynamic Point)]" << endl;
    Otrezok* z2 = new Otrezok(1, 2, 3, 4);
    Otrezok* z3 = new Otrezok(*z2);
    delete z2;
    delete z3;

    cout << endl << "[Triangle (static Point)]" << endl;
    Triangle* t2 = new Triangle(1, 1, 2, 2, 3, 3);
    Triangle* t3 = new Triangle(*t2);
    delete t2;
    delete t3;






    int i;
    cin >> i;
    return 0;
}