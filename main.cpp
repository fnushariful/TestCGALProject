#include "DrawUsingQt.h"
#include "CGALComponents.h"
#include "QuadraticTimeClosestPair.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); /*** Warning! Do not delete this line. Otherwise, QT GUI won't start!! ***/

    unsigned N = 1000;
    std::vector<Point> P;
    std::cout << "Point generation started..." << std::endl;
    generatePointsInsideASquare(N,500,P);
    std::cout << "Point generation is complete." << std::endl;

    std::sort(P.begin(),P.end());

    auto pointsToIdsMap = createMapOfPoints(P);

    std::cout << "\nFinding the closest pair..." << std::endl;
    CGAL::Timer clock;
    clock.start();
    std::pair closestPair = findClosestPairQuadratic(P);
    clock.stop();
    std::cout << "Found the closest pair in " << clock.time() << " seconds." << std::endl;

    std::vector<unsigned> idsOfSpecialPoints;
    idsOfSpecialPoints.push_back(closestPair.first);
    idsOfSpecialPoints.push_back(closestPair.second);

    std::cout << P[closestPair.first] << ", " << P[closestPair.second] << std::endl;
    std::cout << P[pointsToIdsMap[P[closestPair.first]]] << ", " << P[pointsToIdsMap[P[closestPair.second]]] << std::endl;

    draw(P,idsOfSpecialPoints,false);
}

/*#include <iostream>
#include <string>
#include "Myheader.h"

#include <vector>

unsigned square(int i){
    return i * i;
}

namespace unf {
    class Circle {
        double xOfCenter, yOfCenter, radius;
    };
}

namespace ucf {
    class Circle {
        double xOfCenter, yOfCenter, radius;
    };
}

class Student {
public:
    unsigned nNumber;
    std::string name;

    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << s.nNumber << ": " << s.name;
        return os;
    }
};


int main() {
    //std::cout << "Hello, World!" << std::endl;

//    for(int i = 0; i < 10; ++i) {
//        std::cout << "I am printing " << i << std::endl;
//    }
//
//    unsigned i = 0;
//    while(i<10) {
//        std::cout << "I am printing " << i << std::endl;
//        i++;
//    }

    std::cout << square(100) << std::endl;

    Student anirban;
    anirban.nNumber = 1388139;
    anirban.name = "Anirban Ghosh";

    std::cout << anirban << std::endl;
    std:: cout << isPostive(-99 ) << std::endl;

    using namespace unf;
    Circle c;

    std::vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);

    for(auto i : myVector )
        std::cout << i << " ";

    return 0;
}
 */

/*#include <iostream>
#include "CGALComponents.h"

int main() {
    Point p(1,1), q(10,10), m(5, 9);
    std::cout << "p: " << p << ",  q: " << q << ",  m: " << m << std::endl;
    std::cout << "x-coordinate of q: " << q.x() << ", y-coordinate of q: " << q.y() << std::endl;
    std::cout << "sqdist(p,q) = " << CGAL::squared_distance(p,q) << std::endl;

    switch (CGAL::orientation(p,q,m)){
        case CGAL::COLLINEAR:
            std::cout << "p, q, and m are collinear\n"; break;
        case CGAL::LEFT_TURN:
            std::cout << "p, q, and m make a left turn\n"; break;
        case CGAL::RIGHT_TURN:
            std::cout << "p, q, and m make a right turn\n"; break;
    }
    std::cout << "midpoint(p,q) = " << CGAL::midpoint(p,q) << std::endl;

    Point a(0, 0.3), b(1, 0.6), c(2, 0.9);
    std::cout << CGAL::collinear(a,b,c) << std::endl;

    return 0;
}*/


