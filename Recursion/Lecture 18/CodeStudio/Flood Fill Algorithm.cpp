void flood(int i, int j, vector<vector<int>> &image, int oldColor, int newColor, int n, int m)
{
    // [i][j] denotes the current cell
    // n*m is the size of the images which is also denoting the boundary of the image

    // base condition
    if (i < 0 || j < 0 || i == n || j == m || image[i][j] != oldColor)
        return;

    // change the current cell to newColor
    image[i][j] = newColor;

    // recursive call in the downward direction
    flood(i + 1, j, image, oldColor, newColor, n, m);

    // recursive call in the upward direction
    flood(i - 1, j, image, oldColor, newColor, n, m);

    // recursive call in the right direction
    flood(i, j + 1, image, oldColor, newColor, n, m);

    // recursive call in the left direction
    flood(i, j - 1, image, oldColor, newColor, n, m);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // it is denoting the oldcolor
    int oldColor = image[x][y];

    // incase the oldColor & newColor is same then there is a possibility of forming an infinite recursion therefore to avoid such type of situation we are putting this condition over here if oldColor != newColor then it will proceed else it will return us the same image
    if (oldColor == newColor)
        return image;

    int n = image.size(), m = image[0].size();

    // recursion call
    flood(x, y, image, oldColor, newColor, n, m);

    return image;
}

/*
    time complexity: O(M * N)
    space complexity: O(M * N)
*/