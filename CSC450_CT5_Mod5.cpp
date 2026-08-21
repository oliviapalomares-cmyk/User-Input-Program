//============================================================================
// Name        : CSC450_CT5_Mod5.cpp
// Author      : Olivia
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Method to reverse the contents of the file
void reverseFile()
{
    ifstream inputFile("CSC450_CT5_mod5.txt");

    if (!inputFile)
    {
        cout << "Error opening CSC450_CT5_mod5.txt" << endl;
        return;
    }

    // Read the entire file
    string contents;
    string line;

    while (getline(inputFile, line))
    {
        contents += line;
        contents += '\n';
    }

    inputFile.close();

    // Reverse all characters
    reverse(contents.begin(), contents.end());

    // Create the reversed file
    ofstream outputFile("CSC450-mod5-reverse.txt");

    if (!outputFile)
    {
        cout << "Error creating CSC450-mod5-reverse.txt" << endl;
        return;
    }

    outputFile << contents;

    outputFile.close(); // @suppress("Method cannot be resolved")

    cout << "The reversed file was created successfully." << endl;
}

int main()
{
    string userInput;

    cout << "Enter information to add to the file: ";
    getline(cin, userInput);

    // Open the original file in append mode
    ofstream outputFile("CSC450_CT5_mod5.txt", ios::app);

    if (!outputFile)
    {
        cout << "Error opening CSC450_CT5_mod5.txt" << endl;
        return 1;
    }

    // Add the user's input to the existing file
    outputFile << userInput << endl;

    outputFile.close(); // @suppress("Method cannot be resolved")

    cout << "Your information was added to the file." << endl;

    // Reverse the complete file
    reverseFile();

    return 0;
}
