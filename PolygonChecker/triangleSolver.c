#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"

#define SumAngles 180



const char* analyzeTriangle(int side1, int side2, int side3) {
	const char* result = "";

	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
		// angle calculation -- Equilateral 
		int angles = SumAngles / 3;
		printf("Angles: %d\n", angles);

	}
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2) || (side2 == side3 && side2 != side1)) {
		// angle calculation - Isosceles 
		double cosA, BcosA, sinA, BsinA, r1, r2, r3, r4;

		cosA = pow(side3, 2) + pow(side1, 2) - pow(side2, 2);
		BcosA = 2 * (side3) * (side1);
		r1 = cosA / BcosA;
		r2 = (acos(r1));

		// calculation for the other angle (different)
		r4 = SumAngles - 2 * (r2 * 180 / 3.14);
		
		if (side1 == side2) {
			printf("Angles 1 & 2: %.2lf\n", r2 * 180 / 3.14);
			printf("Angle 3: %.2lf\n", r4);

		} else if(side1 == side3) { 
			
			cosA = pow(side1, 2) + pow(side2, 2) - pow(side3, 2);
			BcosA = 2 * (side1) * (side2);
			r1 = cosA / BcosA;
			r2 = (acos(r1));

			// calculation for the other angle (different)
			r4 = SumAngles - 2 * (r2 * 180 / 3.14);

			printf("Angles 1 & 3: %.2lf\n", r2 * 180 / 3.14);
			printf("Angle 2: %.2lf\n",r4);	
		
		}
		else if(side2 == side3) {
			printf("Angles 2 & 3: %.2lf\n", r2 * 180 / 3.14);
			printf("Angle 1: %.2lf\n", r4);

		}

		result = "Isosceles triangle";
		
	} else {
		result = "Scalene triangle";

		// angle calculation -- Scalene 

		double cosA, BcosA, sinA, BsinA, r1, r2, r3, r4;
	// First Angle
		cosA = pow(side3, 2) - pow(side1, 2) - pow(side2, 2);
		BcosA = -2 * (side1) * (side2);
		r1 = cosA / BcosA;
		r2 = (acos(r1));

		//Second Angle
		sinA = (sin(r2) * (side1));
		BsinA = sinA / side3;
		r3 = (asin(BsinA));

		printf("Angle 1: %.2lf\n", r2 * 180 / 3.14);
		printf("Angle 2: %.2lf\n", r3 * 180 / 3.14);

		// Thrid Angle
		r4 = SumAngles - r2 * 180 / 3.14 - r3 * 180 / 3.14;
		printf("Angle 3: %.2lf\n", r4);

	}
	return result;
}


	

	

	
		







