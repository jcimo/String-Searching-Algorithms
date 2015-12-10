#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

// INCLUDE STRING SEARCHING ALGORITHMS FUNCTIONS

// NAIVE IMPLEMENTATION (BRUTE FORCE APPROACH)
#include "naive.h"

// BOYER MOORE STRING SEARCH ALGORITHM
#include "boyer-moore.h"

// KNUTH MORRIS PRATT STRING SEARCH ALGORITHM
#include "knuth-morris-pratt.h"

// MAIN METHOD
int main(int argc, char* argv[]) {
    
    // Check command line arguments
    if(argc > 2 || argc < 2) {
        cout << "ERROR: Please provide input file" << endl;
        exit(0);
    }
    
    // initialize strings for search
    string key, base;
    
    // prepare for file read
    string line;
    string inputfile = argv[1];
    ifstream input(inputfile.c_str());
    
    // read input file
    int lineCount = 0;
    while(getline(input,line)) {
        if( lineCount == 0 ){
            key = line;
            lineCount++;
        } else {
            base = base + line;
        }
    }
    
    // Brute Force Implementation
    clock_t naive_begin_timer = clock();
    vector<int> naive = naive_search(base,key);
    float naive_time = clock() - naive_begin_timer;
    
    // Boyer-Moore Implementation
    clock_t bm_begin_timer = clock(); 
    vector<int> bm = boyer_moore_search(base,key);
    float bm_time = clock() - bm_begin_timer;
    
    // Knuth-Morris-Pratt Implementation
    clock_t kmp_begin_timer = clock();
    vector<int> kmp = kmp_search(base,key);
    float kmp_time = clock() - kmp_begin_timer;
    
    string time_unit = " us";
    int time_factor = 1000000;
    
    cout << "NAIVE:\t" << ( (float) naive_time ) * time_factor / CLOCKS_PER_SEC << time_unit << endl;
    for (int i = 0; i < naive.size(); i++) {
        cout << naive[i] << " ";
    } cout << endl << endl;
    
    cout<< "BM:\t" << ( (float) bm_time ) * time_factor / CLOCKS_PER_SEC << time_unit << endl;
    for(int i = 0; i < bm.size(); i++){
        cout << bm[i] << " ";
    } cout << endl << endl;
    
    cout << "KMP:\t" << ( (float) kmp_time ) * time_factor / CLOCKS_PER_SEC << time_unit << endl;
    for (int i = 0; i < kmp.size(); i++) {
        cout << kmp[i] << " ";
    } cout << endl << endl;
    
    return 0;
}