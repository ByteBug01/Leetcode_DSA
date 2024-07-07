class Solution {
public:

//simple intutition is : minimun enemyEnergy chor ke jitte bhi other enemies hai
// unki energy add krte jaenge currenEnegy se
// and minimum enemy energy subtract krk , points gain krenge

    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        
        sort(enemyEnergies.begin(), enemyEnergies.end());

        if(enemyEnergies[0] > currentEnergy) return 0;

        long long sum  = 0;

        int n = enemyEnergies.size();

        for(int i = 1; i<n; i++){
            sum += enemyEnergies[i];
        }

       sum +=  currentEnergy ; //total energy

        return (sum / enemyEnergies[0]);

    }
};