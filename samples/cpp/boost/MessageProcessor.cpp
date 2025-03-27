#include "MessageProcessor.h"

std::string MessageProcessor::process(const std::string& input) {
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    auto now_tm = *std::localtime(&now_time_t);
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%H:%M:%S");
    std::string timestamp = oss.str();
    return "You said@" + timestamp + ":" + input;
}
