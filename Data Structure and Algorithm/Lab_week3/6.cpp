// Given a list of points on the 2-D plane (points[] with n elements) and an integer k. Your task in this exercise is to implement the closestKPoints function to find K closest points to the given point (des_point) and print them by descending order of distances.

// Prototype of closestKPoints:



// void closestKPoints(Point points[], int n, Point& des_point, int k);
// Note: The distance between two points on a plane is the Euclidean distance.

// Template:

// #include <iostream>
// #include <string>
// #include <cmath>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Point{
//    public:
//    int x, y;
//    Point(int x = 0, int y = 0){
//       this->x = x;
//       this->y = y;
//    }
//    void display(){
//       cout << "("<<x<<", "<<y<<")";
//    }
// };


// For example:

// Test	Result
// Point points[] = {{3, 3},{5, -1},{-2, 4}};
// int n = sizeof(points)/sizeof(points[0]);
// int k = 2;
// Point des_point = {0,2};
// closestKPoints(points, n, des_point, k);
// (-2, 4)
// (3, 3)
// Point points[] = {{3, 3},{5, -1},{-2, 4}};
// int n = sizeof(points)/sizeof(points[0]);
// int k = 3;
// Point des_point = {0,2};
// closestKPoints(points, n, des_point, k);
// (-2, 4)
// (3, 3)
// (5, -1)


struct PointWithDistance {
    Point p;
    double distance;
};

// Calculate Euclidean distance between two points
double getDistance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Compare function to sort PointWithDistance based on distance in ascending order
bool compare(const PointWithDistance& p1, const PointWithDistance& p2) {
    return p1.distance < p2.distance;  // Changing this to '<' for ascending order
}

void closestKPoints(Point points[], int n, Point& des_point, int k) {
    vector<PointWithDistance> pointDistances;

    // Fill the pointDistances vector with the points and their distances
    for (int i = 0; i < n; i++) {
        PointWithDistance pwd;
        pwd.p = points[i];
        pwd.distance = getDistance(points[i], des_point);
        pointDistances.push_back(pwd);
    }

    // Sort the pointDistances based on distance
    sort(pointDistances.begin(), pointDistances.end(), compare);

    // Print the top k points
    for (int i = 0; i < k && i < n; i++) {
        pointDistances[i].p.display();
        cout<<endl;
    }
}
