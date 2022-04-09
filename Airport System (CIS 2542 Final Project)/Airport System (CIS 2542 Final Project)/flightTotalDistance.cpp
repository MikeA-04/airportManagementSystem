/*
Name:	Mike Apreza
File:	flightTotalDistance.cpp
Date:	12/12/2019
Class:	CIS 2542-002
*/

#include <iostream>
#include <string>

// Make enum global
enum Flights { Detroit, Miami, LA, Seattle };

// Declare global 2D array of strings
/*
	A 2D array was created because this connected graph is not directed so if the user wishes
	to figure out the distance a flight travels from LA to Seattle or Seattle to LA, the string
	will be the same for either.
*/
/*
		 Detroit | Miami | Los Angeles | Seattle
	D   	--
	M   			--
	LA  						--
	S   									--
*/
const int SIZE = 4;
static std::string distances[SIZE][SIZE] = {
	{ " ", "1153 mi/1855 km", "1983 mi/3192 km", "1938 mi/3119 km" },
	{ "1153 mi/1855 km", " ", "2339 mi/3764 km", "2734 mi/4399 km" },
	{ "1983 mi/3192 km", "2339 mi/3764 km", " ", "959 mi/1544 km" },
	{ "1938 mi/3119 km", "2734 mi/4399 km", "959 mi/1544 km", " " }
};

static void DetroitTo()
{
	// Declare integer variable to hold choice for following switch statement
	int answer;

	// Display menu
	std::cout << "\tArrival to:\n\n";
	std::cout << "1. Miami\n"
		<< "2. Los Angeles\n"
		<< "3. Seattle\n";
	std::cout << "Enter your choice: ";
	std::cin >> answer;

	// validate user input
	while ((answer != 1) && (answer != 2) && (answer != 3))
	{
		std::cout << "Enter a valid number: ";
		std::cin >> answer;
	}

	// Switch statement
	switch (answer)
	{
		case 1:
		{
			std::cout << "The flight distance from Detroit to Miami is " << distances[Detroit][Miami] << std::endl;
			system("PAUSE");
			break;
		}
		case 2:
		{
			std::cout << "The flight distance from Detroit to Los Angeles is " << distances[Detroit][LA] << std::endl;
			system("PAUSE");
			break;
		}
		case 3:
		{
			std::cout << "The flight distance from Detroit to Seattle is " << distances[Detroit][Seattle] << std::endl;
			system("PAUSE");
			break;
		}
	}
}

static void MiamiTo()
{
	// Declare integer variable to hold choice for following switch statement
	int answer;

	// Display menu
	std::cout << "\tArrival to:\n\n";
	std::cout << "1. Detroit\n"
		<< "2. Los Angeles\n"
		<< "3. Seattle\n";
	std::cout << "Enter your choice: ";
	std::cin >> answer;

	// validate user input
	while ((answer != 1) && (answer != 2) && (answer != 3))
	{
		std::cout << "Enter a valid number: ";
		std::cin >> answer;
	}

	// Switch statement
	switch (answer)
	{
		case 1:
		{
			std::cout << "The flight distance from Miami to Detroit is " << distances[Miami][Detroit] << std::endl;
			system("PAUSE");
			break;
		}
		case 2:
		{
			std::cout << "The flight distance from Miami to Los Angeles is " << distances[Miami][LA] << std::endl;
			system("PAUSE");
			break;
		}
		case 3:
		{
			std::cout << "The flight distance from Miami to Seattle is " << distances[Miami][Seattle] << std::endl;
			system("PAUSE");
			break;
		}
	}
}

static void LAto()
{
	// Declare integer variable to hold choice for following switch statement
	int answer;

	// Display menu
	std::cout << "\tArrival to:\n\n";
	std::cout << "1. Detroit\n"
		<< "2. Miami\n"
		<< "3. Seattle\n";
	std::cout << "Enter your choice: ";
	std::cin >> answer;

	// validate user input
	while ((answer != 1) && (answer != 2) && (answer != 3))
	{
		std::cout << "Enter a valid number: ";
		std::cin >> answer;
	}

	// Switch statement
	switch (answer)
	{
		case 1:
		{
			std::cout << "The flight distance from Los Angeles to Detroit is " << distances[LA][Detroit] << std::endl;
			system("PAUSE");
			break;
		}
		case 2:
		{
			std::cout << "The flight distance from Los Angeles to Miami is " << distances[LA][Miami] << std::endl;
			system("PAUSE");
			break;
		}
		case 3:
		{
			std::cout << "The flight distance from Los Angeles to Seattle is " << distances[LA][Seattle] << std::endl;
			system("PAUSE");
			break;
		}
	}
}

static void SeattleTo()
{
	// Declare integer variable to hold choice for following switch statement
	int answer;

	// Display menu
	std::cout << "\tArrival to:\n\n";
	std::cout << "1. Detroit\n"
		<< "2. Miami\n"
		<< "3. Los Angeles\n";
	std::cout << "Enter your choice: ";
	std::cin >> answer;

	// validate user input
	while ((answer != 1) && (answer != 2) && (answer != 3))
	{
		std::cout << "Enter a valid number: ";
		std::cin >> answer;
	}

	// Switch statement
	switch (answer)
	{
		case 1:
		{
			std::cout << "The flight distance from Seattle to Detroit is " << distances[Seattle][Detroit] << std::endl;
			system("PAUSE");
			break;
		}
		case 2:
		{
			std::cout << "The flight distance from Seattle to Miami is " << distances[Seattle][Miami] << std::endl;
			system("PAUSE");
			break;
		}
		case 3:
		{
			std::cout << "The flight distance from Seattle to Los Angeles is " << distances[Seattle][LA] << std::endl;
			system("PAUSE");
			break;
		}
	}
}

/*
	This function allows the user to check the total distance a flight has to travel
	by typing in the number of the place the airplane is departing from. Then, the appropriate
	function is called where the user has to enter the corresponding number of the place
	the airplane is arriving to.
*/
static void flightDistances()
{
	// Declare integer variable for choice for switch statements
	int choice;

	// Loop to display menu
	do
	{
		system("CLS");
		std::cout << "\tFlight Distances: Departure from:\n\n";
		std::cout << "1. Detroit\n"
			<< "2. Miami\n"
			<< "3. Los Angeles\n"
			<< "4. Seattle\n"
			<< "5. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
			case 1:
				DetroitTo();
				break;
			case 2:
				MiamiTo();
				break;
			case 3:
				LAto();
				break;
			case 4:
				SeattleTo();
				break;
			case 5:
				break;
			default:
			{
				std::cout << "Enter a valid number.\n";
				system("PAUSE");
				break;
			}
		}
	} while (choice != 5);
}