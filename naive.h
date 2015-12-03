// NAIVE IMPLEMENTATION (BRUTE FORCE APPROACH)

// param - base_str: the string to search
// param - key_str: the key string you are searching for
//
// returns the index of the first char of the key from
// the base string
//
// return -1 if key string is not in base string

int naive_search(string base_str, string key_str) {
    
    // base string index
    int i = 0;
    
    int base_length = base_str.length();
    int key_length = key_str.length();
    
    // if the key string is larger than the base string
    if (key_length > base_length) {
        i = -1;
    } else {
        
        // while search is true, the key has not been found
        bool search = true;
        
        // search through each starting char in base
        while (search && (i < base_length)) {
            
            // while sub_search is true, the key has
            // been accurate in the base thus far
            bool sub_search = true;
            int j = 0;
            
            while (sub_search && (j < key_length)) {
                
                if (i+j < base_length) {
                    if (base_str[i+j] != key_str[j]) {
                        sub_search = false;
                    }
                }
                
                // increment key string index
                j++;
            }
            
            // if the key was found
            if (sub_search) { search = false; }
            
            // increment base string index
            i++;
        }
        
        // adjust index for search conclusion
        // -1 for not found, else -1 for index adjusment
        if (search) { i = -1; } else { i--; }
    }
    
    return i;
}