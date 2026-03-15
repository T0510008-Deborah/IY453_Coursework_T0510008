# IY453 Stage 2

| Assessment Details | Please Complete All Details        |
| ------------------ | ---------------------------------- |
| Group              | B                                  |
| Module Title       | Software Design and Implementation |
| Assessment Type    | Stage2                             |
| Module Tutor Name  | Jonathan Shore                     |
| Student ID Number  | P510008                            |
| Date of Submission | 13th February 2026                 |
| Word Count         | 1989                               |

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
