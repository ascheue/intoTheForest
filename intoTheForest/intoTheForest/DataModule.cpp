#include "DataModule.h"
#include <iostream>

// Constructor
DataModule::DataModule() {}

void DataModule::add(const std::string& key, float value) {
    data[key] = value;
}

float DataModule::get(const std::string& key) const {
    auto it = data.find(key);
    if (it != data.end()) {
        return it->second;
    }
    else {
        std::cerr << "Key not found!" << std::endl;
        return -1.0;
    }
}

bool DataModule::remove(const std::string& key) {
    return data.erase(key) > 0;
}

void DataModule::printAll() const {
    for (const auto& pair : data) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}