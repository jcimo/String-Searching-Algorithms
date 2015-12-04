// KNUTH MORRIS PRATT STRING SEARCH ALGORITHM

// param - base_str: the string to search
// param - key_str: the key string you are searching for
//
// returns a vector<int> indicating all indexes of the base that
// are equal to instances of the first char of the key found in
// the base string
//
// return an empty vector if the key string is not found

vector<int> kmp_search(string base_str, string key_str) {
    
    vector<int> finds;
    
    // get string size lengths
    int base_length = base_str.length();
    int key_length = key_str.length();
    
    // check string size conditions before search
    if (key_length != 0 && key_length <= base_length) {
        
        
        // PART 1: CREATE KMP TABLE
        // =============================================================
        
        vector<int> T(key_length+1); // KMP table of size = length of key
        
        int pos = 2; // index (position) in T we are computing
        int cnd = 0; // index of the key string of the next
                     // character of the current candidate substring
        
        // set first two elements in the T table
        T[0] = -1;
        T[1] = 0;
        
        while (pos < key_length) {
            
            // case 1
            // substring continues
            if (key_str[pos-1] == key_str[cnd]) {
                T[pos] = cnd+1;
                cnd++;
                pos++;
            }
            
            // case 2
            // substring doesn't continue, we fall back
            else if (cnd > 0) {
                cnd = T[cnd];
            }
            
            // case 3
            // we ran out of candidates
            // (cnd == 0)
            else {
                T[pos] = 0;
                pos++;
            }
            
        }
        
        // debug T table
        //for (int i = 0; i < T.size(); i++) {
        //    cout << T[i] << endl;
        //}
        
        // PART 2: SEARCH
        // =============================================================
        
        int m = 0; // index in base string
        int i = 0; // index in key string
        int val;
        
        // for each possible instance of key
        while (m+i < base_length) {
            
            if (key_str[i] == base_str[m+i]) {
                
                if (i == key_length - 1) {
                    finds.push_back(m + i - key_length + 1);
                }
                
                i++;
                
            } else {
                
                if (T[i] > -1) {
                    m = m + i - T[i];
                    i = T[i];
                } else {
                    i = 0;
                    m++;
                }
            }
        }
    }
    
    return finds;
}