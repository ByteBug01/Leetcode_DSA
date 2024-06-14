class Solution {
public:

void fill(vector<vector<int>>& image, int sr, int sc, int color, int prevColor){
    if(sr<0 || sc<0  || sr>= image.size() || sc>= image[0].size() || image[sr][sc]!= prevColor){
      return;
    }

    image[sr][sc] = color;
    fill(image, sr-1, sc, color, prevColor);
    fill(image, sr+1, sc, color, prevColor);
    fill(image, sr, sc-1, color, prevColor);
    fill(image, sr, sc+1, color, prevColor);
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        int prevColor = image[sr][sc];
        fill(image, sr, sc, color, prevColor);
        return image;
    }
};