#pragma once

#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <unordered_map>
using std::unordered_map;
using std::string;

class MessageProcessor {
    private:
    unordered_map<string, string> map;
    private:
    void updateMap();
    public:
    MessageProcessor();
public:
    std::string process(const std::string& input);
    std::string trimWhitespace(const std::string& input);
};
