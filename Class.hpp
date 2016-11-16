#ifndef CLASS_HPP_INCLUDED
#define CLASS_HPP_INCLUDED


#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <cmath>

const int alphArrSize= 91;

class encrypter{
public:
//Generates key file
    void keyGen(){
        int genNum;
        std::ofstream key;
        key.open("keycode.txt");
        srand(time(NULL));
        for(signed int x= 0; x<= userInput.length(); x++){
            genNum= (rand()% 10);
            keyCode= genNum;
            key<< keyCode;
        }
        std::cerr<< "...Key file generated!\n";
        key.close();
    }

//Converts user text into an encrypted file.
    void txtGen(){
        std::string jumbled;
        std::ifstream key("keycode.txt");
        for(signed int i = 0; i<userInput.length(); i++){
                char origChar= userInput[i];
                char keyNum;
                key.get(keyNum);
            for(signed int j = 0; j<alphArrSize; ++j){
                if(origChar== alphArr[j]){
                    signed int intKeyNum= keyNum- '0';
                    jumbled+= alphArr[(j+ intKeyNum)% alphArrSize];
                    //debug out
                }
            }

        std::ofstream enfile;
        enfile.open ("encryptedFile.txt");
        enfile << jumbled;
        enfile.close();
        }
        std::cout<< "...Encrypted file generated!\n";
    }

//Getter function for user input
    std::string inputUsrData(std::string in){
        return userInput= in;
        std::cout<< userInput << " and "<< in;
    }
private:
    signed int keyCode;     //Used to store RNG key
    char realLetter;        //Used to store actual chars

    std::string userFileInput= "default.txt";  //useless until I find a way to accept user input with file selection
    std::string fileText;                  //Stores the entirety of files contents
    char fileLetter;                  //Stores one character from a file to place in fileText

protected:
    std::string userInput;

    char alphArr[alphArrSize]=
    {' ', 'a', 'A',  'b', 'B', 'c', 'C', 'd', 'D', 'e',             //10
     'E', 'f', 'F',  'g', 'G', 'h', 'H', 'i', 'I', 'j',             //20
     'J', 'k', 'K',  'l', 'L', 'm', 'M', 'n', 'N', 'o',             //30
     'O', 'p', 'P',  'q', 'Q', 'r', 'R', 's', 'S', 't',             //40
     'T', 'u', 'U',  'v', 'V', 'w', 'W', 'x', 'X', 'y',             //50
     'Y', 'z', 'Z',  '0', '1', '2', '3', '4', '5', '6',             //60
     '7', '8', '9', '!', '@', '#', '$', '%', '^', '&',              //70
     '*', '(', ')', '[', ']', '{', '}', ':', ';','\?',	            //80
     '\"', '.', ':', '\'', ',','\n', '<', '>', '~', '\\', '/'};     //91
};


#endif // CLASS_HPP_INCLUDED
