#ifndef DATAMODULE_H
#define DATAMODULE_H

#include <unordered_map>
#include <string>

class DataModule {
private:
    std::unordered_map<std::string, float> data;

public:
    DataModule(); // Constructor

    void add(const std::string& key, float value); // Add or update a key-value pair

    float get(const std::string& key) const; // Retrieve the value associated with a key

    bool remove(const std::string& key); // Remove a key-value pair

    void printAll() const; // Print all key-value pairs
};

#endif //DATAMODULE_H