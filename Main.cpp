#include <iostream>
#include "MagicalPet.hpp"
#include "MagicalException.hpp"
#include "DragonGotchi.hpp"
#include "PhoenixGotchi.hpp"
#include "ReadWriteToFile.hpp"

int main() {
    // Create your pets
    MagicalPet* pets[2];
    pets[0] = new DragonGotchi();
    pets[1] = new PhoenixGotchi();

    bool running = true;
    while (running) {
        std::cout << "\n=== Mythical Tamagotchi Menu ===\n";
        std::cout << "1. Feed a pet\n";
        std::cout << "2. Play with a pet\n";
        std::cout << "3. Heal a pet\n";
        std::cout << "4. Train a pet\n";
        std::cout << "5. Show status of all pets\n";
        std::cout << "6. Save data to file\n";
        std::cout << "7. Load data from file\n";
        std::cout << "8. Quit\n";
        std::cout << "Choice: ";

        int choice = 0;
        std::cin >> choice;

        try {
            if (choice == 1) {
                // 1. FEED
                std::cout << "Which pet? (0 for Dragon, 1 for Phoenix): ";
                int idx = 0;
                std::cin >> idx;
                if (idx < 0 || idx > 1) {
                    std::cout << "Invalid pet index!\n";
                } else {
                    std::cout << "Enter feed amount: ";
                    int amount = 0;
                    std::cin >> amount;
                    pets[idx]->feed(amount);
                }
            }
            else if (choice == 2) {
                // 2. PLAY
                std::cout << "Which pet? (0 for Dragon, 1 for Phoenix): ";
                int idx = 0;
                std::cin >> idx;
                if (idx < 0 || idx > 1) {
                    std::cout << "Invalid pet index!\n";
                } else {
                    pets[idx]->play();
                }
            }
            else if (choice == 3) {
                // 3. HEAL
                std::cout << "Which pet? (0 for Dragon, 1 for Phoenix): ";
                int idx = 0;
                std::cin >> idx;
                if (idx < 0 || idx > 1) {
                    std::cout << "Invalid pet index!\n";
                } else {
                    pets[idx]->heal();
                }
            }
            else if (choice == 4) {
                // 4. TRAIN
                std::cout << "Which pet? (0 for Dragon, 1 for Phoenix): ";
                int idx = 0;
                std::cin >> idx;
                if (idx < 0 || idx > 1) {
                    std::cout << "Invalid pet index!\n";
                } else {
                    pets[idx]->train();
                }
            }
            else if (choice == 5) {
                // 5. SHOW STATUS
                pets[0]->showStatus();
                pets[1]->showStatus();
            }
            else if (choice == 6) {
                // 6. SAVE
                int dHun = 0, dHap = 0;
                int pHun = 0, pHap = 0;

                // Example: dynamic_cast or public getters
                DragonGotchi* dg = dynamic_cast<DragonGotchi*>(pets[0]);
                PhoenixGotchi* ph = dynamic_cast<PhoenixGotchi*>(pets[1]);

                // Retrieve current data (assuming you have getters)
                if (dg) {
                    dHun = dg->getHunger();
                    dHap = dg->getHappiness();
                }
                if (ph) {
                    pHun = ph->getHunger();
                    pHap = ph->getHappiness();
                }

                ReadWriteToFile rw;
                rw.saveData(dHun, dHap, pHun, pHap);
                std::cout << "Data saved to petsData.txt\n";
            }
            else if (choice == 7) {
                // 7. LOAD
                int dHun = 0, dHap = 0;
                int pHun = 0, pHap = 0;

                ReadWriteToFile rw;
                rw.loadData(dHun, dHap, pHun, pHap);

                // Now apply the loaded data
                DragonGotchi* dg = dynamic_cast<DragonGotchi*>(pets[0]);
                PhoenixGotchi* ph = dynamic_cast<PhoenixGotchi*>(pets[1]);

                if (dg) {
                    dg->setHunger(dHun);
                    dg->setHappiness(dHap);
                }
                if (ph) {
                    ph->setHunger(pHun);
                    ph->setHappiness(pHap);
                }

                std::cout << "Data loaded from petsData.txt\n";
            }
            else if (choice == 8) {
                // 8. QUIT
                running = false;
            }
            else {
                std::cout << "Invalid choice!\n";
            }
        }
        catch (MagicalException &e) {
            std::cout << e.what() << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Standard exception: " << e.what() << std::endl;
        }
        catch (...) {
            std::cout << "Unknown error occurred." << std::endl;
        }
    }

    // Cleanup
    delete pets[0];
    delete pets[1];
    return 0;
}






