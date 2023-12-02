#include "FiguresArray.h"

FiguresArray::FiguresArray(): _size(0), _array{nullptr} {}

FiguresArray::FiguresArray(const size_t &n, Figure* t){
    _array = new Figure*[n];
    for(size_t i = 0; i < n; ++i)
        _array[i] = t;
    _size = n;
}

FiguresArray::FiguresArray(const std::initializer_list<Figure*> &t){
    _array = new Figure*[t.size()];
    size_t i{0};
    for(auto c : t){
        _array[i++] = c;
    }
    _size = t.size();
}

FiguresArray::FiguresArray(const FiguresArray &other){
    _size = other._size;
    _array = new Figure*[_size];

    for(size_t i = 0; i < _size; ++i) _array[i] = other._array[i];
}

FiguresArray::FiguresArray(FiguresArray &&other){
    _size = other._size;
    _array = other._array;

    other.~FiguresArray();
}
std::ostream& operator<<(std::ostream& os, const FiguresArray& num) {
    for(size_t i = 0; i < num._size; ++i){
        os << num._array[i];
    }
    return os;
}

FiguresArray& FiguresArray::operator=(const FiguresArray& other){
    if(&other != this)
    {
        _size = other._size;
        _array = new Figure*[_size];

        for(size_t i = 0; i < _size; ++i) _array[i] = other._array[i];
    }
    return *this;
}

void FiguresArray::AddElement(Figure* f){
    size_t newSize = _size + 1;
    Figure** newArray = new Figure*[newSize];

    for (int i = 0; i < _size; ++i) {
        newArray[i] = _array[i];
    }

    newArray[_size] = f;
    delete[] _array;

    _array = newArray;
    _size = newSize;
}

void FiguresArray::DeleteElementbyIndex(const int index){
    if (index < 0 || index >= _size) {
        std::cout << "Invalid index.\n";
        return;
    }

    for (int i = index; i < _size - 1; ++i) {
        _array[i] = _array[i + 1];
    }

    --_size;

    Figure** newArray = new Figure*[_size];

    for (int i = 0; i < _size; ++i) {
        newArray[i] = _array[i];
    }

    delete[] _array;
    _array = newArray;
}

void FiguresArray::print_geometric_center() const {
    std::cout << std::endl << "Geometric center" << std::endl;
    for (size_t i = 0; i < _size; ++i) {
        std::cout << i << " " << (*_array[i]).calculate_geometric_center() << std::endl;
    }
}

void FiguresArray::print_area() const {
    std::cout << std::endl << "Area" << std::endl;
    for (size_t i = 0; i < _size; ++i) {
        std::cout << i << " " << (*_array[i]).calculate_area() << std::endl;
    }
}

double FiguresArray::calculate_total_area() const{
    double total_area { 0 };
    for (size_t i = 0; i < _size; ++i) {
        total_area += (*_array[i]).calculate_area();
    }

    return total_area;
}

size_t FiguresArray::get_size() const{
    return _size;
}

Figure* FiguresArray::operator[](size_t index) const{
    assert((index >= 0) && (index < _size));
    return _array[index];
}

FiguresArray::~FiguresArray() noexcept{
    if(_size > 0){
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}