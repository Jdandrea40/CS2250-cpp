#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
int intro();
string encryptionCheck();
string decryptionCheck();
void bruteForceCheck();
string encryptedMessage(string& message, int& shiftValue);
string decryptedMessage(string& message, int& shiftValue);
void bruteForceDecrypt(string& message);

// Main method to run application
int main()
{
	// Prints a one time intro message
	cout << "Welcome to the Tali-banned Encrypter!" << endl;
	cout << "Make a selection from the menu and then follow the prompts." << endl;

	int menuChoice = 0;						// initialization of menu selection

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
				bruteForceCheck();
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
	
	// Message prompts
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
// Encryption case checking and verifying
string decryptionCheck()
{
	string message;								// initialize message

	// Message Prompts
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
// Checks and passes message to brute force decryption
void bruteForceCheck()
{
	string message;						//message initialization

	// Prompt and read in
	cout << "Please enter the message to decrypt:" << endl;
	cin.ignore();
	getline(cin, message);

	cout << "Decrypted as:" << endl;

	bruteForceDecrypt(message);	
}
// Function to encrypt a message
string encryptedMessage(string& message, int& shiftValue)
{
	for (int i = 0; i <= message.length(); i++)
	{
		int letterShift = 0;

		// stores the current letter as a char
		char letter = message[i];

		// Ensures that all special chars and spaces are not changed
		if (letter >= 'A' && letter <= 'Z')
		{
			// stores the shifted letter value seperately to avoid,
			// improper letter wrapping
			letterShift = letter + shiftValue;
			if (letterShift > 'Z')
			{
				letterShift -= 26;
			}
			letter = letterShift;
		}
		else if (letter >= 'a' && letter <= 'z')
		{
			letterShift = letter + shiftValue;
			if (letterShift > 'z')
			{
				letterShift -= 26;
			}
			letter = letterShift;

		}
		// replaces the orginal letter with encrypted letter
		message[i] = letter;
	}
	return message;
}
// Function for message decryption
string decryptedMessage(string& message, int& shiftValue)
{
	for (int i = 0; i <= message.length(); i++)
	{
		char letter = message[i];
		int letterShift = 0;

		// Ensures that all special chars and spaces are not changed
		if (letter >= 'A' && letter <= 'Z')
		{
			letterShift = letter - shiftValue;
			if (letterShift < 'A')
			{
				letterShift += 26;
			}
			letter = letterShift;
		}
		// Ensures that all special chars and spaces are not changed
		else if (letter >= 'a' && letter <= 'z')
		{
			// Stores the adjusted 
			letterShift = letter - shiftValue;
			if (letterShift < 'a')
			{
				letterShift += 26;
			}
			letter = letterShift;
		}
		message[i] = letter;
	}

	return message;
}
// Decrypts the message 25 times
void bruteForceDecrypt(string& message)
{
	string bruteForceMessage;				// message initialization

	int counter = 1;
	int shiftValue = 1; 

	// ensure 25 messages are attempted
	while (counter <= 25)
	{
		// reuses the drcrypt message function
		bruteForceMessage = decryptedMessage(message, shiftValue);

		// prints the message
		cout << bruteForceMessage << endl;

		counter++;
	}
}