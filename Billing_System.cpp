# include <iostream>
# include <process.h>  
# include <fstream>  
# include <stdlib.h>
using namespace std;

class user_interface

{
	// string array with limit of 49 placements including null. 
	char item_name[50][50];
	// declaration of variables given floating point space value of 3 for
	// the sake of managing money.
public:
	int shopping_list;
	float item_quantity[3];
	float item_price[3];
	int added_tax_price[3];
	int total_price[3];
	// variables that do not require perameters for the given project. 
	// according to documentation, its a means of calling functions later on. 
	void customer_input();
	void system_output();
};
class added_tax:public user_interface
{
	float added_taxes;
public:
	void calculatedtax();
	void tracked_outputs();
	void cash_summation();
};



//customer input function:

void user_interface::customer_input()
{
	system("CLS");
	cout<<"\nPlease enter the number of items purchased: ";
	cin>>shopping_list;

	// for loop gathering data on a customer's shopping list. Like in most
	// loops itterating through lists it will itterate through it dependent on
	// the amount of items within the shopping list and then spit out a 
	// calculated price based on what was inputed. 
	for (int i = 0; i < shopping_list; i++)
	{
		cout << "\nPlease enter the name of your item " << i + 1 << ": ";
		cin >> item_name[i];
		cout << "Please enter quantity of specified item: ";
		cin >> item_quantity[i];
		cout << "Enter the displayed price of this product: " << i + 1 << ": ";
		cin >> item_price[i];
		total_price[i] = item_quantity[i] * item_price[i];
	}
}

//system output function:

void user_interface::system_output()

{
	//This function required the most research for the terms of documentation.
	//The ifstream and ofstream functions combined with the infile and outfile commands.
	//they will literally use the collected data storing it in that alpha variable and then
	//write it to two seperate text files for the sake of recalling data from a 
	//previous shopping trip. Think of it as a reciept.
	int alpha;

	ifstream infile("shopping_data.txt");
	infile >> alpha; 

	ofstream outfile("shopping_data.txt");
	alpha += 1;
	outfile << alpha;
	outfile.close();
	//Pulling data from text file and organizing it into readable display
	{ofstream outfile("customer_data.txt", ios::app);
	outfile << endl << "Bill ID.: " << alpha << endl;
	outfile << "----------------------------------------------------------------"
		<< endl;
	cout << "\n";
	cout << "Given name of Item: \ Total Quantity:   Price:    Total Price:  \n";
	// data organized from text file into respective categories. 
	for (int i = 0; i < shopping_list; i++)
	{
		outfile << "Product Name:  " << item_name[i] << " Quantity of Items: " << item_quantity[i] << " Item Price: " << total_price[i] << endl;
		cout << item_name[i] << "\t\t" << item_quantity[i] << "\t    " << item_price[i] << "\t    " << total_price[i] << "\n";
	}
	// closes the text file when completed with it. 
	outfile << "------------------------------------------------------------------"
		<< endl;
	outfile.close();
	}
}

//Sales tax calcualtion function

void added_tax::calculatedtax()
{
	//This function is a representation of sales tax using different variables
	//defined at the begginning of this program. 
	customer_input();
	for (int i = 0; i < shopping_list; i++) 
	{
		if (item_price[i] <= 100.00)
		{
			added_tax_price[i] = total_price[i] + (0.03 * total_price[i]);
		}
		else
		{
			added_tax_price[i] = total_price[i] + (0.1 * total_price[i]);
		}
	}
}

//System output function

void added_tax::tracked_outputs()

{
	system_output();
	// This is defining the payment method of which the customer(user)
	// will carry out payment for their aquired products.
	float bank_account = 0, basic_sum = 0, quantity_of_items = 0, total_sum = 0;
	// this for loop sets the new values of the processed data equal to the 
	// value of the corrected data. 
	for (int i = 0; i < shopping_list; i++)
	{
		total_sum += total_price[i];
		basic_sum += added_tax_price[i];
		quantity_of_items += item_quantity[i];
	}
	cout << "\nTotal: ";
	cout << "\n------------------------------------------------------------";
	cout << "\n\t Total Quantity =  "<<quantity_of_items<<"\t\t Total Sum of purchase = "<<total_sum<<"\t Total with Tax: "<<basic_sum;
	cout << "\n------------------------------------------------------------";
// a loop for the customer to enter in the proper amount of funds for the
// given purchase. 
pay: 

	cout << "\n\n\t\t\t****PAYMENT SUMMERAY****\n";
	cout << "\n\t\t\t Total Payment given: ";
	cin >> bank_account;

	if (bank_account >= basic_sum)
		cout << "\n\t\t\t Change: " << bank_account - basic_sum<<"\n";
	else
	{
		cout << "\n\t\t\t Insufficent funds";

		goto pay;
	}

}


// a password protected function meant for security.

int security_password()
{
	char password_1, password_2, password_3;

	cout << "\n\n\n\n\n\n\t\t\tPLEASE ENTER ACCOUNT PASSWORD: ";

	cin >> password_1;
	cout << "*";
	cin >> password_2;
	cout << "*";
	cin >> password_3;
	cout << "*";

	if ((password_1 == 'a' || password_1 == 'A') && (password_2 == 'x' || password_2 == 'X') && (password_3 == 'e' || password_3 == 'E'))
		return 1;
	else
		return 0;
}



// the main function of the program

int main()
{
	added_tax obj;
	char option, choice;
	int a = 1;
	ifstream fin;
	a == security_password();
	if (!a)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << "\nIncorrect password, please try again.\n";
			if (security_password())
			{
				goto last;
			}
			else
			{
				cout << "\n\n\t\t\t password attempts limit reached.";
				cout << "\n\n\n\t\t\t initiating account lockdown.................. ";
				exit(0);
			}
		}
		cout << "\t\t\t Account lockdown in effect, please contact the account support number.";
	}
	else {
	last:;
		do {
		start:
			system("PAUSE");
			system("CLS");
			cout << "\n\n\t\t\t------------------------------";
			cout << "\n\t\t\tOnline shopping aid";
			cout << "\n\t\t\t------------------------------";
			cout << "\n\n\t\t\tWhere are we starting today?";
			cout << "\n\t\t\t1.\tEnter new shopping entry\n\t\t\t2.\t view previous entries\n\t\t\t3.\tExit\n";
			cout << "\n\nPlease enter your option: ";
			cin >> option;
			switch (option)
			{
			case'1':
				obj.calculatedtax();
				obj.tracked_outputs();
				goto start;
			case'2':
				fin.open("HIS.TXT", ios::in);
				while (fin.get(choice))
				{
					cout << choice;
				}
				fin.close();
				goto start;
			case'3':
				exit(0);
			default:
				cout << "\a";
			}
		} while (option != 3);
	}
	return 0;
}




