#include "ReadWriteToFile.hpp"
#include <fstream>

ReadWriteToFile::ReadWriteToFile() {}
ReadWriteToFile::~ReadWriteToFile() {}

void ReadWriteToFile::saveData(int dragonHunger, int dragonHappiness,
                               int phoenixHunger, int phoenixHappiness) {
    std::ofstream out("petsData.txt");
    if (out) {
        // Write each pet's hunger and happiness on separate lines
        out << dragonHunger << " " << dragonHappiness << "\n";
        out << phoenixHunger << " " << phoenixHappiness << "\n";
    }
    out.close();
}

void ReadWriteToFile::loadData(int &dragonHunger, int &dragonHappiness,
                               int &phoenixHunger, int &phoenixHappiness) {
    std::ifstream in("petsData.txt");
    if (in) {
        // Read lines (dragon first, phoenix second)
        in >> dragonHunger >> dragonHappiness;
        in >> phoenixHunger >> phoenixHappiness;
    }
    in.close();
}
