/*
Name:	Mike Apreza
File:	planesTakeOffAndLand.cpp
Date:	12/12/2019
Class:	CIS 2542-002
*/

#include <iostream>
#include <string>
#include <queue>

/*
	This function takes a pointer to a queue of strings and lets the authorized employee
	to add a plane to the queue of planes waiting to departure, remove the next plane from
	the queue, and view all the planes in the queue.
*/
static void planesQueue(std::queue<std::string> * pPtr)
{
	// Declare integer variable to hold choice
	int choice;
	// Declare string variale to hold name of airplane
	std::string plane;

	// Loop to iterate for as long as user wishes to take action on the planes
	do
	{
		system("CLS");
		std::cout << "\tDeparture Planes\n"
			<< "1. Add Plane to Queue\n"
			<< "2. Remove Plane from Queue\n"
			<< "3. View Queue\n"
			<< "4. Exit\n"
			<< "Enter your choice: ";
		std::cin >> choice;

		// Switch statement
		switch (choice)
		{
			case 1:
			{
				std::cin.ignore();
				std::cout << "Enter the name of the plane waiting for departure: ";
				std::getline(std::cin, plane);
				pPtr->push(plane);
				std::cout << "Plane successfully added to the queue.\n";
				system("PAUSE");
				break;
			}
			case 2:
			{
				if (pPtr->empty())
				{
					std::cout << "There are no planes waiting to depart.\n";
				}
				else
				{
					std::cout << pPtr->front() << " has departed.\n";
					pPtr->pop();
					std::cout << pPtr->front() << " is next to departure.\n";
				}
				system("PAUSE");
				break;
			}
			case 3:
			{
				if (pPtr->empty())
				{
					std::cout << "There are no planes waiting in queue.\n";
				}
				else
				{
					std::cout << "\nPlanes in Queue:\n";
					for (unsigned int i = 0; i < pPtr->size(); i++)
					{
						plane = pPtr->front();
						pPtr->pop();
						std::cout << plane << std::endl;
						pPtr->push(plane);
					}
				}
				system("PAUSE");
				break;
			}
			case 4:
				break;
			default:
			{
				std::cout << "Enter a valid number.\n";
				system("PAUSE");
				break;
			}
		}
	} while (choice != 4);
}