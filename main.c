#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "conversion_data.c"
#include "calcultor.c"

void clearScreen(void);


void unitsMessage(short int, short int, short int *); // 0 -> fromUnit, 1 -> toUnit

void main()
{
	int choice;
	char userInput, userInput1;
	short int a, c;
	short int fromUnit, toUnit;
	float fromMagnitude, toMagnitude;

	while (1)
	{

		printf("Hey ! press 1 to use calculator or press 2 to use unit converter \n");
		puts("1)calculator");
		puts("2)Unit converter");
		puts("Q) Quit to Desktop");
		while (1)
		{
			userInput1 = getch();

			if (userInput1 == '1')
			{
				clearScreen();
				a = 1;
				break;
			}
			else if (userInput1 == '2')
			{
				clearScreen();
				a = 2;
				break;
			}

			else if (userInput1 == 'Q' || userInput1 == 'q')
				exit(0);
		}

		if (a == 1)
		{
			clearScreen();
			printf("\t\tWelcome to the scientific calculator!!\n\n");

			printf("\n******* Press 0 to quit the program ********\n");
			printf("Enter 1 for Addition \n");
			printf("Enter 2 for Subtraction \n");
			printf("Enter 3 for Multiplication \n");
			printf("Enter 4 for Division \n");
			printf("Enter 5 for Modulus\n");
			printf("Enter 6 for Power \n");
			printf("Enter 7 for Factorial \n");
			printf("Enter 8  for square \n");
			printf("Enter 9  for cube \n");
			printf("Enter 10 for squareroot\n\n");

			while (1)
			{

				printf("\n\nEnter the operation you want to do: ");

				scanf("%d", &choice);

				switch (choice)
				{
				case 1:
					addition();
					break;
				case 2:
					subtraction();
					break;
				case 3:
					multiplication();
					break;
				case 4:
					division();
					break;
				case 5:
					modulus();
					break;
				case 6:
					power();
					break;
				case 7:
					factorial();
					break;
				case 8:
					square();
					break;
				case 9:
					cube();
					break;
				case 10:
					squareroot();
					break;
				case 0:
					exit(0);
				default:
					printf("\n******* %s ********\n", note);
				}
				exit(0);
			}
		}

		else
		{
			while (1)
			{

				clearScreen();
				printf("Hey there! Welcome to Unit Converter!\n");
				printf("Please press the Number Key according to the option you want to go with.\n");
				puts("1) Distance Converter");
				puts("2) Mass Converter");
				puts("3) Volume Converter");
				puts("Q) Quit to Desktop");

				while (1)
				{
					userInput = getch();

					if (userInput == '1')
					{
						clearScreen();
						c = 1;
						break;
					}
					else if (userInput == '2')
					{
						clearScreen();
						c = 2;
						break;
					}
					else if (userInput == '3')
					{
						clearScreen();
						c = 3;
						break;
					}

					else if (userInput == 'Q' || userInput == 'q')
					{
						exit(0);
					}
				}

				unitsMessage(c, 0, &fromUnit); // taking 'From' unit from the user
				unitsMessage(c, 1, &toUnit);   // taking 'To' unit from the user

				printf("Enter Magnitude ");
				switch (c)
				{
				case 1:
					switch (fromUnit)
					{
					case 1:
						printf("(in km):\n");
						break;
					case 2:
						printf("(in m):\n");
						break;
					case 3:
						printf("(in cm):\n");
						break;
					case 4:
						printf("(in miles):\n");
						break;
					case 5:
						printf("(in yards):\n");
						break;
					case 6:
						printf("(in mm):\n");
						break;
					case 7:
						printf("(in feet):\n");
						break;
					case 8:
						printf("(in inches):\n");
						break;
					default:
						printf("(in ?)\n");
						break;
					}
					break;
				case 2:
					switch (fromUnit)
					{
					case 1:
						printf("(in kg):\n");
						break;
					case 2:
						printf("(in g):\n");
						break;
					case 3:
						printf("(in mg):\n");
						break;
					case 4:
						printf("(in tonne):\n");
						break;
					case 5:
						printf("(in US ton):\n");
						break;
					case 6:
						printf("(in pounds):\n");
						break;
					case 7:
						printf("(in stones):\n");
						break;
					case 8:
						printf("(in ounces):\n");
						break;
					default:
						printf("(in ?)\n");
						break;
					}
					break;
				case 3:
					switch (fromUnit)
					{
					case 1:
						printf("(in cubic m):\n");
						break;
					case 2:
						printf("(in L):\n");
						break;
					case 3:
						printf("(in mL):\n");
						break;
					case 4:
						printf("(in US liquid gallons):\n");
						break;
					case 5:
						printf("(in US legal cups):\n");
						break;
					case 6:
						printf("(in US tablespoons):\n");
						break;
					case 7:
						printf("(in Imperial gallons):\n");
						break;
					case 8:
						printf("(in Imperial cups):\n");
						break;
					case 9:
						printf("(in Imperial tablespoons):\n");
						break;
					case 0:
						printf("(in fluid ounces):\n");
						break;
					default:
						printf("(in ?)\n");
						break;
					}
					break;
				}

				scanf("%f", &fromMagnitude);

				toMagnitude = convertData(c, fromUnit, toUnit, fromMagnitude);
				printf("Magnitude in ");
				switch (c)
				{
				case 1:
					switch (toUnit)
					{
					case 1:
						printf("km\n:");
						break;
					case 2:
						printf("m:\n");
						break;
					case 3:
						printf("cm:\n");
						break;
					case 4:
						printf("miles:\n");
						break;
					case 5:
						printf("yards:\n");
						break;
					case 6:
						printf("mm:\n");
						break;
					case 7:
						printf("feet:\n");
						break;
					case 8:
						printf("inches:\n");
						break;
					default:
						printf("?\n");
						break;
					}
					break;
				case 2:
					switch (toUnit)
					{
					case 1:
						printf("kg:\n");
						break;
					case 2:
						printf("g:\n");
						break;
					case 3:
						printf("mg:\n");
						break;
					case 4:
						printf("tonne:\n");
						break;
					case 5:
						printf("US ton:\n");
						break;
					case 6:
						printf("pounds:\n");
						break;
					case 7:
						printf("stones:\n");
						break;
					case 8:
						printf("ounces:\n");
						break;
					default:
						printf("?\n");
						break;
					}
					break;
				case 3:
					switch (toUnit)
					{
					case 1:
						printf("cubic m:\n");
						break;
					case 2:
						printf("L:\n");
						break;
					case 3:
						printf("mL:\n");
						break;
					case 4:
						printf("US liquid gallons:\n");
						break;
					case 5:
						printf("US legal cups:\n");
						break;
					case 6:
						printf("US tablespoons:\n");
						break;
					case 7:
						printf("Imperial gallons:\n");
						break;
					case 8:
						printf("Imperial cups:\n");
						break;
					case 9:
						printf("Imperial tablespoons:\n");
						break;
					case 0:
						printf("fluid ounces:\n");
						break;
					default:
						printf("?\n");
						break;
					}
					break;
				}
				printf("%f", toMagnitude);

				getch();
			}
		}
	}

}

void unitsMessage(short int c, short int unit, short int *u)
{
	int userInput;
	if (unit == 0)
		printf("Choose 'From' Unit:\n");
	else
		printf("Choose 'To' Unit:\n");

	switch (c)
	{
	case 1:
		puts("1) Kilometers (km)");
		puts("2) Meters (m)");
		puts("3) Centimeters (cm)");
		puts("4) Miles");
		puts("5) Yards");
		puts("6) Milimeters (mm)");
		puts("7) Feet");
		puts("8) Inches");
		break;
	case 2:
		puts("1) Kilograms (kg)");
		puts("2) Grams (g)");
		puts("3) Miligrams (mg)");
		puts("4) Tonne");
		puts("5) US Ton");
		puts("6) Pounds");
		puts("7) Stones");
		puts("8) Ounces");
		break;
	case 3:
		puts("1) Cubic Meters");
		puts("2) Litres (L)");
		puts("3) Mililitres (mL)");
		puts("4) US Liquid Gallons");
		puts("5) US Legal Cups");
		puts("6) US Tablespoons");
		puts("7) Imperial Gallons");
		puts("8) Imperial Cups");
		puts("9) Imperial Tablespoons");
		puts("0) Fluid Ounces");
		break;
	}

	while (1)
	{
		userInput = getch();

		if (userInput == '1')
		{
			clearScreen();
			*u = 1;
			break;
		}
		else if (userInput == '2')
		{
			clearScreen();
			*u = 2;
			break;
		}
		else if (userInput == '3')
		{
			clearScreen();
			*u = 3;
			break;
		}
		else if (userInput == '4')
		{
			clearScreen();
			*u = 4;
			break;
		}
		else if (userInput == '5')
		{
			clearScreen();
			*u = 5;
			break;
		}
		else if (userInput == '6')
		{
			clearScreen();
			*u = 6;
			break;
		}
		else if (userInput == '7')
		{
			clearScreen();
			*u = 7;
			break;
		}
		else if (userInput == '8')
		{
			clearScreen();
			*u = 8;
			break;
		}
		else if (userInput == '9')
		{
			clearScreen();
			*u = 9;
			break;
		}
		else if (userInput == '0')
		{
			clearScreen();
			*u = 0;
			break;
		}
	}
}

void clearScreen()
{
	system("cls");
}
