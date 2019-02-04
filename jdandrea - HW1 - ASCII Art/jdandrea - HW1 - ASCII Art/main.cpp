#include <iostream>
#include <string>

using namespace std;

// Displays intro message
int Intro()
{
	int selectionChoice;

	// Intro Prompt
	cout << "Welcome to the shape renderer!" << endl;
	cout << "You can draw a few different shapes at a variety of sizes!" << endl;
	cout << "********************************************************************************" << endl;
	cout << "* Please select a menu option(1 - 6) :" << endl;
	cout << "* 1 - Square" << endl;
	cout << "* 2 - Right Triangle" << endl;
	cout << "* 3 - Isoceles Triangle" << endl;
	cout << "* 4 - Hourglass" << endl;
	cout << "* 5 - Diamond" << endl;
	cout << "* 6 - Quit (exit application)" << endl;
	cout << "********************************************************************************" << endl;
	cout << "Please select a menu option(1-6)" << endl;
	cin >> selectionChoice;

	// Loops to ensure a proper selection has been made
	while (selectionChoice > 6 || selectionChoice <= 0)
	{
		cout << "You have not selected a valid menu option, please try again." << endl;
		cin >> selectionChoice;
	}

	// returns an appropriate choice
	return selectionChoice;
}

// Prototype Function Calls
int ShapeSelection(int& selectionChoice);
void Square(int& size);
void RightTriangle(int& size);
void IsoscelesTriangle(int& size,int& selectionChoice);
void HourGlass(int& size, int& selectionChoice);
void Diamond(int& size, int& selectionChoice);

// Main function to run Application
int main()
{
	// Intro StartUp
	int selectionChoice = Intro();

	// Shape Selection
	ShapeSelection(selectionChoice);

	return 0;
}
	
// Function for choosing the desired shape
int ShapeSelection(int& selectionChoice)
{
	// shape size variable
	int size;

	// Switch case based on the user choice
	switch (selectionChoice)
	{
		// Case for ASCII Square
		case 1:
		{
			cout << "You have selected a square!  What size should your square be (1-20)?" << endl;
			cin >> size;
			while (size <= 0 || size > 20)
			{
				cout << "You have not selected an appropriate size, please try again." << endl;
				cout << "Please give your desired size: " << endl;
				cin >> size;
			}
			Square(size);
			return size;
		}
		// Case for ASCII Right Triangle
		case 2:
		{
			cout << "You have selected a right triangle!  What size should your right triangle be (1-20)?" << endl;
			cin >> size;
			while (size <= 0 || size > 20)
			{
				cout << "You have not selected an appropriate size, please try again." << endl;
				cout << "Please give your desired size: " << endl;
				cin >> size;
			}
			RightTriangle(size);
			return size;
		}
		// Case for ASCII Isosceles Triangle
		case 3:
		{
			cout << "You have selected a isosceles triangle!  What size should your isosceles triangle be (1-20)?" << endl;
			cin >> size;
			while (size <= 0 || size > 20)
			{
				cout << "You have not selected an appropriate size, please try again." << endl;
				cout << "Please give your desired size: " << endl;
				cin >> size;
			}
			IsoscelesTriangle(size, selectionChoice);
			return size;
		}
		// Case for ASCII HourGlass
		case 4:
		{
			cout << "You have selected an hourglass!  What size should your hourglass be (1-20)?" << endl;
			cin >> size;
			while (size <= 0 || size > 20)
			{
				cout << "You have not selected an appropriate size, please try again." << endl;
				cout << "Please give your desired size: " << endl;
				cin >> size;
			}
			HourGlass(size, selectionChoice);
			return size;
		}
		// Case for ASCII Diamond
		case 5:
		{
			cout << "You have selected a diamond!  What size should your diamond be (1-20)?" << endl;
			cin >> size;
			while (size <= 0 || size > 20)
			{
				cout << "You have not selected an appropriate size, please try again." << endl;
				cout << "Please give your desired size: " << endl;
				cin >> size;
			}
			Diamond(size, selectionChoice);
			return size;
		}
		// Quit Application
		case 6:
		{
			cout << "Thank you for using our application!  Good-bye!";
			return 0;
		}
	}
}

// Function for drawing an ASCII Square
// Takes in a size parameter
void Square(int& size)
{
	// Loop for drawing the desired square
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			// ASCII art drawn to console
			cout << "*";
		}
		cout << " " << endl;
	}
	cout << "********************************************************************************" << endl;

	// restarts application
	main();
}

// Function used for drawing Right Triangles
// Takes in a size parameter
void RightTriangle(int& size)
{
	// bases the height of the triangle on inputed size
	for (int i = 0; i < size; i++)
	{
		// ensures that 1 less "*" is printed per row
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << " " << endl;
	}
	cout << "********************************************************************************" << endl;

	// restarts application
	main();

}

// Function used to draw an Isoceles Triangle
// Takes in a size parameter and selection choice for function reusability
void IsoscelesTriangle(int& size, int& selectionChoice)
{
	// allows for diamond reusability
	int height = size;
	// size - 1 so that an extra row is not printed in Diamond creation
	if (selectionChoice == 5) { height = size - 1; }

	int baseLength = (size * 2) - 1;

	// The height of the triangle (i) is a constant height (size)
	for (int i = 1; i <= height; i++)
	{
		// the amount of "spaces" printed is always equal to the size minus 1 (j = size - 1)
		// once that is reached, it will move to the "*" printing in k loop
		// we "--" j so that it will eventually be < (size - 1) in order to stop the spaces and move to *
		for (int j = size; j >= i; j--)
		{
			cout << " ";
		}
		// k will print the current rows max base length
		// as "i" increments down column, k will know how long that "base" should be (k < (current row * 2) - 1) 
		for (int k = 0; k < (i * 2) - 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
	if (selectionChoice == 3)
	{
		cout << "********************************************************************************" << endl;

		// restarts application
		main();
	}
}
// Function that draws an Hourglass
// takes in size and selection choice for reusabilty in other functions
void HourGlass(int& size, int& selectionChoice)
{	
	// a counter used for proper "*" position
	int myCount = 0;
	int baseLength = (size * 2) - 1;
	
	// Allows for Diamond reusabilty
	// size + 1 in order to draw the tip of the diamond
	if (selectionChoice == 5) { size = size + 1; }

	// The height of the triangle (i) is a constant height (size)
	// to attached the regular Isosceles triangle to tip, size must lose 1 row 
	for (int i = 1; i <= size - 1; i++)
	{
		// checks the current row of "i" to determine if an "indent" is necessary
		for (int k = 0; k <= i - 1; k++)
		{
			cout << " ";
		}
		// draws a "*" based on current row/column
		for (int j = myCount; j < baseLength; j++)
		{
			cout << "*";
		}
		// used to keep track of how man "*" are needed
		myCount = myCount + 2;
		cout << endl;
	}
	// Only calls on isosceles when the selection is Hourglass
	if (selectionChoice == 4)
	{
		IsoscelesTriangle(size, selectionChoice);
		cout << "********************************************************************************" << endl;

		// restarts application
		main();
	}
}
// Function that draws a Diamond
// Takes in size and selection choice for other function reusability
void Diamond(int& size, int& selectionChoice)
{
	// Calls on two different functions to draw a diamond
	// Isosceles = top (size is editted in Function to draw properly)
	IsoscelesTriangle(size, selectionChoice);

	// Hourglass = bottom (size is editted in Function to draw properly)
	HourGlass(size, selectionChoice);

	cout << "********************************************************************************" << endl;
	
	// restarts application
	main();
}