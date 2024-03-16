#define  _CRT_SECURE_NO_WARNINGS
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
			int pointsArray[4][2];
                // Gather and check points for a rectangle
                if (gatherAndCheckPoints(pointsArray)) {
                    // Check if the points form a rectangle
                    if (isRectangle(pointsArray)) {
                        printf("The points form a rectangle.\n"); 
						//find side lengths 
						int line1 = calculateSideLength(pointsArray[0], pointsArray[1]);
						int line2 = calculateSideLength(pointsArray[1], pointsArray[2]);
						int line3 = calculateSideLength(pointsArray[2], pointsArray[3]);
						int line4 = calculateSideLength(pointsArray[3], pointsArray[0]);

						printf("The perimeter of the rectangle is: %d\n", calculatePerimeter(line1, line2, line3, line4));
						printf("The area of the rectangle is: %d\n", calculateArea(line1, line2, line3, line4));
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

        for (int j = 0; j < i; ++j) {
            if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                printf("Error: Duplicate points detected.\n");
                return false;
            }
        }

        // Clear input buffer
        while (getchar() != '\n');

        return true;
    }
}

