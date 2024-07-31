#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>

void signalHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received." << std::endl;
    std::cout << "Signal ignored :) " << std::endl;
    // exit(signum);
}

int main() {
    std::signal(SIGINT, signalHandler);
    std::cout << "Sleeping for 3 seconds..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Awake now!" << std::endl;
    std::cout << std::chrono::steady_clock::now().time_since_epoch().count() << std::endl;
}
