#include "math.h"
#include <iostream>
#include <string>

using namespace std;

class Pair 
{
protected:
    double x;
    double y;
public:
    Pair(double x, double y) 
    {
        this->x = x;
        this->y = y;
    }

    int compare(const Pair &other) const //сравнение
    {
        double len1 = sqrt(x * x + y * y);
        double len2 = sqrt(other.x * other.x + other.y * other.y);

        if (len1 == len2)
            return 0;
        else return len1 < len2 ? -1 : 1;
    }

    friend string pairtToString(const Pair &pair)// ф-ция вывода
    {
        return  "X: " + to_string(pair.x) + "  Y: "  + to_string(pair.y);
    }

    friend void pairtToString(Pair &pair, int x, int y) // ф-ция ввода
    {
        pair.x = x;
        pair.y = y;
    }

    friend bool operator ==(const Pair &pair1, const Pair &pair2) 
    {
        return pair1.compare(pair2) == 0;
    }

    friend bool operator !=(const Pair &pair1, const Pair &pair2) 
    {
        return !(pair1 == pair2);
    }

    friend bool operator < (const Pair &pair1, const Pair &pair2) 
    {
        return pair1.compare(pair2) == -1;
    }

    friend bool operator > (const Pair &pair1, const Pair &pair2) 
    {
        return pair1.compare(pair2) == 1;
    }

    friend bool operator <= (const Pair &pair1, const Pair &pair2)
    {
        return pair1 < pair2 || pair1 == pair2;
    }

    friend bool operator >= (const Pair &pair1, const Pair &pair2) 
    {
        return pair1 > pair2 || pair1 == pair2;
    }

};


class Point : public Pair 
{
public:

    Point(double x, double y) : Pair(x, y) 
    {

    }

    void setX(double x) //перемещение точки по х
    {
        this->x = x;
    }

    void setY(double y) //перемещение точки по y
    {
        this->y = y;
    }

    double distanceFromStart() //расстояние от начала координат
    {
        return sqrt(x * x + y * y);
    }

    double distanceToPoint(const Point &othPoint) //расстояние до точки
    {
        double x2 = x - othPoint.x;
        double y2 = y - othPoint.y;

        return sqrt(x2 * x2 + y2 * y2);
    }

    double getPolarAngle() //нахождение полярного угла
    {
        return x == 0 && y == 0 ? 0 : atan2(x, y);
    }

    double getPolarRadius() //полярный радиус
    {
        return distanceFromStart();
    }

    bool isIdentical(const Point &othPoint) const //сравненеие на совпадение
    {
        return compare(othPoint) == 0 ? 1 : 0;
    }

    friend bool operator ==(const Point &pair1, const Point &pair2) 
    {
        return pair1.isIdentical(pair2);
    }

    friend bool operator !=(const Point &pair1, const Point &pair2) 
    {
        return !(pair1 == pair2);
    }

};

int main()
{
    Pair Tochka(100, 100);
    Pair Com(1, 1);

    pairtToString(Tochka);
    pairtToString(Com);

    cout << "== " << (Tochka == Com) << endl;
    cout << "!= " << (Tochka != Com) << endl;
    cout << "> " << (Tochka > Com) << endl;
    cout << "< " << (Tochka < Com) << endl;
    cout << ">= " << (Tochka >= Com) << endl;
    cout << "<= " << (Tochka <= Com) << endl;

}