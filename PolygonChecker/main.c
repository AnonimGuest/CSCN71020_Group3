#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"


int main() {
	bool continueProgram = true;
	while (continueProgram) {
		
		printWelcome();
		
		int shapeChoice = printShapeMenu();

		switch (shapeChoice) {
		case 1:
			printf_s("Triangle selected.\n");
			double triangleSides[3] = { 0.0, 0.0, 0.0 };
			double* triangleSidesPtr = getTriangleSides(triangleSides);
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			break; 
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}


int printShapeMenu() { 
	double shapeChoice;

	while (1) {
		printf_s("1. Triangle\n");
		printf_s("2. Rectangle\n");
		printf_s("0. Exit\n");

		printf_s("Enter number: ");

		if (scanf_s("%lf", &shapeChoice) != 1 || (int)shapeChoice != shapeChoice || (shapeChoice < 0 || shapeChoice > 2)) {
			printf_s("Invalid input. Please enter a valid integer.\n\n");
			while (getchar() != '\n');
		}
		else {
			break;
		}
	}
	return (int)shapeChoice;
}


double* getTriangleSides(double* triangleSides) {

	const char* sideNames[3] = {"first", "second", "third"};

	for (int i = 0; i < 3; ++i) {
		do {
			printf("Enter %s side of the triangle: ", sideNames[i]);
			if (scanf_s("%lf", &triangleSides[i]) != 1 || triangleSides[i] <= 0) {
				printf("Invalid input. Please enter a positive number.\n");
				while (getchar() != '\n');
			}
			else {
				break;
			}
		} while (1);
	}

	const char* triangleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);
	printf("Triangle type: %s\n", triangleType);

	return triangleSides;
}

