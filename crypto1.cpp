/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
#include <limits.h>
#include<math.h>
int binarySearch(int a[], int l, int r, int target){
    if(l > r) return -1;
    int middle = l + (r - l)/2;
    if(a[middle] == target) return middle;
    else if (a[middle] > target) return binarySearch(a, l, r - 1, target);
    else return binarySearch(a, l + 1, r, target);
}


void playFair(){
    int selectMenu = 0;
    std::cout << "Welcome to the Playfair encryption! What do you like to use our service" << std::endl;
    std::cout << "1. Encryption" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << "Enter your service number:";
    std::cin >> selectMenu;
    if(selectMenu != 1 && selectMenu != 3) {
        std::cout << "Please re-enter your service";
        std::cin >> selectMenu;
    }
    if(selectMenu != 2) {
        int check[26];
        for(int i = 0 ; i < 26 ; i++) check[i] = -1;
        std::string key;
        std::string cypherText;
        std::cout << "Enter your key: ";
        std::cin.ignore();
        getline(std::cin, key);
        int count = 0;
        for(int i = 0 ; i < key.size() ; i++) {
            if(key[i] >= 'a' && key[i] <= 'z') key[i] -= 32;
            if(check[i] == 'J') check[i] == 'I';
            if(check[key[i]-'A'] == -1) {
                check[key[i] - 'A'] = count;
                count ++;
            }
        }
        for(int i = 0 ; i < 26 ; i++) {
            if(check[i] == -1 && i != 'J' - 'A') {
                check[i] = count;
                count ++;
            }
        }
        check['J' - 'A'] = check['I' - 'A'];
        for(int i = 0 ; i < 26 ; i++) std::cout << check[i] << " ";
        std::cout << "Enter your plain text: ";
        std::string plainText;
        getline(std::cin, plainText);
        char firstLetter = '0';
        char secondLetter = '0';
        for(int i = 0 ; i < plainText.size() ; i++) std::cout << plainText[i];
        std::cout << std::endl;
        for(int i = 0 ; i < plainText.size(); i++){
            if(plainText[i] >= 'a' && plainText[i] <= 'z') plainText[i] -= 32;
            if(plainText[i] >= 'A' && plainText[i] <= 'Z') {
                if(firstLetter == '0') firstLetter = plainText[i];
                else {
                    secondLetter = plainText[i];
                    std::cout << firstLetter << " " << secondLetter << std::endl;
                    if(firstLetter == secondLetter) {
                        cypherText += firstLetter;
                        cypherText += 'X';
                    }
                    else {
                    int index1 = check[firstLetter - 'A'];
                int index2 = check[secondLetter - 'A'];
                std::cout << index1 << " " << index2 << std::endl;
                if(index1 / 5 == index2 / 5){
                    if(index1 % 5 == 4) {
                        index1 -= 4;
                        index2 += 1;
                    }
                    else if(index2 % 5 == 4){
                        index2 -= 4;
                        index1 += 1;
                    }
                    else {
                        index1 += 1;
                        index2 += 1;
                    }
                }
                else if(index1 % 5 == index2 % 5){
                    if(index1 / 5 == 4) {
                        index1 -= 20;
                        index2 += 5;
                    }
                    else if(index2 / 5 == 4){
                        index2 -= 20;
                        index1 += 5;
                    }
                    else {
                        index1 += 5;
                        index2 += 5;
                    }
                }
                else {
                    int diff = index1 % 5 - index2 % 5;
                    index1 -= diff;
                    index2 += diff;
                }
                std::cout << "New index: " << index1 << " " << index2 << std::endl;
                for(int i = 0 ; i < 26 ; i++) if(index1 == check[i]) cypherText += i + 'A';
                for(int i = 0 ; i < 26 ; i++) if(index2 == check[i]) cypherText += i + 'A';
                    }
                    
                    firstLetter = '0';
                    secondLetter = '0';
                }
            }


            
        }
        std::cout << "So your cypherText is :" << cypherText << std::endl;
    }
}

void affine(){
    int selectMenu = 0;
    std::cout << "Welcome to the Affine encryption! What do you like to use our service" << std::endl;
    std::cout << "1. Encryption" << std::endl;
    std::cout << "2. Decryption" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your service number:";
    std::cin >> selectMenu;
    if(selectMenu != 1 && selectMenu != 2 && selectMenu != 3) {
        std::cout << "Please re-enter your service";
        std::cin >> selectMenu;
    }
    if(selectMenu != 3) {
        int a_num;
        int b_num;
        int a[12] = {1,3,5,7,9,11,15,17,19,21,23,25};
        int aMinus[12] = {1,9,21,15,3,19,7,23,11,5,17,25};
        std::cout<< "Enter your number a (a must be a number included in this array: 1,3,5,7,9,11,15,17,19,21,23,25):";
        std::cin >> a_num;
        int a_index = binarySearch(a, 0, 11, a_num);
        while(a_index == -1){
            std::cout << "Please re-enter your number a (a must be a number included in this array: 1,3,5,7,9,11,15,17,19,21,23,25): ";
            std::cin >> a_num;
            a_index = binarySearch(a, 0, 11, a_num);
        }
        std::cout << a_index << " " << aMinus[a_index] << std::endl;
        std::cout<< "Enter your number b (b must be between 0 and 25):";
        std::cin >> b_num;
        while(b_num < 0 || b_num > 25) {
            std::cout << "Please re-enter your number b (b must be between 0 and 25): ";
            std::cin >> b_num;
        }
        if(selectMenu == 1){
            std::string plainText;
            std::cout << "Please enter the message you want to encode:";
            std::cin.ignore();
            getline(std::cin, plainText);
            for(int i = 0 ; i < plainText.size(); i++){
                if(plainText[i] >= 'A' && plainText[i] <= 'Z'){
                    plainText[i] = (a_num * (plainText[i] - 'A') + b_num) % 26 + 'A';
                }
                else if(plainText[i] >= 'a' && plainText[i] <= 'z'){
                    plainText[i] = (a_num * (plainText[i] - 'a') + b_num) % 26 + 'a';
                }
            }
            std::cout << "The encryption of your message is:" << plainText << std::endl;
        }
        else if (selectMenu == 2){
            std::string cypherText;
            std::cout << "Please enter the message you want to decode:";
            std::cin.ignore();
            getline(std::cin, cypherText);
            for(int i = 0 ; i < cypherText.size() ; i++){
                if(cypherText[i] >= 'A' && cypherText[i] <= 'Z'){
                    cypherText[i] = (26 + (aMinus[a_index]*(cypherText[i] - 'A' - b_num))%26)%26 + 'A';
                }
                else if(cypherText[i] >= 'a' && cypherText[i] <= 'z'){
                    cypherText[i] = (26 + (aMinus[a_index]*(cypherText[i] - 'a' - b_num))%26)%26 + 'a';
                }
            }
            std::cout << "The decryption of your message is:" << cypherText << std::endl;
        }
    }
}

void display(){
    std::cout << "Welcome to the cryptography classes!" << std::endl;
    std::cout << "Here we introduce you two ways to encrypt a message" << std::endl;
    std::cout << "1. Playfair encryption" << std::endl;
    std::cout << "2. Affine encryption" << std::endl;
    std::cout << "3. Exit application" << std::endl;
    std::cout << "Enter your selection:" << std::endl;
}

int main()
{
    int selection = 0;
    do {
        display();
        std::cin >> selection;
        while(selection != 1 && selection != 2 && selection != 3){
            std::cout << "Please re-enter your selection from 1 to 3:";
            std::cin >> selection;
        }
        if(selection == 1){
            playFair();
        }
        else if (selection == 2){
            affine();
        }
    } while(selection != 3) ;
    return 0;

}