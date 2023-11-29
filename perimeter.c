#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point 
{
    int x;
    int y;
} Point;

int FindNumPoints(char* fileName);
Point* FindPoints(char* fileName); 
double DistanceFormula(int x1, int y1, int x2, int y2);
void CalcPerim(char* fileName, Point* points);

/*
Function reads the first number in a file when if formatted correctly, 
is the number of points in the rest of the file
@fileName: the name of the input file
@returns: the number of points in the file
*/
int FindNumPoints(char* fileName)
{
    FILE* file = fopen(fileName, "rb");
    int numPoints;
    fread(&numPoints, sizeof(int), 1, file);
    fclose(file);

    return numPoints;
}

/*
Function reads the points containted within a file if formatted correctly
@fileName: the name of the input file
@returns: an array of points (x,y)
*/
Point* FindPoints(char* fileName) 
{
    FILE* file = fopen(fileName, "rb");
    int numPoints = FindNumPoints(fileName);
    Point* points = (Point*)malloc(numPoints * sizeof(Point));

    fseek(file, sizeof(int), SEEK_SET);
    for (int i=0; i < numPoints; i++)
    {
        fread(&(points[i].x), sizeof(int), 1, file);
        fread(&(points[i].y), sizeof(int), 1, file);
    }
    fclose(file);
    return points;
}

/*
Function takes two points (x,y) and calculates the distance between them
@x1: 1st x coord
@y1: 1st y coord
@x2: 2nd x coord
@y2: 2nd y coord
@returns: the distance between the two points
*/
double DistanceFormula(int x1, int y1, int x2, int y2)
{
    return sqrt((pow((double)x2-(double)x1, 2)) + (pow((double)y2-(double)y1, 2)));
}


/*
Function takes a file and an array of points to calculate the perimeter if connected
@fileName: the name of the file input
@points: an array of points (x,y)
@returns: nothing, prints the perimeter
*/
void CalcPerim(char* fileName, Point* points)
{
    double total = 0;

    int numPoints = FindNumPoints(fileName);

    for (int i=0; i < numPoints - 1; i++)
    {
        total += DistanceFormula(points[i].x, points[i].y, points[i+1].x, points[i+1].y);
    }
    total += DistanceFormula(points[0].x, points[0].y, points[numPoints-1].x, points[numPoints-1].y);
    printf("The perimeter is %.2lf", total);
}


/*
Function reads the points containted within a file if formatted correctly
@fileName: the name of the input file
@returns: an array of points (x,y)
*/
int main(int argc, char** argv)
{
    Point* points = FindPoints(argv[1]);
    CalcPerim(argv[1], points);
}