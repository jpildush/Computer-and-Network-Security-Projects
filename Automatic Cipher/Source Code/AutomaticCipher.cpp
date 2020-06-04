/*
*	AutomaticCipher Program - This program is designed to encrypt plaintext with a random uniquelly generated key. 
*				  Decryption of that ciphertext would only be possible with the original key that had been used to encrypt the original plaintext.
*	
*	By - Joseph Pildush
*/

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <ctime>
#include <locale>


using namespace std;

//Cipher Alphabet used with generated key for encryption and decryption
const string cipherAlphabet = "ZBJDESGQICWLMUOPHRFTNVKXYA";
//Regular alphabet that is used to translate the plaintext
const string regAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//The new alphabet that is created based on the cipher alphabet and the generated key
string newAlph;
/*
*	initCipher - Initialize gen key alphabet
*/
void initCipher() {
	newAlph = "";
}
/*
* generateKey - Generate special keys. Will not regenerate the key, make sure to save your key!
*	@return - 	key (string)
*/
string generateKey() 
{
	string key;
	for (int i = 0; i < 7; i++)
		key.push_back('A' + rand() % 26);

	return key;
}
/* 
*	encryptMessage - Encrypt the plaintext
*		@param - key(string) the generated key used to encrypt the message
*		@return - (bool) true if encryption succeeds, false otherwise
*/
bool encryptMessage(const string key)
{
	string plaintext = "";
	string newKey = "";
	size_t pos = 0;
	string ciphertext = plaintext;
	newAlph = cipherAlphabet;

	cout << "Enter a Message to Encrypt: ";
	getline(cin, plaintext);
	if (!cin.fail())
	{
		

		for (int i = 0; i < key.length(); i++)
		{
			pos = newAlph.find(key[i]);

			if (pos != -1)
			{
				newKey += key[i];
				newAlph.erase(pos, 1);
			}
		}
		newAlph += newKey;

		for (int i = 0; i < plaintext.length(); i++)
		{
			if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
			{
				pos = regAlphabet.find(plaintext[i]);
				ciphertext += newAlph[pos];

			}
			else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
			{
				pos = regAlphabet.find(toupper(plaintext[i]));
				ciphertext += tolower(newAlph[pos]);
			}
			else if(plaintext[i] == ' ')
				ciphertext += ' ';
			else
				ciphertext += plaintext[i];
		}

		ofstream encMsgOut("EncryptedMessage.txt", ios::out);

		if (encMsgOut.is_open())
		{
			encMsgOut << ciphertext;
			cout <<endl<< "Congratulations! Message has been successfully encrypted!" << endl << endl;
			cout << "Encrypted Message:  " << ciphertext << endl << endl;
			cout << "\nPress any key to continue ... "<<endl<<endl;
			cin.get();
		}
		else
		{
			cout << endl << "Error has occured! File not opened!" << endl;
			cout << "\nPress any key to continue ... "<<endl<<endl;
			cin.get();
			return false;
		}
		encMsgOut.close();

	}
	else
	{
		cout << "Error getting the nessage!" << endl;
	}

	return true;
}
/*
*	decryptMessage - decrypt the ciphertext
*		@param - ciphertext (srting) encrypted message from file
*		@param - key (string) generated key read from file
*		@return - (bool) true if decryption was successful, otherwise false
*/
bool decryptMessage(const string ciphertext, const string key)
{
	string newKey = ""; 
	size_t pos = 0;
	string plaintext = "";
	newAlph = cipherAlphabet;

	for (int i = 0; i < key.length(); i++)
	{
		pos = newAlph.find(key[i]);

		if (pos != -1)
		{
			newKey += key[i];
			newAlph.erase(pos, 1);
		}
	}

	newAlph += newKey;

	for (int i = 0; i < ciphertext.length(); i++)
	{
		if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
		{
			pos = newAlph.find(ciphertext[i]);
			plaintext += regAlphabet[pos];
		}
		else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
		{
			pos = newAlph.find(toupper(ciphertext[i]));
			plaintext += tolower(regAlphabet[pos]);
		}
		else if (ciphertext[i] == ' ')
			plaintext += ' ';
		else
			plaintext += ciphertext[i];
	}
	cout << endl << "Congratulations! The encrypted message has been successfully decrypted!" << endl << endl;
	cout << "Decrypted Message:  " << plaintext << endl << endl;
	cout << "\nPress any key to continue ... "<<endl;
	cin.get();
	return true;
}
/*
*	saveKey - will save the user selected key, from the list of genereated keys, into a txt file
*		@param - key (string) selected key that will be saved
*		@return - (bool) true if the save of the key was successful, false otherwise
*/
bool saveKey(const string key)
{
	//Display Message
	ofstream keyOut("EncryptionKey.txt", ios::out);

	if (keyOut.is_open())
	{
		cout << endl<<"Encryption Key has been Selected and Saved under EncryptionKey.txt" << endl;
		keyOut << key;
		cout << "\nPress any key to continue ... "<<endl;
		cin.get();
	}
	else
	{
		cout << endl << "Error has occured! File not opened!" << endl;
		cout << "\nPress any key to continue ... "<<endl;
		cin.get();
		return false;
	}
	keyOut.close();
	return true;
}
/*
*	Main function which is in an infinite loop until exit is selected
*	Users would be able to select to encrypt a new message or decrypt an existing encrypted message
*	Files for the encryption and decryption process will be generated at the location of this program.
*/
int main()
{
	ifstream keyFileIn;
	char input;
	bool exit = false;
	srand(time(NULL));
	initCipher();
	while (!exit)
	{
		cout << "Welcome to the Automatic Encryption Algorithm!" << endl << " ---by Joseph Pildush, inspired by the Keyword and Caeser Cipher" << endl << endl;

		cout << "---Select an Option---" << endl << endl;
		cout << "| 1. Encryption      |" << endl;
		cout << "| 2. Decryption      |" << endl;
		cout << "| 3. Exit Program    |" << endl;
		cout << "----------------------" << endl;
		cout << "->";
		cin >> input;

		if (!cin.fail() && (int)input >= 48 && (int)input <= 56)
		{
			cin.ignore(50, '\n');
			string key[3];
			switch (atoi(&input)) {
			case 1:
				for (int i = 0; i < 3; i++)
					key[i] = generateKey();
				cout << "Select 1 out of the 3 Generated Keys Below:" << endl << endl;
				cout << "1. " << key[0] << endl;
				cout << "2. " << key[1] << endl;
				cout << "3. " << key[2] << endl;
				cout << "4. Exit Program" << endl;
				cout << "----------------------" << endl;
				cout << "->";
				cin >> input;
				if (!cin.fail() && (int)input >= 48 && (int)input <= 56)
				{
					cin.ignore(50, '\n');
					switch (atoi(&input))
					{
					case 1:
						saveKey(key[0]);
						if (!encryptMessage(key[0]))
						{
							cout << "Error occured with Encryption" << endl;
						}
						break;
					case 2:
						saveKey(key[1]);
						if (!encryptMessage(key[1]))
						{
							cout << "Error occured with Encryption" << endl;
						}
						break;
					case 3:
						saveKey(key[2]);
						if (!encryptMessage(key[2]))
						{
							cout << "Error occured with Encryption" << endl;
						}
						break;
					case 4:
						cout << "Exiting Program!" << endl;
						exit = true;
						break;
					default:
						cout << "exit" << endl;
						break;
					}
				}
				break;
			case 2:
				cout << endl<<"Encryption Key requires to be in the same folder as this program," << endl;
				cout << "Named EncryptionKey.txt, as generated by this program." << endl;
				cout << "\nPress any key to recover the Encryption Key ... "<<endl;
				cin.get();
				keyFileIn.open("EncryptionKey.txt", ios::in);
				if (keyFileIn.is_open())
				{
					string key = "";
					while (!keyFileIn.eof())
					{
						char temp;
						keyFileIn >> temp;
						key += temp;
					}

					cout <<endl<< "Encrypted Message requires to be in the same folder as this program," << endl;
					cout << "Named EncryptedMessage.txt, as generated by this program." << endl;
					cout << "\nPress any key to recover the Encrypted Message ... "<<endl;
					cin.get();
					ifstream encMsgIn("EncryptedMessage.txt", ios::in);
					if (encMsgIn.is_open())
					{
						string encMessage = "";
						while (!encMsgIn.eof())
						{
							string temp;
							encMsgIn >> temp;
							encMessage += temp;
							encMessage += " ";
						}
						decryptMessage(encMessage, key);
					}
					else
					{
						cout << "Key not found! Restarting Program!" << endl;
					}
					encMsgIn.close();
				}
				else
				{
					cout << "Key not found! Restarting Program!" << endl;
				}

				keyFileIn.close();

				break;
			case 3:
				exit = true;
				break;
			}
		}
		else
		{
			cout << endl << "Error: Incorrect Menu Item Selected!" << endl;
			cin.get();
			cout << "\nPress any key to continue ... "<<endl;
			cin.get();
			exit = false;
		}
	}
	return 0;
}
