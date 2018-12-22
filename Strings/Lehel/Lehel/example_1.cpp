#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int  main()
{
   string strInput("");
   //string strFirstWord = NULL;
   string strFirstWord("");
   string strLastWord("");
   string strSubs("");
   string strReplacedSentence("");
   string strPartOfTheSentence("");
   char chCharacterToSearch = ' '; // -- I want to searching for spaces 

   int nNumberOfWords = 0;
   int nNumberOfCharacters = 0;
   int nTotalNumberOfCharacters;

   size_t sztPos = NULL;


   //--- This is how I read a sentence (not a word but a sentence with spaces etc)
   cout << "Please enter a sentence - ";
   getline(cin, strInput);

   cout << "This is what was entered and stored in the variable = " << strInput << endl;

   //--- This is how I get the first word
   istringstream iss(strInput, istringstream::in);
   strFirstWord = strInput.substr(0, strInput.find(' '));

   //--- This is how I get the last word
   std::size_t pos = strInput.size();
   while (strInput[pos] == ' ' && pos > 0) --pos;
   if (pos == 0) { /* string consists entirely of spaces */ }
   strLastWord = strInput.substr(strInput.find_last_of(' ', pos));

   //--- This is how I split every word in the sentence
   do
   {
      strSubs.clear(); // make sure I initialize it everytime to avoid any garbage
      iss >> strSubs;
      if (!strSubs.empty()) // check if we have received any null character because you don't want to print them (end of line for example)
      {
         cout << "Substring: " << strSubs << endl;
         nNumberOfWords++;  // This counter keeps track of the total number of words in the sentence
      }
   } while (iss);


   nNumberOfCharacters = count(begin(strInput), end(strInput), chCharacterToSearch);
   nTotalNumberOfCharacters = strInput.length();
   strReplacedSentence = strInput;
     
   cout << endl << "First word in the sentence = " << strFirstWord << endl;
   cout << "Last word in the sentence = " << strLastWord << endl;
   cout << "Total words in the sentence = " << nNumberOfWords << endl;
   cout << "Total number of characters = " << nTotalNumberOfCharacters << endl;
   cout << "Total number of charactes without spaces = " << (nTotalNumberOfCharacters - nNumberOfCharacters) << endl;
   cout << "Replace examples a with * " << endl;

   strPartOfTheSentence = strInput.substr(0, 5); // Getting just the first 5 characters (remember you can get anything from any starting postion

   replace(strInput.begin(), strInput.end(), 'a', '*'); // replace all 'a' to '*'
   cout << endl << "Replaced sentence = " << strInput << endl;
   cout << "Replace the sentence using the first word to good " << endl;

   sztPos =strReplacedSentence.find(strFirstWord);
   // Repeat till end is reached
   while (sztPos != std::string::npos)
   {
      // Replace this occurrence of Sub String
      strReplacedSentence.replace(sztPos, strFirstWord.size(), "good");
      // Get the next occurrence from the current position
      sztPos = strReplacedSentence.find(strFirstWord, sztPos + strFirstWord.size());
   }
   
   //while (strReplacedSentence.find(strFirstWord) != string::npos)
   //   strReplacedSentence.replace(strReplacedSentence.find(strFirstWord), strFirstWord.length(), "good");
   cout << endl << "Replaced sentence = " << strReplacedSentence << endl;

   cout << endl << "Partial sentence just 5 characters = " << strPartOfTheSentence << endl;

   return (0);
}