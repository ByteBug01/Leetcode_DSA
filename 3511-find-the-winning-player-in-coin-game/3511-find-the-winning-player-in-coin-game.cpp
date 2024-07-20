//-----wrong solution---------------
// class Solution {
// public:
//     string losingPlayer(int x, int y) {
//         if(x >= 1 && (y/4)%2 == 0 ){
//             return "Bob";
//         }else if(x = 1 && (y/4)%2 != 0 )
//         {return "Alice";}
//         else{
//             return "Bob";
//         }
//     }
// };

class Solution {
public:
    string losingPlayer(int x, int y) {
        int turns = min(x, y/4);

        return (turns% 2 == 0)? "Bob" : "Alice";
    }
};