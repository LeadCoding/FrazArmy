/* This Question asks us to color all the Neighbouring Cells of (x , y) with the given Color
By Neighbouring we can move in 4 directions - a) Up , b) Down , c) Left , d) Right
And we change colors of only those Neighbouring Cells which have the same color as the Original Cell(x , y)
If old-Color of (x , y) is same as New-Color, we don't need to modify anything. Just return the previous Matrix
*/

public class Solution
{
    static void flood(int i, int j, int[][] image, int oldColor, int newColor, int n, int m)
    {

        // If we move out of the Matrix Or oldColor is not equal to newColor, we just return back

        if (i < 0 || j < 0 || i == n || j == m || image[i][j] != oldColor)
            return;

        // We change the color of the Current-Cell to newColor

        image[i][j] = newColor;

        // Recursive call in Downward direction

        flood(i + 1, j, image, oldColor, newColor, n, m);

        // Recursive call in the Upward direction

        flood(i - 1, j, image, oldColor, newColor, n, m);

        // Recursive call in the Right direction

        flood(i, j + 1, image, oldColor, newColor, n, m);

        // Recursive call in the left direction

        flood(i, j - 1, image, oldColor, newColor, n, m);
    }
    
    public static int[][] floodFill(int[][] image, int x, int y, int newColor)
    {
        // We calculate oldColor first using the coordinates (sr , sc)
        
        int oldColor = image[x][y];

        // Incase the oldColor & new Color is same, we can simply return the Original Image

        if (oldColor == newColor)
            return image;

        // We calculate the Dimmensions of image matrix[]

        int n = image.length, m = image[0].length;

        flood(x , y , image, oldColor, newColor , n, m);

        // We return the new image[][] matrix after changing all the Neighbouring Cells of (sr , sc) having OldColor to Color

        return image;
    }
}

/* 
Time Complexity:  O(N * M) 
Space Complexity: O(N * M)
*/
