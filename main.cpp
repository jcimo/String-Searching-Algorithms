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
    
    string base = "kabcjhdflkabcjhdf";
    string key = "abc";
    cout.flush();
    
    vector<int> x = naive_search(base,key);
    vector<int> y = kmp_search(base,key);
    
    cout << "Naive:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    } cout << endl;
    
    cout << "KMP:" << endl;
    for (int i = 0; i < y.size(); i++) {
        cout << y[i] << " ";
    } cout << endl;
    
    return 0;
}