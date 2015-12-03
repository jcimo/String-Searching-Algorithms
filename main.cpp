#include <iostream>
#include <string>

using namespace std;

// INCLUDE STRING SEARCHING ALGORITHMS FUNCTIONS

// NAIVE IMPLEMENTATION (BRUTE FORCE APPROACH)
#include "naive.h"

// BOYER MOORE STRING SEARCH ALGORITHM
#include "boyer-moore.h"

// KNUTH MORRIS PRATT STRING SEARCH ALGORITHM
#include "knuth-morris-pratt.h"

// MAIN METHOD
int main(void) {
    
    int a = naive_search("hello", "el");
    int b = naive_search("hello", "o");
    int c = naive_search("apple", "banana");
    int d = naive_search("apple", "xy");
    int e = naive_search("abcdefghijklmnopqrst", "hijklmnop");
    int f = naive_search("abcdefghijklmnopqrst", "");
    
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    
    return 0;
}