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

public:
    void startGame() {
        string name;
        cout << "Welcome to Golden Dunes: The Lost Caravan" << endl;
        cout << "Enter your name: ";
        getline(cin, name);

        player = Player(name);
        runGame();
    }

    int getChoice() {
        int choice;
        cout << "Choose (1 or 2): ";
        cin >> choice;

        while (choice != 1 && choice != 2) {
            cout << "Invalid choice. Enter 1 or 2: ";
            cin >> choice;
        }

        return choice;
    }

    void runGame() {
        scenario1();
        scenario2();
        scenario3();
        scenario4();
        scenario5();
        scenario6();
        scenario7();
        scenario8();

        cout << "\nCongratulations! You survived the Golden Dunes." << endl;
    }

    // 8 Scenarios

    void scenario1() {
        TrailEvent event("You find a water well in the desert.");
        event.displayEvent();

        cout << "1. Drink the water\n2. Ignore it" << endl;
        int choice = getChoice();

        if (choice == 1) {
            Item water("Fresh Water", 20, 0);
            water.applyItem(player);
        } else {
            player.loseHealth(10);
        }
    }

    void scenario2() {
        TrailEvent event("A sandstorm is approaching.");
        event.displayEvent();

        cout << "1. Take shelter\n2. Walk through" << endl;
        int choice = getChoice();

        if (choice == 2) {
            player.loseHealth(20);
        }
    }

    void scenario3() {
        TrailEvent event("You find a rusty sword.");
        event.displayEvent();

        cout << "1. Take sword\n2. Leave it" << endl;
        int choice = getChoice();

        if (choice == 1) {
            Item sword("Rusty Sword", 0, 5);
            sword.applyItem(player);
        }
    }

    void scenario4() {
        TrailEvent event("A bandit blocks your path.");
        event.displayEvent();

        cout << "1. Fight\n2. Run" << endl;
        int choice = getChoice();

        if (choice == 1 && player.getAttackPower() < 15) {
            player.loseHealth(30);
        } else if (choice == 2) {
            player.loseHealth(10);
        }
    }

    void scenario5() {
        TrailEvent event("You find food supplies.");
        event.displayEvent();

        cout << "1. Eat food\n2. Save it" << endl;
        int choice = getChoice();

        if (choice == 1) {
            Item food("Food", 15, 0);
            food.applyItem(player);
        }
    }

    void scenario6() {
        TrailEvent event("You reach a broken bridge.");
        event.displayEvent();

        cout << "1. Cross\n2. Go around" << endl;
        int choice = getChoice();

        if (choice == 1) {
            player.loseHealth(20);
        }
    }

    void scenario7() {
        TrailEvent event("You meet a travelling merchant.");
        event.displayEvent();

        cout << "1. Trade\n2. Ignore" << endl;
        int choice = getChoice();

        if (choice == 1) {
            Item potion("Health Potion", 25, 0);
            potion.applyItem(player);
        }
    }

    void scenario8() {
        TrailEvent event("Final challenge: Desert Guardian!");
        event.displayEvent();

        cout << "1. Fight\n2. Flee" << endl;
        int choice = getChoice();

        if (choice == 1 && player.getAttackPower() < 20) {
            player.loseHealth(40);
        }
    }
};

// Main
int main() {
    Game game;
    game.startGame();
    return 0;
}
