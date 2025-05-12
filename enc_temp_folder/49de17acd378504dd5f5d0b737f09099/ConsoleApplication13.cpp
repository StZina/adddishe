#include <iostream>
#include <string>
#include <vector>
#include <random> 
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace std;

void text(string txt, int ms) {

    for (int i = 0; i < txt.size(); i++) {

        cout << txt[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(ms));
    }
}

enum class item_ {
    panties,
    cup,
    magazine,
    notebook

};

string items_item[4]{ "трусики","чашка","журнал","блокнот"};

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
    string dis;
    string loc_name;
    vector <portal_> p;
    vector<item_> item_l;

};


location_ room[5];


info player;


void InitGame() {

    void diolog(); {
        if (player.current_loc != 4) {
            cout << "Кек";

        }
        if (player.current_loc == 0 && find(player.item_p.begin(), player.item_p.end(), item_::notebook) != player.item_p.end()) {
            auto it = remove_if(player.item_p.begin(), player.item_p.end(), [](const item_& x) { return x == item_::notebook; });
            player.item_p.erase(it, player.item_p.end());

            // Реакция девушки на ресепшене
            text("\nДевушка на ресепшене благодарно улыбнулась и сказала: \"Спасибо!\"\n", 100);
        }
    }

    room[0].loc_name = "Ресепшен";
    room[0].dis = "Сегодня на ресепшене меня встретила незнакомка с холодным взглядом.\nБез лишних слов она резко ткнула пальцем в журнал и отрывисто приказала : - Распишись.\nИ потом загляните в бухгалтерию для оформления на работу, кабинет шестьдесят девять. Иди.\n";
    room[0].p.push_back({ "69", 1 });
    room[0].p.push_back({ "Туалет", 2 });


    room[1].loc_name = "Бухгалтерия";
    room[1].p.push_back({ "44", 3 });
    room[1].p.push_back({ "Завод", 4 });
    room[1].p.push_back({ "Ресепшен", 0 });
    room[1].dis = "Парень вошёл. Очаровательная помощница главного бухгалтера виновато вздохнула и сообщила, что ей нужно ещё время — она потеряла шаблон документа.\nЗатем расплылась в улыбке и произнесла, что недавно сварила кофе и предложила парню выпить чашечку, подождав в комнате отдыха.\n";

    room[2].loc_name = "Тубзик";
    room[3].loc_name = "Место отдыха";
    room[4].loc_name = "Отдел производства";
    room[2].dis = "Прохладный воздух струился лёгкими порывами, пока взгляд парня скользил по грязному полу\nи натолкнулся на белоснежный кусочек кружева — нежные девичьи трусики.\nМир замедлился, кровь застучала в ушах, лицо вспыхнуло ярким румянцем.\n"; 
    room[3].dis = "От аромата свежесваренного кофе сразу появляется желание налить чашечку, где же кружка?\nВзгляд скользнул по столу и зацепился за уголок потрепанного блокнота, открытого на странице с остроумными прозвищами постоянных клиентов.\nАвтору наверняка придётся несладко, если босс наткнётся на него.\n";
    room[4].dis = "Шагнув внутрь отдела микрочипов, парень встретил внимательный взгляд старшего инженера, девушки с мягкой улыбкой.\nОна кивнула приветливо: - Мы тебя заждались, новичок! Проходи сюда, покажу твоё рабочее место.\n";
  
    room[2].p.push_back({ "Респепшен", 0 });
    room[3].p.push_back({ "69", 1 });
    room[4].p.push_back({ "69", 1 });
    room[4].p.push_back({ "44", 1 });

    room[2].item_l.push_back(item_::panties);
    room[3].item_l.push_back(item_::cup);
    room[3].item_l.push_back(item_::notebook);
    room[4].item_l.push_back(item_::magazine);
}




void game() {

    while (true) {
        text("Вы находитесь в ", 100);
        cout << room[player.current_loc].loc_name << endl;
        text(room[player.current_loc].dis, 100);

            string chouse;
            cin >> chouse;
            //
            /*if (chouse == "p")   cout << room[player.current_loc].dis << endl;*/

            if (chouse == "иди") {

                for (int i = 0; i < room[player.current_loc].p.size(); ++i) {
                    cout << "Дверь: ";
                    text(room[player.current_loc].p[i].portal_name, 100);
                    cout << "\n";
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

             


            if (chouse == "возьми") {
                // Список предметов на текущей локации
                if (room[player.current_loc].item_l.empty()) {
                    cout << "На этой локации нет предметов." << endl;
                }
                else {
                    cout << "Какие предметы находятся здесь:" << endl;
                    for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                        cout << i + 1 << ". " << items_item[(int)room[player.current_loc].item_l[i]] << endl;
                    }

                    // Просьба ввести номер предмета для подбора
                    cout << "Напишите название предмета для подъёма (или 'no' для отказа): ";
                    string answer;
                    cin >> answer;

                    if (answer != "no") {

                        for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                            // Поднимаем указанный предмет

                            if (answer == items_item[(int)room[player.current_loc].item_l[i]]) {

                                player.item_p.push_back(room[player.current_loc].item_l[i]);

                                cout << "Вы подняли предмет " << items_item[(int)player.item_p.back()] << "." << endl;
                                room[player.current_loc].item_l.erase(room[player.current_loc].item_l.cbegin() + i);
                            }
                        }
                    }
                    if (answer == "no") {
                        cout << "Неверный выбор. Попробуйте ещё раз." << endl;
                    }
                }
            }

        

        if (chouse == "отдай") {
            // Список предметов игрока
            if (player.item_p.empty()) {
                cout << "У Вас нет предметов." << endl;
            }
            else {
                cout << "Список ваших предметов:" << endl;
                for (int i = 0; i < player.item_p.size(); i++) {
                    cout << i + 1 << ". " << items_item[(int)player.item_p[i]] << endl;
                }

                // Просьба ввести номер предмета для сброса
                cout << "Укажите номер предмета для сброса (или 'no' для отмены): ";
                string answer;
                cin >> answer;

                if (answer != "no") {
                    int index = stoi(answer) - 1; // Получение индекса
                    if (index >= 0 && index < player.item_p.size()) {
                        // Сбрасываем указанный предмет обратно в текущую комнату
                        room[player.current_loc].item_l.push_back(player.item_p[index]);
                        player.item_p.erase(player.item_p.begin() + index);
                        cout << "Вы бросили предмет " << items_item[(int)room[player.current_loc].item_l.back()] << "." << endl;
                    }

                    else {
                        cout << "Неверный выбор. Попробуйте ещё раз." << endl;
                    }
                }
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

/*if (chouse == "item") {

    for (int i = 0; i < player.item_p.size(); i++) {
        cout << "Predmet: " << items_item[(int)player.item_p[i]] << endl;
    }

}

if (chouse == "seek") {
    for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
        cout << "Predmet " << room[player.current_loc].item_l[i] << endl;
    }
}
}*/