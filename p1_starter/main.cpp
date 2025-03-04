/*
CSE 310 Hash Function DIY Contest
Instructor: Yezhou Yang
Your name(s): Shashwat Raj, Ara 
Your team alias: 
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }

    HashTable ht(k);

    // Insert all tokens into the hash table.
    for (int i = 0; i < n; i++) {
        ht.insert(texts[i]);
    }


    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now

    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    int limit = (k < 5) ? k : 5;
    for (int i = 0; i < limit; i++) {
        cout << "Slot " << (i + 1) << ":";
        vector<string> slotData = ht.getSlot(i);
        for (const auto &s : slotData) {
            cout << " " << s;
        }
        cout << endl;
    }


    cout << "==== Printing the slot lengths ====" << endl;
    for (int i = 0; i < limit; i++) {
        cout << "Slot " << (i + 1) << ": " << ht.getSlotLength(i) << endl;
    }

    // Print the population standard deviation of slot sizes.
    cout << "\n==== Printing the standard deviation =====" << endl;
    double stdev = ht.getStandardDeviation();
    cout << fixed << setprecision(4) << stdev << endl;


    cout << "==== Printing the standard variance =====" << endl;
    double variance = stdev * stdev;
    cout << fixed << setprecision(4) << variance << endl;

    return 0;
}