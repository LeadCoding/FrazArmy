// Approach 1 -
public class Solution
{

    public static void floodFillHelper(int[][] image, int i, int j, int oldColor, int newColor)
    {
        if (i < 0 || i >= image.length || j < 0 || j >= image[0].length)
        {
            return;
        }

        if (image[i][j] != oldColor)
        {
            return;
        }

        if (image[i][j] == newColor)
        {
            return;
        }

        image[i][j] = newColor;

        floodFillHelper(image, i, j + 1, oldColor, newColor);
        floodFillHelper(image, i, j - 1, oldColor, newColor);
        floodFillHelper(image, i + 1, j, oldColor, newColor);
        floodFillHelper(image, i - 1, j, oldColor, newColor);
    }

    public static int[][] floodFill(int[][] image, int x, int y, int newColor)
    {

        int oldColor = image[x][y];

        floodFillHelper(image, x, y, oldColor, newColor);

        return image;

    }
}

// Approach 2 -
import java.util.Queue;
import java.util.LinkedList;
import javafx.util.Pair;

public class Solution
{
    public static int[][] floodFill(int[][] image, int x, int y, int newColor)
    {

        int oldColor = image[x][y];
        int m = image.length;
        int n = image[0].length;

        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        Pair<Integer, Integer> temp = new Pair<Integer, Integer> (x, y);
        q.add(temp);

        while (!q.isEmpty())
        {

            Pair<Integer, Integer> currentPixel = q.remove();

            int i = currentPixel.getKey();
            int j = currentPixel.getValue();

            if (i >= 0 && i < m && j >= 0 && j < n)
            {
                if (image[i][j] == oldColor && image[i][j] != newColor)
                {
                    image[i][j] = newColor;

                    // Push the adjacent pixels into the queue.
                    Pair<Integer, Integer> up = new Pair<Integer, Integer> (i, j + 1);
                    Pair<Integer, Integer> down = new Pair<Integer, Integer> (i, j - 1);
                    Pair<Integer, Integer> right = new Pair<Integer, Integer> (i + 1, j);
                    Pair<Integer, Integer> left = new Pair<Integer, Integer> (i - 1, j);

                    q.add(up);
                    q.add(down);
                    q.add(right);
                    q.add(left);
                }
            }
        }

        return image;

    }
}