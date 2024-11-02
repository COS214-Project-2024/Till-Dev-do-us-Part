#include "ModeFactory.h"

// ModeFactory::~ModeFactory() {
//     for (auto mode : modes) {
//         delete mode;
//     }
//     modes.clear();
// }

// void ModeFactory::removeMode(TransportMode* mode) {
//     auto it = std::find(modes.begin(), modes.end(), mode);
//     if (it != modes.end()) {
//         delete *it;
//         modes.erase(it);
//     }
// }