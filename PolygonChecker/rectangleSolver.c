#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rectangleSolver.h"

#define NUMBEROFPOINTS 4
#define PI 3.14
#define RIGHTANGLE 90

//function definitions
int calculateSideLength(int point1[2], int point2[2]);
void sortPoints(int points[NUMBEROFPOINTS][2], int point1[2], int point2[2], int point4[2], int point3[2]);
void swapPlaces(int points[NUMBEROFPOINTS][2], int firstIndex, int secondIndex);

bool isRectangle(int points[4][2]) {
	int point1[2];
	int point2[2];
	int point4[2];
	int point3[2];
	sortPoints(points, point1, point2, point4, point3);

	int side1 = calculateSideLength(point4, point3);
	int side2 = calculateSideLength(point3, point2);
	int side3 = calculateSideLength(point2, point1); 
	int side4 = calculateSideLength(point1, point4); 

	double diagonal1 = sqrt(side1 * side1 + side2 * side2);
	double diagonal2 = sqrt(side3 * side3 + side4 * side4);
	//printf("side1: %d side2: %d side3: %d side4: %d diag1: %f diag2: %f \n", side1, side2, side3, side4, sqrt(side1 * side1 + side2 * side2), sqrt(side3 * side3 + side4 * side4));

	return (side1 == side3 && side2 == side4 && side1 != side2) && (diagonal1 == diagonal2);
}

int calculateSideLength(int point1[2], int point2[2]) {
	return sqrt(pow((point1[0] - point2[0]), 2) + pow((point1[1] - point2[1]), 2));
}

int calculatePerimeter(int line1, int line2, int line3, int line4) {
	return (line1 + line2 + line3 + line4);
}

int calculateArea(int line1, int line2, int line3, int line4) {
	//checks to make sure the different length sides are multiplied
	return (line1 == line2) ? (line1 * line3) : (line1 * line2);
}

void sortPoints(int points[NUMBEROFPOINTS][2], int point1[2], int point2[2], int point4[2], int point3[2]) {
	//sorta the array of points by lowest to highest x value, if x is the same the one with lowest y val comes first
	for (int currentIndex= 0; currentIndex< NUMBEROFPOINTS - 1; currentIndex++) { //loop through each of the points
		for (int nextIndex = currentIndex+ 1; nextIndex < NUMBEROFPOINTS; nextIndex++) { //loops through the points that are after the current index 
			if (points[currentIndex][0] > points[nextIndex][0]) {//compare the x value of the points
				swapPlaces(points, currentIndex, nextIndex); //swich the places of the points if the currentindex x val is greater
			}
			//if the x values are equal, compare the y values of the points 
			else if (points[currentIndex][0] == points[nextIndex][0] && points[currentIndex][1] > points[nextIndex][1]) {
				swapPlaces(points, currentIndex, nextIndex); //swich the places of the points if the currentindex y val is greater
			}
		}
	}
		point1[0] = points[0][0];
		point1[1] = points[0][1];
		point2[0] = points[1][0];
		point2[1] = points[1][1];
		point3[0] = points[3][0]; //point3= [3][] and point4 =[2][] need to be this way to ensure proper order of points
		point3[1] = points[3][1];
		point4[0] = points[2][0];
		point4[1] = points[2][1];
}

void swapPlaces(int points[NUMBEROFPOINTS][2], int firstIndex, int secondIndex) {
	int temporaryXValue = points[firstIndex][0]; // store the first points x and y value in temporary variable
	int temporaryYValue = points[firstIndex][1];
	//switch the place of the first point and second point
	points[firstIndex][0] = points[secondIndex][0]; //move the second point to where the first one was
	points[firstIndex][1] = points[secondIndex][1];
	points[secondIndex][0] = temporaryXValue; //move the first point's x and y value (stored in temp) to the second point's old spot
	points[secondIndex][1] = temporaryYValue;
}