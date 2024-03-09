#include <stdio.h>
#include <stdbool.h>
#include "triangleSolver.h"

const char* analyzeTriangle(double side1, double side2, double side3) {
	const char* result = "";

	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2)) {
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}
	return result;
}