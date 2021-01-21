//Directives
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAXARRAYSIZE 10

int main() {

	//Variables
	//////////////////////////////////////////////
	int Table[MAXARRAYSIZE];
	int index_smallest = 0;
	int smallest;
	int search_key;
	int new_value;
	int number_of_values = 0;
	int number_less_than_average = 0;
	int number_equal_to_average = 0;
	int number_greater_than_average = 0;
	double sum = 0;
	double average = 0;
	char yes_or_no;
	bool value_found;
	//////////////////////////////////////////////

	//Prompt the user to enter number
	cout << "Welcome!" << endl;
	cout << "Please enter 5-10 integers!" << endl;
	cout << "Please enter a negative number if you would like to quit/stop!";
	cout << endl;

	//Repetitive Storing
	for (int i = 0; i < MAXARRAYSIZE; i++) {

		cout << "Enter the number to insert to slot " << i << ":";
		cin >> new_value;

		//Exit if the number is less than zero
		if (new_value < 0)
		break;

		//Store the value in the Table
		Table[i]=new_value;

		//Calculate Sum
		sum+=new_value;

		//Increment
		number_of_values++;
	}

	//Prints the Content of the Array
	cout << "======================RESULTS======================" << endl;

	cout << "Number Of Values: " << number_of_values << endl;

	cout << "Contents Of The Array: " << endl;

	for(int j = 0; j < number_of_values; j++) {

		cout << "Slot " << j << ": " << Table[j] << endl;
	}

	//Calculate Average
	average = sum / number_of_values;

	//Calculate Numbers that are less, equal, or greater to the average
	for(int k = 0; k < number_of_values; k++)
	{
		if(Table[k] < average)
		number_less_than_average++;

		else if (Table[k] == average)
		number_equal_to_average++;

		else
		number_greater_than_average++;
	}

	//Print Results
	cout << "The Average is: " << average << endl;
	cout << "The number of values less than average is: " << number_less_than_average << endl;
	cout << "The number of values equal to average is: " << number_equal_to_average << endl;
	cout << "The number of values greater than average is: " << number_greater_than_average << endl;
	cout << endl;
	cout << "Would you like to search for a number within the slot?(Enter y/n)" << endl;
	cin >> yes_or_no;

	//Yes = to find a number in the array.
	//No  = to end the program.
	if(yes_or_no == 'y')
	{
		do {
			cout << "Enter the value that you would like to find: ";
			cin >> search_key;

			for(int l = 0 ; l < number_of_values; l++)
			{
				if (Table[l] == search_key)
				{
					cout << "The requested value of " << search_key << " was found at Index: " << l;
					cout << endl;
					value_found = true;
				}
			}

			if (value_found == false)
			{
				cout << "The requested value of " << search_key << " was not found" << endl;
			}

			value_found = false;

			cout << "Would you like to search for another number within the slot?(Enter y/n)" << endl;
			cin >> yes_or_no;

		}while(yes_or_no == 'Y' || yes_or_no == 'y');

	}

	//Find Smallest number in the array

	smallest = Table[0];

	for(int m = 0; m < number_of_values; m++)
	{
		if (smallest > Table[m])
		{
			smallest = Table[m];
			Table[m] = Table[0];
			Table[0] = smallest;

			index_smallest = m;
		}
	}

	//Print Smallest Number and the New Sorted Array
	if (number_of_values == 0)
	{
		cout << "Thank you for using this program!" << endl;
		cout << "Smallest number was not found because no input was entered!" << endl;
		cout << "Goodbye!" << endl;
	}
	else if (number_of_values > 0)
	{
		cout << "Thank you for using this program!" << endl;
		cout << "After Calculation, the smallest number within the slot is ";
		cout << smallest;
		cout << endl;
		cout << "Located at index: " << index_smallest << endl;
		cout << "New Sorted Array after finding smallest: " << endl;

		for(int n = 0; n < number_of_values; n++) {

			cout << "Slot " << n << ": " << Table[n] << endl;
		}
	}
	return 0;
}
