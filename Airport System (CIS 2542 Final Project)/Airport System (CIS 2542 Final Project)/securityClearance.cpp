/*
Name:	Mike Apreza
File:	securityClearance.cpp
Date:	12/12/2019
Class:	CIS 2542-002
*/

#include <iostream>
#include <string>
#include <queue>

static void securityClear(std::queue<std::string> * sPtr)
{
	// Declare integer variable to hold choice for switch statement
	int choice;
	// Declare string variable to hold name of a customer
	std::string customer;

	do
	{
		// Display menu
		system("CLS");
		std::cout << "1. Add Customer to Queue\n"
			<< "2. Remove Customer from Queue\n"
			<< "3. Display Customers Waiting\n"
			<< "4. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
			case 1:
			{
				std::cout << "Enter the name of the customer waiting for security clearance: ";
				std::cin.ignore();
				std::getline(std::cin, customer);
				sPtr->push(customer);
				std::cout << "Customer successfully added to the queue.\n";
				system("PAUSE");
				break;
			}
			case 2:
			{
				if (sPtr->empty())
				{
					std::cout << "There are no customers in line.\n";
				}
				else
				{
					std::cout << sPtr->front() << " has been removed from the queue.\n";
					sPtr->pop();
				}
				system("PAUSE");
				break;
			}
			case 3:
			{
				if (sPtr->empty())
				{
					std::cout << "There are no customers in line.\n";
				}
				else
				{
					std::cout << "Customers Waiting for Security Clearance:\n";
					for (unsigned int i = 0; i < sPtr->size(); i++)
					{
						// Remove customer from queue and display
						customer = sPtr->front();
						sPtr->pop();
						std::cout << customer << std::endl;
						// Add the same customer back into the queue
						sPtr->push(customer);
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