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
private:
    string name;
    float health;
    float gold;

public:
    Player() {
        name = "Player";
        health = 100;
        gold = 50;
    }

    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    float getHealth() {
        return health;
    }

    float getGold() {
        return gold;
    }

    void addGold(float g) {
        gold += g;
    }

    void damage(float d) {
        health -= d;
        if (health < 0) health = 0;
    }

    void showStatus() {
        cout << "\n--- PLAYER STATUS ---\n";
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Gold: " << gold << endl;
    }
};
// Scene
class Scene {
public:
    string id;
    string description;

    Scene() {}

    Scene(string i, string d) {
        id = i;
        description = d;
    }
};

// Choice
class Choice {
public:
    string parentScene;
    string text;
    string resultType;
    string resultID;
    string nextScene;

    Choice(string p, string t, string r, string id, string n) {
        parentScene = p;
        text = t;
        resultType = r;
        resultID = id;
        nextScene = n;
    }
};

// Combat
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

//Trade
class Trade{

public:
    float goldReward;
    string nextAccept;
    string nextDecline;
};

// Updated Item
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


    //Menu
    void menu(){

        int choice;

        while(true){

            cout << "\n===== DESERT QUEST =====\n";
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


// Main
int main() {

    srand(time(0));

    Game game;

    game.mainMenu();

    return 0;
}
