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
    
    //Read file name from command line. Error checked for command line args
    //Expecting first line of input file to be search key, rest of file is base string
    if(argc > 2 || argc < 2){
        cout << "Expected filename as command line parameter. Exiting." << endl; 
        exit(0);
    }
    
    // initialize key and base string for use in search
    string key, base;
    
    // get input file name
    //
    // the first line of the file should be the key string
    // and the remainder of the file should be the base string
    
    string inputfile = argv[1];
    ifstream input(inputfile.c_str());
    
    int lineCount = 0;
    while(getline(input,line)){
        if(lineCount == 0){
            key = line;
            lineCount++;
        } else {
            base = base + line; 
        }
    }
    
    // brute force call
    clock_t naive_begin_timer = clock();
    vector<int> x = naive_search(base,key);
    float naive_time = clock() - naive_begin_timer;
    
    // boyer moore call
    clock_t bm_begin_timer = clock();
    vector<int> bm = boyer_moore_search(base,key);
    float bm_time = clock() - bm_begin_timer;
    
    // knuth morris pratt call
    clock_t kmp_begin_timer = clock();
    vector<int> y = kmp_search(base,key);
    float kmp_time = clock() - kmp_begin_timer;

    
    cout << "Naive: " << naive_time << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    } cout << endl;
    
    cout<< "BM: " << bm_time << endl;
    for(int i = 0; i < bm.size(); i++){
        cout << bm[i] << " ";
    }cout << endl;
    
    cout << "KMP: " << kmp_time << endl;
    for (int i = 0; i < y.size(); i++) {
        cout << y[i] << " ";
    } cout << endl;

    
    return 0;
}