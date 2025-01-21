#ifndef READWRITETOFILE_HPP
#define READWRITETOFILE_HPP

class ReadWriteToFile {
public:
    ReadWriteToFile();
    ~ReadWriteToFile();

    // Saves the state of both pets (hunger, happiness) to "petsData.txt".
    void saveData(int dragonHunger, int dragonHappiness,
                  int phoenixHunger, int phoenixHappiness);

    // Loads the state of both pets from "petsData.txt".
    // Overwrites the provided references with loaded values.
    void loadData(int &dragonHunger, int &dragonHappiness,
                  int &phoenixHunger, int &phoenixHappiness);
};

#endif
