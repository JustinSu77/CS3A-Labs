/**
	Date: 9/26/2023
	By: Justin Su
	Purpose: Problem #1 of Lab #9
**/
#include <iostream>
#include <iomanip>
using namespace std;

// Wallet class

class Wallet
{
	// Private member variables
private:
	int quarters;
	int dimes;
	int nickels;
	int cents;
	// Public functions
public:
	/**
		Default constructor.
		Precondition: Wallet object is instantiated with no arguements.
		Postcondition: Private variables quarters, dimes, nickels, and cents are set to 0.
	**/
	Wallet();

	/**
		Constructor with 4 arguments.
		Precondition: Wallet object is instantiated with 4 arguments.
		Postcondition: Private variables quarters, dimes, nickels, cents are set to given
					   newQuarters, newDimes, newNickels, and newCents.
			newQuarters as the amount of quarters wallet will have as int
			newDimes as the amount of dimes wallet will have as int
			newNickels as the amount of nickels wallet will have as int
			newCents as the amount of cents wallet will have as int
	**/
	Wallet(int newQuarters, int newDimes, int newNickels, int newCents);

	/**
		Setter function for quarters.
		Precondition: Private member variable quarters is set to 0 or a integer value.
		Postcondition: Private member variable quarters is set to given newQuarters
			newQuarters as new value for private member variable quarters as int.
	**/
	void setQuarters(int newQuarters);

	/**
		Setter function for dimes.
		Precondition: Private member variable dimes is set to 0 or a integer value.
		Postcondition: Private member variable dimes is set to given newDimes
			newDimes as new value for private member variable dimes as int.
	**/
	void setDimes(int newDimes);

	/**
		Setter function for nickels.
		Precondition: Private member variable nickels is set to 0 or a integer value.
		Postcondition: Private member variable nickels is set to given newNickels
			newNickels as new value for private member variable nickels as int.

	**/
	void setNickels(int newNickels);

	/**
		Setter function for cents.
		Precondition: Private member variable cents is set to 0 or a integer value.
		Postcondition: Private member variable cents is set to given newCents
			newCents as new value for private member variable cents as int.
	**/
	void setCents(int newCents);

	/**
		Getter function for quarters.
		Precondition: Private member variable quarters is set to 0 or a integer value.
		Postcondition: Private member variable quarters is returned as int
	**/
	int getQuarters();

	/**
		Getter function for dimes.
		Precondition: Private member variable dimes is set to 0 or a integer value.
		Postcondition: Private member variable dimes is returned as int
	**/
	int getDimes();

	/**
		Getter function for nickels.
		Precondition: Private member variable nickels is set to 0 or a integer value.
		Postcondition: Private member variable nickels is returned as int
	**/
	int getNickels();

	/**
		Getter function for cents.
		Precondition: Private member variable cents is set to 0 or a integer value.
		Postcondition: Private member variable cents is returned as int
	**/
	int getCents();
};

/**
	Prompt user and save their input for the number of each coin that will be used to create Wallet object.
	Precondition: Given quarters, dimes, nickels, and cents are 0 or have some other values.
	Postcondition: Given quarters, dimes, nickels, and cents have their values set to value from user.
		walletName as the name of the current wallet to set values for as int
		quarters as int reference
		dimes as int reference
		nickels as int reference
		cents as int reference
**/
void getNumberOfEachCoin(string walletName, int& quarters, int& dimes, int& nickels, int& cents);

/**
	Display the name, number of each coin ,and the total amount in given Wallet object.
	Precondition: Given Wallet object has been instantiated.
	Postcondition: The name, number of each coin, and the total amount in given Wallet object is printed to terminal.
		wallet as Wallet object
		walletName as the name if given Wallet object as string
**/
void displayWallet(Wallet wallet, string walletName);

/**
	Return the sum of the coins in given wallet object.
	Assumed even though obvious that coin values are based on United States values
	Precondition: Given Wallet object has been instantiated.
	Postcondition: The sum of the coins in given wallet object is eturned.
		wallet as Wallet object
**/
double getAmountInGivenWallet(Wallet wallet);

/**
	Output which given Wallet objects walletOne or walletTwo have the
	largest total sum of their coins or if they have the same amount.
	Precondition: Given Wallet objects walletOne and walletTwo have been instantiated.
	Postcondition: Outputs "[wallet name of wallet object with largest amount of coins] amount is greater than
							[wallet name of wallet object with lesser amount of coins]" or
							"[walletOneName] and [walletTwoName] have the same amount".
		walletOne as Wallet object
		walletOneName as name of walletOne as string
		walletTwo as Wallet object
		walletTwoName as name of walletTwo as string
**/
void outputWhichWalletAmountIsGreater(Wallet walletOne, string walletOneName, Wallet walletTwo, string walletTwoName);

/**
	Return a new Wallet object that has the sum of the coins from given walletOne and walletTwo.
	Precondition: Given Wallet objects walletOne and walletTwo have been instantiated.
	Postcondition: A Wallet object whose amount of each coin is the sum of the
				   corresponding coins from given walletOne and walletTwo.
		walletOne as Wallet object
		walletTwo as Wallet object
**/
Wallet addTwoWallets(Wallet walletOne, Wallet walletTwo);
int main()
{
	// Declare and initialize variables for each coin that will be in wallet objects
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int cents = 0;
	// Prompt and get number of each coin for first wallet from user.
	// Variables are passed into function as reference to reduce number of variables needed 
	getNumberOfEachCoin("w1", quarters, dimes, nickels, cents);
	// Instantiate first wallet object with the number of coins from user
	Wallet w1(quarters, dimes, nickels, cents);
	// Prompt and get number of each coin for second wallet from user
	getNumberOfEachCoin("w2", quarters, dimes, nickels, cents);
	// Instantiate second wallet object with the number of coins from user
	Wallet w2(quarters, dimes, nickels, cents);
	// Output the number of each coin and the total amount for each wallet object to terminal
	displayWallet(w1, "w1");
	cout << endl;
	displayWallet(w2, "w2");
	cout << endl;
	// Output which given wallet object has the largest amount or if they are equal to terminal
	outputWhichWalletAmountIsGreater(w1, "w1", w2, "w2");
	// Output newline to terminal for readability
	cout << endl;
	// Output that a new Wallet object will be created to terminal
	cout << "Create new Wallet #3 by adding w1 and w2" << endl;
	// Instantiate new Wallet object to be the Wallet object returned by function 
	Wallet w3 = addTwoWallets(w1, w2);
	// Output newline to terminal for readability
	cout << endl;
	// Output the number of each coin and total amount of third Wallet object
	displayWallet(w3, "w3");

	return 0;
}

Wallet::Wallet()
{
	// Set the private variables to 0
	quarters = 0;
	dimes = 0;
	nickels = 0;
	cents = 0;
}

Wallet::Wallet(int newQuarters, int newDimes, int newNickels, int newCents)
{
	// Set the private variable to the given corresponding values
	quarters = newQuarters;
	dimes = newDimes;
	nickels = newNickels;
	cents = newCents;
}

void Wallet::setQuarters(int newQuarters)
{
	// Set the quarters private member variable to given newQuarters
	quarters = newQuarters;
}

void Wallet::setDimes(int newDimes)
{
	// Set the dimes private member variable to given newDimes
	dimes = newDimes;
}

void Wallet::setNickels(int newNickels)
{
	// Set the nickels private member variable to given newNickels
	nickels = newNickels;
}

void Wallet::setCents(int newCents)
{
	// Set the cents private member variable to given newCents
	cents = newCents;
}

int Wallet::getQuarters()
{
	// Return private variable quarters
	return  quarters;
}

int Wallet::getDimes()
{
	// Return private variable dimes
	return dimes;
}

int Wallet::getNickels()
{
	// Return private variable nickels
	return nickels;
}

int Wallet::getCents()
{
	// Return private variable cents
	return cents;
}

void getNumberOfEachCoin(string walletName, int& quarters, int& dimes, int& nickels, int& cents)
{

	cout << "Enter the number of quarters for " << walletName << "  : ";
	cin >> quarters;
	cout << "Enter the number of dimes for " << walletName << "     : ";
	cin >> dimes;
	cout << "Enter the number of nickles for " << walletName << "   : ";
	cin >> nickels;
	cout << "Enter the number of pennies for " << walletName << "   : ";
	cin >> cents;
	cout << endl;
}

void displayWallet(Wallet wallet, string walletName)
{
	// Get the amount of each coin in given Wallet object 
	int quarters = wallet.getQuarters();
	int dimes = wallet.getDimes();
	int nickels = wallet.getNickels();
	int cents = wallet.getCents();
	// Output the name of wallet
	cout << walletName << " :" << endl;
	// Output the number of each coin
	cout << "     " << quarters << " quarters" << endl;
	cout << "     " << dimes << " dimes" << endl;
	cout << "     " << nickels << " nickels" << endl;
	cout << "     " << cents << " cents" << endl;

	// Set cout to display double values rounded to 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	// Output the total amount of given wallet
	cout << "     ----> amount = $" << getAmountInGivenWallet(wallet) << endl;

}

double getAmountInGivenWallet(Wallet wallet)
{
	// Declare and initialize the value of each coin
	const double QUARTER_VALUE = 0.25;
	const double DIME_VALUE = 0.10;
	const double NICKEL_VALUE = 0.05;
	const double CENT_VALUE = 0.01;
	// Get the amount of each coin in given Wallet object
	int quarters = wallet.getQuarters();
	int dimes = wallet.getDimes();
	int nickels = wallet.getNickels();
	int cents = wallet.getCents();
	// Declare and initialize the variable to be returned as the total sum of the coins in the given Wallet object
	double amount = (quarters * QUARTER_VALUE) + (dimes * DIME_VALUE) + (nickels * NICKEL_VALUE) + (cents * CENT_VALUE);
	// Return amount
	return amount;
}

void outputWhichWalletAmountIsGreater(Wallet walletOne, string walletOneName, Wallet walletTwo, string walletTwoName)
{
	// Get the total amount of each given Wallet object
	double walletOneAmount = getAmountInGivenWallet(walletOne);
	double walletTwoAmount = getAmountInGivenWallet(walletTwo);
	// If the total amount of walletOne is greater than total amount in walletTwo
	if (walletOneAmount > walletTwoAmount)
	{
		// Output to terminal
		cout << walletOneName << " amount is greater than " << walletTwoName << endl;
	}
	// If total amount of walletOne is greater than total amount in walletTwo
	else if (walletOneAmount < walletTwoAmount)
	{
		// Output to terminal
		cout << walletTwoName << " amount is greater than " << walletOneName << endl;
	}
	// If total amount of each wallet is equal
	else
	{
		// Output to terminal
		cout << walletOneName << " and " << walletTwoName << " have the same amount" << endl;
	}
}

Wallet addTwoWallets(Wallet walletOne, Wallet walletTwo)
{
	// Declare and initialize the number of each coin that Wallet object that is returned will have
	// Add the number of corresponding coins from each given Wallet object
	int numberOfQuarters = walletOne.getQuarters() + walletTwo.getQuarters();
	int numberOfDimes = walletOne.getDimes() + walletTwo.getDimes();
	int numberOfNickels = walletOne.getNickels() + walletTwo.getNickels();
	int numberOfPennies = walletOne.getCents() + walletTwo.getCents();
	// Instantiate the Wallet object to be retured
	Wallet newWallet(numberOfQuarters, numberOfDimes, numberOfNickels, numberOfPennies);
	// Return the instantiated Wallet object
	return newWallet;
}