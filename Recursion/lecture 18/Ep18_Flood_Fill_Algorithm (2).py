# Approach 1 - 
def floodFillHelper(image, i, j, oldColor, newColor):
    if (i < 0 or i >= len(image) or j < 0 or j >= len(image[0])):
        return

    if (image[i][j] != oldColor):
        return

    if (image[i][j] == newColor):
        return

    image[i][j] = newColor

    floodFillHelper(image, i, j + 1, oldColor, newColor)
    floodFillHelper(image, i, j - 1, oldColor, newColor)
    floodFillHelper(image, i + 1, j, oldColor, newColor)
    floodFillHelper(image, i - 1, j, oldColor, newColor)

def floodFill(image, x, y, newColor):
    oldColor = image[x][y]
    floodFillHelper(image, x, y, oldColor, newColor)
    return image


# Approach 2 - 
from collections import deque 

def floodFill(image, x, y, newColor):

    oldColor = image[x][y]
    m = len(image)
    n = len(image[0])
    q=deque([])

    q.append((x, y))

    while (len(q)>0):

        currentPixel = q.popleft()

        i = currentPixel[0]
        j = currentPixel[1]

        if (i >= 0 and i < m and j >= 0 and j < n):

            if (image[i][j] == oldColor and image[i][j] != newColor):
                image[i][j] = newColor
                q.append((i, j + 1))
                q.append((i, j - 1))
                q.append((i + 1, j))
                q.append((i - 1, j))

    return image