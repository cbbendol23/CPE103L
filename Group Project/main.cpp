#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

/*
Bendol, Cherry Ben Jr. R.

*/

// Universal Variables
const int maxNumCustomer = 100;
string accountTable[maxNumCustomer][4] =
    {{"0123-4567-8901", "Dina Bale", "5000.00", "1111"},
    {"2345-6789-0123", "Mally Gaya", "0.00", "2222"},
    {"3456-7890-1234", "Toto Lee", "10000", "3333"},
    {"4567-8901-2345", "Mina Mahal", "2500", "4444"},
    {"5678-9012-3456", "Cory Pot", "10000", "5555"}};
int currentNumCustomer = 5;
int currentAccIndex = -1;

// Function Prototype
void outputOne();
void adminView();
void outputThree();
void balanceInquiry();
void withdrawal();
void deposit();
void cancel();
bool validatePin(string pin);

void outputOne(){

    char choice;

    cout << "____________________________________" << endl;
    cout << "_                                  _" << endl;
    cout << "_                FBC               _" << endl;
    cout << "_   Filipinas Banking Corporation  _" << endl;
    cout << "____________________________________" << endl;
    cout << "_                                  _" << endl;
    cout << "_      S-> Start Transaction       _" << endl;
    cout << "_      Q-> Quit                    _" << endl;
    cout << "_                                  _" << endl;
    cout << "____________________________________" << endl;
    cout << endl;

    cout << "Choice: ";
    cin >> choice;

    if (choice == 'Q' || choice == 'q')
    {
        cout << "\n";
        cout << "Quiting..." << endl;
        exit(0);
    }
    else if (choice == 'S' || choice == 's')
    {
    	cout << "\n";
        cout << "Starting..." << endl;
        return;
    }
    else
    {
        cout << "Invalid choice. Please Enter 'S' to start or 'Q' to quit." << endl;
        exit(0);
    }
};

void viewCustomerInformation()
{
	cout << "Viewing Customers Information" << endl;
	cout << setw(20) << "Account Number" << setw(20) << "Account Name"
		 << setw(20) << "Balance" << setw(20) << "Pin" << endl;

	for (int i = 0; i < currentNumCustomer; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << setw(20) << accountTable[i][j];
		}
		cout << endl;
	}
	adminView();
}

void addNewCustomer()
{
	string newCustomerAcc, newCustomerName, newBalance, newPin;

	cout << "\n";
	cout << "Adding new Customer Information..." << endl;
	cout << "\n";

	cout << "Enter Account Number: ";
	cin >> newCustomerAcc;

	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, newCustomerName);

	cout << "Enter Balance: ";
	cin >> newBalance;

	cout << "Enter Pin: ";
	cin >> newPin;

	if (currentNumCustomer < maxNumCustomer)
	{
		accountTable[currentNumCustomer][0] = newCustomerAcc;
		accountTable[currentNumCustomer][1] = newCustomerName;
		accountTable[currentNumCustomer][2] = newBalance;
		accountTable[currentNumCustomer][3] = newPin;

		currentNumCustomer++;

		cout << "\n";
		cout << "New Customer Added Successfully!" << endl;
	}
	else
	{
		cout << "Maximum Number of Customer has been reached. Cannot add new Customer, sorry." << endl;
	}
	adminView();
}

void editCustomerInformation()
{
	string editAccNum;
	bool match = false;

	cout << "\n";
	cout << "Editing Customer Information..." << endl;

	cout << "\n";
	cout << "Enter Account Aumber that is to be edited: ";
	cin >> editAccNum;

	for (int i = 0; i < currentNumCustomer; ++i)
	{
		if (editAccNum == accountTable[i][0])
		{
			match = true;

			cout << "\n";
			cout << "Account Number is found.. Please enter new informations" << endl;

			cout << "Enter New Name: ";
			cin.ignore();
			getline(cin, accountTable[i][1]);

			cout << "Enter New Balance: ";
			cin >> accountTable[i][2];

			cout << "Enter New Pin: ";
			cin >> accountTable[i][3];

			cout << "\n";
			cout << "Editing Information has been successfully done!" << endl;
			break;
		}
	}
	if (!match)
	{
		cout << "\n";
		cout << "Inputted Account Number has no match to our system" << endl;
	}
	adminView();
}

void changeCustomerPin()
{
	string editAccNum;
	bool match = false;

	cout << "\n";
	cout << "Changing Customer Pin..." << endl;
	cout << "\n";

	cout << "Enter Account Number that is to be edited: ";
	cin >> editAccNum;

	for (int i = 0; i < currentNumCustomer; ++i)
	{
		if (editAccNum == accountTable[i][0])
		{
			match = true;

			cout << "\n";
			cout << "Account Number is found..";

			cout << "\n";
			cout << "Enter New Pin: ";
			cin >> accountTable[i][3];
		}
	}
	if (!match)
	{
		cout << "\n";
		cout << "Inputted Account Number has no match to our system" << endl;
	}
	adminView();
}

void adminView()
{
	char choice;
	cout << "____________________________________" << endl;
    cout << "_                                  _" << endl;
    cout << "_                FBC               _" << endl;
    cout << "_   Filipinas Banking Corporation  _" << endl;
    cout << "____________________________________" << endl;
    cout << "_                                  _" << endl;
    cout << "_    What would you like to do?    _" << endl;
    cout << "_                                  _" << endl;
    cout << "_  (V) - View Customer Information _" << endl;
    cout << "_  (A) - Add New Customer          _" << endl;
    cout << "_  (E) - Edit Customer Information _" << endl;
    cout << "_  (C) - Change Customer Pin #     _" << endl;
    cout << "_  (X) - Exit                      _" << endl;
    cout << "____________________________________" << endl;
    cout << endl;

    cout << "Choice: ";
    cin >> choice;



    switch (choice)
    {
    	case 'v':
    	case 'V':
    		viewCustomerInformation();
    		break;
    	case 'a':
    	case 'A':
    		addNewCustomer();
    		break;
    	case 'e':
    	case 'E':
    		editCustomerInformation();
    		break;
    	case 'c':
    	case 'C':
    		changeCustomerPin();
    		break;
    	case 'x':
    	case 'X':
    		cout << "Exiting Admin View..." << endl;
    		exit(0);
	}

}

// Used for validation of Pin during outputTwo
bool validatePin(string pin)
{
	for (int i = 0; i < currentNumCustomer; ++i)
	{
		if (accountTable[i][3] == pin)
		{
			currentAccIndex = i;
			return true;
		}
	}
	return false;
}

void outputTwo(){

    string inputPin;
    int attempts = 0;
    const int maxAttempts = 3;
    bool pinFound = false;

	while (attempts < maxAttempts)
	{
	    cout << "____________________________________" << endl;
	    cout << "_                                  _" << endl;
	    cout << "_                FBC               _" << endl;
	    cout << "_   Filipinas Banking Corporation  _" << endl;
	    cout << "____________________________________" << endl;
	    cout << "_                                  _" << endl;
	    cout << "_      Enter your pin number:      _" << endl;
	    cout << "_                                  _" << endl;
	    cout << "____________________________________" << endl;
	    cout << endl;

	    cout << "Pin: ";
	    cin >> inputPin;

	    if (inputPin == "0000")
	    {
	    	adminView();
	    	exit(0);
		}

	    if (validatePin(inputPin))
        {
            cout << "PIN validated successfully. Proceeding with transaction..." << endl;
            pinFound = true;
            outputThree();
            break;

        }
        else
        {
            cout << "\n";
            cout << "Invalid PIN. Try again." << endl;
            attempts++;
        }
    }

    if (!pinFound) {
        cout << "CAPTURED CARD... PLEASE CALL 143-44" << endl;
        exit(0);
	}
}

void outputThree()
{
	char choice;
	cout << "____________________________________" << endl;
    cout << "_                                  _" << endl;
    cout << "_                FBC               _" << endl;
    cout << "_   Filipinas Banking Corporation  _" << endl;
    cout << "____________________________________" << endl;
    cout << "_                                  _" << endl;
    cout << "_    Select Type of Transaction    _" << endl;
    cout << "_                                  _" << endl;
    cout << "_    B -> Balance Inquiry          _" << endl;
    cout << "_    W -> Withdrawal               _" << endl;
    cout << "_    D -> Deposit                  _" << endl;
    cout << "_    C -> Cancel                   _" << endl;
    cout << "_                                  _" << endl;
    cout << "_    Enter Transaction Type: ___   _" << endl;
    cout << "____________________________________" << endl;
    cout << "\n";

    cout << "Choice: ";
    cin >> choice;

    switch (choice)
    {
    	case 'b':
    	case 'B':
    		balanceInquiry();
    		break;

    	case 'w':
    	case 'W':
    		withdrawal();
    		break;

    	case 'd':
    	case 'D':
    		deposit();
    		break;

    	case 'c':
    	case 'C':
    		outputOne();
    		break;

        default:
            cout << "Invalid Key" << endl;
            outputThree();
	}
}

void balanceInquiry()
{
    char choice;

    while (true)
    {
        cout << "____________________________________" << endl;
        cout << "_                                  _" << endl;
        cout << "_                FBC               _" << endl;
        cout << "_   Filipinas Banking Corporation  _" << endl;
        cout << "____________________________________" << endl;
        cout << "\n";
        cout << "Account #: " << accountTable[currentAccIndex][0] << endl;
        cout << "Account Name: " << accountTable[currentAccIndex][1] << endl;
        cout << "Balance: " << accountTable[currentAccIndex][2] << endl;
        cout << "\n";

        cout << "Press X to exit" << endl;
        cin >> choice;

        if (choice == 'x' || choice == 'X')
        {
            outputThree();
            break;
        }
        else
        {
            cout << "\n";
            cout << "Invalid Key. Press X to exit." << endl;
        }
    }
}

void withdrawal()
{
    string input;
    int withdrawnAmount;

    while (true)
    {
        cout << "____________________________________" << endl;
        cout << "_                                  _" << endl;
        cout << "_                FBC               _" << endl;
        cout << "_   Filipinas Banking Corporation  _" << endl;
        cout << "____________________________________" << endl;
        cout << "\n";
        cout << "_   Enter amount to be withdrawn   _" << endl;
        cout << "_                                  _" << endl;
        cout << "_          Press X to exit         _" << endl;
        cout << "____________________________________" << endl;
        cout << "\n";

        cout << "Amount: ";
        cin >> input;

        if (input == "X" || input == "x")
        {
            outputThree();
            break;
        }

        stringstream ss(input);
        ss >> withdrawnAmount;

        if (withdrawnAmount <= 0 || withdrawnAmount < 100 || withdrawnAmount % 100 != 0)
        {
            cout << "\n";
            cout << "Invalid amount!" << endl;
            continue;
        }

        // Compare withdrawal money to the current balance
        float currentBalance = stof(accountTable[currentAccIndex][2]);
        if (withdrawnAmount > currentBalance)
        {
            cout << "\n";
            cout << "Insufficient Funds!" << endl;
            continue;
        }

        // Update the Balance of the Customer
        currentBalance  = currentBalance - withdrawnAmount;

        // Convert to string
        stringstream newBalance;

        // Set to 2 decimal places only
        newBalance << fixed << setprecision(2) << currentBalance;
        accountTable[currentAccIndex][2] = newBalance.str();

        cout << "Withdrawal successfull!" << endl;

        outputThree();
        break;

    }
}

void deposit()
{
    string input;
    int depositedAmount;

    while (true)
    {
        cout << "____________________________________" << endl;
        cout << "_                                  _" << endl;
        cout << "_                FBC               _" << endl;
        cout << "_   Filipinas Banking Corporation  _" << endl;
        cout << "____________________________________" << endl;
        cout << "\n";
        cout << "_   Enter amount to be deposited   _" << endl;
        cout << "_                                  _" << endl;
        cout << "_          Press X to exit         _" << endl;
        cout << "____________________________________" << endl;
        cout << "\n";

        cout << "Amount: ";
        cin >> input;

        if (input == "X" || input == "x")
        {
            outputThree();
            break;
        }

        stringstream ss(input);
        ss >> depositedAmount;

        if (depositedAmount <= 0 || depositedAmount < 100 || depositedAmount % 100 != 0)
        {
            cout << "\n";
            cout << "Invalid amount!" << endl;
            continue;
        }

        // Get the value from the array and store in current function
        float currentBalance = stof(accountTable[currentAccIndex][2]);

        // Update the Balance of the Customer
        currentBalance  = currentBalance + depositedAmount;

        // Convert to string
        stringstream newBalance;

        // Set to 2 decimal places only
        newBalance << fixed << setprecision(2) << currentBalance;
        accountTable[currentAccIndex][2] = newBalance.str();

        cout << "Deposit successfull!" << endl;

        outputThree();
        break;

    }
}


int main()
{
    while (true)
    {
        outputOne();
        outputTwo();
    }
}
