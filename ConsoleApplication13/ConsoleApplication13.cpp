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
    string dis;
    string loc_name;
    vector <portal_> p;
    vector<item_> item_l;

};


location_ room[5];


info player;


void InitGame() {

    room[0].loc_name = "��������";
    room[0].dis = "���� ���?";
    room[0].p.push_back({ "69", 1 });
    room[0].p.push_back({ "������", 2 });
    room[0].item_l.push_back(item_::hemlet);

    room[1].loc_name = "�����������";
    room[1].p.push_back({ "44", 3 });
    room[1].p.push_back({ "�����", 4 });
    room[1].dis = "��� ������?";

    room[2].loc_name = "������";
    room[3].loc_name = "��������";
    room[4].loc_name = "����� ������������";
    room[2].dis = "�����?";
  
    room[2].item_l.push_back(item_::sword);
    room[3].item_l.push_back(item_::hemlet);
    room[3].item_l.push_back(item_::axe);
    room[4].item_l.push_back(item_::axe);
}

void game() {

    while (true) {

        text("Ky ky\n", 100);
        text("�� ���������� � ", 100);
        cout << room[player.current_loc].loc_name << endl;
        text(room[player.current_loc].dis, 100);

            string chouse;
            cin >> chouse;
            //
            /*if (chouse == "p")   cout << room[player.current_loc].dis << endl;*/

            if (chouse == "go") {

                for (int i = 0; i < room[player.current_loc].p.size(); ++i) {
                    cout << "�����: ";
                    text(room[player.current_loc].p[i].portal_name, 100);
                    cout << "\n";
                }

                string vxod;
                cout << "������� �������� �����: ";
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
                    cout << "������ ������� ���! ���������� �����." << endl;
                    continue;
                }

            }

            if (chouse == "pickup") {
                // ������ ��������� �� ������� �������
                if (room[player.current_loc].item_l.empty()) {
                    cout << "�� ���� ������� ��� ���������." << endl;
                }
                else {
                    cout << "����� �������� ��������� �����:" << endl;
                    for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                        cout << i + 1 << ". " << items_item[(int)room[player.current_loc].item_l[i]] << endl;
                    }

                    // ������� ������ ����� �������� ��� �������
                    cout << "�������� �������� �������� ��� ������� (��� 'no' ��� ������): ";
                    string answer;
                    cin >> answer;

                    if (answer != "no") {

                        for (int i = 0; i < room[player.current_loc].item_l.size(); i++) {
                            // ��������� ��������� �������

                            if (answer == items_item[(int)room[player.current_loc].item_l[i]]) {

                                player.item_p.push_back(room[player.current_loc].item_l[i]);

                                cout << "�� ������� ������� " << items_item[(int)player.item_p.back()] << "." << endl;
                                room[player.current_loc].item_l.erase(room[player.current_loc].item_l.cbegin() + i);
                            }
                        }
                    }
                    if (answer == "no") {
                        cout << "�������� �����. ���������� ��� ���." << endl;
                    }
                }
            }
        

        if (chouse == "drop") {
            // ������ ��������� ������
            if (player.item_p.empty()) {
                cout << "� ��� ��� ���������." << endl;
            }
            else {
                cout << "������ ����� ���������:" << endl;
                for (int i = 0; i < player.item_p.size(); i++) {
                    cout << i + 1 << ". " << items_item[(int)player.item_p[i]] << endl;
                }

                // ������� ������ ����� �������� ��� ������
                cout << "������� ����� �������� ��� ������ (��� 'no' ��� ������): ";
                string answer;
                cin >> answer;

                if (answer != "no") {
                    int index = stoi(answer) - 1; // ��������� �������
                    if (index >= 0 && index < player.item_p.size()) {
                        // ���������� ��������� ������� ������� � ������� �������
                        room[player.current_loc].item_l.push_back(player.item_p[index]);
                        player.item_p.erase(player.item_p.begin() + index);
                        cout << "�� ������� ������� " << items_item[(int)room[player.current_loc].item_l.back()] << "." << endl;
                    }

                    else {
                        cout << "�������� �����. ���������� ��� ���." << endl;
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