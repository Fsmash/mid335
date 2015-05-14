/*  CS335 Lab 4, Challenge #2
 *  Bryant Dinh
 *  K&R Indent Style
 *
 *  This program finds all the words in a text string in the input file going forwards and backwards. All words are three 
 *  or more characters long and is within the cracklib-small file.  
 *
 * */


#include <iostream>
#include <string>
#include <fstream>
#define MAX_VALUE 60000

using namespace std;

int numLines = 0;
void printDictSearch(string [60000], string);
void reverseString(string &);

int main()
{
    cout << "CS335 Lab4 Challenge #2\n";

    ifstream dict;
    dict.open("cracklib-small");

    ifstream input;
    input.open("input");

    if (dict.fail() || input.fail()) {
        cout << "Error opening file\n";
        return 1;
    }

    string dictWords[MAX_VALUE];                //string array that holds words on every line of cracklib-small file

    while (getline(dict, dictWords[numLines]))  //get number of lines while inserting each word into array
        ++numLines;
    
    string inputStr;
    input >> inputStr;                      //input string 
    
    cout << "\nForwards\n";
    printDictSearch(dictWords, inputStr);   //prints every word length 3 or more found within input string

    cout << "\nBackwards\n";
    reverseString(inputStr);                //reverses input string
    printDictSearch(dictWords, inputStr);   //prints every word length 3 or more found backwards withing input string

    dict.close();
    input.close();

    return 0;
}

void printDictSearch(string word[60000], string str) 
{

    string sub;         //substring of string str
    int anchor = 0;     //beginning position of substring in string
    int len = 3;        //substring length

    while ((anchor + len) <= str.length()) {    //while substring is still within the string
       
        sub = str.substr(anchor, len);
       
        for (int i = 0; i < numLines; i++) {    
            sub = str.substr(anchor, len);

            if (word[i].find(sub) == 0) {       //substring found at beginning of cracklib-small word

                if (word[i].compare(sub) == 0) {    //substring is equal to word
                    cout << sub << endl;
                    ++len;
                    continue;
                } else {                            //substring not equal but part of word
                    ++len;
                    continue;
                }
            }
        }
       
        ++anchor;                                   //not a word so increment substring position and reset substring leng
        len = 3;
    
    }
}

void reverseString(string &revStr) 
{
    
    int end = revStr.length() - 1;
    
    for(int i = 0; i < end; i++, end--) {

        char tmp = revStr[i];
        revStr[i] = revStr[end];
        revStr[end] = tmp;
    
    }
}

