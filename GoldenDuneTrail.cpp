#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Inventory
class Inventory {
public:
    int food;
    int ammo;
    int clothes;
    int parts;

    Inventory() {
        food = 200;
        ammo = 50;
        clothes = 10;
        parts = 3;
    }

    void show() {
        cout << "\n--- Inventory ---\n";
        cout << "Food: " << food << endl;
        cout << "Ammo: " << ammo << endl;
        cout << "Clothes: " << clothes << endl;
        cout << "Spare Parts: " << parts << endl;
    }
};

// Player
class Player {
public:
    string name;
    string role;
    int health;
    int gold;
    int distance;

    Player() {
        health = 100;
        distance = 500;
        gold = 0;
    }

    void chooseRole() {
        int choice;

        cout << "\nChoose your role:\n";
        cout << "1. Banker (More gold)\n";
        cout << "2. Doctor (Better health)\n";
        cout << "3. Carpenter (Better repairs)\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            role = "Banker";
            gold = 1600;
        }
        else if (choice == 2) {
            role = "Doctor";
            gold = 800;
            health = 120;
        }
        else {
            role = "Carpenter";
            gold = 600;
        }

        cout << "\nYou chose: " << role << endl;
    }

    void showStatus() {
        cout << "\n--- Player Status ---\n";
        cout << "Name: " << name << endl;
        cout << "Role: " << role << endl;
        cout << "Health: " << health << endl;
        cout << "Gold: " << gold << endl;
        cout << "Distance remaining: " << distance << " miles\n";
    }
};

class EventSystem {
public:

    static void randomEvent(Player &player, Inventory &inv) {

        int event = rand() % 4;

        if (event == 0) {
            cout << "\nA sandstorm hits your caravan!\n";
            player.health -= 10;
            cout << "You lost health.\n";
        }

        else if (event == 1) {
            cout << "\nYou found abandoned supplies!\n";
            inv.food += 40;
        }

        else if (event == 2) {
            cout << "\nBandits attacked!\n";
            if (inv.ammo > 0) {
                cout << "You fought them off.\n";
                inv.ammo -= 10;
            } else {
                cout << "You had no ammo. You lost supplies.\n";
                inv.food -= 20;
            }
        }

        else if (event == 3) {
            cout << "\nOne of your wagon wheels broke.\n";
            if (inv.parts > 0) {
                inv.parts--;
                cout << "You repaired it.\n";
            } else {
                cout << "You cannot repair it easily.\n";
                player.health -= 5;
            }
        }
    }
};

// Will come back Item Class later!

// item
// class Item {
// private:
//     string name;
//     int healthBonus;
//     int attackBonus;
//
// public:
//     Item(string tempName, int tempHealthBonus, int tempAttackBonus) {
//         name = tempName;
//         healthBonus = tempHealthBonus;
//         attackBonus = tempAttackBonus;
//     }
//
//     void applyItem(Player& player) {
//         player.gainHealth(healthBonus);
//         player.increaseAttack(attackBonus);
//         cout << "You used " << name << "!" << endl;
//     }
// };

class RiverCrossing {
public:

    static void cross(Player &player, Inventory &inv) {

        int choice;

        cout << "\nYou reached a river crossing.\n";

        cout << "1. Ford the river\n";
        cout << "2. Caulk the wagon\n";
        cout << "3. Pay ferry (50 gold)\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "You attempt to ford the river...\n";

            if (rand() % 2 == 0) {
                cout << "Success!\n";
            } else {
                cout << "You lost some food in the water.\n";
                inv.food -= 30;
            }
        }

        else if (choice == 2) {
            cout << "You seal the wagon and float across.\n";
            inv.parts--;
        }

        else if (choice == 3) {
            if (player.gold >= 50) {
                player.gold -= 50;
                cout << "The ferry safely carries you across.\n";
            } else {
                cout << "Not enough gold.\n";
            }
        }
    }
};
// Will come back to TrailEvent Later !
// // TrailEvent
// class TrailEvent {
// private:
//     string description;
//
// public:
//     TrailEvent(string tempDescription) {
//         description = tempDescription;
//     }
//
//     void displayEvent() {
//         cout << description << endl;
//     }
// };

// Game
class Game {
private:
    Player player;
    Inventory inventory;
    bool running;

public:

    Game() {
        running = true;
    }

    void showHowToPlay() {

        ifstream file("howtoplay.txt");

        if (!file) {
            cout << "Help file not found.\n";
            return;
        }

        string line;

        cout << endl;

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }

    void startJourney() {

        cout << "\nEnter your name: ";
        cin >> player.name;

        player.chooseRole();

        cout << "\nYour journey across the Golden Dunes begins...\n";

        journeyLoop();
    }

    void journeyLoop() {

        while (player.distance > 0 && player.health > 0) {

            int choice;

            cout << "\n==============================\n";
            cout << "Distance remaining: " << player.distance << " miles\n";
            cout << "==============================\n";

            cout << "\nJourney Menu\n";
            cout << "1. Travel Forward\n";
            cout << "2. Hunt for Food\n";
            cout << "3. Rest\n";
            cout << "4. Check Status\n";
            cout << "5. Check Inventory\n";
            cout << "6. Continue Journey\n";

            cout << "\nEnter choice: ";
            cin >> choice;

            if (choice == 1) {

                cout << "\nYou travel across the dunes...\n";

                player.distance -= 40;
                inventory.food -= 10;

                EventSystem::randomEvent(player, inventory);

                if (rand() % 5 == 0)
                    RiverCrossing::cross(player, inventory);
            }

            else if (choice == 2) {

                if (inventory.ammo > 0) {
                    cout << "\nYou go hunting.\n";

                    inventory.food += 30;
                    inventory.ammo -= 5;
                } else {
                    cout << "You have no ammo.\n";
                }
            }

            else if (choice == 3) {

                cout << "\nYou rest at camp.\n";
                player.health += 10;
                inventory.food -= 5;
            }

            else if (choice == 4) {
                player.showStatus();
            }

            else if (choice == 5) {
                inventory.show();
            }

            else if (choice == 6) {
                cout << "The caravan moves onward...\n";
                player.distance -= 30;
            }

            if (inventory.food <= 0) {
                cout << "\nYou ran out of food!\n";
                player.health -= 10;
            }

            if (player.health <= 0)
                break;
        }

        if (player.health <= 0) {
            cout << "\nYour caravan did not survive the desert...\n";
        } else {
            cout << "\nYou reached the Golden City beyond the dunes!\n";
        }

        cout << "\nJourney ended.\n";
    }


// MainMenu
void mainMenu() {

    while (running) {

        int choice;

        cout << "\n=================================\n";
        cout << "        GOLDEN DUNES TRAIL\n";
        cout << "=================================\n";

        cout << "1. Start New Journey\n";
        cout << "2. How To Play\n";
        cout << "3. Credits\n";
        cout << "4. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            startJourney();

        else if (choice == 2)
            showHowToPlay();

        else if (choice == 3)
            credits();

        else if (choice == 4)
            running = false;

        else
            cout << "Invalid choice.\n";
    }
}
};

// Main
int main() {

    srand(time(0));

    Game game;

    game.mainMenu();

    return 0;
}
