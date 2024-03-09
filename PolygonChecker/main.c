#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
#include <math.h>

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
                // Gather and check points for a rectangle
                if (gatherAndCheckPoints(pointsArray)) {
                    // Check if the points form a rectangle
                    if (isRectangle(pointsArray)) {
                        printf("The points form a rectangle.\n");

                        // Additional logic or calculations for a rectangle can be added here

                    } else {
                        printf("The points do not form a rectangle.\n");
                    }
                } else {
                    printf("Please enter integers for coordinates.\n");
                }
			break; 
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	int pointsArray[4][2] = { {2, 3}, {3, 4}, {5, 6}, {8, 9} };
	isRectangle(pointsArray);
	
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

bool gatherAndCheckPoints(int points[NUMBER_OF_POINTS][2]) {
    printf("Enter coordinates for four points (x y):\n");

    for (int i = 0; i < NUMBER_OF_POINTS; ++i) {
        printf("Point %d: ", i + 1);

        // Validate input for x coordinate
        if (scanf("%d", &points[i][0]) != 1) {
            printf("Invalid input for x coordinate.\n");
            return false;
        }

        // Validate input for y coordinate
        if (scanf("%d", &points[i][1]) != 1) {
            printf("Invalid input for y coordinate.\n");
            return false;
        }
    }

    // Clear input buffer
    while (getchar() != '\n');

    return true;
}

// Function to check if the points form a rectangle
bool isRectangle(int points[NUMBER_OF_POINTS][2]) {
    // Implement the logic to check if the points form a rectangle

    // Calculate distances between consecutive points
    float side1 = sqrt(pow(points[0][0] - points[1][0], 2) + pow(points[0][1] - points[1][1], 2));
    float side2 = sqrt(pow(points[1][0] - points[2][0], 2) + pow(points[1][1] - points[2][1], 2));
    float side3 = sqrt(pow(points[2][0] - points[3][0], 2) + pow(points[2][1] - points[3][1], 2));
    float side4 = sqrt(pow(points[3][0] - points[0][0], 2) + pow(points[3][1] - points[0][1], 2));

    // Check if opposite sides are equal
    bool oppositeSidesEqual = (side1 == side3) && (side2 == side4);

    // Check if opposite sides are parallel (checking slopes)
    bool oppositeSidesParallel = (points[1][0] - points[0][0]) * (points[2][1] - points[3][1]) ==
                                 (points[2][0] - points[3][0]) * (points[1][1] - points[0][1]);

    return oppositeSidesEqual && oppositeSidesParallel;
}

