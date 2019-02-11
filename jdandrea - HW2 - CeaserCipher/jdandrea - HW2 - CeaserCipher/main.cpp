#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
int intro();
string encryptionCheck();
string decryptionCheck();
string bruteForceCheck();
string encryptedMessage(const string& message, int& shiftValue);
string decryptedMessage(const string& message, int& shiftValue);
string bruteForceDecrypt(const string& message);

// Main method to run application
int main()
{
	// Prints a one time intro message
	cout << "Welcome to the Tali-banned Encrypter!" << endl;
	cout << "Make a selection from the menu and then follow the prompts." << endl;
	int menuChoice = 0;

	while (menuChoice < 5)
	{	
		// Switch case based from intro selection
		switch (intro())
		{
			// Encrypt a Message
			case 1:
			{
				string encryptedMessage = encryptionCheck();
				cout << "Encrypted as: \n" << encryptedMessage << endl;
				break;
			}
			// Decrypt a Message
			case 2:
			{
				string decryptedMessage = decryptionCheck();
				cout << "Decrypted as: \n" << decryptedMessage << endl;
				break;
			}
			// Brute Force a message (25 different decryptions)
			case 3:
			{
				string bruteForceMessage = bruteForceCheck();
				break;
			}
			// exit case
			case 4:
			{
				cout << "Thank you Caesar!  See ya" << endl;
				return 0;
			}
		}
	}
	return 0;
}
// Displays an introduction message and menu
int intro()
{
	int menuChoice = 0;						// menu choice initialization

	cout << "*************************************" << endl;
	cout << "* 1 - Encrypt a message" << endl;
	cout << "* 2 - Decrypt a message" << endl;
	cout << "* 3 - Brute - force decrypt a message" << endl;
	cout << "* 4 - Quit" << endl;
	cout << "*************************************" << endl;
	cout << "Please make a menu selection (1-4):" << endl;

	// takes in menu selection and ensures proper input
	cin >> menuChoice;
	while (menuChoice < 1 || menuChoice > 4)
	{
		cout << "Invalid choice, Please make a menu selection (1-4):" << endl;
		cin >> menuChoice;
	}
	// returns the menu choice for switch statement in main
	return menuChoice;
}

// Encryption case checking and verifying
string encryptionCheck()
{
	string message;								// initialize message
	// Propt messages
	cout << "Please enter the message to encrypt:" << endl;
	cin.ignore();
	getline(cin, message);

	cout << "Please enter the shift value (1-25):" << endl;
	int shiftValue = 0;
	// takes in shift value
	cin >> shiftValue;

	// ensures proper input
	while (shiftValue > 25 || shiftValue < 1)
	{
		cout << "Invalid choice, Please enter the shift value (1-25):" << endl;
		cin >> shiftValue;
	}
	// returns the ecrypted message for printing later
	return encryptedMessage(message, shiftValue);

}
// Encryption case checkingand verifying
string decryptionCheck()
{
	string message;								// initialize message

	cout << "Please enter the message to decrypt:" << endl;;
	cin.ignore();
	getline(cin, message);

	cout << "Please enter the shift value (1-25):" << endl;
	int shiftValue = 0;

	cin >> shiftValue;

	// ensures proper input
	while (shiftValue > 25 || shiftValue < 1)
	{
		cout << "Invalid choice, Please enter the shift value (1-25):";
		cin >> shiftValue;
	}

	return decryptedMessage(message, shiftValue);
}
// 
string bruteForceCheck()
{
	string message;
	cout << "Please enter the message to decrypt:" << endl;
	cin.ignore();
	getline(cin, message);
	cout << "Decrypted as:" << endl;
	return bruteForceDecrypt(message);	
}
// Function to encrypt a message
string encryptedMessage(const string& message, int& shiftValue)
{
	string encryptedMessage = message;				// stores the original message

	for (int i = 0; i <= encryptedMessage.length(); i++)
	{
		// stores the current letter as a char
		char letter = encryptedMessage[i];
		int shift = 1;
		// Ensures that all special chars and spaces are not changed
		// TEST: aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ ,.?/!@#$%^&*()_+
		if (letter >= 'A' && letter <= 'Z')
		{
			while (shift <= shiftValue)
			{
				letter++;
				if (letter > 'Z')
				{
					letter = 'A';
				}
				shift++;

			}
		}
		else if (letter >= 'a' && letter <= 'z')
		{
			while (shift <= shiftValue)
			{
				letter++;
				if (letter > 'z')
				{
					letter = 'a';
				}
				shift++;

			}
		}
		// replaces the orginal letter with encrypted letter
		encryptedMessage[i] = letter;
	}
	return encryptedMessage;
}

string decryptedMessage(const string& message, int& shiftValue)
{
	string decryptedMessage = message;

	for (int i = 0; i <= decryptedMessage.length(); i++)
	{
		char letter = decryptedMessage[i];
		int shift = 1;
		// Ensures that all special chars and spaces are not changed
		// TEST: aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ ,.?/!@#$%^&*()_+
		if (letter >= 'A' && letter <= 'Z')
		{
			while (shift <= shiftValue)
			{
				letter--;
				if (letter < 'A')
				{
					letter = 'Z';
				}
				shift++;
			}
		}
		else if (letter >= 'a' && letter <= 'z')
		{
			while (shift <= shiftValue)
			{
				letter--;
				if (letter < 'a')
				{
					letter = 'z';
				}
				shift++;
			}
		}
		decryptedMessage[i] = letter;
	}
	return decryptedMessage;
}

string bruteForceDecrypt(const string& message)
{
	string bruteForceMessage;
	int counter = 1;
	int shiftValue = 1;

	while (counter <= 25)
	{
		bruteForceMessage = decryptedMessage(message, shiftValue);

		cout << bruteForceMessage << endl;

		counter++;
		shiftValue++;
	}
	return bruteForceMessage;
}