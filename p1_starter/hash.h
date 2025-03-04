#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

int hashFunction(const std::string &s, int k);

class HashTable {
public:
    HashTable(int k);
    ~HashTable();
    void insert(const std::string &s);
    std::vector<std::string> getSlot(int index) const;
    int getSlotLength(int i) const;
    int getNumSlots() const;
    double getStandardDeviation() const;
    void printFirstFiveSlots() const;

 private:
    std::vector<std::vector<std::string>> table;
};

#endif