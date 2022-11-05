# LineEquation
Let l be a line in the x -y plane. If l is a vertical line, its equation is x = a for some real
number a. Suppose l is not a vertical line and its slope is m. Then the equation of l is
y = mx + b, where b is the y-intercept. If (x1, y1) and (x2, y2) are two points in the in the
x -y plane and x1 ≠ x2, the slope of the line passing through these points is:
y2 − y1
m = x2 − x1

![image](https://user-images.githubusercontent.com/25221118/200106194-12db45a5-54b7-4dd4-99c8-97c9c5633db4.png)

Write a program that does not prompt the user, but instead reads two Cartesian coordinate
points in the form: x1 y1 x2 y2 from stdin and computes (See sample interaction):
• the segment length
• the line equation (sloped lines should be in the form y = mx + b)
• whether the line is vertical, horizontal, increasing or decreasing
• reports an error if the input is bad
• reports an error if the points are are the same (treat any points that are within
0.0000001 units of each other as being the same)
