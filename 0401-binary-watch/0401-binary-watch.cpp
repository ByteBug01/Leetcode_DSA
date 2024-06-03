class Solution {
public:
//bit manipulation
//__builtin_popcount : counts the number of 1 in the binary representation of a number
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int h = 0; h<12; h++){
            for(int m=0; m<60; m++){
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn){
                    ans.push_back(to_string(h) + (m<10 ? ":0" : ":") + to_string(m));
                }
            }
        }

        return ans;
    }
};


// Dry Run
// Let's assume turnedOn = 1 and dry run the code.

// Initial Setup
// turnedOn = 1
// result is an empty vector to store the valid times.
// Outer Loop (Hours Loop)
// The outer loop runs from h = 0 to h = 11.

// h = 0

// Inner Loop (Minutes Loop)
// m = 0 to m = 59
// For each minute, it checks if the sum of set bits in the binary representation of h and m equals turnedOn.
// Example:
// m = 1:
// __builtin_popcount(0) = 0 (0 in binary is 0000)
// __builtin_popcount(1) = 1 (1 in binary is 0001)
// 0 + 1 = 1 (matches turnedOn)
// Time "0:01" is added to result.
// m = 2:
// __builtin_popcount(0) = 0
// __builtin_popcount(2) = 1 (2 in binary is 0010)
// 0 + 1 = 1 (matches turnedOn)
// Time "0:02" is added to result.
// Continue this for each minute m where the sum of set bits is 1.
// h = 1

// Inner Loop (Minutes Loop)
// m = 0 to m = 59
// Example:
// m = 0:
// __builtin_popcount(1) = 1 (1 in binary is 0001)
// __builtin_popcount(0) = 0
// 1 + 0 = 1 (matches turnedOn)
// Time "1:00" is added to result.
// m = 1:
// __builtin_popcount(1) = 1
// __builtin_popcount(1) = 1
// 1 + 1 = 2 (does not match turnedOn)
// Time is not added.
// Continue this for each minute m where the sum of set bits is 1.
// h = 2 to h = 11

// Repeat the inner loop for each hour and find valid times where the sum of set bits equals turnedOn.
// Result
// After completing both loops, the result vector contains all times where the sum of set bits in the binary representations of the hour and minute equals turnedOn.

// For turnedOn = 1, some valid times include:

// "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"
// "1:00", "2:00", "4:00", "8:00"