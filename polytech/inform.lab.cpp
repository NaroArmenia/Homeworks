#include <iostream>
#define PI 3.14159

class Shrjan {
private:
    double sharavigh;

public:
 
    Shrjan(double r) : sharavigh(r) {}

    double getMakeres() const {
        return PI * sharavigh * sharavigh;
    }

    Shrjan operator*(const Shrjan& other) const {
        return Shrjan(this->sharavigh * other.sharavigh);
    }

    bool operator==(const Shrjan& other) const {
        return this->sharavigh == other.sharavigh;
    }


    void printSharavigh() const {
        std::cout << "Sharavigh: " << sharavigh << std::endl;
    }
};

int main() {
    Shrjan sh1(3.0);
    Shrjan sh2(4.0);

    std::cout << "Shrjan 1 makeres: " << sh1.getMakeres() << std::endl;
    std::cout << "Shrjan 2 makeres: " << sh2.getMakeres() << std::endl;

    Shrjan sh3 = sh1 * sh2;
    std::cout << "Shrjan 3 sharavigh (sh1 * sh2): ";
    sh3.printSharavigh();

    if (sh1 == sh2) {
        std::cout << "Shrjan 1 == Shrjan 2" << std::endl;
    } else {
        std::cout << "Shrjan 1 != Shrjan 2" << std::endl;
    }

    return 0;
}
