#ifndef CLASS2_HPP_INCLUDED
#define CLASS2_HPP_INCLUDED
#include "Class.hpp"

class decrypter: public encrypter{
public:
//Retrieves key and decrypts encrypted files
    void decypher(){
        //open files
        std::ifstream theKey("keycode.txt");
        std::ifstream theMess("encryptedFile.txt");

        if (theMess.is_open() && theKey.is_open()){
            //reads lines char by char and converts the key to an int
            while(!theMess.eof()){
                theKey.get(keyChar);
                theMess.get(jumChar);
                keyInt= keyChar- '0';
                //std::cerr<< keyInt<< std::endl;

                // uses the info above to navigate the alphArr and decode the message
                for(signed int j= 0; j< alphArrSize; ++j){
                    if(jumChar== alphArr[j]){
                        int temp= (j- keyInt)% alphArrSize;
                        if(temp< 0){
                            temp+= alphArrSize;
                        }
                        actualChar= alphArr[temp];
                        message+= actualChar;
                        std::cerr<< temp << "\n";
                        }
                    }
                }
        message[message.length()- 1]= ' ';
        std::cout<< "\nexporting File...\n";
        std::ofstream defile;
        defile.open ("decryptedFile.txt");
        defile<< message;
        std::cout<< "File decrypted!\n";
        defile.close();
        }else std::cout << "ERROR: missing one or more files!";
    }
private:
    char jumChar;
    char keyChar;
    char actualChar;
    signed int keyInt;
    std::string message;
protected:

};


#endif // CLASS2_HPP_INCLUDED
