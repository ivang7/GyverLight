
void create_param(String name, String value);

void create_parameters()
{
    create_param(F("wifi_mode"), "2"); // wifi mode. 1 - AP, 2 - STA
    create_param(F("ssid"), F("Divolika"));
    create_param(F("pass"), F("8269202692"));


    create_param(F("brightness"), F("255"));
    create_param(F("mode"), F("0"));
}
#include "sys/JeeUI.h"
void make_page(int page)
{
    // Menu
    e_menu[0] = F("Settings");
    e_menu[1] = F("Wi-Fi");
    e_menu[2] = F("Info");

    switch (page)
    {
    case 0: // Settings Page
        select_elements(F("-2"), F("Выключить"));
        select_elements(F("-1"), F("Лампа - белый свет"));
        select_elements(F("-3"), F("Переключение режимов"));
        select_elements(F("0"), F("Бегающие огоньки"));
        select_elements(F("1"), F("Жучки"));
        select_elements(F("2"), F("Цвета"));
        select_elements(F("3"), F("Радуга"));
        select_elements(F("4"), F("Частицы"));
        select_elements(F("5"), F("Огонь"));
        input_select(F("mode"), F("mode"), true, F("Режим работы"));

        input_range(F("brightness"), F("brightness"), 5, 255, F("Яркость лампы"));
        
        button_save(F("Save"), 1);
        break;
    case 1: // Wi-Fi Page
    
        wifi_scan(); // Wi-Fi Scan table
        input_text(F("ssid"), F("ssid"), F("text"), "", F("SSID"));
        input_text("", F("pass"), F("password"), "", F("Password"));

        select_elements("1", F("AP"));
        select_elements("2", F("STA"));
        input_select("", F("wifi_mode"), false, F("Wi-Fi Mode"));

        button_save(F("Save"), 1);
        button_reboot(F("Reboot device"), 4);
        break;
    case 2: // Info page

        border(F("All Parameters"));
        param_table();
        border("");
        break;
    }

}