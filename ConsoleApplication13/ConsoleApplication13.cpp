#include <iostream>
#include <string>
#include <vector>
#include <random> 
#include <Windows.h>
using namespace std;

enum class item_ {
    sword,
    hemlet,
    axe

};

string items_item[3]{ "sword","hemlet","axe" };

struct info {
    int watch = 1;
    std::string name;
    int current_loc = 0;
    bool life;
    vector<item_> item_p;
};


struct portal_ {
    string portal_name;
    int target;
};


struct location_ {
    string loc_name;
    vector <portal_> p;
    vector<item_> item_l;

};


location_ room[5];


info player;


void InitGame() {

    room[0].loc_name = "Ресепшен";
    room[0].p.push_back({ "69", 1 });
    room[0].p.push_back({ "Туалет", 2 });
    room[0].item_l.push_back(item_::hemlet);

    room[1].loc_name = "Бухгалтерия";
    room[1].p.push_back({"44", 3});
    room[1].p.push_back({ "Завод", 4 });

    room[2].loc_name = "Тубзик";
    room[3].loc_name = "Пыточная";
    room[4].loc_name = "Отдел производства";

    player.item_p.push_back(item_::axe);
    player.item_p.push_back(item_::sword);

}

void game() {
    while (true) {
        cout << "Вы находитесь в " << room[player.current_loc].loc_name << endl;
        string chouse;
        cin >> chouse;

        if (chouse == "go") {

            for (int i = 0; i < room[player.current_loc].p.size(); ++i) {
                cout << "Дверь: " << room[player.current_loc].p[i].portal_name << endl;
            }

            string vxod;
            cout << "Введите название двери: ";
            cin >> vxod;

            bool found = false;

            for (int i = 0; i < room[player.current_loc].p.size(); ++i) {
                if (room[player.current_loc].p[i].portal_name == vxod) {
                    player.current_loc = room[player.current_loc].p[i].target;
                    found = true;
                    break;
                }

            }
            //
            if (!found) {
                cout << "Такого портала нет! Попробуйте снова." << endl;
                continue;
            }
        }
        
        if (chouse == "item") {

            for (int i = 0; i < player.item_p.size(); i++) {
                cout << "Predmet: " << items_item[(int)player.item_p[i]] << endl;
            }

        }
        
        if (chouse == "seek") {
            for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                cout << "Predmet " << room[player.current_loc].item_l[i] << endl;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    InitGame();
    game();

}



