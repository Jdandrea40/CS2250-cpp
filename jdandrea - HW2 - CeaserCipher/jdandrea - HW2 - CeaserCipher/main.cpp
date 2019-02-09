#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
int intro();
void encryptionCheck();
void decryptionCheck();
string encryptedMessage(string& message, int& shiftValue);
string decryptedMessage(string& message, int& shiftValue);
string bruteForceDecrypt(string& message);

// Main method to run application
int main()
{

	cout << "Welcome to the Tali-banned Encrypter!" << endl;
	cout << "Make a selection from the menu and then follow the prompts." << endl;
	int menuChoice = 0;

	while (menuChoice < 5)
	{	
		switch (intro())
		{
		case 1:
		{
			encryptionCheck();
			break;
		}
		case 2:
		{
			decryptionCheck();
			break;
		}
		case 3:
		{
			string message;

			cout << "Please enter the message to encrypt:" << endl;
			cin.ignore();
			getline(cin, message);
			bruteForceDecrypt(message);
		}
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
// Encryption case checkingand verifying
void decryptionCheck()
{
	string message;								// initialize message

	cout << "Please enter the message to decrypt:";
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

	decryptedMessage(message, shiftValue);
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
		if (letter >= 'A' && letter <= 'z')
		{
			// shifts the current letter by the appropriate value
			letter = letter + shiftValue;
		}
		// replaces the orginal letter with encrypted letter
		encryptedMessage[i] = letter;
	}

	cout << encryptedMessage << endl;

	return encryptedMessage;
}

string decryptedMessage(string& message, int& shiftValue)
{
	string decryptedMessage = message;

	for (int i = 0; i <= decryptedMessage.length(); i++)
	{
		char letter = decryptedMessage[i];
		if (letter >= 'A' && letter <= 'z')
		{
			letter = letter - shiftValue;
		}

		decryptedMessage[i] = letter;
	}

	cout << decryptedMessage << endl;

	return decryptedMessage;
}

string bruteForceDecrypt(string& message)
{
	string decryptedMessage = message;
	int counter = 1;
	int shiftValue = 1;

	while (counter <= 25)
	{
		for (int i = 0; i <= decryptedMessage.length(); i++)
		{
			char letter = decryptedMessage[i];
			if (letter >= 'A' && letter <= 'z')
			{
				letter = letter - shiftValue;
			}

			decryptedMessage[i] = letter;
		}

		if (counter == 1)
		{
			cout << "Decrypted as: " << endl;
		}
		
		cout << decryptedMessage << endl;

		counter++;
		shiftValue++;
	}
	return decryptedMessage;
}