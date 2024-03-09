#include <stdio.h>
#include <stdbool.h>

#define NUMBEROFPOINTS 4

//function definitions
void findCorners(int points[4][2], int bottom_left[2], int bottom_right[2], int top_left[2], int top_right[2]);
float calculateSideLength(int point1[2], int point2[2]);

bool isRectangle(int points[4][2]) {
	int bottom_left[2];
	int bottom_right[2];
	int top_left[2];
	int top_right[2];

	findCorners(points, bottom_left, bottom_right, top_left, top_right);

	float side3 = calculateSideLength(top_left, top_right);
	float side4 = calculateSideLength(top_right, bottom_right);
	float side1 = calculateSideLength(bottom_right, bottom_left);
	float side2 = calculateSideLength(bottom_left, top_left);

	return true;
}

//identifiying the corners
void findCorners(int points[4][2], int bottom_left[2], int bottom_right[2], int top_left[2], int top_right[2]) {
	//top-left:min x, max y, top-right:max x, max y
	//bottom-left:min x, min y, bottom-right: max x, min y
	//setting initial min and max coordinates
	int minX = points[0][0];
	int minY = points[0][1];
	int maxX = points[0][0];
	int maxY = points[0][1];

	//setting actual min and max x&y
	for (int array_counter = 0; array_counter < NUMBEROFPOINTS; array_counter++) {
		minX = points[array_counter][0] < minX ? points[array_counter][0] : minX;
		minY = points[array_counter][1] < minY ? points[array_counter][1] : minY;
		maxX = points[array_counter][0] > maxX ? points[array_counter][0] : maxX;
		maxY = points[array_counter][1] > maxY ? points[array_counter][1] : maxY;
	}
	//for debugging - remove later
	printf("%d, %d, %d, %d", maxX, maxY, minX, minY);

	//set the corners values 
	bottom_left[0] = minX;
	bottom_left[1] = minY;
	bottom_right[0] = maxX;
	bottom_right[1] = minY;
	top_left[0] = minX;
	top_left[1] = maxY;
	top_right[0] = maxX;
	top_right[1] = maxY;
}

float calculateSideLength(int point1[2], int point2[2]){
	//harjas add your code for side length here ******
}

float calculatePerimeter(float line1, float line2, float line3, float line4) {
	return (line1 + line2 + line3 + line4);
}

float calculateArea(float line1, float line2, float line3, float line4) {
	//checks to make sure the different length sides are multiplied
	//in the case of a square same length is multiplied
	return (line1 == line2) ? (line1 * line3) : (line1 * line2);
}
