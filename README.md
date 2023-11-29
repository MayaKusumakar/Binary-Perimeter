# Binary-Perimeter
## Problem
Write a program that finds the perimeter of an arbitrary, convex shape. Your program will be provided a binary file that contains the vertices of the shape and the program should print out the perimeter of the given shape.

## Specifications
  - Your program must have and meaningfully use a struct that represents a point in 2D space
  - The perimeter of a convex shape is the sum of the lengths of all of its edges
  - Your program should work on a file regardless of the number of points in the file

File Structure:
  - The file contains only binary integers
  - This means if you open the file in a text editor it will look like the values are gibberish because the file is not a text file but a binary file
  - The first integer in the file is the number of points in the file
  - The remaining pairs of integers represent the positions of the shape's vertices in 2D space
  - If you actually look at the points in the file you will see that they won't always correctly represent a convex shape because it was too hard to figure out how to generate the random points and still have a legal shape. Despite this, treat the points as if they actually formed a legal shape.
  - There is an edge between each vertex in the file and the vertex after it.
  - There is also an edge between the last vertex and the first vertex
  - There will always be at least 3 vertices per file

## Restrictions
  - You may not allocate fixed sized arrays for this problem. If you do you will receive ZERO CREDIT on this assignment.
  - As an example, a fixed size array could be an array of 100 characters or 100 ints regardless of whether you statically allocated it, char array[100], or dynamically allocated it, char another_array = (char*)(calloc(100, sizeof(char)).
  - You can of course still make space in your program, but it shouldn't be an arbitrary, fixed amount that never changes
## Assumptions
Input will always be valid

## Valid Input
  - File Path: the path to the binary file containing the shape
    - This will be passed as the first command line parameter
## Requirements
  - Your program must have and meaningfully use a struct that represents a point in 2D space
  - You must use have at least 2 functions in your program

# Examples

## Example 1
In this example, assume that the file example.bin contained the following values in BINARY. I'm displaying the file as text below to help you get an understanding of what the file looks like but remember the file is in BINARY with no spaces between any of the values.

3
287 422
283 -981
781 647
./perimeter.out example.bin

The perimeter is 3648.30
