#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"
#define SumAngles 180

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
		// angle calculation

		int angles = SumAngles/3;
		printf("Angles: %d\n", angles); 
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
		// angle calculation 
	}
	else {
		result = "Scalene triangle";
		// angle calculation 
	}

	return result;
}