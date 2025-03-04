#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.
#ifndef HASH_H
#define HASH_H

#include <string>

class HashTable {
public:
    struct Node {
        std::string token;
        Node* next;
    };

    explicit HashTable(int k);
    ~HashTable();
    void insert(const std::string &token);
    Node* getSlot(int index) const;
    int getSlotLength(int index) const;
    int getNumSlots(int index) const;
    double getStandardDeviation() const;

private:
    int numSlots;
    
    Node** table;
};

int hashFunction(const std::string &s, int k);

#endif