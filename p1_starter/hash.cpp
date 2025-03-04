#include <iostream>
#include <string>
#include <cmath>
#include "hash.h"
#include <cstdlib>

using namespace std;

//This HashFunction is a spinoff of the FNV-1a hash function by bit rotation.
int hashFunction(const std::string &s, int k) {
    const unsigned int FNV_offset_basis = 2166136261u;
    const unsigned int FNV_prime = 16777619u;
    unsigned int hash = FNV_offset_basis;
    
    // Process each byte of the input string.
    for (unsigned int i = 0; i < s.size(); i++) {
        hash ^= static_cast<unsigned char>(s[i]);
        hash *= FNV_prime;
        // Bit rotation by 7
        hash = (hash << 7) | (hash >> (32 - 7));
    }
    
    hash ^= hash >> 16; //shifted right by 16 bits
    hash *= FNV_prime; //hash multiplied by the prime number
    hash ^= hash >> 15; //shifted right by 15 bits
    
    return static_cast<int>(hash % k);
}

//Constructor
HashTable::HashTable(int k) : numSlots(k) {
    table = new Node*[numSlots];
    for (int i = 0; i < numSlots; i++) {
        table[i] = NULL;
    }
}

//Destructor
HashTable::~HashTable() {
    for (int i = 0; i < numSlots; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}

//Inserts a token into the hash table
void HashTable::insert(const std::string &token) {
    if (numSlots <= 0) return;
    int index = hashFunction(token, numSlots);
    
    Node* newNode = new Node;
    newNode->token = token;
    newNode->next = table[index];
    table[index] = newNode;
}


HashTable::Node* HashTable::getSlot(int index) const {
    if (index < 0 || index >= numSlots) {
        return NULL;
    }
    return table[index];
}


int HashTable::getSlotLength(int index) const {
    if (index < 0 || index >= numSlots) {
        return 0;
    }
    int count = 0;
    Node* current = table[index];
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int HashTable::getNumSlots(int index) const {
    return numSlots;
}

double HashTable::getStandardDeviation() const {
    if (numSlots <= 0) return 0.0;
    
    double total = 0.0;
    for (int i = 0; i < numSlots; i++) {
        total += getSlotLength(i);
    }
    double mean = total / numSlots;
    
    double variance = 0.0;
    for (int i = 0; i < numSlots; i++) {
        double diff = getSlotLength(i) - mean;
        variance += (diff * diff)/numSlots;
    }
    return std::sqrt(variance);
}


