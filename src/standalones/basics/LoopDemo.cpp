#include <iostream>
#include <vector>
#include <string>

int main() {

    for (int i = 0; i < 5; i++) {
        std::cout << i << std::endl;
    }

    // Iterating over a vector
    // std::vector<std::string> myVector = {"alpha", "beta", "gamma"};
    // for (int i = 0; i < 5; i++) {
    //     std::cout << i << std::endl;
    // }

    // Interesting trick question - find when fahrenheit and celsius scales are equal.
    // Note the problem - Cel < Fahr is only evaluated after Cel has been updated by Cel--, 
    // meaning Cel < Fahr is checked when Cel is 1 lower than intuitively expected.
    double Fahr, Cel;
    for (Cel = 0, Fahr = 32; Cel < Fahr; Cel--)
    {
        Fahr = Cel * 1.8 + 32;
        std::cout << Cel << "..." << Fahr << std::endl; //monitors the conversion of C to F
    }
    std::cout << "Fahrenheit and Celsius have the same value at " << Fahr << " degrees.\n";

    return 0;

}