// class Solution {
// public:
//     bool canChange(string start, string target) {
//         int n = start.length();

//       int i = n-1;
//       int j = n-1;

//       while(i >= 0 && j >= 0){
//         if(target[j] == start[i]){
//             j--;
//             i--;
//         }
        
//         if(target[j] == 'R' && start[i] == '_'){
//             while(i >= 0){
//                 if(start[i] == 'L') return false;

//                 if(start[i] == '_') i--;
                
//                 if(start[i] == 'R') {
//                     start[j] = 'R';
//                     start[i] = '_';
//                 }
//             }
//         }

//          if(target[j] == 'R' && start[i] == 'L') return false;

//          if(target[j] == '_' && start[i] == 'R') return false;

//       }


//       int a = 0;
//       int b = 0;

//       while(a < n && b < n){
//         if(target[b] == start[a]){
//             a++;
//             b++;

//              if(target[j] == 'L' && start[i] == '_'){
//                 while(a < n){

//                     if(start[a] == 'R') return false;

//                      if(start[a] == '_') a++;
                
//                 if(start[a] == 'L') {
//                     start[b] = 'L';
//                     start[a] = '_';
//                 }

//                 }
//              }
//         }
          
//            if(target[b] == 'L' && start[a] == 'R') return false;

//            if(target[b] == '_' && start[a] == 'L') return false;

//       }



// return true;

//     }
// };



class Solution {
public:
    bool canChange(string start, string target) {
         vector<pair<char, int>> startp, targetp;
    
    for (int i = 0; i < start.size(); ++i) {
        if (start[i] != '_') startp.emplace_back(start[i], i);
        if (target[i] != '_') targetp.emplace_back(target[i], i);
    }
    

    if (startp.size() != targetp.size()) return false;
    
 
    for (int i = 0; i < startp.size(); ++i) {
        char sChar = startp[i].first;
        int sIdx = startp[i].second;
        char tChar = targetp[i].first;
        int tIdx = targetp[i].second;
        
        if (sChar != tChar) return false;
        
        // Check movement rules 
        if (sChar == 'L' && sIdx < tIdx) return false; // L cannot move right
        if (sChar == 'R' && sIdx > tIdx) return false; // R cannot move left
    }
    
    return true;
    }
};