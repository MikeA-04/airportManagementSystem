/*
Name:	Mike Apreza
File:	menu.cpp
Date:	12/12/2019
	Updated: 02/15/2020
Class:	CIS 2542-002
*/

// STL and Files
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include "planesTakeOffAndLand.cpp"
#include "viewEmployees.cpp"
#include "baggage.cpp"
#include "planesLanding.cpp"
#include "securityClearance.cpp"
#include "flightTotalDistance.cpp"

// The main function
int main()
{
	// Declare string variable to hold password
	std::string password;
	// Declare integer variable to hold choice option for switch statement
	int menuOption = 0;
	// Declare character variable to hold choice whether or not user wants to quit using the system
	char answer = 'N';
	// Declare vector of Employee structs and pointer variable to point at a vector of structs
	std::vector<Employee> employeesVector;
	std::vector<Employee> * Employees = &employeesVector;
	// Declare queue of strings for customers waiting for security clearance and pointer to queue
	std::queue<std::string> security;
	std::queue<std::string> * securityPtr = &security;
	// Declare queue of strings for airplanes waiting to take off and pointer to queue
	std::queue<std::string> planes;
	std::queue<std::string> * planesPtr = &planes;
	// Declare stack of strings for airplanes waiting to land and pointer to stack
	std::stack <std::string> planesLanding;
	std::stack <std::string> * pLPtr = &planesLanding;

	// Display first menu and ask user for password to access menu for authorized users
	do
	{ 
		system("CLS");
		std::cout << "\t\tNorthwoods Airport, Inc. Management System\n" << "\t\t\tPlease enter the password.\n"
			<< "\t  Having trouble? Contact the IT department at 630-942-2800.\n\n"
			<< "\t\tPassword: ";
		std::cin >> password;
	} while (password != "delta");

	/*
										OVERALL SUMMARY OF MENU
		This menu displays a welcome message and informs the user of how s/he can execute certain functions.
		Below that is a series of lines displaying a number followed by an action the user can execute.
		At the very bottom is a place for the user to enter the number corresponding to the action that will
		execute is said number is chosen. There are 8 options (numbers 1 through 8). If any other number is 
		entered, the program will inform the user of their mistake and the menu will appear again as if the
		user has just logged in. Should the user want to exit, they will be asked for confirmation.
	*/
	do
	{
		system("CLS");
		std::cout << "\t\t\tWelcome.\n\tPlease select a menu option to get started.\n\t  (Enter the corresponding number.)\n\n";
		std::cout << "1. Add or Remove Airplane(s) (Arrival and Departure)\n"
			<< "2. View Employee Information\n"
			<< "3. Add Customer Baggage\n"
			<< "4. Add or Remove Planes that are Waiting to Land\n"
			<< "5. Add or Remove Customer to Wait for Security Clearance\n"
			<< "6. View Total Distance a Plane Travels from One Place to Another\n"
			<< "7. Exit\n"
			<< "8. Information about the Options\n";
		std::cout << " Option: ";
		std::cin >> menuOption;

		switch (menuOption)
		{
			case 1:
			{
				planesQueue(planesPtr);
				break;
			}
			case 2:
			{
				viewEmployees(Employees);
				break;
			}
			case 3:
			{
				binPacking();
				break;
			}
			case 4:
			{
				planesLand(pLPtr);
				break;
			}
			case 5:
			{
				securityClear(securityPtr);
				break;
			}
			case 6:
			{
				flightDistances();
				break;
			}
			case 7:
			{
				// Ask user if they are sure they want to exit
				do
				{
					std::cout << " Are you sure you want to exit? (Y for Yes, N for No): ";
					std::cin >> answer;
				} while ((answer != 'y') && (answer != 'Y') && (answer != 'n') && (answer != 'N'));

				// Exit system if user selects Yes, otherwise, go back to main menu
				if ((answer == 'y') || (answer == 'Y'))
					break;
				else
				{
					menuOption = 0;
					break;
				}
			}
			case 8:
			{
				system("CLS");
				std::cout << "Below are the numbers corresponding to the same ones in the main menu. After those\n"
					<< "numbers (below), is information about what the user can do if said number is chosen.\n\n";
				std::cout << "1. The user can add or remove airplanes waiting to land or depart from the runway.\n"
					<< "2. View employee information stored (Name, Occupation, Employer).\n"
					<< "3. The user can add a customer's baggage in appropriate containers per flight.\n"
					<< "4. The user can how many planes are waiting to land.\n"
					<< "5. View the names of the customers waiting for security clearance.\n"
					<< "6. View the total distance a flight will from a specific destination hub to a specific arrival hub.\n"
					<< "7. The user will be asked if they wish to continue to exit the program. If the user enters 'y' or 'Y',\n"
					<< "   then the user will be logged out. If the input is 'n' or 'N', the program will take the user to the main menu.\n\n";
				system("PAUSE");
				break;
			}
			default:
			{
				// informs user of their mistake
				system("CLS");
				std::cout << "Please enter the appropriate number (See the top of the menu).\n";
				system("PAUSE");
				break;
			}
		}

	} while (menuOption != 7);

	// Inform user that logging out was successful
	system("CLS");
	std::cout << "\n\t\tSuccessfully Logged Out\n";

	return 0;
}