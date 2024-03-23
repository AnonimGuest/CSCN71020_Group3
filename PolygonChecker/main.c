#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
#define NUMSIDES 3

void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}

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

int printShapeMenu() {
    double shapeChoice;
    char input[20];

    while (1) {
        printf_s("1. Triangle\n");
        printf_s("2. Rectangle\n");
        printf_s("0. Exit\n");

        printf_s("Enter number: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf_s("Error reading input.\n");
            continue;
        }

        if (sscanf(input, "%lf", &shapeChoice) != 1 || (int)shapeChoice != shapeChoice || (shapeChoice < 0 || shapeChoice > 2)) {
            printf_s("Invalid input. Please enter a valid integer between 0 and 2.\n\n");
        }
        else {
            break;
        }
    }

    return (int)shapeChoice;
}


double* getTriangleSides(double* triangleSides) {
    const char* sideNames[NUMSIDES] = { "first", "second", "third" };

    for (int i = 0; i < NUMSIDES; ++i) {
        while (1) {
            printf("Enter %s side of the triangle: ", sideNames[i]);

            char input[20];
            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("Error reading input.\n");
                exit(1);
            }

            char* endptr;
            double value = strtod(input, &endptr);

            if (endptr != input && *endptr == '\n' && value > 0 && input[0] != '.') {
                triangleSides[i] = value;
                break;
            }

            printf("Invalid input. Please enter a valid positive number.\n");
        }
    }

    const char* triangleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);
    printf("Triangle type: %s\n", triangleType);

    return triangleSides;
}


bool gatherAndCheckPoints(int points[NUMBER_OF_POINTS][2]) {
	printf("Enter coordinates for four points (x y):\n");

	for (int i = 0; i < NUMBER_OF_POINTS; ++i) {
		printf("Point %d: ", i + 1);

		char input[100];
		if (fgets(input, sizeof(input), stdin) == NULL) {
			printf("Error reading input.\n");
			return false;
		}

		// Parse input using sscanf
		if (sscanf(input, "%d %d", &points[i][0], &points[i][1]) != 2) {
			printf("Invalid input format.\n");
			return false;
		}

		// Check for duplicate points
		for (int j = 0; j < i; ++j) {
			if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
				printf("Error: Duplicate points detected.\n");
				return false;
			}
		}

		// Clear input buffer
		while (getchar() != '\n');
	}

    // Test the function with some test cases
    //bool success = gatherAndCheckPoints(points);
    //if (success) {
        //printf("Points successfully gathered.\n");
        // Now you can use the points array for further processing
    //} else {
        //printf("Failed to gather points.\n");
    //}

	return true;
}

