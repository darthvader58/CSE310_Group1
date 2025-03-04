/*
CSE 310 Hash Function DIY Contest
Instructor: Yezhou Yang
Your name(s): Shashwat Raj, Ara 
Your team alias: 2^0
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("p1_starter/inputs/bertuncased.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k = 0;      // Number of slots.
    int n = 0;      // Number of tokens.
    std::string texts[500];

    // Read number of slots.
    cin >> k;
    std::string line;
    getline(cin, line); // consume the remainder of the line

    // Read each token (one per line).
    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }

    // Create a HashTable with k slots.
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
        // Traverse the linked list for this slot.
        HashTable::Node* current = ht.getSlot(i);
        while (current != 0) {
            cout << " " << current->token;
            current = current->next;
        }
        cout << endl;
    }

    // Print the slot lengths.
    cout << "\n==== Printing the slot lengths ====" << endl;
    for (int i = 0; i < limit; i++) {
        cout << "Slot " << (i + 1) << ": " << ht.getSlotLength(i) << endl;
    }

    // Print the population standard deviation of slot sizes.
    cout << "\n==== Printing the standard deviation =====" << endl;
    cout << fixed << setprecision(4) << ht.getStandardDeviation() << endl;

    cout << "\n==== Printing the standard variance =====" << endl;
    cout << fixed << setprecision(4) << (ht.getStandardDeviation()*ht.getStandardDeviation()) << endl;

    return 0;
}