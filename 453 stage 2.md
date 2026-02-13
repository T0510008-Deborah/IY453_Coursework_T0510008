# IY453 Stage 1

| Assessment Details | Please Complete All Details        |
| ------------------ | ---------------------------------- |
| Group              | B                                  |
| Module Title       | Software Design and Implementation |
| Assessment Type    | Stage1                             |
| Module Tutor Name  | Jonathan Shore                     |
| Student ID Number  | P510008                            |
| Date of Submission | 30th January 2026                  |
| Word Count         | 1469                               |

- [x] *I confirm that this assignment is my own work. Where I have referred to academic sources, I have provided in-text citations and included the sources in
  the final reference list.*

- [x] *Where I have used AI, I have cited and referenced appropriately.

------------------------------------------------------------------------------------------------------------------------------

### Introduction: Purpose of the Program

------------------------------------------------------------------------------------------------------------------------------

The purpose of this program is to develop a text-based adventure game. The project aims to demonstrate proficiency in Object-Oriented Programming (OOP) principles, with error handling. By creating a branching narrative, the software provides an interactive user experience where choices directly influence the game outcome.

The game allows a player to interact with a story by making choices that affect the outcome of the game. The player navigates through different scenarios, collects items, solves puzzles, and fights enemies. Depending on the choices made, the player may either progress through the story, win the game, or reach a game over stage.

##### Functional Requirements

*Functional requirements describe what the system must do.*

1. **Player Interaction and Choices** - The system should ask the player for their name at the start of the game, present the player with binary choices of two options at each stage of the game. It should also accept user input to choose between options and display the consequences, if any, of each choice. Lastly, it should end the game if the player makes a losing choice. 

2. **Story and Engagement** - For the game flow, it should contain a structured story made up of connected scenes, making it progressive as the story is based on the player’s choices. It should include at least 30 decision having at least one successful ending and several game-over endings.

3. **Inventory and Items** - The system should allow the player to collect items, store items and view them in an inventory, which is essential because it affects the gameplay. Items may include weapons, clothing/Armour, food/potions or keys.

4. **Gameplay Scenarios** - For the gameplay, it should include a variety of scenarios, such as Puzzles, whereby the player is asked to solve puzzles and only when the player has solved it correctly, can move on to the next stage. Other scenarios like combat , to allow the player to fight enemies and item collection, to allow the player to find and pick items.

5. **Save and Resume Functionality** - It allows the player to save the game and store file such as Name, current scene, Health, Inventory and score of the progression of the game. It should then be able to load the saved game and continue.

6. **Score System** - The system must increase the score when solving puzzles, winning fights or making good choices and display the score during the game and the final score at the end.

7. **Error Handling** - This is necessary to prevent Invalid input such as letters instead of numbers. Ask the user to retry if input is wrong and this prevent crashes.

###### Non-Functional Requirements

The system must follow good software engineering principles to ensure quality and maintainability. The program should be developed using object-oriented programming concepts such as encapsulation, inheritance, and polymorphism. This means that related data and behaviours should be grouped into appropriate classes, with specialised scene types derived from a base scene class. The code should be modular and well structured so that new features, scenes, or items can be easily added in the future without major changes to the existing system.

In terms of user experience and performance, the game should provide a simple and consistent text based interface that is easy to understand and use. The program must run smoothly without noticeable delays, and all user inputs should be validated to prevent errors or crashes. The system should be compatible with the C++17 standard and run correctly. Clear comments and documentation should be included to support readability, testing, and debugging throughout development.

------------------------------------------------------------------------------------------------------------------------------

### Inputs, Processes, and Outputs

------------------------------------------------------------------------------------------------------------------------------

This stage identifies the main inputs, processes, and outputs of the Trail game idea.

**Input:** This will be the data provided by the player to interact with the system. These include:

- Player name entered at the start of the game.

- Binary choices made during the journey (e.g. selecting routes or actions).

- Puzzle answers provided in puzzle scenarios.

- User commands for saving or loading the game.

**Processes:** This are the internal operations performed by the system. These include:

- Displaying story scenes and travel descriptions.

- Updating player statistics such as health, water, and score.

- Managing the inventory system (adding and removing items).

- Saving and loading game data from files.

- Checking win and lose conditions.

**Outputs:** The results produced by the system and shown to the player. These include:

- Narrative text describing the current location or event.

- Available choices for each scenario.

- Feedback messages based on player decisions.

- Updated health, water, and inventory status.

- Game over messages or final victory screen.

------------------------------------------------------------------------------------------------------------------------------

### ALgorithm

------------------------------------------------------------------------------------------------------------------------------

START

    SUBROUTINE CreatePlayer(name)
    
        SET Player.name TO name
        SET Player.health TO 100
        SET Player.water TO 5
        SET Player.score TO 0
    
    END SUBROUTINE
    
    SUBROUTINE DisplayEvent()
    
        PRINT "You arrive at a new point on the trail."
        PRINT "1. Travel through the dunes"
        PRINT "2. Visit a nearby oasis"
    
    END SUBROUTINE
    
    
    SUBROUTINE ProcessChoice(choice, Player)
    
        IF choice IS 1 THEN
            PRINT "You continue through the hot dunes."
            SET Player.water TO Player.water - 1
            SET Player.score TO Player.score + 5
    
        ELSE IF choice IS 2 THEN
            PRINT "You find water at the oasis."
            SET Player.water TO Player.water + 2
            SET Player.score TO Player.score + 10
    
        ELSE
            PRINT "Invalid choice."
        END IF
    
    END SUBROUTINE
    
    // main
    
    START
        PRINT "Welcome to Golden Dunes Trail"
        PRINT "Enter your name:"
        READ playerName
    
        CREATE Player WITH playerName
        CREATE Game
    
        CALL Game.StartGame(Player)
    END

END

------------------------------------------------------------------------------------------------------------------------------

#### Class Diagram

------------------------------------------------------------------------------------------------------------------------------

![](C:\Users\user\AppData\Roaming\marktext\images\2026-01-30-12-04-10-image.png)

------------------------------------------------------------------------------------------------------------------------------

##### Program Code

This program implements the text-based adventure game called **Golden Dunes Trail** using object - oriented programming in C++. The system is designed around two main classes: **Player**, which stores and manages the player’s attributes, and **Game**, which controls the overall game flow and scenarios. Other classes include **item** and **trailevent**. The main function acts as the entry point and starts the game by creating a Game object and calling its **startGame()** method.

The Game class presents a sequence of eight scenarios where the player must make choices that affect their health, lives, and attack power. User input is validated to ensure correct choices, and the player’s attributes are updated progressively based on the decisions made throughout the game.

------------------------------------------------------------------------------------------------------------------------------

```cpp
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
```
