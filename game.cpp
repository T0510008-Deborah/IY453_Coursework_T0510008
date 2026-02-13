#include <iostream>
#include <string>
using namespace std;

// Player
class Player {
private:
    string name;
    int health;
    int lives;
    int attackPower;

public:
    Player() {
        name = "default";
        health = 100;
        lives = 3;
        attackPower = 10;
    }

    Player(string tempName) {
        name = tempName;
        health = 100;
        lives = 3;
        attackPower = 10;
    }

    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getLives() {
        return lives;
    }

    int getAttackPower() {
        return attackPower;
    }

    void loseHealth(int amount) {
        health = health - amount;
        if (health <= 0) {
            lives--;
            health = 100;
            cout << "You lost a life! Lives left: " << lives << endl;
        }
    }

    void gainHealth(int amount) {
        health = health + amount;
        if (health > 100) {
            health = 100;
        }
    }

    void increaseAttack(int amount) {
        attackPower = attackPower + amount;
    }
};

// item
class Item {
private:
    string name;
    int healthBonus;
    int attackBonus;

public:
    Item(string tempName, int tempHealthBonus, int tempAttackBonus) {
        name = tempName;
        healthBonus = tempHealthBonus;
        attackBonus = tempAttackBonus;
    }

    void applyItem(Player& player) {
        player.gainHealth(healthBonus);
        player.increaseAttack(attackBonus);
        cout << "You used " << name << "!" << endl;
    }
};

// TrailEvent
class TrailEvent {
private:
    string description;

public:
    TrailEvent(string tempDescription) {
        description = tempDescription;
    }

    void displayEvent() {
        cout << description << endl;
    }
};

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
