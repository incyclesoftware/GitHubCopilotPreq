#include "MessageProcessor.h"
#include <algorithm>

MessageProcessor::MessageProcessor() {
    updateMap();
}

void MessageProcessor::updateMap() {
    map["hello"] = "hello world!";
}

std::string MessageProcessor::trimWhitespace(const std::string& input) {
    std::string trimmed = input;
    trimmed.erase(trimmed.begin(), std::find_if(trimmed.begin(), trimmed.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    trimmed.erase(std::find_if(trimmed.rbegin(), trimmed.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), trimmed.end());
    return trimmed;
}

std::string MessageProcessor::process(const std::string& input) {
    std::string trimmedInput = trimWhitespace(input);
    
    if (map.find(trimmedInput) != map.end()) {
        return map[input]+"\r\n> ";
    }
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    auto now_tm = *std::localtime(&now_time_t);
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%H:%M:%S");
    std::string timestamp = oss.str();
    return "You said@" + timestamp + ":" + trimmedInput+"\r\n> ";
}
