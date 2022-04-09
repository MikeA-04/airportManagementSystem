/*
Name:	Mike Apreza
File:	baggage.cpp
Date:	01/06/2020
Class:	CIS 2542-002
*/

#include <iostream>

/* This function takes an integer values (number of luggage of a particular size
 and max value for container) and calculates the number of bins required. 
   The number of bins is returned*/

static int numberOfBins(int size, int max)
{
	int bins = 0;
	while (size >= max)
	{
		size -= max;
		bins++;
	}
	if (size > 0)
		bins++;
	return bins;
}

/* This function allows the user to enter the amount of luggage there is for
	a specific flight depending on the size. As each element is added, it will
	also be put in it's appropraite bin. */
static void binPacking()
{
	// Create integer variable to hold choice for switch statement, number of baggage, number of elements, 
	// holder for 'small,' 'medium,' and 'large,' and flight number
	int choice, add, small, medium, large, flightNum;
	// Create boolean variable to hold if a flight has not been created yet
	bool flightExists = false;
	
	do
	{
		system("CLS");
		std::cout << "1. Create a New Flight\n"
			<< "2. Add Large Luggage\n"
			<< "3. Add Medium Luggage\n"
			<< "4. Add Small Luggage\n"
			<< "5. View Number of Bins Necessary\n"
			<< "6. Exit\n"
			<< "   *Large = Suitcase, Medium = Box, Small = Small Travel Bag\n"
			<< "Enter your choice: ";
		std::cin >> choice;

		// Switch statement
		switch (choice)
		{
			case 1:
			{
				std::cout << "Enter the flight number: ";
				std::cin >> flightNum;
				small = 0;
				medium = 0;
				large = 0;
				std::cout << "Flight successfully created.\n";
				flightExists = true;
				system("PAUSE");
				break;
			}
			case 2:
			{
				if (flightExists == false)
					std::cout << "Please create a flight (Option 1).\n";
				else
				{
					std::cout << "How many large luggage would you like to add? ";
					std::cin >> add;
					large += add;
					std::cout << add << " large luggage(s) has been added to the flight.\n";
				}
				system("PAUSE");
				break;
			}
			case 3:
			{
				if (flightExists == false)
					std::cout << "Please create a flight (Option 1).\n";
				else
				{
					std::cout << "How many medium luggage would you like to add? ";
					std::cin >> add;
					medium += add;
					std::cout << add << " medium luggage(s) has been added to the flight.\n";
				}
				system("PAUSE");
				break;
			}
			case 4:
			{
				if (flightExists == false)
					std::cout << "Please create a flight (Option 1).\n";
				else
				{
					std::cout << "How many small luggage would you like to add? ";
					std::cin >> add;
					small += add;
					std::cout << add << " small luggage(s) has been added to the flight.\n";
				}
				system("PAUSE");
				break;
			}
			case 5:
			{
				if (flightExists == false)
					std::cout << "Please create a flight (Option 1).\n";
				else
				{
					std::cout << "\n\tFor Flight '" << flightNum << "':\n";
					// Call function to calculate number of bins and display information
					std::cout << "Number of Large Luggage: " << large << "\tNumber of Bins Required: " << numberOfBins(large, 6) << std::endl;
					std::cout << "Number of Medium Luggage: " << medium << "\tNumber of Bins Required: " << numberOfBins(medium, 8) << std::endl;
					std::cout << "Number of Small Luggage: " << small << "\tNumber of Bins Required: " << numberOfBins(small, 5) << std::endl << std::endl;
				}
				system("PAUSE");
				break;
			}
			case 6:
				break;
			default:
			{
				std::cout << "Enter a valid number.\n";
				system("PAUSE");
				break;
			}
		}

	} while (choice != 6);
}