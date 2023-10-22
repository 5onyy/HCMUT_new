class Point
{
private:
    double x, y;

public:
    Point()
    {
        x = y = 0;
    }

    Point(double x, double y)
    {
        this->x = x;    this->y = y;
    }

    void setX(double x)
    {
        this->x = x;
    }

    void setY(double y)
    {
        this->y = y;
    }

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        return sqrt((x-pointA.x)*(x-pointA.x) + (y-pointA.y)*(y-pointA.y));
    }
};