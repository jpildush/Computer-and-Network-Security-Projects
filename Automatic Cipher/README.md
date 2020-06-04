# Automatic Cipher Program - Written in C++

## The Automatic Cipher has three stages in the program.

1.	Generate random and unique one-time use keys 
2.	Encrypt a given plaintext message with the selected key from the list of keys generated
3.	Decrypt a given ciphertext message with the saved generated key from step 1.

### Generating a Key
The beginning of the program will generate three keys to select from. These keys will then be used to change the specific cipher alphabet that has been created, generating a unique cipher alphabet for the unique key. The base cipher alphabet has been created through multiple permutations of the regular English alphabet. This will ensure that the overall unique cipher alphabet will be more randomized compared to using the standard alphabet as its base.

### Encrypting a Message
When encrypting the plaintext, the chosen key would be used to encrypt the plaintext by manipulating the cipher alphabet into a unique cipher alphabet. Before the encryption process may begin, the key would be substituted into the cipher alphabet to generate a more randomized cipher alphabet. With this, the plaintext can be encrypted and the selected unique key in step 1 would be the only key capable of decrypting the soon to be generated ciphertext. 

### Decrypting a Message
The decryption process follows relatively the same steps as the encryption process, but in reverse. Only the random unique key that had been originally generated during the encyrption process, would be able to decrypt the ciphertext. 

## Executing the Automatic Cipher
 **Please note that running the Automatic Cipher will generate 2 text files (the random and unique encryption key and the encrypted cipher text)**
 
 ### Executing on Windows
 A compiled executable file (.exe) has been provided for use on Windows systems.
 
 ### Executing on Mac/Linux
 **I have provided a compiled output file, if compiling the program is not desired. 
 Compiling and executing on Mac or Linux requires terminal access.**
 
 #### Compiling Source Code in Terminal
 **Please note directly copying the execution lines may give errors during compilation. To prevent this, write out the compile command below into terminal rather than pasting it into terminal**
 
 ```
 g++ AutomaticCipher.cpp -o AutomaticCipher.out -std=c++11
 ```
 
 #### Executing Compiled Output File in Terminal
 ```
 ./AutomaticCipher.out
 ```
 
 ### Decryption Requirements
 Ensure that EncryptedMessage.txt and its matching EncryptionKey.txt is in the same folder as the .exe file (Windows) or the .out file (Mac/Linux)
