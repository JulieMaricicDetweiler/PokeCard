#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono;
using std::cout;
using std::endl;

int OOfN(int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
       total++;
    }
    return total;
};

int OOfNSquared(int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            total++;
        }
    }
    return total;
};

int main() {
    int n;
    std::cin >> n;
    // O(n) // FIRST FUNCTION
    auto start = high_resolution_clock::now();
    OOfN(n); // FUNCTION
    auto end = high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::chrono::duration<long, std::micro> int_usec = int_ms;
    std::cout << "OOfN() elapsed time is " << float_ms.count() << " ms " << "( " << int_ms.count() << " milliseconds )" << std::endl;

    // O(n^2) // REST OF FUNCTIONS
    start = high_resolution_clock::now();
    OOfNSquared(n); // FUNCTION
    end = high_resolution_clock::now();
    float_ms = end - start;
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    int_usec = int_ms;
    std::cout << "OOfNSquared() elapsed time is " << float_ms.count() << " ms " << "( " << int_ms.count() << " milliseconds )" << std::endl;

    return 0;
}