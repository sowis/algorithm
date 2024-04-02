#include <iostream>

using namespace std;

int main (void) {
    string str;
    cin >> str;
    
    int result = 0;
    for( int i = 0; i < str.size() - 3; ++i) {
        if (str[i] != 'D') {
            continue;
        }
        
        if (str[i + 1] != 'K') {
            continue;
        }
        
        if (str[i + 2] != 'S') {
            continue;
        }
        
        if (str[i + 3] != 'H') {
            continue;
        }
        
        ++result;
    } 
    
    cout << result << "\n";
    
    return 0;
}