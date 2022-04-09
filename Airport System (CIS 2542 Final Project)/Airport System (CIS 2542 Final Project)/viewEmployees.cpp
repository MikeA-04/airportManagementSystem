/*
Name:	Mike Apreza
File:	viewEmployees.cpp
Date:	12/12/2019
Class:	CIS 2542-002
*/

#include <iostream>
#include <string>
#include <vector>

// Struct to hold information about employee (name, occupation, employer)
struct Employee
{
	std::string name;
	std::string occupation;
	std::string employer;
};

// This function takes a pointer to a vector of structs
static void viewEmployees(std::vector<Employee> * Employees)
{
	// Declare int variable to hold choice for switch statements
	int choice;
	// Declare character variable for choice 3 in switch statement (search by)
	char searchVariable;
	// Declare string variable for name, occupation, or employer
	std::string search;
	// Declare Boolean variable
	bool found = false;

	do
	{
		system("CLS");
		// Display Menu
		std::cout << "1. Add Employee\n"
			<< "2. Search for Employee Information\n"
			<< "3. Exit\n"
			<< "Enter your choice: ";
		std::cin >> choice;

		// Switch statement
		switch (choice)
		{
			case 1:
			{
				system("CLS");
				// Create Employee and ask for the employee's information
				Employee e;
				std::cout << "Enter the employee's name: ";
				std::cin.ignore();
				std::getline(std::cin, e.name);
				std::cout << "Enter the employee's occupation: ";
				std::getline(std::cin, e.occupation);
				std::cout << "Enter the employee's employer: ";
				std::getline(std::cin, e.employer);
				// Add employee to vector
				Employees->push_back(e);
				std::cout << "Employee successfully added.\n";
				system("PAUSE");
				break;
			}
			case 2:
			{
				if (Employees->empty())
				{
					std::cout << "There are no employees on record.\n";
					system("PAUSE");
					break;
				}
				else
				{
					// This loop will iterate as long as the user wishes to search for an employee
					do
					{
						system("CLS");
						std::cout << "Will you be searching for the employee by name, occupation, or employer?\n";
						do
						{
							std::cout << "Enter N for Name, O for occupation, or E for Employer: ";
							std::cin >> searchVariable;
						} while ((searchVariable != 'n') && (searchVariable != 'N') && (searchVariable != 'o') && (searchVariable != 'O') && (searchVariable != 'e') && (searchVariable != 'E'));

						// Let user enter what they they wish to search for according to searchVariable
						if ((searchVariable == 'n') || (searchVariable == 'N'))
						{
							std::cout << "Enter the name of the employee: ";
							std::cin.ignore();
							std::getline(std::cin, search);
							for (unsigned int i = 0; i < Employees->size(); i++)
							{
								if (search == Employees->at(i).name)
								{
									std::cout << "Employee Name: " << Employees->at(i).name << std::endl;
									std::cout << "Employee Occupation: " << Employees->at(i).occupation << std::endl;
									std::cout << "Employee Employer: " << Employees->at(i).employer << std::endl;
									found = true;
									system("PAUSE");
									i = Employees->size();
								}
							}
							if (found == false)
								std::cout << "Employee was not found. Please try again.\n";
							found = false;
						}
						else if ((searchVariable == 'o') || (searchVariable == 'O'))
						{
							std::cout << "Enter the occupation of the employee: ";
							std::cin.ignore();
							std::getline(std::cin, search);
							for (unsigned int i = 0; i < Employees->size(); i++)
							{
								if (search == Employees->at(i).occupation)
								{
									std::cout << "Employee Name: " << Employees->at(i).name << std::endl;
									std::cout << "Employee Occupation: " << Employees->at(i).occupation << std::endl;
									std::cout << "Employee Employer: " << Employees->at(i).employer << std::endl;
									found = true;
									system("PAUSE");
									i = Employees->size();
								}
							}
							if (found == false)
								std::cout << "Employee was not found. Please try again.\n";
							found = false;

						}
						else
						{
							std::cout << "Enter the employer of the employee: ";
							std::cin.ignore();
							std::getline(std::cin, search);
							for (unsigned int i = 0; i < Employees->size(); i++)
							{
								if (search == Employees->at(i).employer)
								{
									std::cout << "Employee Name: " << Employees->at(i).name << std::endl;
									std::cout << "Employee Occupation: " << Employees->at(i).occupation << std::endl;
									std::cout << "Employee Employer: " << Employees->at(i).employer << std::endl;
									found = true;
									system("PAUSE");
									i = Employees->size();
								}
							}
							if (found == false)
								std::cout << "Employee was not found. Please try again.\n";
							found = false;
						}

						// Ask user if they wish to search for another employee
						std::cout << "Would you like to search for another employee? (Enter any letter for Yes, N for No): ";
						std::cin >> searchVariable;
					} while ((searchVariable != 'N') && (searchVariable != 'n'));
					break;
				}
			}
			case 3:
				break;
			default:
			{
				std::cout << "Enter a valid number.\n";
				system("PAUSE");
				break;
			}
		}
	} while (choice != 3);
}