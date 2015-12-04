#include <iostream>
#include <string>
#include <vector>

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
    
    vector<int> x = kmp_search("a","a");
    
    cout << "test:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << endl;
    }
    
    return 0;
}