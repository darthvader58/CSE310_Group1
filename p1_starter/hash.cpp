#include <iostream>
#include <string>
#include <functional>
#include <cmath>
#include "hash.h"

using namespace std;

int computeSlot(const std::string &s, int k) {
    static std::hash<std::string> hasher;
    return static_cast<int>(hasher(s) % k);
    }

HashTable::~HashTable() {}

HashTable::HashTable(int k)
    : table(k){}
    
void HashTable::insert(const std::string &token) {
    if (table.empty()) return;  // if k==0
    int slotIndex = computeSlot(token, getNumSlots());
    table[slotIndex].push_back(token);
}

std::vector<std::string> HashTable::getSlot(int index) const {
    if (index >= 0 && index < getNumSlots()) {
        return table[index];
    } else{
        return {};
    }
}


int HashTable::getSlotLength(int index) const {
    if (index >= 0 && index < getNumSlots()) {
        return static_cast<int>(table[index].size());
    }
    return 0;
}

int HashTable::getNumSlots() const {
    return static_cast<int>(table.size());
}

double HashTable::getStandardDeviation() const {
    int k = getNumSlots();
    if (k == 0) return 0.0;
    double mean = 0.0;
    for (int i = 0; i < k; i++) {
        mean += table[i].size();
    }   
    mean /= k;
    double variance = 0.0;

    
    for (const auto &slot : table) {
        double diff = slot.size() - mean;
        variance += (diff * diff)/k;
    }

}

int hash_function(string text) {
    // Implement your own hash function here
    return 1;
}