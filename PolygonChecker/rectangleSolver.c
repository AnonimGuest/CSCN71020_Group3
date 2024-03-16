#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rectangleSolver.h"

#define NUMBEROFPOINTS 4
#define PI 3.14
#define RIGHTANGLE 90

//function definitions
bool findCorners(int points[4][2], int bottom_left[2], int bottom_right[2], int top_left[2], int top_right[2]);
int calculateSideLength(int point1[2], int point2[2]);

bool isRectangle(int points[4][2]) {
	int bottom_left[2];
	int bottom_right[2];
	int top_left[2];
	int top_right[2];

	if (!findCorners(points, bottom_left, bottom_right, top_left, top_right)) {
		return false;
	}
	else {
		int top_side = calculateSideLength(top_left, top_right); //top side
		int right_side = calculateSideLength(top_right, bottom_right); //right side
		int bottom_side = calculateSideLength(bottom_right, bottom_left); //bottom side
		int left_side = calculateSideLength(bottom_left, top_left); //left side

		double diagonal1 = sqrt(top_side * top_side + right_side * right_side);
		double diagonal2 = sqrt(bottom_side * bottom_side + left_side * left_side);
		//printf("top_side: %d right_side: %d bottom_side: %d left_side: %d diag1: %f diag2: %f \n", top_side, right_side, bottom_side, left_side, sqrt(top_side * top_side + right_side * right_side), sqrt(bottom_side * bottom_side + left_side * left_side));

		return (top_side == bottom_side && right_side == left_side && top_side != right_side) && (diagonal1 == diagonal2);
	}
}

//identifiying the corners
bool findCorners(int points[4][2], int bottom_left[2], int bottom_right[2], int top_left[2], int top_right[2]) {
	//printf("Points:\n");
	//for (int i = 0; i < NUMBEROFPOINTS; i++) {
	//	printf("(%d, %d)\n", points[i][0], points[i][1]);
	//}
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

	//top-left:min x, max y, top-right:max x, max y
    //bottom-left:min x, min y, bottom-right: max x, min y
	for (int array_counter = 0; array_counter < NUMBEROFPOINTS; array_counter++) {
		if (points[array_counter][0] == minX && points[array_counter][1] == maxY) { //top-left
			top_left[0] = points[array_counter][0];
			top_left[1] = points[array_counter][1];
		}
		else if ((points[array_counter][0] == maxX && points[array_counter][1] == maxY)) { //top-right
			top_right[0] = points[array_counter][0];
			top_right[1] = points[array_counter][1];
		}
		else if ((points[array_counter][0] == maxX && points[array_counter][1] == minY)) { //bottom-right
			bottom_right[0] = points[array_counter][0];
			bottom_right[1] = points[array_counter][1];
		}
		else if ((points[array_counter][0] == minX && points[array_counter][1] == minY)) { //bottom-left
			bottom_left[0] = points[array_counter][0];
			bottom_left[1] = points[array_counter][1];
		}
		else {
			return false;
		}
	}
	return true;
	//printf("corners %d %d %d %d %d %d %d %d\n", bottom_left[0], bottom_left[1], bottom_right[0], bottom_right[1], top_left[0], top_left[1], top_right[0], top_right[1]);
}

int calculateSideLength(int point1[2], int point2[2]) {
	return sqrt(pow((point1[0] - point2[0]), 2) + pow((point1[1] - point2[1]), 2));
}

double calculateDiagonal(double line1, double line2) {
	return sqrt(line1 * line1 + line2 * line2);
}

int calculatePerimeter(int line1, int line2, int line3, int line4) {
	return (line1 + line2 + line3 + line4);
}

int calculateArea(int line1, int line2, int line3, int line4) {
	//checks to make sure the different length sides are multiplied
	return (line1 == line2) ? (line1 * line3) : (line1 * line2);
}

