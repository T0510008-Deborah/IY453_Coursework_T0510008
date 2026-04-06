#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

// Item Class
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

// Trade Class
class Trade {
private:
    string itemRequired;
    float goldReward;
    string itemGiven;
    string nextAccept;
    string nextDecline;

public:

    Trade() : goldReward(0) {}

    Trade(string req, float gold, string given, string accept, string decline)
        : itemRequired(req), goldReward(gold), itemGiven(given),
          nextAccept(accept), nextDecline(decline) {}

    string getItemRequired() const { return itemRequired; }
    float  getGoldReward() const { return goldReward; }
    string getItemGiven() const { return itemGiven; }
    string getNextAccept() const { return nextAccept; }
    string getNextDecline() const { return nextDecline; }

    void setItemRequired(string r) { itemRequired = r; }
    void setGoldReward(float g) { goldReward = g; }
    void setItemGiven(string gi) { itemGiven = gi; }
    void setNextAccept(string a) { nextAccept = a; }
    void setNextDecline(string d) { nextDecline = d; }
};

// Player Class
class Player {
private:
    string name;
    int gold;
    int maxCarryWeight;
    int currentWeight;
    int foodSupply;
    int hp;
    int attack;
    int heatResist;
    int stormResist;
    int travelSpeed;
    vector<Item> inventory;
    vector<Item> shopItems;
    vector<Occupation> occupations;
    vector<Story> stories;

public:

    Player()
        : name("Traveler"), gold(0), maxCarryWeight(100), currentWeight(0), foodSupply(0), hp(100), attack(5),
          heatResist(0), stormResist(0), travelSpeed(1) {}

    Player(string playerName)
        : name(playerName), gold(0), maxCarryWeight(100), currentWeight(0), foodSupply(0), hp(100), attack(5),
          heatResist(0), stormResist(0), travelSpeed(1) {}

    string getName() const { return name; }
    int getGold() const { return gold; }
    int getMaxCarryWeight() const { return maxCarryWeight; }
    int getCurrentWeight() const { return currentWeight; }
    int getFoodSupply() const { return foodSupply; }
    int getHP() const { return hp; }
    int getAttack() const { return attack; }
    int getHeatResist() const { return heatResist; }
    int getStormResist() const { return stormResist; }
    int getTravelSpeed() const { return travelSpeed; }
    vector<Item>& getInventory() { return inventory; }
    const vector<Item>& getInventory() const { return inventory; }
    vector<Item>& getShopItems() { return shopItems; }
    vector<Occupation>& getOccupations() { return occupations; }
    vector<Story>& getStories() { return stories; }


    void setName(string n) { name = n; }
    void setGold(int g) { gold = g; }
    void setHP(int h) { hp = h; }
    void setAttack(int a) { attack = a; }
    void setHeatResist(int h){ heatResist = h; }
    void setStormResist(int s) { stormResist = s; }
    void setTravelSpeed(int t) { travelSpeed = t; }
    void setFoodSupply(int f) { foodSupply = f; }
    void setCurrentWeight(int w) { currentWeight = w; }

    void addGold(int amount) { gold += amount; }
    void subtractGold(int amount) { gold -= amount; }
    void addHP(int amount) { hp += amount; }
    void subtractHP(int amount) { hp -= amount; }
    void addFood(int amount) { foodSupply += amount; }
    void subtractFood(int amount) { foodSupply -= amount; if(foodSupply < 0) foodSupply = 0; }
    void addWeight(int amount) { currentWeight += amount; }

    void addToInventory(Item item) { inventory.push_back(item); }
    void clearInventory() { inventory.clear(); }
    bool inventoryEmpty() const { return inventory.empty(); }

    void reset()
    {
        gold = 0;
        currentWeight = 0;
        foodSupply = 0;
        hp  = 100;
        attack = 5;
        heatResist = 0;
        stormResist = 0;
        travelSpeed = 1;
        inventory.clear();
    }

    void buildStats()
    {
        hp = 100;
        attack = 5;
        heatResist = 0;
        stormResist = 0;
        travelSpeed = 1;
        foodSupply = 0;

        for(auto &item : inventory)
        {
            if(item.getCategory() == "Food") {

            }
                if(item.getId() == 1) foodSupply += 6;
                if(item.getId() == 2) foodSupply += 9;
                if(item.getId() == 3) foodSupply += 7;
                if(item.getId() == 4) foodSupply += 8;
                if(item.getId() == 5) foodSupply += 10;

            if(item.getCategory() == "Clothing")
            {

                heatResist  += 10;
                stormResist += 10;
            }

            if(item.getCategory() == "Weapon")
            {
                if(item.getId() == 11) attack = 15;
                if(item.getId() == 12) attack = 18;
                if(item.getId() == 13) attack = 10;
                if(item.getId() == 14) attack = 25;
                if(item.getId() == 15) attack = 20;
            }

            if(item.getCategory() == "Animal")
            {
                if(item.getId() == 16) travelSpeed = 3;
                if(item.getId() == 17) travelSpeed = 2;
                if(item.getId() == 18) travelSpeed = 1;
                if(item.getId() == 19) travelSpeed = 3;
                if(item.getId() == 20) travelSpeed = 4;
            }
        }
    }
};

// CSV Loader Class
class CsvLoader {
public:
    static void loadScenes(const string &file, map<string, Scene> &scenes, string &firstScene)
    {
        ifstream f(file);
        string line;
        getline(f, line);

        while(getline(f, line))
        {
            if(line.empty()) continue;
            string id, desc;
            size_t commaPos = line.find(',');
            id   = line.substr(0, commaPos);
            desc = line.substr(commaPos + 1);

            if(!desc.empty() && desc.front() == '"')
            {
                desc.erase(0, 1);
                while(desc.back() != '"')
                {
                    string nextLine;
                    getline(f, nextLine);
                    desc += "\n" + nextLine;
                }
                desc.pop_back();
            }
            scenes[id] = Scene(id, desc);
            if(firstScene == "") firstScene = id;
        }
    }

    static void loadChoices(const string &file, vector<Choice> &choices)
    {
        ifstream f(file);
        string line;
        getline(f, line);

        while(getline(f, line))
        {
            if(line.empty()) continue;
            string cid, parent, text, type, rid, next;
            stringstream ss(line);
            getline(ss, cid, ',');
            getline(ss, parent, ',');
            getline(ss, text, ',');
            getline(ss, type, ',');
            getline(ss, rid, ',');
            getline(ss, next);
            choices.push_back(Choice(parent, text, type, rid, next));
        }
    }

static void loadCombat(const string &file, map<string, Combat> &combats)
    {
        ifstream f(file);
        string line;
        getline(f, line);

        while(getline(f, line))
        {
            if(line.empty()) continue;
            string id, name, hp, atk, rew, win, lose;
            stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, hp, ',');
            getline(ss, atk, ',');
            getline(ss, rew, ',');
            getline(ss, win, ',');
            getline(ss, lose);
            try {
                Combat c(name, stof(hp), stof(atk), win, lose);
                combats[id] = c;
            }
            catch(...) { cout << "Combat CSV error: " << line << "\n"; }
        }
    }

    static void loadPuzzle(const string &file, map<string, Puzzle> &puzzles)
    {
        ifstream f(file);
        string line;
        getline(f, line);

        while(getline(f, line))
        {
            if(line.empty()) continue;
            string id, q, a, correct, wrong;
            stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, q, ',');
            getline(ss, a, ',');
            getline(ss, correct, ',');
            getline(ss, wrong);
            Puzzle p;
            p.setQuestion(q);
            p.setAnswer(a);
            p.setNextCorrect(correct);
            p.setNextWrong(wrong);
            puzzles[id] = p;
        }
    }

    static void loadTrade(const string &file, map<string, Trade> &trades)
    {
        ifstream f(file);
        string line;
        getline(f, line);

        while(getline(f, line))
        {
            if(line.empty()) continue;
            string id, item, gld, give, accept, decline;
            stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, item, ',');
            getline(ss, gld, ',');
            getline(ss, give, ',');
            getline(ss, accept, ',');
            getline(ss, decline);
            try {
                Trade t(item, stof(gld), give, accept, decline);
                trades[id] = t;
            }
            catch(...) { cout << "Trade CSV error: " << line << "\n"; }
        }
    }

    static void loadItems(const string &file, vector<Item> &items)
    {
        ifstream f(file);
        string line;
        getline(f, line);

        while(getline(f, line))
        {
            if(line.empty()) continue;
            stringstream ss(line);
            string temp;
            try {
                int id, price, weight;
                string name, category, description, effect;
                getline(ss, temp, ',');       id = stoi(temp);
                getline(ss, name, ',');
                getline(ss, category, ',');
                getline(ss, temp, ',');       price = stoi(temp);
                getline(ss, temp, ',');       weight = stoi(temp);
                getline(ss, description, ',');
                getline(ss, effect);
                items.push_back(Item(id, name, category, price,
                                     weight, description, effect));
            }
            catch(...) { cout << "Skipping bad inventory row\n"; }
        }
    }

    static void loadOccupations(const string &file, vector<Occupation> &occupations)
    {
        ifstream f(file);
        if(!f.is_open()) { cout << "Error opening occupations.csv\n"; return; }
        string line;
        getline(f, line);

        while(getline(f, line))
        {
            if(line.empty()) continue;
            stringstream ss(line);
            string temp;
            try {
                string gender, name, description;
                int startGold;
                getline(ss, gender, ',');
                getline(ss, name, ',');
                getline(ss, temp, ',');
                temp.erase(remove(temp.begin(), temp.end(), '$'), temp.end());
                startGold = stoi(temp);
                getline(ss, description);
                occupations.push_back(Occupation(gender, name, startGold, description));
            }
            catch(...) { cout << "Skipping bad occupation row\n"; }
        }
    }

    static void loadStory(const string &file, vector<Story> &stories)
    {
        ifstream f(file);
        string line;
        getline(f, line);

        while(getline(f, line))
        {
            if(line.empty()) continue;
            string stage, text;
            size_t commaPos = line.find(',');
            stage = line.substr(0, commaPos);
            text  = line.substr(commaPos + 1);

            if(!text.empty() && text.front() == '"')
            {
                text.erase(0, 1);
                while(text.back() != '"')
                {
                    string nextLine;
                    getline(f, nextLine);
                    text += "\n" + nextLine;
                }
                text.pop_back();
            }
            stories.push_back(Story(stage, text));
        }
    }
};

// Game Class
class Game {
private:
    map<string, Scene>  scenes;
    vector<Choice> choices;
    map<string, Combat> combats;
    map<string, Puzzle> puzzles;
    map<string, Trade> trades;
    string current_scene;

    void applySceneDrain(Player &p)
    {
        int foodDrain = max(1, 3 - p.getTravelSpeed() + 1);

        bool hotScene   = (current_scene=="S2" || current_scene=="S8"  ||
                           current_scene=="S15" || current_scene=="S29" ||
                           current_scene=="S30");
        bool stormScene = (current_scene=="S3" || current_scene=="S4");

        if(hotScene)
        {
            int loss = max(0, 8 - p.getHeatResist() / 5);
            if(loss > 0)
            {
                p.subtractHP(loss);
                cout << "  [Heat]   The blazing desert scorches your caravan. -"
                     << loss << " HP\n";
            }
        }

        if(stormScene)
        {
            int loss = max(0, 6 - p.getStormResist() / 5);
            if(loss > 0)
            {
                p.subtractHP(loss);
                cout << "  [Storm]  The sandstorm batters your caravan. -"
                     << loss << " HP\n";
            }
        }

        p.subtractFood(foodDrain);

        if(p.getFoodSupply() == 0)
        {
            p.subtractHP(5);
            cout << "  [Hunger] Your supplies are exhausted. The caravan weakens. -5 HP\n";
        }
    }


    void showJourneyStatus(const Player &p)
    {
        string nameTag = "[ " + p.getName() + " ]";
        string header  = " Caravan Status " + nameTag;
        while((int)header.size() < 42) header += " ";

        cout << "\n+" << string(42, '-') << "+\n";
        cout << "| " << header << "|\n";
        cout << "+" << string(42, '-') << "+\n";

        auto row = [](string label, string value) {
            string line = "| " + label + " : " + value;
            while((int)line.size() < 43) line += " ";
            cout << line << "|\n";
        };

        row("HP       ", to_string(p.getHP()) + " / 100");
        row("Food     ", to_string(p.getFoodSupply()) + " days remaining");
        row("Gold     ", "$" + to_string(p.getGold()));
        row("Attack   ", to_string(p.getAttack()));
        row("Heat Res ", to_string(p.getHeatResist()) + "%");
        row("Storm Res", to_string(p.getStormResist()) + "%");

        cout << "+" << string(42, '-') << "+\n";
    }


    void showScene()
    {
        cout << "\n------------------------------------------------------------------\n";
        cout << scenes[current_scene].getDescription() << "\n";
        cout << "------------------------------------------------------------------\n";
    }

    vector<Choice> getChoices()
    {
        vector<Choice> result;
        for(auto &c : choices)
            if(c.getParentScene() == current_scene)
                result.push_back(c);
        if((int)result.size() > 2)
            result.erase(result.begin() + 2, result.end());
        return result;
    }

    /* ── Combat ── */
    bool fightEnemy(Combat &enemy, Player &p)
    {
        float eHP  = enemy.getEnemyHP();
        float pHP  = (float)p.getHP();
        float pAtk = (float)p.getAttack();
        float eAtk = enemy.getEnemyAttack();

        cout << "\n==================== COMBAT ====================\n";
        cout << "  Enemy    : " << enemy.getEnemyName()  << "\n";
        cout << "  Enemy HP : " << (int)eHP << "\n";
        cout << "  Your HP  : " << (int)pHP << "\n";
        cout << "  Your ATK : " << (int)pAtk << "\n";
        cout << "================================================\n";

        int round = 1;
        while(eHP > 0 && pHP > 0)
        {
            cout << "\n  -- Round " << round++ << " --\n";
            eHP -= pAtk;
            cout << "  You strike " << enemy.getEnemyName()
                 << " for " << (int)pAtk << " damage.  "
                 << "Enemy HP: " << max(0, (int)eHP) << "\n";
            if(eHP <= 0) break;
            pHP -= eAtk;
            cout << "  " << enemy.getEnemyName() << " hits you for "
                 << (int)eAtk << ".  Your HP: " << max(0, (int)pHP) << "\n";
        }

        if(pHP <= 0)
        {
            p.setHP(1);
            cout << "\n  You are badly wounded but manage to survive...\n";
            cout << "================================================\n";
            return false;
        }

        p.setHP((int)pHP);
        int reward = (int)(eAtk * 3);
        p.addGold(reward);
        cout << "\n  " << enemy.getEnemyName() << " is defeated!\n";
        cout << "  You find " << reward << " gold among their belongings.\n";
        cout << "================================================\n";
        return true;
    }

    string solvePuzzle(Puzzle &puzzle)
    {
        cout << "\n================== PUZZLE ==================\n";
        cout << "  " << puzzle.getQuestion() << "\n";
        cout << "============================================\n";
        cout << "  Your answer: ";

        string ans;
        cin.ignore();
        getline(cin, ans);

        while(!ans.empty() && ans.front() == ' ') ans.erase(ans.begin());
        while(!ans.empty() && ans.back()  == ' ') ans.pop_back();

        string ansL = ans, corL = puzzle.getAnswer();
        transform(ansL.begin(), ansL.end(), ansL.begin(), ::tolower);
        transform(corL.begin(), corL.end(), corL.begin(), ::tolower);

        if(ansL == corL)
        {
            cout << "\n  Correct! The ancient mechanism yields...\n";
            cout << "============================================\n";
            return puzzle.getNextCorrect();
        }
        else
        {
            cout << "\n  Wrong. The answer was: " << puzzle.getAnswer() << "\n";
            cout << "============================================\n";
            return puzzle.getNextWrong();
        }
    }

    string doTrade(Trade &t, Player &p)
    {
        cout << "\n================== TRADE ===================\n";
        if(!t.getItemRequired().empty())
            cout << "  You offer your " << t.getItemRequired() << " to the other party.\n";
        if(t.getGoldReward() > 0)
        {
            p.addGold((int)t.getGoldReward());
            cout << "  You receive " << (int)t.getGoldReward() << " gold in return.\n";
        }
        if(!t.getItemGiven().empty() && t.getItemGiven() != "0")
            cout << "  In exchange you receive: " << t.getItemGiven() << ".\n";
        cout << "============================================\n";
        return t.getNextAccept();
    }

    string resolveChoice(Choice &c, Player &p)
    {
        if(c.getResultType() == "COMBAT" && combats.count(c.getResultID()))
        {
            Combat &enemy = combats[c.getResultID()];
            return fightEnemy(enemy, p) ? enemy.getNextWin() : enemy.getNextLose();
        }
        if(c.getResultType() == "PUZZLE" && puzzles.count(c.getResultID()))
        {
            Puzzle &puzzle = puzzles[c.getResultID()];
            return solvePuzzle(puzzle);
        }
        if(c.getResultType() == "TRADE" && trades.count(c.getResultID()))
        {
            Trade &t = trades[c.getResultID()];
            return doTrade(t, p);
        }
        return c.getNextScene();
    }

    void saveGame(Player &p)
    {
        ofstream f("savegame.csv");
        if(!f.is_open()) { cout << "  [Save failed]\n"; return; }

        f << "field,value\n";
        f << "playerName,"   << p.getName()           << "\n";
        f << "scene,"        << current_scene         << "\n";
        f << "gold,"         << p.getGold()           << "\n";
        f << "playerHP,"     << p.getHP()             << "\n";
        f << "playerAttack," << p.getAttack()         << "\n";
        f << "heatResist,"   << p.getHeatResist()     << "\n";
        f << "stormResist,"  << p.getStormResist()    << "\n";
        f << "travelSpeed,"  << p.getTravelSpeed()    << "\n";
        f << "foodSupply,"   << p.getFoodSupply()     << "\n";
        f << "currentWeight,"<< p.getCurrentWeight()  << "\n";

        for(auto &item : p.getInventory())
            f << "inventory," << item.getId() << "\n";

        f.close();
        cout << "  [Game saved.]\n";
    }

public:

    void setStartScene(string s) { current_scene = s; }

    void loadScenes(string file)
    {
        CsvLoader::loadScenes(file, scenes, current_scene);
    }
    void loadChoices(string file)
    {
        CsvLoader::loadChoices(file, choices);
    }
    void loadCombat(string file)
    {
        CsvLoader::loadCombat(file, combats);
    }
    void loadPuzzle(string file)
    {
        CsvLoader::loadPuzzle(file, puzzles);
    }
    void loadTrade(string file)
    {
        CsvLoader::loadTrade(file, trades);
    }

    void start(Player &p, bool buildStatsFirst = true)
    {
        if(current_scene == "")
        {
            cout << "\n[No starting scene found.]\n";
            return;
        }

        if(buildStatsFirst)
            p.buildStats();

        cout << "\n==================================================================\n";
        cout << "                    THE JOURNEY BEGINS\n";
        cout << "==================================================================\n";
        showJourneyStatus(p);

        while(true)
        {
            if(scenes.find(current_scene) == scenes.end())
            {
                cout << "\n[Journey ends — unknown scene: " << current_scene << "]\n";
                break;
            }

            applySceneDrain(p);
            showScene();

            if(p.getHP() <= 0)
            {
                cout << "\n====================================\n";
                cout << "  *** YOUR CARAVAN HAS FALLEN ***\n";
                cout << "  The desert has claimed you.\n";
                cout << "====================================\n";
                cout << "  Final Gold : $" << p.getGold() << "\n";
                break;
            }

            if(current_scene == "S31" || current_scene == "S32")
            {
                cout << "\n====================================\n";
                if(current_scene == "S31")
                    cout << "  *** YOU HAVE REACHED AURION ***\n";
                else
                    cout << "  *** YOUR JOURNEY HAS ENDED ***\n";
                cout << "====================================\n";
                cout << "  Final Gold : $" << p.getGold()       << "\n";
                cout << "  Final HP   : " << p.getHP()          << " / 100\n";
                cout << "  Food left  : " << p.getFoodSupply()  << " days\n";
                break;
            }

            vector<Choice> sceneChoices = getChoices();

            if(sceneChoices.empty())
            {
                cout << "\n[No choices available journey ends here.]\n";
                break;
            }

            cout << "\nWhat do you do?\n";
            for(int i = 0; i < (int)sceneChoices.size(); i++)
                cout << "  " << i + 1 << ". " << sceneChoices[i].getText() << "\n";
            cout << "  S. Save game\n";

            string input;
            int pick = 0;
            while(true)
            {
                cout << "------------\n";
                cout << "Enter choice: ";
                cin >> input;

                if(input == "s" || input == "S")
                {
                    saveGame(p);
                    continue;
                }

                try {
                    pick = stoi(input);
                    if(pick >= 1 && pick <= (int)sceneChoices.size()) break;
                } catch(...) {}

                cout << "Invalid. Try again.\n";
            }

            string nextScene = resolveChoice(sceneChoices[pick - 1], p);
            showJourneyStatus(p);

            if(!nextScene.empty())
                current_scene = nextScene;
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

