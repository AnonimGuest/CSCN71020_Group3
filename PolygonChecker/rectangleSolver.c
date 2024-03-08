#include <stdio.h>
#include <stdbool.h>

/*
* Add a new feature to the application program to accept four points. Each point is an x,y pair.
You may ask the user to enter the x and y one at a time, or at once and split the input yourself.
There should be some validation on the user input to ensure you are given proper values. Once
given the four points, generate four lines and determine if these lines form a rectangle. You
may find it useful to re-use your triangle angle code to assist this, but you may use a unique
function to determine if the lines make a rectangle. Report the shape's perimeter, and if it is a
rectangle also report its area.

The second approach is to write code to determine which "corner" each point is, and
then connect the corners to form the shape. Using this approach, no matter the
order the points are entered, no lines will cross. This approach is worth extra marks.*/

#define NUMBEROFPOINTS 4
//define x and y to replace 0 and 1

bool isRectangle(int points[4][2]) {

	return true;

}

int findCornerArray(int points[2][4]) {
//identifiying the corners:
//top-left:min x, max y
//top-right:max x, max y
//bottom-left:min x, min y
//bottom-right: max x, min y

//setting initial min and max coordinates
	int minX = points[0][0];
	int minY = points[0][1];
	int maxX = points[0][0];
	int maxY = points[0][1];

	//setting actual min and max x&y 
	//can reduce with ? : format later
	for (int array_counter = 0; array_counter < NUMBEROFPOINTS; array_counter++) {
		if (points[array_counter][0] < minX) {
			minX = points[array_counter][0];
		}
		if (points[array_counter][1] < minY) {
			minY = points[array_counter][1];
		}
		if (points[array_counter][0] > maxX) {
			maxX = points[array_counter][0];
		}
		if (points[array_counter][1] > maxY) {
			maxY = points[array_counter][1];
		}
	}

	//find which corner each is and put into a corner array
	//identifiying the corners:
	//top-left:min x, max y
	//top-right:max x, max y
	//bottom-left:min x, min y
	//bottom-right: max x, min y
	int sorted_corner_array[2][4]; //IN ORDER: top-lft, top-right, bottom-left, bottom-right
	for (int counter = 0; counter < NUMBEROFPOINTS; counter++) {
		if (points[counter][0] == minX && points[counter][1] == minY) {
			sorted_corner_array[0][0] = points[counter][0];
			sorted_corner_array[0][1] = points[counter][1];
		}
	}

}

float calculatePerimeter(float line1, float line2, float line3, float line4) {
	return (line1 + line2 + line3 + line4);
}

float calculateArea(float line1, float line2, float line3, float line4) {
	//checks to make sure the different length sides are multiplied
	//in the case of a square same length is multiplied
	return (line1 == line2) ? (line1 * line3) : (line1 * line2);
}