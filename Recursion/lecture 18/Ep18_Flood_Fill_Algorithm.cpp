// Approach 1 -
void floodFillHelper(vector<vector<int>> &image, int i, int j, int oldColor, int newColor) {
    if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size()) {
        return;
    }

    if (image[i][j] != oldColor) {
        return;
    }

    if (image[i][j] == newColor) {
        return;
    }

    image[i][j] = newColor;

    floodFillHelper(image, i, j + 1, oldColor, newColor);
    floodFillHelper(image, i, j - 1, oldColor, newColor);
    floodFillHelper(image, i + 1, j, oldColor, newColor);
    floodFillHelper(image, i - 1, j, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor) {
    int oldColor = image[x][y];
    floodFillHelper(image, x, y, oldColor, newColor);
    return image;
}

// Approach 2 -
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int oldColor = image[x][y];
    int m = image.size();
    int n = image[0].size();
    queue<pair<int, int>> q;

    q.push({x, y});

    while (!q.empty())
    {
        pair<int, int> currentPixel = q.front();
        q.pop();

        int i = currentPixel.first;
        int j = currentPixel.second;

        if (i >= 0 && i < m && j >= 0 && j < n)
        {
            if (image[i][j] == oldColor && image[i][j] != newColor) 
            {
                image[i][j] = newColor;
                q.push({i, j + 1});
                q.push({i, j - 1});
                q.push({i + 1, j});
                q.push({i - 1, j});
            }
        }
    }

    return image;
}