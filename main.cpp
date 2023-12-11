#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "FiguresArray.h"
#include "Hexagon.h"
#include "Pentagon.h"
#include "Rhombus.h"


using namespace std;

void generateRandomPolygonCoordinates(int sides) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(5, 20); // Random side length between 5 and 20

    int sideLength = dis(gen); // Random side length

    std::cout << "Random side length: " << sideLength << "\n";
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 1; i <= sides; ++i) {
        double angle = (2 * M_PI / sides) * i;
        int x = static_cast<int>(sideLength * cos(angle));
        int y = static_cast<int>(sideLength * sin(angle));

        std::cout << "Vertex " << i << ": (" << x << ", " << y << ")\n";
    }
}

int main() {
    generateRandomPolygonCoordinates(6);
    Rhombus* rhomb = new Rhombus(Point(0,14), Point(-14,0), Point(0,-14), Point(14,0));
    cout << *rhomb << endl;
    Pentagon* pent = new Pentagon(Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0));
    cout << *pent << endl;
    Hexagon* hex = new Hexagon(Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0));
    cout << *hex << endl;

    // Figure* figre_collection[]{rhomb, pent, hex};

    // for(Figure* f_ptr : figre_collection){
    //     cout << f_ptr->calculate_area() << ' ' << f_ptr->calculate_geometric_center();
    // }

    FiguresArray f_arr;
    f_arr.AddElement(rhomb);
    f_arr.AddElement(pent);
    f_arr.AddElement(hex);

    f_arr.print_geometric_center();
    f_arr.print_area();
    f_arr.calculate_total_area();
}