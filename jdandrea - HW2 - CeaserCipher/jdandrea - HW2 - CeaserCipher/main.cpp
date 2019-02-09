#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
int intro();
void encryptionCheck();
string encryptedMessage(string& message, int& shiftValue);

// Main method to run application
int main()
{
	int menuChoice = intro();					// switch statement support
	switch (menuChoice)
	{
		case 1:
		{
			encryptionCheck();
			break;
		}
	}


	int a;
	cin >> a;

	return 0;
}

// Displays an introduction message and menu
int intro()
{
	cout << "Welcome to the Tali-banned Encrypter!" << endl;
	cout << "Make a selection from the menu and then follow the prompts." << endl;
	cout << "*************************************" << endl;
	cout << "* 1 - Encrypt a message" << endl;
	cout << "* 2 - Decrypt a message" << endl;
	cout << "* 3 - Brute - force decrypt a message" << endl;
	cout << "* 4 - Quit" << endl;
	cout << "*************************************" << endl;
	cout << "Please make a menu selection (1-4):" << endl;

	int menuChoice = 0;						// menu choice initialization
	cin >> menuChoice;
	while (menuChoice < 1 || menuChoice > 4)
	{
		cout << "Please make a menu selection (1-4):" << endl;
		cout << "Invalid choice, Please make a menu selection (1-4):" << endl;
		cin >> menuChoice;
	}

	return menuChoice;
}

// Encryption case checkingand verifying
void encryptionCheck()
{
	string message;								// initialize message

	cout << "Please enter the message to encrypt:";
	cin.ignore();
	getline(cin, message);

	cout << "Please enter the shift value (1-25):";
	int shiftValue = 0;

	cin >> shiftValue;


	while (shiftValue > 25 || shiftValue < 1)
	{
		cout << "Invalid choice, Please enter the shift value (1-25):";
		cin >> shiftValue;
	}

	encryptedMessage(message, shiftValue);
}

// Function to encrypt a message
string encryptedMessage(string& message, int& shiftValue)
{
	string encryptedMessage = message;				// stores the original message

	for (int i = 0; i <= encryptedMessage.length(); i++)
	{
		// stores the current letter as a char
		char letter = encryptedMessage[i];

		// Ensures that all special chars and spaces are not changed
		if (letter > 'A' && letter < 'z')
		{
			// shifts the current letter by the appropriate value
			letter = letter + shiftValue;
		}
		// replaces the orginal letter with encrypted letter
		encryptedMessage[i] = letter;
	}

	cout << encryptedMessage;
	
	return encryptedMessage;

}