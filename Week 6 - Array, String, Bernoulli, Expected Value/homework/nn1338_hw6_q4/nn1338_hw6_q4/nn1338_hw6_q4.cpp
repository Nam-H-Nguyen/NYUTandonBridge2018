//
//  nn1338_hw6_q4.cpp
//  nn1338_hw6_q4
//
//  Created by NomNomNam on 5/24/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Traditional password entry schemes are susceptible to "shoulder surfing" in which an attacker
 watches an unsuspecting user enter their password or PIN number and uses it later to gain
 access to the account. One way to combat this problem is with a randomized challenge-
 response system. In these systems the user enters different information every time, based on a
 secret in response to a randomly generated challenge.
 Consider the following scheme, in which the password consists of a five-digit PIN number (00000
 to 99999). Each digit is assigned a random number that is 1, 2, or 3. The user enters the random
 numbers that correspond to their PIN instead of their actual PIN numbers.
 
 For example, consider an actual PIN number of 12345. To authenticate the user would be
 presented with a screen such as:
 PIN: 0 1 2 3 4 5 6 7 8 9
 NUM: 3 2 3 1 1 3 2 2 1 3
 The user would enter 23113 instead of 12345. This doesn’t divulge the password even if an
 attacker intercepts the entry because 23113 could correspond to other PIN numbers, such as
 69440 or 70439.
 The next time the user logs in, a different sequence of random numbers would be generated,
 such as:
 PIN: 0 1 2 3 4 5 6 7 8 9
 NUM: 1 1 2 3 1 2 2 3 3 3
 
 Write a program to simulate the authentication process. Store an actual 5-digit PIN number in
 your program (make one up, and store it as a constant). The program should use an array to
 assign random numbers to the digits from 0 to 9. Output the random digits to the screen, input
 the response from the user, and output whether or not the user’s response correctly matches
 the PIN number.
 
 Assuming that the actual PIN number is 12345, your program should interact with the user
 exactly as it shows in the following examples (2 different executions of the program):
 Please enter your PIN according to the following mapping:
 PIN: 0 1 2 3 4 5 6 7 8 9
 NUM: 3 2 3 1 1 3 2 2 1 3
 23113
 Your PIN is correct
 
 Please enter your PIN according to the following mapping:
 PIN: 0 1 2 3 4 5 6 7 8 9
 NUM: 1 1 2 3 1 2 2 3 3 3
 23113
 Your PIN is not correct
 
 Note: Think how to break down your implementation to functions.
 
 */

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

// Store user's actual pin in a constant variable array
const int ACTUAL_PIN_NUM[5] = {1, 2, 3, 4, 5};

int main() {

    srand(time(0)); // Seed random num

    string user_entered_PIN; // Store user's input of 5 digit passcode
    
    // Print an ordered element for Pin Array
    int pinArrSize = 10;
    int pinArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    cout<<"PIN:\t";
    for (int i = 0; i < pinArrSize; i++) {
        cout<<pinArr[i]<<" ";
    }
    
    cout<<endl;
    
    int rand_array[10];
    
    // Store randomized numbers in each element in the random array variable
    for(int i = 0; i < 10; i++) {
        rand_array[i] = rand() % 3 + 1;
    }

    // Print the randomized array to prevent shoulder surfing
    cout<<"NUM:\t";
    for (int i=0; i<10; i++)
        cout << rand_array[i] << " ";
    
    cout <<endl;
    
    cout<<"Enter your 5 digit passcode: \n";
    cin>>user_entered_PIN;
    
    // Initialize the bool variable
    bool is_PIN_Matched = true;
    
    // Iterate through the user's input
    for (int i = 0; i < user_entered_PIN.length(); i++) {
        // Delete elements in the array with trailing and leading 0's
        // Compare the user input elements to the randomized array but with the values of
        // actual pin number
        if( (user_entered_PIN[i] - '0') != rand_array[ACTUAL_PIN_NUM[i]])
            is_PIN_Matched = false;
    }
    
    
    if (is_PIN_Matched == true)
        cout<<"Your PIN is correct"<<endl;
    else
        cout<<"Your PIN is not correct"<<endl;
    
    return 0;
}
