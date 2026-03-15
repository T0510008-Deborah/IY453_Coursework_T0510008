# IY453 Stage 3

| Assessment Details | Please Complete All Details        |
| ------------------ | ---------------------------------- |
| Group              | B                                  |
| Module Title       | Software Design and Implementation |
| Assessment Type    | Stage 3                            |
| Module Tutor Name  | Jonathan Shore                     |
| Student ID Number  | P510008                            |
| Date of Submission | 15 March 2026                      |
| Word Count         | 8174                               |

- [x] *I confirm that this assignment is my own work. Where I have referred to academic sources, I have provided in-text citations and included the sources in
  the final reference list.*

- [x] *Where I have used AI, I have cited and referenced appropriately.

------------------------------------------------------

### STAGE 1

-----------------------------------------------------------

### Introduction: Purpose of the Program

The purpose of this program is to develop a text-based adventure game. The project aims to demonstrate proficiency in Object - Oriented Programming (OOP) principles, with error handling. By creating a branching narrative, the software provides an interactive user experience where choices directly influence the game outcome.

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

The system must follow good software engineering principles to ensure quality and maintainability. The program should be developed using object - oriented programming concepts such as encapsulation, inheritance, and polymorphism. This means that related data and behaviours should be grouped into appropriate classes, with specialised scene types derived from a base scene class. The code should be modular and well structured so that new features, scenes, or items can be easily added in the future without major changes to the existing system.

In terms of user experience and performance, the game should provide a simple and consistent text based interface that is easy to understand and use. The program must run smoothly without noticeable delays, and all user inputs should be validated to prevent errors or crashes. The system should be compatible with the C++17 standard and run correctly. Clear comments and documentation should be included to support readability, testing, and debugging throughout development.

----------------------------------------------------------------------------

#### Input Process Output Table

--------------------------------------------------------------------------------------

*Below is a representation in a table.*

| **Inputs**                                                           | **Processes**                                                                           | **Outputs**                                                     |
| -------------------------------------------------------------------- | --------------------------------------------------------------------------------------- | --------------------------------------------------------------- |
| **Player enters their name (string)**                                | System creates a Player object and initialises attributes (health, lives, attack power) | Welcome message and initial player stats displayed              |
| **Player selects menu options (1 or 2) in each scenario**            | Game evaluates the selected option and executes the corresponding scenario logic        | Story text describing what happened in the scenario             |
| **Player chooses actions during puzzles (e.g. take item or ignore)** | Game checks choice and updates player attributes accordingly                            | Updated health, lives, or attack power shown                    |
| **Player makes combat decisions (fight or flee)**                    | Game compares player attack power with enemy difficulty                                 | Combat result message (win, lose health, or lose life)          |
| **Player collects items (e.g. food, sword, potion)**                 | Item effects are applied to the player (increase health or attack)                      | Confirmation message showing item used and new stats            |
| **Invalid input (not 1 or 2)**                                       | Input validation loop forces user to re-enter a valid choice                            | Error message prompting correct input                           |
| **Completion of final scenario**                                     | Game ends and calculates final player state                                             | Final summary showing remaining lives, health, and attack power |

---

### ALgorithm

-----------------------------------------------------------------------------

```
RECORD Item
    name : STRING
    type : STRING
    attack : INTEGER
    defense : INTEGER
    health : INTEGER
END RECORD

RECORD Player
    name : STRING
    health : INTEGER
    attack : INTEGER
    defense : INTEGER
    score : INTEGER
    inventory : LIST OF Item
END RECORD

RECORD Scene
    id : STRING
    description : STRING
END RECORD

RECORD Choice
    parentScene : STRING
    text : STRING
    resultType : STRING
    resultID : STRING
    nextScene : STRING
END RECORD

RECORD Combat
    enemyName : STRING
    enemyHP : INTEGER
    enemyAttack : INTEGER
    nextWin : STRING
    nextLose : STRING
END RECORD

RECORD Puzzle
    question : STRING
    answer : STRING
    nextCorrect : STRING
    nextWrong : STRING
END RECORD

RECORD Trade
    goldReward : INTEGER
    nextAccept : STRING
    nextDecline : STRING
END RECORD



START PROGRAM

DECLARE userChoice : INTEGER

CALL Menu
CALL LoadScenes
CALL LoadChoices
CALL LoadCombat
CALL LoadPuzzle
CALL LoadTrade

CALL StartGame

END PROGRAM



SUBROUTINE Menu

START

DECLARE userChoice : INTEGER

WHILE TRUE

    PRINT "===== DESERT QUEST ====="
    PRINT "1 Start Game"
    PRINT "2 Load Game"
    PRINT "3 Instructions"
    PRINT "4 Exit"

    READ userChoice

    IF userChoice = 1 THEN
        RETURN
    ELSE IF userChoice = 2 THEN
        CALL LoadGame
        RETURN
    ELSE IF userChoice = 3 THEN
        PRINT "Explore the desert, solve puzzles and defeat enemies."
    ELSE IF userChoice = 4 THEN
        STOP PROGRAM
    END IF

END WHILE

END

END SUBROUTINE



SUBROUTINE LoadScenes

START

OPEN "Scenarios.csv"

FOR EACH line IN file

    DECLARE newScene : Scene

    READ newScene.id
    READ newScene.description

    STORE newScene IN scenes

END FOR

END

END SUBROUTINE



SUBROUTINE LoadChoices

START

OPEN "Choice.csv"

FOR EACH line IN file

    DECLARE newChoice : Choice

    READ newChoice.parentScene
    READ newChoice.text
    READ newChoice.resultType
    READ newChoice.resultID
    READ newChoice.nextScene

    ADD newChoice TO choices

END FOR

END

END SUBROUTINE



SUBROUTINE LoadCombat

START

OPEN "Combat.csv"

FOR EACH line IN file

    DECLARE newCombat : Combat

    READ newCombat.enemyName
    READ newCombat.enemyHP
    READ newCombat.enemyAttack
    READ newCombat.nextWin
    READ newCombat.nextLose

    STORE newCombat IN combats

END FOR

END

END SUBROUTINE



SUBROUTINE LoadPuzzle

START

OPEN "Puzzle.csv"

FOR EACH line IN file

    DECLARE newPuzzle : Puzzle

    READ newPuzzle.question
    READ newPuzzle.answer
    READ newPuzzle.nextCorrect
    READ newPuzzle.nextWrong

    STORE newPuzzle IN puzzles

END FOR

END

END SUBROUTINE



SUBROUTINE LoadTrade

START

OPEN "Trade.csv"

FOR EACH line IN file

    DECLARE newTrade : Trade

    READ newTrade.goldReward
    READ newTrade.nextAccept
    READ newTrade.nextDecline

    STORE newTrade IN trades

END FOR

END

END SUBROUTINE



SUBROUTINE StartGame

START

IF player.name IS EMPTY THEN
    PRINT "Enter your name"
    READ player.name
END IF

WHILE TRUE

    CALL ShowScene
    CALL ShowPlayerStats

    SET options TO GetChoices(currentScene)

    IF options IS EMPTY THEN

        PRINT "===== VICTORY ====="
        PRINT "Final Score: ", player.score

        CALL ShowInventory

        STOP PROGRAM

    END IF

    DISPLAY options

    PRINT "3 Save Game"
    PRINT "4 Inventory"

    DECLARE choice : INTEGER
    READ choice

    IF choice = 3 THEN
        CALL SaveGame
        CONTINUE
    ELSE IF choice = 4 THEN
        CALL ShowInventory
        CONTINUE
    END IF

    SET currentScene TO ResolveChoice(choice)

END WHILE

END

END SUBROUTINE



SUBROUTINE FightEnemy(enemy : Combat)

START

DECLARE enemyHP : INTEGER
SET enemyHP = enemy.enemyHP - player.attack

PRINT "Enemy appears"

IF enemyHP <= 0 THEN

    PRINT "Enemy defeated"
    ADD 50 TO player.score

    RETURN enemy.nextWin

ELSE

    DECLARE damage : INTEGER
    SET damage = enemy.enemyAttack - player.defense

    IF damage < 0 THEN
        SET damage = 0
    END IF

    SET player.health = player.health - damage

    IF player.health <= 0 THEN
        PRINT "Game Over"
        STOP PROGRAM
    END IF

END IF

END

END SUBROUTINE



SUBROUTINE SolvePuzzle(puzzle : Puzzle)

START

DECLARE playerAnswer : STRING

PRINT puzzle.question
READ playerAnswer

IF playerAnswer = puzzle.answer THEN

    PRINT "Correct"
    ADD 30 TO player.score

    RETURN puzzle.nextCorrect

ELSE

    PRINT "Wrong answer"

    RETURN puzzle.nextWrong

END IF

END

END SUBROUTINE



SUBROUTINE TradeEvent(trade : Trade)

START

DECLARE decision : STRING

PRINT "Accept trade? (y/n)"
READ decision

IF decision = "y" THEN

    DECLARE newItem : Item

    SET newItem.name = "Desert Sword"
    SET newItem.type = "Weapon"
    SET newItem.attack = 10
    SET newItem.defense = 0
    SET newItem.health = 0

    ADD newItem TO player.inventory

    SET player.attack = player.attack + 10
    SET player.score = player.score + 10

    RETURN trade.nextAccept

ELSE

    RETURN trade.nextDecline

END IF

END

END SUBROUTINE



SUBROUTINE ShowInventory

START

IF player.inventory IS EMPTY THEN

    PRINT "Inventory empty"

ELSE

    FOR EACH item IN player.inventory

        PRINT item.name
        PRINT item.type

    END FOR

END IF

END

END SUBROUTINE



SUBROUTINE SaveGame

START

OPEN save file

WRITE player.name
WRITE player.health
WRITE player.score
WRITE currentScene

DECLARE inventoryCount : INTEGER
SET inventoryCount = SIZE OF player.inventory

WRITE inventoryCount

FOR EACH item IN player.inventory

    WRITE item.name
    WRITE item.type
    WRITE item.attack
    WRITE item.defense
    WRITE item.health

END FOR

PRINT "Game Saved"

END

END SUBROUTINE



SUBROUTINE LoadGame

START

OPEN save file

IF file DOES NOT EXIST THEN
    PRINT "No save file found"
    RETURN
END IF

READ player.name
READ player.health
READ player.score
READ currentScene

DECLARE inventoryCount : INTEGER
READ inventoryCount

FOR i FROM 1 TO inventoryCount

    DECLARE newItem : Item

    READ newItem.name
    READ newItem.type
    READ newItem.attack
    READ newItem.defense
    READ newItem.health

    ADD newItem TO player.inventory

END FOR

PRINT "Game Loaded"

END

END SUBROUTINE
```

------------------------------------------------------------------------------------

### STAGE 2

-------------------------------------------------------------------------------------------

#### **Introduction: Purpose of the Program**

---

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

---

### Inputs, Processes, and Outputs

---

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

*Below is a representation in a table.*

| **Inputs**                                                           | **Processes**                                                                           | **Outputs**                                                     |
| -------------------------------------------------------------------- | --------------------------------------------------------------------------------------- | --------------------------------------------------------------- |
| **Player enters their name (string)**                                | System creates a Player object and initialises attributes (health, lives, attack power) | Welcome message and initial player stats displayed              |
| **Player selects menu options (1 or 2) in each scenario**            | Game evaluates the selected option and executes the corresponding scenario logic        | Story text describing what happened in the scenario             |
| **Player chooses actions during puzzles (e.g. take item or ignore)** | Game checks choice and updates player attributes accordingly                            | Updated health, lives, or attack power shown                    |
| **Player makes combat decisions (fight or flee)**                    | Game compares player attack power with enemy difficulty                                 | Combat result message (win, lose health, or lose life)          |
| **Player collects items (e.g. food, sword, potion)**                 | Item effects are applied to the player (increase health or attack)                      | Confirmation message showing item used and new stats            |
| **Invalid input (not 1 or 2)**                                       | Input validation loop forces user to re-enter a valid choice                            | Error message prompting correct input                           |
| **Completion of final scenario**                                     | Game ends and calculates final player state                                             | Final summary showing remaining lives, health, and attack power |

---------------------------------------------------------------------

#### Algorithm

--------------------------------------------------------------------------------------

```
RECORD Item
    name : STRING
    type : STRING
    attack : INTEGER
    defense : INTEGER
    health : INTEGER
END RECORD

RECORD Player
    name : STRING
    health : INTEGER
    attack : INTEGER
    defense : INTEGER
    score : INTEGER
    inventory : LIST OF Item
END RECORD

RECORD Scene
    id : STRING
    description : STRING
END RECORD

RECORD Choice
    parentScene : STRING
    text : STRING
    resultType : STRING
    resultID : STRING
    nextScene : STRING
END RECORD

RECORD Combat
    enemyName : STRING
    enemyHP : INTEGER
    enemyAttack : INTEGER
    nextWin : STRING
    nextLose : STRING
END RECORD

RECORD Puzzle
    question : STRING
    answer : STRING
    nextCorrect : STRING
    nextWrong : STRING
END RECORD

RECORD Trade
    goldReward : INTEGER
    nextAccept : STRING
    nextDecline : STRING
END RECORD



START PROGRAM

DECLARE userChoice : INTEGER

CALL Menu
CALL LoadScenes
CALL LoadChoices
CALL LoadCombat
CALL LoadPuzzle
CALL LoadTrade

CALL StartGame

END PROGRAM



SUBROUTINE Menu

START

DECLARE userChoice : INTEGER

WHILE TRUE

    PRINT "===== DESERT QUEST ====="
    PRINT "1 Start Game"
    PRINT "2 Load Game"
    PRINT "3 Instructions"
    PRINT "4 Exit"

    READ userChoice

    IF userChoice = 1 THEN
        RETURN
    ELSE IF userChoice = 2 THEN
        CALL LoadGame
        RETURN
    ELSE IF userChoice = 3 THEN
        PRINT "Explore the desert, solve puzzles and defeat enemies."
    ELSE IF userChoice = 4 THEN
        STOP PROGRAM
    END IF

END WHILE

END

END SUBROUTINE



SUBROUTINE LoadScenes

START

OPEN "Scenarios.csv"

FOR EACH line IN file

    DECLARE newScene : Scene

    READ newScene.id
    READ newScene.description

    STORE newScene IN scenes

END FOR

END

END SUBROUTINE



SUBROUTINE LoadChoices

START

OPEN "Choice.csv"

FOR EACH line IN file

    DECLARE newChoice : Choice

    READ newChoice.parentScene
    READ newChoice.text
    READ newChoice.resultType
    READ newChoice.resultID
    READ newChoice.nextScene

    ADD newChoice TO choices

END FOR

END

END SUBROUTINE



SUBROUTINE LoadCombat

START

OPEN "Combat.csv"

FOR EACH line IN file

    DECLARE newCombat : Combat

    READ newCombat.enemyName
    READ newCombat.enemyHP
    READ newCombat.enemyAttack
    READ newCombat.nextWin
    READ newCombat.nextLose

    STORE newCombat IN combats

END FOR

END

END SUBROUTINE



SUBROUTINE LoadPuzzle

START

OPEN "Puzzle.csv"

FOR EACH line IN file

    DECLARE newPuzzle : Puzzle

    READ newPuzzle.question
    READ newPuzzle.answer
    READ newPuzzle.nextCorrect
    READ newPuzzle.nextWrong

    STORE newPuzzle IN puzzles

END FOR

END

END SUBROUTINE



SUBROUTINE LoadTrade

START

OPEN "Trade.csv"

FOR EACH line IN file

    DECLARE newTrade : Trade

    READ newTrade.goldReward
    READ newTrade.nextAccept
    READ newTrade.nextDecline

    STORE newTrade IN trades

END FOR

END

END SUBROUTINE



SUBROUTINE StartGame

START

IF player.name IS EMPTY THEN
    PRINT "Enter your name"
    READ player.name
END IF

WHILE TRUE

    CALL ShowScene
    CALL ShowPlayerStats

    SET options TO GetChoices(currentScene)

    IF options IS EMPTY THEN

        PRINT "===== VICTORY ====="
        PRINT "Final Score: ", player.score

        CALL ShowInventory

        STOP PROGRAM

    END IF

    DISPLAY options

    PRINT "3 Save Game"
    PRINT "4 Inventory"

    DECLARE choice : INTEGER
    READ choice

    IF choice = 3 THEN
        CALL SaveGame
        CONTINUE
    ELSE IF choice = 4 THEN
        CALL ShowInventory
        CONTINUE
    END IF

    SET currentScene TO ResolveChoice(choice)

END WHILE

END

END SUBROUTINE



SUBROUTINE FightEnemy(enemy : Combat)

START

DECLARE enemyHP : INTEGER
SET enemyHP = enemy.enemyHP - player.attack

PRINT "Enemy appears"

IF enemyHP <= 0 THEN

    PRINT "Enemy defeated"
    ADD 50 TO player.score

    RETURN enemy.nextWin

ELSE

    DECLARE damage : INTEGER
    SET damage = enemy.enemyAttack - player.defense

    IF damage < 0 THEN
        SET damage = 0
    END IF

    SET player.health = player.health - damage

    IF player.health <= 0 THEN
        PRINT "Game Over"
        STOP PROGRAM
    END IF

END IF

END

END SUBROUTINE



SUBROUTINE SolvePuzzle(puzzle : Puzzle)

START

DECLARE playerAnswer : STRING

PRINT puzzle.question
READ playerAnswer

IF playerAnswer = puzzle.answer THEN

    PRINT "Correct"
    ADD 30 TO player.score

    RETURN puzzle.nextCorrect

ELSE

    PRINT "Wrong answer"

    RETURN puzzle.nextWrong

END IF

END

END SUBROUTINE



SUBROUTINE TradeEvent(trade : Trade)

START

DECLARE decision : STRING

PRINT "Accept trade? (y/n)"
READ decision

IF decision = "y" THEN

    DECLARE newItem : Item

    SET newItem.name = "Desert Sword"
    SET newItem.type = "Weapon"
    SET newItem.attack = 10
    SET newItem.defense = 0
    SET newItem.health = 0

    ADD newItem TO player.inventory

    SET player.attack = player.attack + 10
    SET player.score = player.score + 10

    RETURN trade.nextAccept

ELSE

    RETURN trade.nextDecline

END IF

END

END SUBROUTINE



SUBROUTINE ShowInventory

START

IF player.inventory IS EMPTY THEN

    PRINT "Inventory empty"

ELSE

    FOR EACH item IN player.inventory

        PRINT item.name
        PRINT item.type

    END FOR

END IF

END

END SUBROUTINE



SUBROUTINE SaveGame

START

OPEN save file

WRITE player.name
WRITE player.health
WRITE player.score
WRITE currentScene

DECLARE inventoryCount : INTEGER
SET inventoryCount = SIZE OF player.inventory

WRITE inventoryCount

FOR EACH item IN player.inventory

    WRITE item.name
    WRITE item.type
    WRITE item.attack
    WRITE item.defense
    WRITE item.health

END FOR

PRINT "Game Saved"

END

END SUBROUTINE



SUBROUTINE LoadGame

START

OPEN save file

IF file DOES NOT EXIST THEN
    PRINT "No save file found"
    RETURN
END IF

READ player.name
READ player.health
READ player.score
READ currentScene

DECLARE inventoryCount : INTEGER
READ inventoryCount

FOR i FROM 1 TO inventoryCount

    DECLARE newItem : Item

    READ newItem.name
    READ newItem.type
    READ newItem.attack
    READ newItem.defense
    READ newItem.health

    ADD newItem TO player.inventory

END FOR

PRINT "Game Loaded"

END

END SUBROUTINE
```

--------------------------------------------------------------------------------

#### Program Code

---

##### Program Code

The program is a console-based adventure game called Golden Dunes Trail developed in C++ using object - oriented programming. The game uses several classes such as Player, Scene, Choice, Combat, Puzzle, Trade, and Item to organise the game structure. The main game system controls the flow of the game, loads data from CSV files, and manages player interactions.

During gameplay, the player navigates through scenes by selecting choices that may lead to combat, puzzles, or trade events. The Player class manages the player’s health, score, attack, defense, and inventory items. The program also includes save and load functionality so that the player’s progress and game state can be stored and restored.

---

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

/* ================= ITEM ================= */

class Item {
public:
    string name;
    string type;
    float attack;
    float defense;
    float health;

    Item(){}

    Item(string n,string t,float a,float d,float h){
        name=n;
        type=t;
        attack=a;
        defense=d;
        health=h;
    }
};

/* ================= PLAYER ================= */

class Player {

private:

    string name;
    float health = 100;
    float attack = 5;
    float defense = 2;
    int score = 0;

public:

    vector<Item> inventory;

    void setName(string n){
        name=n;
    }

    string getName(){
        return name;
    }

    float getHealth(){
        return health;
    }

    float getAttack(){
        return attack;
    }

    float getDefense(){
        return defense;
    }

    int getScore(){
        return score;
    }

    void setHealth(float h){
        health=h;
    }

    void setScore(int s){
        score=s;
    }

    void damage(float d){

        float finalDamage = d - defense;

        if(finalDamage < 0)
            finalDamage = 0;

        health -= finalDamage;

        if(health < 0)
            health = 0;
    }

    void heal(float h){
        health += h;
    }

    void addScore(int s){
        score += s;
    }

    void addItem(Item item){

        inventory.push_back(item);

        attack += item.attack;
        defense += item.defense;
        health += item.health;

        cout << "\nItem collected: " << item.name << endl;
    }

    void showInventory(){

        cout << "\n--- INVENTORY ---\n";

        if(inventory.empty()){
            cout << "Inventory empty\n";
            return;
        }

        for(Item i : inventory){
            cout << i.name << " (" << i.type << ")\n";
        }
    }

    void showStats(){

        cout << "\n--- PLAYER STATS ---\n";
        cout << "Health: " << health << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Score: " << score << endl;
    }
};

/* ================= STORY STRUCTURES ================= */

class Scene{

public:
    string id;
    string description;

    Scene(){}

    Scene(string i,string d){
        id=i;
        description=d;
    }
};

class Choice{

public:

    string parentScene;
    string text;
    string resultType;
    string resultID;
    string nextScene;

    // Default constructor (needed for vector)
    Choice(){}

    Choice(string p,string t,string r,string id,string n){
        parentScene = p;
        text = t;
        resultType = r;
        resultID = id;
        nextScene = n;
    }
};

class Combat{

public:
    string enemyName;
    float enemyHP;
    float enemyAttack;
    string nextWin;
    string nextLose;
};

class Puzzle{

public:
    string question;
    string answer;
    string nextCorrect;
    string nextWrong;
};

class Trade{

public:
    float goldReward;
    string nextAccept;
    string nextDecline;
};

/* ================= GAME ================= */

class Game{

private:

    map<string,Scene> scenes;
    vector<Choice> choices;
    map<string,Combat> combats;
    map<string,Puzzle> puzzles;
    map<string,Trade> trades;

    Player player;

    string current_scene;
    string last_scene_shown;

public:

/* ================= MENU ================= */

void menu(){

    int choice;

    while(true){

        cout << "\n===== GOLDEN DUNES =====\n";
        cout << "1 Start Game\n";
        cout << "2 Load Game\n";
        cout << "3 Instructions\n";
        cout << "4 Exit\n";
        cout << "Choice: ";

        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }

        if(choice==1) return;

        if(choice==2){

            if(loadGame()){
                return;
            }
        }

        if(choice==3){

            cout << "\nExplore the desert, solve puzzles and defeat enemies.\n";
            cout << "Collect items to increase your power.\n";
        }

        if(choice==4){
            exit(0);
        }
    }
}

/* ================= CSV LOADERS ================= */

void loadScenes(string file){

    ifstream f(file);
    string line;

    getline(f,line);

    while(getline(f,line)){

        string id,desc;

        stringstream ss(line);

        getline(ss,id,',');
        getline(ss,desc);

        scenes[id] = Scene(id,desc);

        if(current_scene=="")
            current_scene=id;
    }
}

void loadChoices(string file){

    ifstream f(file);
    string line;

    getline(f,line);

    while(getline(f,line)){

        string cid,parent,text,type,rid,next;

        stringstream ss(line);

        getline(ss,cid,',');
        getline(ss,parent,',');
        getline(ss,text,',');
        getline(ss,type,',');
        getline(ss,rid,',');
        getline(ss,next);

        choices.push_back(Choice(parent,text,type,rid,next));
    }
}

    void loadCombat(string file){

    ifstream f(file);
    string line;

    getline(f,line);

    while(getline(f,line)){

        if(line.empty()) continue;

        string id,name,hp,atk,rew,win,lose;

        stringstream ss(line);

        getline(ss,id,',');
        getline(ss,name,',');
        getline(ss,hp,',');
        getline(ss,atk,',');
        getline(ss,rew,',');
        getline(ss,win,',');
        getline(ss,lose);

        Combat c;

        try{

            c.enemyName = name;
            c.enemyHP = stof(hp);
            c.enemyAttack = stof(atk);
            c.nextWin = win;
            c.nextLose = lose;

            combats[id] = c;

        }catch(...){

            cout << "Combat CSV error skipped: " << line << endl;
        }
    }
}

void loadPuzzle(string file){

    ifstream f(file);
    string line;

    getline(f,line);

    while(getline(f,line)){

        string id,q,a,correct,wrong;

        stringstream ss(line);

        getline(ss,id,',');
        getline(ss,q,',');
        getline(ss,a,',');
        getline(ss,correct,',');
        getline(ss,wrong);

        Puzzle p;

        p.question=q;
        p.answer=a;
        p.nextCorrect=correct;
        p.nextWrong=wrong;

        puzzles[id]=p;
    }
}

    void loadTrade(string file){

    ifstream f(file);
    string line;

    getline(f,line);

    while(getline(f,line)){

        if(line.empty()) continue;

        string id,item,gold,give,accept,decline;

        stringstream ss(line);

        getline(ss,id,',');
        getline(ss,item,',');
        getline(ss,gold,',');
        getline(ss,give,',');
        getline(ss,accept,',');
        getline(ss,decline);

        Trade t;

        try{

            t.goldReward = stof(gold);
            t.nextAccept = accept;
            t.nextDecline = decline;

            trades[id] = t;

        }catch(...){

            cout << "Trade CSV error skipped: " << line << endl;
        }
    }
}

/* ================= GAME FUNCTIONS ================= */

vector<Choice> getChoices(string sceneID){

    vector<Choice> result;

    for(Choice c:choices){

        if(c.parentScene==sceneID)
            result.push_back(c);
    }

    if(result.size() > 2){
        result.erase(result.begin() + 2, result.end());
    }

    return result;
}

void showScene(){

    if(current_scene != last_scene_shown){

        cout << "\nThe desert wind howls across the dunes.\n";
        cout << player.getName() << ", your journey continues...\n";

        last_scene_shown=current_scene;
    }

    cout << "\n" << scenes[current_scene].description << endl;
}

/* ================= COMBAT ================= */

bool fightEnemy(Combat enemy){

    cout << "\nEnemy appears: " << enemy.enemyName << endl;

    enemy.enemyHP -= player.getAttack();

    if(enemy.enemyHP <= 0){

        cout << "Enemy defeated!\n";

        player.addScore(50);

        return true;
    }

    player.damage(enemy.enemyAttack);

    if(player.getHealth() <= 0){

        cout << "You were defeated.\n";

        return false;
    }

    return true;
}

/* ================= CHOICE RESOLUTION ================= */

string resolveChoice(Choice c){

    if(c.resultType=="COMBAT"){

        Combat enemy = combats[c.resultID];

        if(fightEnemy(enemy))
            return enemy.nextWin;
        else
            gameOver();
    }

    if(c.resultType=="PUZZLE"){

        Puzzle p = puzzles[c.resultID];

        cout << p.question << endl;

        string ans;
        cin >> ans;

        if(ans == p.answer){

            cout << "Correct!\n";
            player.addScore(30);
            return p.nextCorrect;
        }
        else{

            cout << "Wrong!\n";
            return p.nextWrong;
        }
    }

    if(c.resultType=="TRADE"){

        Trade t = trades[c.resultID];

        char ch;

        cout << "Accept trade? (y/n): ";
        cin >> ch;

        if(ch=='y'){

            player.addScore(10);

            Item reward("Desert Sword","weapon",5,0,0);
            player.addItem(reward);

            return t.nextAccept;
        }

        return t.nextDecline;
    }

    return c.nextScene;
}

/* ================= SAVE SYSTEM ================= */

void saveGame(){

    ofstream save("savegame.txt");

    save << player.getName() << endl;
    save << current_scene << endl;
    save << player.getHealth() << endl;
    save << player.getScore() << endl;

    save << player.inventory.size() << endl;

    for(Item i:player.inventory){

        save << i.name << ","
             << i.type << ","
             << i.attack << ","
             << i.defense << ","
             << i.health << endl;
    }

    save.close();

    cout << "Game Saved.\n";
}

/* ================= LOAD SYSTEM ================= */

bool loadGame(){

    ifstream save("savegame.txt");

    if(!save){

        cout << "No save file found.\n";
        return false;
    }

    string name;

    getline(save,name);
    player.setName(name);

    getline(save,current_scene);

    float h;
    save >> h;
    player.setHealth(h);

    int s;
    save >> s;
    player.setScore(s);

    int count;
    save >> count;

    save.ignore();

    for(int i=0;i<count;i++){

        string line;

        getline(save,line);

        stringstream ss(line);

        string n,t,a,d,h;

        getline(ss,n,',');
        getline(ss,t,',');
        getline(ss,a,',');
        getline(ss,d,',');
        getline(ss,h,',');

        try{

            Item item(n,t,stof(a),stof(d),stof(h));
            player.inventory.push_back(item);

        }catch(...){

            cout << "Invalid item in save file skipped\n";
        }
    }

    cout << "Game Loaded.\n";

    return true;
}

/* ================= GAME OVER ================= */

void gameOver(){

    cout << "\n===== GAME OVER =====\n";

    cout << "Score: " << player.getScore() << endl;

    int c;

    cout << "1 Restart\n";
    cout << "2 Exit\n";

    cin >> c;

    if(c==1){

        start();
    }
    else{
        exit(0);
    }
}

/* ================= MAIN GAME LOOP ================= */

void start(){

    if(player.getName()==""){

        cout << "Enter your name: ";
        string n;
        cin >> n;

        player.setName(n);
    }

    while(true){

        showScene();

        player.showStats();

        vector<Choice> options = getChoices(current_scene);

        if(options.empty()){

            cout << "\n===== VICTORY =====\n";
            cout << "Final Score: " << player.getScore() << endl;

            player.showInventory();

            break;
        }

        cout << "\nChoices:\n";

        for(int i=0;i<options.size();i++){

            cout << i+1 << ". " << options[i].text << endl;
        }

        cout << "3 Save Game\n";
        cout << "4 Inventory\n";

        int choice;

        while(true){

            cout << "Choice: ";
            cin >> choice;

            if(cin.fail()){

                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }

            break;
        }

        if(choice==3){

            saveGame();
            continue;
        }

        if(choice==4){

            player.showInventory();
            continue;
        }

        if(choice<1 || choice>options.size())
            continue;

        current_scene = resolveChoice(options[choice-1]);
    }
}

};

/* ================= MAIN ================= */

int main(){

    Game game;

    game.menu();

    game.loadScenes("Scenarios.csv");
    game.loadChoices("Choice.csv");
    game.loadCombat("Combat.csv");
    game.loadPuzzle("Puzzle.csv");
    game.loadTrade("Trade.csv");

    game.start();

    return 0;
}
```

---

### STAGE 3

------------------------------------------------------------------------------------------------------------------------------

#### Introduction

-------------------------------------------

The purpose of this program is to develop a text-based adventure game. The project aims to demonstrate proficiency in Object - riented Programming (OOP) principles, with error handling and program design techniques in order to build an interactive game system. The game allows the player to explore a fictional desert world called Golden Dunes, where the player travels through different scenarios, solves puzzles, fights enemies, and makes choices that influence the story.

Text based adventure games rely entirely on written descriptions and user input rather than graphics. The player interacts with the game by selecting choices that determine the direction of the story. Each decision leads to different outcomes such as combat encounters, puzzles, or trading opportunities. The game also demonstrates good programming practices including modular code structure, error handling, and data driven design using external CSV files.

------------------------------------------------------------------------------------------------------------------------------

#### Analysis and Design

------------------------------------------------------------------------------

##### Program Specification

The goal of the program is to create an interactive adventure game where players travel across a desert environment and make decisions that influence their survival and progress.

The main features of the program include:

- The main features of the program include:

- Multiple scenarios that describe locations in the game

- Binary choices allowing the player to decide how to proceed

- Combat encounters with enemies

- Trading interactions where gold can be gained

- External data files used to define scenes, puzzles, enemies, and trades

- Puzzle challenges that require the player to answer questions

- Trading interactions where gold can be gained

- External data files used to define scenes, puzzles, enemies, and trades

The game progresses by loading different scenes from external files (CSVs) and presenting choices to the player until the story reaches an ending.

##### Inputs, Processes and Outputs

| **Input**                                                                | **Process**                                                                                          | **Output**                                                            |
| ------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------- |
| Player name entered at game start                                        | Program stores the name using setName() and initializes player stats                                 | Player name displayed during gameplay                                 |
| CSV files (Scenarios.csv, Choice.csv, Combat.csv, Puzzle.csv, Trade.csv) | Game loads data using file streams and stringstream parsing                                          | Game scenes, choices, puzzles, enemies, and trades become available   |
| Player selects menu option (Start, Load, Instructions, Exit)             | Menu function processes user input and runs the appropriate function                                 | Game starts, saved game loads, instructions shown, or program exits   |
| Player selects a story choice                                            | Program checks the selected choice and determines result type (combat, puzzle, trade, or next scene) | Game progresses to the next scene or event                            |
| Combat encounter triggered                                               | Player attack reduces enemy HP, enemy attack damages player considering defense                      | Enemy defeated, player damaged, or game over                          |
| Puzzle answer entered by player                                          | Program compares input with the correct puzzle answer                                                | Correct answer increases score, wrong answer moves to alternate scene |
| Trade decision (Accept/Decline)                                          | If accepted, player receives an item and score increases                                             | Item added to inventory and player stats increase                     |
| Player chooses **Save Game**                                             | Game writes player name, health, score, current scene, and inventory to file                         | Save file created                                                     |
| Player chooses **Load Game**                                             | Program reads saved data and restores player state                                                   | Previous game progress restored                                       |
| Player selects **Inventory**                                             | Game reads inventory vector and prints collected items                                               | Inventory list displayed to player                                    |

------------------------------------------------------------------------------------------

##### Algorithms

**Game Start Algorithm**

This algorithm initializes the game. It displays the main menu and allows the player to choose between starting a new game, loading a saved game, viewing instructions, or exiting the program. If the player starts a new game, the system asks for the player’s name and initializes the player’s starting attributes.

```
START

PRINT "===== GOLDEN DUNES ====="
PRINT "1 Start Game"
PRINT "2 Load Game"
PRINT "3 Instructions"
PRINT "4 Exit"

READ userChoice

IF userChoice IS 1 THEN
    PRINT "Enter your name"
    READ playerName
    SET player health TO 100
    SET player score TO 0
    SET current scene TO first scene
    CALL GameLoop

ELSE IF userChoice IS 2 THEN
    CALL LoadGame
    CALL GameLoop

ELSE IF userChoice IS 3 THEN
    PRINT "Explore the desert, solve puzzles and defeat enemies"

ELSE IF userChoice IS 4 THEN
    PRINT "Exiting game"
END IF

ENDop
END
```

**Scene Algorithm**

This algorithm controls how the player progresses through the story. The game displays the description of the current scene and presents the available choices. Based on the player's selected option, the program determines and loads the next scene

```
START

PRINT current scene description

GET list of choices for current scene

FOR EACH choice IN choices
    PRINT choice number and description
END FOR

READ playerChoice

IF playerChoice IS valid THEN
    SET current scene TO next scene linked to the choice
END IF

END scene
END WHILE
```

**Combat Algorithm**

This algorithm manages battles between the player and enemies. The player attacks the enemy, reducing the enemy's health, while the enemy attacks the player. The player's defense reduces the damage taken. If the enemy’s health reaches zero the player wins; if the player's health reaches zero the game ends.

```
START

PRINT enemy appears

SET enemyHealth TO enemy starting health

SET enemyHealth TO enemyHealth - playerAttack

IF enemyHealth IS LESS OR EQUAL TO 0 THEN
    PRINT "Enemy defeated"
    ADD 50 TO player score
    MOVE TO nextWin scene

ELSE
    SET damage TO enemyAttack - playerDefense

    IF damage IS LESS THAN 0 THEN
        SET damage TO 0
    END IF

    SET playerHealth TO playerHealth - damage

    IF playerHealth IS LESS OR EQUAL TO 0 THEN
        PRINT "Game Over"
    END IF

END IF

END
```

**Puzzle System algorithm**

This algorithm presents a puzzle question to the player and waits for an answer. The program checks whether the player's answer matches the correct answer. If the answer is correct, the player gains points and moves to the success scene. If incorrect, the game continues to an alternate scene.

```
START

PRINT puzzle question

READ playerAnswer

IF playerAnswer IS equal to correctAnswer THEN
    PRINT "Correct"
    ADD 30 TO player score
    MOVE TO correct scene

ELSE
    PRINT "Wrong"
    MOVE TO wrong scene
END IF

END
```

**Trade algorithm**

This algorithm allows the player to accept or decline a trade offer. If the player accepts, the player receives an item that is added to the inventory and the player’s score increases. If the player declines, the game proceeds without giving the item.

```
START

PRINT "Accept trade? (y/n)"

READ playerDecision

IF playerDecision IS "y" THEN
    CREATE item Desert Sword
    ADD item TO player inventory
    INCREASE player attack
    ADD 10 TO player score
    MOVE TO accept scene

ELSE
    MOVE TO decline scene
END IF

END
```

**Inventory algorithm**

This algorithm manages the player's inventory. It stores all items collected during the game and allows the player to view the list of items at any time. Items may also modify the player's attributes such as attack, defense, or health.

```
START

IF inventory IS empty THEN
    PRINT "Inventory empty"

ELSE
    FOR EACH item IN inventory
        PRINT item name and type
    END FOR
END IF

END
```

**Save Game algorithm**

This algorithm saves the current game progress to a file. It stores important information such as the player's name, health, score, current scene, and inventory so the player can continue the game later.

```
START

OPEN save file

WRITE player name TO file
WRITE player health TO file
WRITE player score TO file
WRITE current scene TO file

WRITE number of items in inventory

FOR EACH item IN inventory
    WRITE item name
    WRITE item type
    WRITE item attack
    WRITE item defense
    WRITE item health
END FOR

PRINT "Game Saved"

END
```

**Load Game algorithm**

This algorithm loads previously saved game data. The program reads the saved file and restores the player's statistics, inventory items, and the scene where the game was last saved, allowing the player to continue from that point.

```
START

OPEN save file

IF file does not exist THEN
    PRINT "No save file found"

ELSE
    READ player name
    READ player health
    READ player score
    READ current scene

    READ number of inventory items

    FOR i FROM 1 TO number of items
        READ item information
        ADD item TO inventory
    END FOR

    PRINT "Game Loaded"
END IF

ENDdingly
```

------------------------------------------------------------------------------------------------------------------------------

#### Testing

--------------------------------------------------------------

Black box testing checks whether the system behaves correctly based on user input, without examining the internal code structure.

| **Test No** | **Feature Tested**     | **Input**                                        | **Expected Output**                                    | **Actual Output**           | **Status** |
| ----------- | ---------------------- | ------------------------------------------------ | ------------------------------------------------------ | --------------------------- | ---------- |
| 1           | Start Game             | Select menu option **1**                         | Game asks player to enter name and starts first scene  | Game starts correctly       | Pass       |
| 2           | Load Game              | Select menu option **2** with existing save file | Saved game loads and player continues from saved scene | Game loads correctly        | Pass       |
| 3           | Invalid Menu Input     | Enter a letter instead of a number               | Program ignores invalid input and asks again           | Input validation works      | Pass       |
| 4           | Scene Choice Selection | Enter choice **1 or 2**                          | Game moves to the next scene                           | Scene changes correctly     | Pass       |
| 5           | Combat System          | Choose a combat option                           | Enemy appears and player attacks enemy                 | Combat result displayed     | Pass       |
| 6           | Puzzle System          | Enter correct puzzle answer                      | Message "Correct!" and score increases                 | Correct answer accepted     | Pass       |
| 7           | Puzzle System (Wrong)  | Enter wrong answer                               | Message "Wrong!" and alternate scene triggered         | Wrong answer handled        | Pass       |
| 8           | Trade System           | Enter **y** to accept trade                      | Item added to inventory and stats increase             | Item collected successfully | Pass       |
| 9           | Save Game              | Select **Save Game option**                      | Game progress stored in save file                      | Save file created           | Pass       |
| 10          | Load Saved Game        | Load previously saved game                       | Player health, score, scene and inventory restored     | Game restored correctly     | Pass       |
| 11          | Inventory Display      | Select **Inventory option**                      | List of collected items displayed                      | Inventory displayed         | Pass       |
| 12          | Game Over              | Player health reaches **0**                      | Game Over screen appears with restart option           | Game ends correctly         | Pass       |

--------------------------------------------------------------------------------------

##### Technical Elements

This project was implemented using C++ and follows an object-oriented programming approach. Several technical concepts and standard library components were used to support the functionality of the game.

**Programming Language**: The program was developed using C++17 standard , which supports object - oriented programming and efficient memory management.

**Object - Oriented Design**: The system uses multiple classes to organise the program into logical components;

- <u>Item Class</u> - Represents items that the player can collect. Items can modify player attributes such as attack, defense, or health.

- <u>Player Class</u> - Stores player information including name, health, attack, defense, score, and inventory.

- <u>Scene Class</u> - Represents a story scene containing the description shown to the player.

- <u>Choice Class</u> - Stores the options available to the player and determines the next action or scene.

- <u>Combat, Puzzle, and Trade Classes</u> - Manage different gameplay events such as fighting enemies, solving puzzles, and accepting trades.

- <u>Game Class</u>  - Controls the overall game flow including the menu, scene navigation, saving, and loading.

**Data Structures**

<u>Vector</u>

- Allows dynamic storage that can grow as new items are collected.

- Used to store lists of items and player choices.

<u>Map</u>

- Used to store scenes, combats, puzzles, and trades.

- Enables fast lookup using unique identifiers from the CSV files.

**File Handling**

File input & output is used to support two major features:

<u>CSV Data Loading</u>

- The game reads story elements such as scenes, choices, puzzles, combats, and trades from CSV files.

- This allows the story content to be modified without changing the program code.

<u>Save and Load System</u>

- Game progress is stored in a text file (savegame.txt).

- The program records player statistics, current scene, and inventory so the player can continue the game later.

**Input Validation**

Basic input validation is implemented using cin.fail() to handle invalid user inputs and prevent program crashes when non-numeric values are entered.

---

#### Referencing

------------------------------------------------------------------------------------------------------------------------------

cplusplus.com (n.d.). *C++ File Input/Output*. Retrieved from: https://cplusplus.com/doc/tutorial/files/
 [Accessed 20 January 2026].

GeeksforGeeks (n.d.). *Vector in C++ STL*. Retrieved from: https://www.geeksforgeeks.org/vector-in-cpp-stl/
 [Accessed 20 January 2026].

Stackoverflow (n.d.). *Reading CSV files in C++*. Retrieved from: https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
 [Accessed 20 January 2026].

W3Schools (n.d.). *C++ File Handling*. Retrieved from: https://www.w3schools.com/cpp/cpp_files.asp
 [Accessed 20 January 2026].

------------------------------------------------------------------------------------------------------------------------------

#### Appendix Code Listing

------------------------------------------------------------------------------------------------------------------------------

The program is a console-based adventure game called Desert Quest developed in C++ using object-oriented programming. The game uses several classes such as Player, Scene, Choice, Combat, Puzzle, Trade, and Item to organise the game structure. The main game system controls the flow of the game, loads data from CSV files, and manages player interactions.

During gameplay, the player navigates through scenes by selecting choices that may lead to combat, puzzles, or trade events. The Player class manages the player’s health, score, attack, defense, and inventory items. The program also includes save and load functionality so that the player’s progress and game state can be stored and restored.

------------------------------------------------------------------------------------

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

/* ================= ITEM ================= */

class Item {
public:
    string name;
    string type;
    float attack;
    float defense;
    float health;

    Item(){}

    Item(string n,string t,float a,float d,float h){
        name=n;
        type=t;
        attack=a;
        defense=d;
        health=h;
    }
};

/* ================= PLAYER ================= */

class Player {

private:

    string name;
    float health = 100;
    float attack = 5;
    float defense = 2;
    int score = 0;

public:

    vector<Item> inventory;

    void setName(string n){
        name=n;
    }

    string getName(){
        return name;
    }

    float getHealth(){
        return health;
    }

    float getAttack(){
        return attack;
    }

    float getDefense(){
        return defense;
    }

    int getScore(){
        return score;
    }

    void setHealth(float h){
        health=h;
    }

    void setScore(int s){
        score=s;
    }

    void damage(float d){

        float finalDamage = d - defense;

        if(finalDamage < 0)
            finalDamage = 0;

        health -= finalDamage;

        if(health < 0)
            health = 0;
    }

    void heal(float h){
        health += h;
    }

    void addScore(int s){
        score += s;
    }

    void addItem(Item item){

        inventory.push_back(item);

        attack += item.attack;
        defense += item.defense;
        health += item.health;

        cout << "\nItem collected: " << item.name << endl;
    }

    void showInventory(){

        cout << "\n--- INVENTORY ---\n";

        if(inventory.empty()){
            cout << "Inventory empty\n";
            return;
        }

        for(Item i : inventory){
            cout << i.name << " (" << i.type << ")\n";
        }
    }

    void showStats(){

        cout << "\n--- PLAYER STATS ---\n";
        cout << "Health: " << health << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Score: " << score << endl;
    }
};

/* ================= STORY STRUCTURES ================= */

class Scene{

public:
    string id;
    string description;

    Scene(){}

    Scene(string i,string d){
        id=i;
        description=d;
    }
};

class Choice{

public:

    string parentScene;
    string text;
    string resultType;
    string resultID;
    string nextScene;

    // Default constructor (needed for vector)
    Choice(){}

    Choice(string p,string t,string r,string id,string n){
        parentScene = p;
        text = t;
        resultType = r;
        resultID = id;
        nextScene = n;
    }
};

class Combat{

public:
    string enemyName;
    float enemyHP;
    float enemyAttack;
    string nextWin;
    string nextLose;
};

class Puzzle{

public:
    string question;
    string answer;
    string nextCorrect;
    string nextWrong;
};

class Trade{

public:
    float goldReward;
    string nextAccept;
    string nextDecline;
};

/* ================= GAME ================= */

class Game{

private:

    map<string,Scene> scenes;
    vector<Choice> choices;
    map<string,Combat> combats;
    map<string,Puzzle> puzzles;
    map<string,Trade> trades;

    Player player;

    string current_scene;
    string last_scene_shown;

public:

/* ================= MENU ================= */

void menu(){

    int choice;

    while(true){

        cout << "\n===== GOLDEN DUNES =====\n";
        cout << "1 Start Game\n";
        cout << "2 Load Game\n";
        cout << "3 Instructions\n";
        cout << "4 Exit\n";
        cout << "Choice: ";

        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }

        if(choice==1) return;

        if(choice==2){

            if(loadGame()){
                return;
            }
        }

        if(choice==3){

            cout << "\nExplore the desert, solve puzzles and defeat enemies.\n";
            cout << "Collect items to increase your power.\n";
        }

        if(choice==4){
            exit(0);
        }
    }
}

/* ================= CSV LOADERS ================= */

void loadScenes(string file){

    ifstream f(file);
    string line;

    getline(f,line);

    while(getline(f,line)){

        string id,desc;

        stringstream ss(line);

        getline(ss,id,',');
        getline(ss,desc);

        scenes[id] = Scene(id,desc);

        if(current_scene=="")
            current_scene=id;
    }
}

void loadChoices(string file){

    ifstream f(file);
    string line;

    getline(f,line);

    while(getline(f,line)){

        string cid,parent,text,type,rid,next;

        stringstream ss(line);

        getline(ss,cid,',');
        getline(ss,parent,',');
        getline(ss,text,',');
        getline(ss,type,',');
        getline(ss,rid,',');
        getline(ss,next);

        choices.push_back(Choice(parent,text,type,rid,next));
    }
}

    void loadCombat(string file){

    ifstream f(file);
    string line;

    getline(f,line);

    while(getline(f,line)){

        if(line.empty()) continue;

        string id,name,hp,atk,rew,win,lose;

        stringstream ss(line);

        getline(ss,id,',');
        getline(ss,name,',');
        getline(ss,hp,',');
        getline(ss,atk,',');
        getline(ss,rew,',');
        getline(ss,win,',');
        getline(ss,lose);

        Combat c;

        try{

            c.enemyName = name;
            c.enemyHP = stof(hp);
            c.enemyAttack = stof(atk);
            c.nextWin = win;
            c.nextLose = lose;

            combats[id] = c;

        }catch(...){

            cout << "Combat CSV error skipped: " << line << endl;
        }
    }
}

void loadPuzzle(string file){

    ifstream f(file);
    string line;

    getline(f,line);

    while(getline(f,line)){

        string id,q,a,correct,wrong;

        stringstream ss(line);

        getline(ss,id,',');
        getline(ss,q,',');
        getline(ss,a,',');
        getline(ss,correct,',');
        getline(ss,wrong);

        Puzzle p;

        p.question=q;
        p.answer=a;
        p.nextCorrect=correct;
        p.nextWrong=wrong;

        puzzles[id]=p;
    }
}

    void loadTrade(string file){

    ifstream f(file);
    string line;

    getline(f,line);

    while(getline(f,line)){

        if(line.empty()) continue;

        string id,item,gold,give,accept,decline;

        stringstream ss(line);

        getline(ss,id,',');
        getline(ss,item,',');
        getline(ss,gold,',');
        getline(ss,give,',');
        getline(ss,accept,',');
        getline(ss,decline);

        Trade t;

        try{

            t.goldReward = stof(gold);
            t.nextAccept = accept;
            t.nextDecline = decline;

            trades[id] = t;

        }catch(...){

            cout << "Trade CSV error skipped: " << line << endl;
        }
    }
}

/* ================= GAME FUNCTIONS ================= */

vector<Choice> getChoices(string sceneID){

    vector<Choice> result;

    for(Choice c:choices){

        if(c.parentScene==sceneID)
            result.push_back(c);
    }

    if(result.size() > 2){
        result.erase(result.begin() + 2, result.end());
    }

    return result;
}

void showScene(){

    if(current_scene != last_scene_shown){

        cout << "\nThe desert wind howls across the dunes.\n";
        cout << player.getName() << ", your journey continues...\n";

        last_scene_shown=current_scene;
    }

    cout << "\n" << scenes[current_scene].description << endl;
}

/* ================= COMBAT ================= */

bool fightEnemy(Combat enemy){

    cout << "\nEnemy appears: " << enemy.enemyName << endl;

    enemy.enemyHP -= player.getAttack();

    if(enemy.enemyHP <= 0){

        cout << "Enemy defeated!\n";

        player.addScore(50);

        return true;
    }

    player.damage(enemy.enemyAttack);

    if(player.getHealth() <= 0){

        cout << "You were defeated.\n";

        return false;
    }

    return true;
}

/* ================= CHOICE RESOLUTION ================= */

string resolveChoice(Choice c){

    if(c.resultType=="COMBAT"){

        Combat enemy = combats[c.resultID];

        if(fightEnemy(enemy))
            return enemy.nextWin;
        else
            gameOver();
    }

    if(c.resultType=="PUZZLE"){

        Puzzle p = puzzles[c.resultID];

        cout << p.question << endl;

        string ans;
        cin >> ans;

        if(ans == p.answer){

            cout << "Correct!\n";
            player.addScore(30);
            return p.nextCorrect;
        }
        else{

            cout << "Wrong!\n";
            return p.nextWrong;
        }
    }

    if(c.resultType=="TRADE"){

        Trade t = trades[c.resultID];

        char ch;

        cout << "Accept trade? (y/n): ";
        cin >> ch;

        if(ch=='y'){

            player.addScore(10);

            Item reward("Desert Sword","weapon",5,0,0);
            player.addItem(reward);

            return t.nextAccept;
        }

        return t.nextDecline;
    }

    return c.nextScene;
}

/* ================= SAVE SYSTEM ================= */

void saveGame(){

    ofstream save("savegame.txt");

    save << player.getName() << endl;
    save << current_scene << endl;
    save << player.getHealth() << endl;
    save << player.getScore() << endl;

    save << player.inventory.size() << endl;

    for(Item i:player.inventory){

        save << i.name << ","
             << i.type << ","
             << i.attack << ","
             << i.defense << ","
             << i.health << endl;
    }

    save.close();

    cout << "Game Saved.\n";
}

/* ================= LOAD SYSTEM ================= */

bool loadGame(){

    ifstream save("savegame.txt");

    if(!save){

        cout << "No save file found.\n";
        return false;
    }

    string name;

    getline(save,name);
    player.setName(name);

    getline(save,current_scene);

    float h;
    save >> h;
    player.setHealth(h);

    int s;
    save >> s;
    player.setScore(s);

    int count;
    save >> count;

    save.ignore();

    for(int i=0;i<count;i++){

        string line;

        getline(save,line);

        stringstream ss(line);

        string n,t,a,d,h;

        getline(ss,n,',');
        getline(ss,t,',');
        getline(ss,a,',');
        getline(ss,d,',');
        getline(ss,h,',');

        try{

            Item item(n,t,stof(a),stof(d),stof(h));
            player.inventory.push_back(item);

        }catch(...){

            cout << "Invalid item in save file skipped\n";
        }
    }

    cout << "Game Loaded.\n";

    return true;
}

/* ================= GAME OVER ================= */

void gameOver(){

    cout << "\n===== GAME OVER =====\n";

    cout << "Score: " << player.getScore() << endl;

    int c;

    cout << "1 Restart\n";
    cout << "2 Exit\n";

    cin >> c;

    if(c==1){

        start();
    }
    else{
        exit(0);
    }
}

/* ================= MAIN GAME LOOP ================= */

void start(){

    if(player.getName()==""){

        cout << "Enter your name: ";
        string n;
        cin >> n;

        player.setName(n);
    }

    while(true){

        showScene();

        player.showStats();

        vector<Choice> options = getChoices(current_scene);

        if(options.empty()){

            cout << "\n===== VICTORY =====\n";
            cout << "Final Score: " << player.getScore() << endl;

            player.showInventory();

            break;
        }

        cout << "\nChoices:\n";

        for(int i=0;i<options.size();i++){

            cout << i+1 << ". " << options[i].text << endl;
        }

        cout << "3 Save Game\n";
        cout << "4 Inventory\n";

        int choice;

        while(true){

            cout << "Choice: ";
            cin >> choice;

            if(cin.fail()){

                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }

            break;
        }

        if(choice==3){

            saveGame();
            continue;
        }

        if(choice==4){

            player.showInventory();
            continue;
        }

        if(choice<1 || choice>options.size())
            continue;

        current_scene = resolveChoice(options[choice-1]);
    }
}

};

/* ================= MAIN ================= */

int main(){

    Game game;

    game.menu();

    game.loadScenes("Scenarios.csv");
    game.loadChoices("Choice.csv");
    game.loadCombat("Combat.csv");
    game.loadPuzzle("Puzzle.csv");
    game.loadTrade("Trade.csv");

    game.start();

    return 0;
}
```

------------------------------------------------------------------------------------------------------------------------------
