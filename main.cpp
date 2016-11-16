#include "Class.hpp"
#include "Class2.hpp"
#include "Class3.hpp"

int main(int argc, const char * argv[]){
    signed int choice= 3;
    encrypter myFile;
    decrypter myCypher;
	std::string tempInput= " ";
	std::string totalInput;

        while(choice!= 0){
            std::cout<< "Welcome to Be Cryptic, the command line encryption software!\n";
            std::cout<< "What would you like to do?\n   1= encrypt\n   2= decrypt\n   0= Exit\n";
            std::cin>> choice;
        if(choice== 1){
            std::cout<< "Please input text to be encrypted\n";
            std::cout<< "enter an empty line to finish:\n";
            std::cin.ignore();
            //std::getline(std::cin, tempInput);
            ////////////////////////////////////
            while(tempInput.length()!= 0){
                tempInput= "";
                getline(std::cin, tempInput);
                totalInput= totalInput + ' ' + tempInput;
            }
            ////////////////////////////////////
            myFile.inputUsrData(totalInput);
            myFile.keyGen();
            myFile.txtGen();
        }
        if(choice== 2){
            myCypher.decypher();
        }
    }
return 0;
}
