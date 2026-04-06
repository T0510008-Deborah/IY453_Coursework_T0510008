#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

/ Item Class
class Item {
private:
    int id;
    string name;
    string category;
    int price;
    int weight;
    string description;
    string effect;

public:

    Item() : id(0), price(0), weight(0) {}


    Item(int id, string name, string category, int price, int weight, string description, string effect)
        : id(id), name(name), category(category), price(price),
          weight(weight), description(description), effect(effect) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getCategory() const { return category; }
    int getPrice() const { return price; }
    int getWeight() const { return weight; }
    string getDescription() const { return description; }
    string getEffect() const { return effect; }
};

// Occupation Class
class Occupation {
private:
    string gender;
    string name;
    int startingGold;
    string description;

public:

    Occupation() : startingGold(0) {}

    Occupation(string gender, string name, int startingGold, string description)
        : gender(gender), name(name), startingGold(startingGold), description(description) {}

    string getGender() const { return gender; }
    string getName() const { return name; }
    int getStartingGold() const { return startingGold; }
    string getDescription() const { return description; }
};

// Story Class
class Story {
private:
    string stage;
    string text;

public:

    Story() {}

    Story(string stage, string text) : stage(stage), text(text) {}

    string getStage() const { return stage; }
    string getText() const { return text; }
};

//Scene Class
class Scene {
private:
    string id;
    string description;

public:

    Scene() {}

    Scene(string i, string d) : id(i), description(d) {}

    string getId() const { return id; }
    string getDescription() const { return description; }
};

// Choice Class
class Choice {
private:
    string parentScene;
    string text;
    string resultType;
    string resultID;
    string nextScene;

public:

    Choice() {}


    Choice(string p, string t, string r, string id, string n)
        : parentScene(p), text(t), resultType(r), resultID(id), nextScene(n) {}

    string getParentScene() const { return parentScene; }
    string getText() const { return text; }
    string getResultType() const { return resultType; }
    string getResultID() const { return resultID; }
    string getNextScene() const { return nextScene; }
};

// Combat Class
class Combat {
private:
    string enemyName;
    float enemyHP;
    float enemyAttack;
    string nextWin;
    string nextLose;

public:

    Combat() : enemyHP(0), enemyAttack(0) {}

    Combat(string name, float hp, float atk, string win, string lose)
        : enemyName(name), enemyHP(hp), enemyAttack(atk),
          nextWin(win), nextLose(lose) {}

    string getEnemyName() const { return enemyName; }
    float  getEnemyHP() const { return enemyHP; }
    float  getEnemyAttack() const { return enemyAttack; }
    string getNextWin() const { return nextWin; }
    string getNextLose() const { return nextLose; }

    void setEnemyHP(float hp) { enemyHP = hp; }
    void setEnemyAttack(float atk) { enemyAttack = atk; }
    void setEnemyName(string n) { enemyName = n; }
    void setNextWin(string w) { nextWin = w; }
    void setNextLose(string l) { nextLose = l; }
};

// Puzzle Class
class Puzzle {
private:
    string question;
    string answer;
    string nextCorrect;
    string nextWrong;

public:

    Puzzle() {}

    Puzzle(string q, string a, string correct, string wrong)
        : question(q), answer(a), nextCorrect(correct), nextWrong(wrong) {}

    string getQuestion() const { return question; }
    string getAnswer() const { return answer; }
    string getNextCorrect() const { return nextCorrect; }
    string getNextWrong() const { return nextWrong; }

    void setQuestion(string q) { question = q; }
    void setAnswer(string a) { answer = a; }
    void setNextCorrect(string c) { nextCorrect = c; }
    void setNextWrong(string w)  { nextWrong = w; }
};

//Trade
class Trade{

public:
    float goldReward;
    string nextAccept;
    string nextDecline;
};

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

/* ================= CSV LOADERS ================= */

    void loadScenes(string file)
{
    ifstream f(file);
    string line;

    getline(f, line); // skip header

    while(getline(f, line))
    {
        if(line.empty()) continue;

        string id, desc;

        size_t commaPos = line.find(',');

        id = line.substr(0, commaPos);
        desc = line.substr(commaPos + 1);

        // 🔥 HANDLE MULTI-LINE QUOTED TEXT
        if(!desc.empty() && desc.front() == '"')
        {
            desc.erase(0, 1); // remove opening quote

            while(desc.back() != '"')
            {
                string nextLine;
                getline(f, nextLine);
                desc += "\n" + nextLine;
            }

            desc.pop_back(); // remove closing quote
        }

        scenes[id] = Scene(id, desc);

        if(current_scene == "")
            current_scene = id;
    }
}

// void loadScenes(string file){
//
//     ifstream f(file);
//     string line;
//
//     getline(f,line);
//
//     while(getline(f,line)){
//
//         string id,desc;
//
//         stringstream ss(line);
//
//         getline(ss,id,',');
//         getline(ss,desc);
//
//         scenes[id] = Scene(id,desc);
//
//         if(current_scene=="")
//             current_scene=id;
//     }
// }

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

        cout << "\n" << p.question << endl;
        cout << "Your answer: ";

        string ans;
        cin.ignore();
        getline(cin, ans);

        // convert to lowercase
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);

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

    // if(c.resultType=="PUZZLE"){
    //
    //     Puzzle p = puzzles[c.resultID];
    //
    //     cout << p.question << endl;
    //
    //     string ans;
    //     cin >> ans;
    //
    //     if(ans == p.answer){
    //
    //         cout << "Correct!\n";
    //         player.addScore(30);
    //         return p.nextCorrect;
    //     }
    //     else{
    //
    //         cout << "Wrong!\n";
    //         return p.nextWrong;
    //     }
    // }

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

// Main
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

