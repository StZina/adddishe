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

string items_item[4]{ "трусики","чашка","журнал","блокнот" };

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
    //новая штучка должна сработать ))
        string to_lower(string s) {
            for (char& c : s) c = tolower((unsigned char)c);
            return s;
        }

        string chouse;
        cin >> chouse;
        //
        /*if (chouse == "p")   cout << room[player.current_loc].dis << endl;*/

        if (chouse == "иди") {

            for (int i = 0; i < room[player.current_loc].p.size(); ++i) {
                cout << "Дверь: ";
                text(room[player.current_loc].p[i].portal_name,
                    100);
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
            if (player.item_p.empty()) {
                cout << "У Вас нет предметов." << endl;
            }
            else {
                cout << "Ваши предметы:" << endl;
                for (int i = 0; i < player.item_p.size(); i++) {
                    cout << "- " << items_item[(int)player.item_p[i]] << endl;
                }

                cout << "Введите название предмета для передачи (или 'no' для отмены): ";
                string answer;
                cin.ignore(); // Очищаем буфер
                getline(cin, answer); // На случай ввода с пробелами

                if (answer != "no") {
                    bool found = false;

                    for (int i = 0; i < player.item_p.size(); ++i) {
                        // Сравниваем введённую строку с названием предмета
                        if (answer == items_item[(int)player.item_p[i]]) {
                            item_ item_dropped = player.item_p[i];

                            // Удаляем предмет из инвентаря и кладём в текущую локацию
                            room[player.current_loc].item_l.push_back(item_dropped);
                            player.item_p.erase(player.item_p.begin() + i);

                            cout << "Вы отдали предмет: " << answer << "." << endl;

                            // Победа: если в Бухгалтерии и отданы трусики
                            if (player.current_loc == 1 && item_dropped == item_::panties) {
                                cout << "\n*** ПОБЕДА! Трусики доставлены в бухгалтерию! ***\n";
                                exit(0); // Завершение игры
                            }

                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "У вас нет такого предмета. Убедитесь, что написание верно." << endl;
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
//void diolog(); {
  //    if (player.current_loc != 4) {
  //        cout << "Кек";

  //    }
  //    if (player.current_loc == 0 && find(player.item_p.begin(), player.item_p.end(), item_::notebook) != player.item_p.end()) {
  //        auto it = remove_if(player.item_p.begin(), player.item_p.end(), [](const item_& x) { return x == item_::notebook; });
  //        player.item_p.erase(it, player.item_p.end());

  //        // Реакция девушки на ресепшене
  //        text("\nДевушка на ресепшене благодарно улыбнулась и сказала: \"Спасибо!\"\n", 100);
  //    }
  //}
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
//#include <iostream>
//#include <string> // подключаем библиотеку для стринг
//#include <vector>
//
//using namespace std;
//
//enum class item_ { // структура предметов, в ней представленны значения в виде чисел, axe содержит в себе 0, sword содержит 1 и т.д
//
//    axe,
//    sword,
//    hemlet,
//    key
//};
//
//string itemLib[] = { "axe","sword","hemlet", "key" }; // создал массив с именами предметов, в который будут передаваться предметы 
//
//struct player_ {
//
//    int current_loc = 0; // переменная отвечает в какой локации будет находиться игрок
//    bool life = true; // переменная, отвечающая за жизнь игрока
//    vector<item_> item; // созадим вектор типа item_, это будет наш инвенарь, там будут храниться наши предметы в виде цифр.
//};
//
//
//struct portal_ { // структура портала, в которой будут лежать все переменные, связанные с порталом
//
//    string name; // имя портала
//    int target;  // куда будет вести портал, в какую локацию
//    bool activ;
//
//};
//
//struct location_ {      // создали структуру локации, в ней есть имя и наши портал, по которым мы будем перемещаться
//
//    string name; // имя локации
//    vector<portal_>portal; // раньше вектор был типа int, но так как мы добавили структуру порталов, и имена порталов в структуре, нужно чтобы вектор был типа portal_ 
//    vector<item_>item;
//
//};
//
//player_ user; // создали глобальную переменную игрока
//location_ room[4];
//
//void InitGame() {       // создаем функцию которая будет заносить все наши значения в массив room
//
//    room[0].name = "Home"; // задаем кажой комнате имя
//    room[0].portal.push_back({ "green_door", 1 , false }); // закидываем в векотор portal с помощью метода: имя, и куда ведет локация
//    room[0].portal.push_back({ "black_door", 2, false });
//    room[0].item.push_back((item_::axe));// закинул предмет
//
//    room[1].name = "room";
//    room[1].portal.push_back({ "back", 0 , true });
//    room[1].item.push_back((item_::sword));// закинули предмет
//    room[1].item.push_back((item_::hemlet));
//
//    room[2].name = "Entrance";
//    room[2].portal.push_back({ "back", 0 , true });
//    room[2].portal.push_back({ "iron_door", 3, false });
//
//    room[3].name = "Street";
//
//    user.item.push_back(item_::key); // добавили в наш инвентарь топор, чтобы протестировать
//
//}
//
//// use команд, реализовал скрытые порталы
//int main()
//{
//
//    InitGame();
//    string chouse; // создали переменную для ввода пользователя
//
//    cout << "You're in location: " << room[user.current_loc].name << endl; // выведем имя локации  в которой находится игрок
//
//    while (user.life) { // цикл игры, пока пользователь живой
//
//        cin >> chouse;
//
//        if (chouse == "help") {
//
//            cout << "1.go\n2.list\n3.trunk\n4.pick\n5.drop\n6.use\n";
//        }
//
//
//        if (chouse == "go") { // логика работы наших команд, если ввели go, нам будут показываться все доступные порталы в локации, где находится игрок
//
//            for (int i = 0; i < room[user.current_loc].portal.size(); i++) {  // идем по массиву порталов в кажой локции где находится персонаж
//
//                auto p = room[user.current_loc].portal[i];
//
//                cout << room[user.current_loc].portal[i].name << (p.activ ? " is unlocked" : " is locked") << endl; // здесь будут уже не цифры а имена порталов.
//            }
//
//
//            cin >> chouse;// повторный ввод на имя портала
//
//
//            for (int i = 0; i < room[user.current_loc].portal.size(); i++) {
//
//
//                if (chouse == room[user.current_loc].portal[i].name) { // если ввод пользователя сходится с именем портала локации
//
//                    if (room[user.current_loc].portal[i].activ) { // проверка, на активен ли портал
//
//                        user.current_loc = room[user.current_loc].portal[i].target; // то мы текущую локацию игрока, меняем на таргет портала, куда ведет портал, в какую комнату
//
//                        cout << "You're in location: " << room[user.current_loc].name << endl;
//                    }
//                    else {
//                        cout << "LOCKED\n";
//                    }
//                }
//            }
//        }
//
//        if (chouse == "trunk") {
//
//            for (int i = 0; i < user.item.size(); i++) { // идем по массиву item, нам нужна его размерность 
//                cout << itemLib[(int)user.item[i]] << endl; // я прировнял цифровые переменные, которые храняться в массиве инвентаря к int и передаю в массив string
//
//            }
//
//        }
//
//        if (chouse == "list") { //  показать все предметы, находящиеся в локации
//
//            cout << "You have found: \n";
//
//            for (int i = 0; i < room[user.current_loc].item.size(); i++) {
//
//                cout << itemLib[(int)room[user.current_loc].item[i]] << endl;
//            }
//
//        }
//
//        if (chouse == "pick") { // подобрать предмет
//
//            cin >> chouse;
//
//            for (int i = 0; i < room[user.current_loc].item.size(); i++) {
//
//                if (chouse == itemLib[(int)room[user.current_loc].item[i]]) {
//
//                    cout << "You have picked item: " << itemLib[(int)room[user.current_loc].item[i]] << endl;
//                    user.item.emplace_back(room[user.current_loc].item[i]); // добавил предмет в инвентарь игрока
//                    room[user.current_loc].item.erase(room[user.current_loc].item.cbegin() + i); // удалил предмет из локации
//
//                }
//
//            }
//
//        }
//
//        if (chouse == "drop") {
//
//            cin >> chouse;
//
//            for (int i = 0; i < user.item.size(); i++) {
//
//                if (chouse == itemLib[(int)user.item[i]]) {
//
//                    cout << "You have deleted item: " << itemLib[(int)user.item[i]] << endl;
//                    room[user.current_loc].item.emplace_back(user.item[i]); // добавил предмет в инвентарь локации
//                    user.item.erase(user.item.cbegin() + i); // удалил предмет из инвенторя игрока
//
//                }
//
//            }
//
//        }
//
//
//        if (chouse == "use") {
//
//            int dir;
//
//            if (!user.item.empty()) {
//
//                for (int i = 0; i < user.item.size(); i++) {
//
//                    cout << i + 1 << ". " << itemLib[(int)user.item[i]] << endl;
//
//                }
//
//                cout << "Enter number item\n";
//
//                cin >> dir;
//
//
//
//
//                switch ((int)user.item[dir - 1]) {
//
//                case 0: {
//
//                    cout << "use axe\n";
//                    break;
//
//                }
//
//                case 1: {
//
//                    cout << "use sword\n";
//                    break;
//
//                }
//
//                case 2: {
//
//                    cout << "use hemlet\n";
//                    break;
//
//                }
//
//                case 3: {
//
//                    for (int i = 0; i < room[user.current_loc].portal.size(); i++) {
//
//                        cout << i + 1 << ". " << room[user.current_loc].portal[i].name << endl;
//
//                    }
//                    cout << "Enter number door: \n";
//
//                    cin >> dir;
//
//                    room[user.current_loc].portal[dir - 1].activ ? room[user.current_loc].portal[dir - 1].activ = false : room[user.current_loc].portal[dir - 1].activ = true; //читайте про тернарный оператор
//
//                    cout << "You're " << (room[user.current_loc].portal[dir - 1].activ ? "unlocked door " : "locked door ") << room[user.current_loc].portal[dir - 1].name << endl;
//
//                    break;
//
//                }
//
//                }
//
//
//            }
//        }
//    }
//}

