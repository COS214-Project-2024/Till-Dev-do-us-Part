#include "display.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#ifdef _WIN32
    #include <cstdlib>
#endif

// ANSI Color codes definitions
const std::string RESET = "\033[0m";
const std::string BLUE = "\033[38;5;27m";
const std::string PURPLE = "\033[38;5;93m";
const std::string PINK = "\033[38;5;218m";
const std::string CYAN = "\033[38;5;51m";
const std::string DEEP_BLUE = "\033[38;5;25m";
const std::string LIGHT_PURPLE = "\033[38;5;147m";
const std::string BOLD = "\033[1m";
const std::string GREEN = "\033[38;5;46m";
const std::string WATER_BLUE = "\033[38;5;39m";

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void sleep(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void animateText(const std::string& text, int delay) {
    for(char c : text) {
        std::cout << c << std::flush;
        sleep(delay);
    }
    std::cout << std::endl;
}

void displayLoadingBar() {
    std::cout << CYAN << "\n Initializing Our City Systems: ";
    for(int i = 0; i < 20; i++) {
        std::cout << "█" << std::flush;
        sleep(100);
    }
    std::cout << " Complete!" << RESET << std::endl;
    sleep(500);
}

void displayIntro() {
    clearScreen();
    
    sleep(500);

    // Updated Title for INGELAND CITY SIM all in purple
    std::string title = PURPLE + R"(                  
                        ██╗███╗   ██╗ ██████╗ ███████╗██╗      █████╗ ███╗   ██╗██████╗     ██████╗██╗████████╗██╗   ██╗    ███████╗██╗███╗   ███╗
                        ██║████╗  ██║██╔════╝ ██╔════╝██║     ██╔══██╗████╗  ██║██╔══██╗    ██╔════╝██║╚══██╔══╝╚██╗ ██╔╝    ██╔════╝██║████╗ ████║
                        ██║██╔██╗ ██║██║  ███╗█████╗  ██║     ███████║██╔██╗ ██║██║  ██║    ██║     ██║   ██║    ╚████╔╝     ███████╗██║██╔████╔██║)"+ PINK + R"(
                        ██║██║╚██╗██║██║   ██║██╔══╝  ██║     ██╔══██║██║╚██╗██║██║  ██║    ██║     ██║   ██║     ╚██╔╝      ╚════██║██║██║╚██╔╝██║
                        ██║██║ ╚████║╚██████╔╝███████╗███████╗██║  ██║██║ ╚████║██████╔╝    ╚██████╗██║   ██║      ██║       ███████║██║██║ ╚═╝ ██║
                        ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝      ╚═════╝╚═╝   ╚═╝      ╚═╝       ╚══════╝╚═╝╚═╝     ╚═╝)" + RESET;

    animateText(title, 5);

    // Welcome message after title
    std::string welcome = BOLD + WATER_BLUE + R"(
                                                    ╔═══════════════════════════════════════════════════════════╗
                                                    ║         WELCOME TO THE GREATEST CITY IN 214               ║
                                                    ╚═══════════════════════════════════════════════════════════╝)" + RESET;
    
    animateText(welcome, 5);
    sleep(300);

    // Enhanced cityscape with river and more detailed buildings
  std::cout << PURPLE + R"(
                                                                              ⭐
                                                                   /\        |═══|      /\
                                                                  /──\    .__|   |___. /──\
                                                         /│\     /    \   │ ___ │    |/    \     /│\
                                                        /│█│\   /      \  │|   |│    /      \   /│█│\
                                                       /│███│\ ╱  ╔══╗  ╲ │|   |│   ╱  ╔══╗  ╲ /│███│\
                                                  _____ ║║█║║ │   ║██║   │ │|   |│ │   ║██║   │ ║║█║║ _____
                                                  ║███║ ║║█║║ │   ║██║   │▓│|   |│▓│   ║██║   │ ║║█║║ ║███║
                                                  ║███║ ║║█║║ │   ║██║   │▓│|   |│▓│   ║██║   │ ║║█║║ ║███║
                                                  ║███║_║║█║║_│   ║██║   │▓│|   |│▓│   ║██║   │ ║║█║║_║███║)" + WATER_BLUE + R"(
                                                ▓▓░░▒▒████████████████████████████████████████████████▒▒░░▓▓
                                                ░░▒▒▓▓≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈▓▓▒▒░░
                                                ▒▒▓▓░░~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~▓▓▒▒░░
                                                ▓▓░░▒▒≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈░░▒▒▓▓
                                                                                                            )" + RESET + "\n";
    
    sleep(1000);
    displayLoadingBar();
}