class Solution {
public:
//----------fir se visit this---------------
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
         vector<int> result;
        unordered_map<int, int> ballColors;
        unordered_set<int> distinctColors;

        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            // If the ball already has a color, remove the old color from the set if it's still present
            if (ballColors.find(ball) != ballColors.end()) {
                int oldColor = ballColors[ball];
                ballColors[ball] = color; // Update to new color

                // If the old color is still in the map, we should not remove it from the set
                bool colorStillPresent = false;
                for (const auto& entry : ballColors) {
                    if (entry.second == oldColor) {
                        colorStillPresent = true;
                        break;
                    }
                }
                if (!colorStillPresent) {
                    distinctColors.erase(oldColor);
                }
            } else {
                ballColors[ball] = color;
            }

            // Insert the new color into the set
            distinctColors.insert(color);

            // The size of the set represents the number of distinct colors
            result.push_back(distinctColors.size());
        }

        return result;
    }
};