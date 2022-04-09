/*
Name:	Mike Apreza
File:	planesLanding.cpp
Date:	01/05/2020
Class:	CIS 2542-002
*/

#include <iostream>
#include <stack>
#include <string>

// This function takes a pointer to a stack of strings
static void planesLand(std::stack <std::string> * planes)
{
	// Declare integer to hold choice
	int choice;
	// Declare string to hold name of plane
	std::string plane;

	do
	{
		system("CLS");
		// Display menu
		std::cout << "1. Add Plane (Waiting to Land)\n"
			<< "2. Remove Plane (Landed)\n"
			<< "3. See Planes Waiting to Land\n"
			<< "4. Exit\n"
			<< "Enter your choice: ";
		std::cin >> choice;

		// Switch statement
		// If option 2 or 3 is chosen, make sure it planes stack is not empty
		switch (choice)
		{
			case 1:
			{
				std::cin.ignore();
				std::cout << "Enter the name of the plane waiting to land: ";
				std::getline(std::cin, plane);
				planes->push(plane);
				std::cout << "Plane successfully added to the stack.\n";
				system("PAUSE");
				break;
			}
			case 2:
			{
				if (planes->empty())
				{
					std::cout << "There are no planes waiting to land.\n";
				}
				else
				{
					std::cout << planes->top() << " has landed.\n";
					planes->pop();
				}
				system("PAUSE");
				break;
			}
			case 3:
			{
				if (planes->empty())
				{
					std::cout << "There are no planes waiting to land.\n";
				}
				else
				{
					// Create stack of strings to hold planes (strings) from planes stack
					std::stack <std::string> s;
					// Display stack
					std::cout << "\nPlanes waiting to land:\n";
					while (!planes->empty())
					{
						plane = planes->top();
						planes->pop();
						s.push(plane);
						std::cout << plane << std::endl;
					}
					// Fix planes stack
					while (!s.empty())
					{
						plane = s.top();
						s.pop();
						planes->push(plane);
					}
				}
				system("PAUSE");
				break;
			}
			case 4:
				break;
			default:
			{
				std::cout << "Enter a valid choice.\n";
				system("PAUSE");
				break;
			}
		}
	} while (choice != 4);
}