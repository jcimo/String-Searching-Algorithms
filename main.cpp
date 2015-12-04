#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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
    
    string base = "aaaaaaabkjdshflkajhfdabcdlkjhasldkfjh";
    string key = "abcd";
    
    clock_t naive_begin_timer = clock();
    vector<int> x = naive_search(base,key);
    float naive_time = clock() - naive_begin_timer;
    
    clock_t kmp_begin_timer = clock();
    vector<int> y = kmp_search(base,key);
    float kmp_time = clock() - kmp_begin_timer;
    
    cout << "Naive: " << naive_time << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    } cout << endl;
    
    cout << "KMP: " << kmp_time << endl;
    for (int i = 0; i < y.size(); i++) {
        cout << y[i] << " ";
    } cout << endl;
    
    return 0;
}