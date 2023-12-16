#include <iostream>
#include <memory>
#include <Figure.h>
#include <Rhombus.h>
#include <Pentagon.h>
#include <Hexagon.h>
#include <Array.h>

using namespace std;

using pii = std::pair<double,double>;

int main() {
    Rhombus<double> rhomb({pii(0,14), pii(-14,0), pii(0,-14), pii(14,0)});

    cout << rhomb << endl;
    cout << rhomb.calculate_area() << endl;
    cout << rhomb.calculate_geometric_center().first << ' ' << rhomb.calculate_geometric_center().second << endl;
    
    Pentagon<double> pent({pii(5,17), pii(-14, 10), pii(-14,-10), pii(5,-17), pii(18,0)});

    cout << pent << endl;
    cout << pent.calculate_area() << endl;
    cout << pent.calculate_geometric_center().first << ' ' << pent.calculate_geometric_center().second << endl;
    
    Hexagon<double> hex({pii(2,4), pii(-2,4), pii(-5,0), pii(-2,-4), pii(2,-4), pii(5,0)});

    cout << hex << endl;
    cout << hex.calculate_area() << endl;
    cout << hex.calculate_geometric_center().first << ' ' << hex.calculate_geometric_center().second << endl;

    Array<std::shared_ptr<Figure<double>>> arr({
        std::make_shared<Rhombus<double>>(pii(0,14), pii(-14,0), pii(0,-14), pii(14,0))
    });

    // arr.AddElement(hex);
    // arr.DeleteElementbyIndex(1);
    arr.print_area();
    arr.print_geometric_center();
    cout << arr.size();
}