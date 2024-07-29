class Solution {
public:
//a number is special if and only if it is the square of a prime number
//use a Sieve of Eratosthenes to find all prime numbers up to sqroot(r).

    int nonSpecialCount(int l, int r) {

        int n = sqrt(r);
        vector<int> isPrime(n+1, 1);

        isPrime[0] = 0;
        isPrime[1] = 0;

        for(int i =  2; i*i<=n; i++){
            if(isPrime[i] == 1){
                for(int j = i*i; j<=n; j+=i){
                    isPrime[j] = 0;
                }
            }
        }

vector<int> sqPrime;
        for(int i = 2; i<=n; i++){
              if(isPrime[i] == 1){
                int x = i*i;
                if(x >= l && x<= r){
                    sqPrime.push_back(x);
                }
              }
        }

        int totLen = r-l+1;

        return totLen - (sqPrime.size());
       
    }
};