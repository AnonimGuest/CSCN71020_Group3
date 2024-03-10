#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define NUMBEROFPOINTS 4
#define PI 3.14
#define RIGHTANGLE 90

//function definitions
void findCorners(int points[4][2], int bottom_left[2], int bottom_right[2], int top_left[2], int top_right[2]);
int calculateSideLength(int point1[2], int point2[2]);

bool isRectangle(int points[4][2]) {
	int bottom_left[2];
	int bottom_right[2];
	int top_left[2];
	int top_right[2];

	findCorners(points, bottom_left, bottom_right, top_left, top_right);

	int side1 = calculateSideLength(top_left, top_right); //top side
	int side2 = calculateSideLength(top_right, bottom_right); //right side
	int side3 = calculateSideLength(bottom_right, bottom_left); //bottom side
	int side4 = calculateSideLength(bottom_left, top_left); //left side

	int diagonal1 = calculateSideLength(top_left, bottom_right);
	int diagonal2 = calculateSideLength(top_right, bottom_left);

	////NEED ANGLE CODE FROM TRIANGLE CODE TO CHECK FOR RIGHT ANGLES HERE

	return (side1 == side3 && side2 == side4) && (diagonal1 == diagonal2) ;
}

//identifiying the corners
void findCorners(int points[4][2], int bottom_left[2], int bottom_right[2], int top_left[2], int top_right[2]) {
	printf("Points:\n");
	for (int i = 0; i < NUMBEROFPOINTS; i++) {
		printf("(%d, %d)\n", points[i][0], points[i][1]);
	}
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

int calculateSideLength(int point1[2], int point2[2]){
	return sqrt(pow((point2[0] - point1[0]), 2) + pow((point2[1] - point1[1]), 2));
}

int calculatePerimeter(int line1, int line2, int line3, int line4) {
	return (line1 + line2 + line3 + line4);
}

int calculateArea(int line1, int line2, int line3, int line4) {
	//checks to make sure the different length sides are multiplied
	//in the case of a square same length is multiplied
	return (line1 == line2) ? (line1 * line3) : (line1 * line2);
}
