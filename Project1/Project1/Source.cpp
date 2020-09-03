/*
   File: prog2_b_p224.cpp

   Author: Brisa Puente
   C.S.1428.001
   Lab Section: L03
   Program: #2
   Due Date: 10/03/18

   This program prompts the user to enter the amount of a purchase (in cents).
   It then prompts the user to enter the amount received in payment (in cents).
   It calculates the amount of change due, printing the results to an output
   file. The author's identifying information is provided followed by the
   number of each coin to be given in change: the number of dollars, half
   dollars, quarters, dimes, nickels and pennies are listed in tabular form.
   Monetary amounts are displayed to two decimal places.

   An appropriate message is displayed to the console screen if the output
   file fails to open.

   An appropriate message is written to the console screen informing the
   user of the output file name to which the results have been written.
   The layout and content of the file output are shown in the sample below.

   Input (keyboard):
		  purchase amount, integer (in cents)
		  payment amount, integer (in cents)

   Constants: none

   Output (screen):

		   Author's Name
		   C.S.1428.?         // '?' represents author's lecture section #
		   Lab Section: L?    // '?' represents student's lab section #
		   --/--/--           // dashes represent due date, month/day/year
				<blank line>
				<blank line>
		   <Appropriate message indicating the name of the output file.>

   Output (file - prog2_00?out.txt): // '?' represents author's lect sec #

		   Author's Name
		   C.S.1428.?         // '?' represents author's lecture section #
		   Lab Section: L?    // '?' represents student's lab section #
		   --/--/--           // dashes represent due date, month/day/year
				<blank line>
		   Received ? for a purchase of ?
				<blank line>
			  Change in coins:
		   Coin           Number
		   ---------------------
		   Dollars          ?
		   Half Dollars     ?
		   Quarters         ?
		   Dimes            ?
		   Nickels          ?
		   Pennies          ?

   ================================================

   <Output will vary based on actual input values.>
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	float purchase_amount,
		amount_received;
	int change,
		dollar_bill = 0,
		half_dollar = 0,
		quarters = 0,
		dimes = 0,
		nickels = 0;

	ofstream fout;
	fout.open("prog2_001out.txt");

	cout << "Enter the amount of the purchase (in cents): ";
	cin >> purchase_amount;
	cout << "Enter the amount received in payment (in cents): ";
	cin >> amount_received;

	change = amount_received - purchase_amount;

	if (change >= 100)
	{
		dollar_bill = change / 100;
		change = change % 100;
	}
	if (change >= 50)
	{
		half_dollar = change / 50;
		change = change % 50;
	}
	if (change >= 25)
	{
		quarters = change / 25;
		change = change % 25;
	}
	if (change >= 10)
	{
		dimes = change / 10;
		change = change % 10;
	}
	if (change >= 5)
	{
		nickels = change / 5;
		change = change % 5;
	}

	fout << "Brisa Puente" << endl
		<< "C.S.1428.001" << endl
		<< "Lab Section: 03" << endl
		<< "10/03/18" << endl << endl;

	amount_received /= 100.0f;
	fout << fixed << setprecision(2) << "Received " << amount_received  << " for a purchase of " << purchase_amount / 100
		<< endl << endl;
	fout << "  Change in coins: " << endl
		<< "Coin          Number" << endl
		<< "--------------------" << endl
		<< "Dollars      " << setw(3) << dollar_bill << endl
		<< "Half_Dollars " << setw(3) << half_dollar << endl
		<< "Quarters     " << setw(3) << quarters << endl
		<< "Dimes        " << setw(3) << dimes << endl
		<< "Nickels      " << setw(3) << nickels << endl
		<< "Pennies      " << setw(3) << change << endl;

	cout << endl
		<< "Brisa Puente" << endl
		<< "C.S.1428.001" << endl
		<< "Lab Section: 03" << endl
		<< "10/03/18" << endl << endl;
	cout << "Program results have been written to prog2_001out.txt"
		<< endl << endl;

	fout.close();

	system("PAUSE>NUL");

	return 0;
}
