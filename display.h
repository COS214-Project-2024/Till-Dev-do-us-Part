// display.h
#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

// ANSI Color codes declarations
extern const std::string RESET;
extern const std::string BLUE;
extern const std::string PURPLE;
extern const std::string CYAN;
extern const std::string DEEP_BLUE;
extern const std::string LIGHT_PURPLE;
extern const std::string BOLD;
extern const std::string GREEN;
extern const std::string WATER_BLUE;

// Function declarations
void clearScreen();
void sleep(int milliseconds);
void animateText(const std::string& text, int delay = 50);
void displayLoadingBar();
void displayIntro();

#endif