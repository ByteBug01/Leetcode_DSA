#define psi pair<string, int>

struct Compare {
    bool operator()(const psi p1, const psi p2) const{
        return p1.second > p2.second or (p1.second == p2.second and p1.first < p2.first);
    }
};

class FoodRatings {
public:
    unordered_map<string, set<psi, Compare>> cuisine2rating;
    // cuisine -> {<food, rating>}
    unordered_map<string, psi> food2rating;
    // food -> <cuisine, rating>

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            cuisine2rating[cuisines[i]].emplace(foods[i], ratings[i]);
            food2rating[foods[i]] = {cuisines[i], ratings[i]};
        }
    }

    void changeRating(string food, int newRating) {
        auto [cuisine, rating] = food2rating[food];
        cuisine2rating[cuisine].erase({food, rating});
        cuisine2rating[cuisine].emplace(food, newRating);
        food2rating[food] = {cuisine, newRating};
    }

    string highestRated(string cuisine) {
        return (*cuisine2rating[cuisine].begin()).first;
    }
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */