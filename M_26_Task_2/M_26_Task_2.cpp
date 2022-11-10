/*Задание 2. Реализация программы симуляции мобильного телефона

Что нужно сделать
Реализуйте программу простой симуляции работы мобильного телефона.
По мобильному телефону можно звонить и отправлять СМС. Также мобильный
телефон содержит адресную книгу. Телефон и отдельные записи адресной
книги должны быть реализованы с помощью классов. Все номера телефонов
задаются в формате +7 <10 цифр>.
Пользователь взаимодействует с программой с помощью команд:
Команда add добавляет в адресную книгу новый номер телефона и ассоциирует
его с именем контакта. Оба эти параметра команда получает от пользователя
через стандартный ввод.
Команда call запрашивает у пользователя имя контакта или номер телефона,
на который требуется позвонить. Сам по себе звонок симулируется с помощью
вывода в консоль сообщения CALL с номером телефона, на который
осуществляется вызов.
Команда sms. Запрашивает у пользователя номер телефона (или имя контакта),
на который требуется послать сообщение. Само сообщение также вводится через
стандартный ввод.
Команда exit — выход из программы.*/

#include <iostream>
#include <vector>
#include"PhoneBook.h"

int main()
{
    std::vector<std::string> pattern{ "add", "call", "sms" };
    std::vector<std::string> names;
    PhoneBook phoneBook;
    std::string comand;
    std::string subscriber;
    std::string tel;
    std::string nameOrTel;
    std::string sms;
    std::string resultTelStr;
    Flags flag;

    while (comand != "exit") {
        std::cout << "Inter comand: ";
        int intComand{ -1 };
        std::getline(std::cin, comand);
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == comand)
                intComand = i;
        }
        switch (intComand)
        {
        case 0:
            std::cout << "Enter the subscriber's name: ";
            std::getline(std::cin, subscriber);
            std::cout << "Enter your phone number: ";
            std::getline(std::cin, tel);
            while (true) {
                flag = phoneBook.AddTel(tel, subscriber);
                if (flag == Flags::OK) {
                    std::cout << "Contact saved!\n\n";
                    break;
                }
                else if (flag == Flags::ERR_TEL) {
                    std::cout << "Incorrect phone number!\nEnter the phone number again:";
                    std::getline(std::cin, tel);
                }
                else if (flag == Flags::DUBL_NUMBER) {
                    std::cout << "This number already exists!\nEnter the phone number again:";
                    std::getline(std::cin, tel);
                }
            }
            break;
        case 1:
            std::cout << "Enter the subscriber's name or phone number: ";
            std::getline(std::cin, nameOrTel);
            if (phoneBook.operateSelect(nameOrTel)) {
                flag = phoneBook.CallTel(nameOrTel, resultTelStr);
                if (flag == Flags::OK)
                    std::cout << resultTelStr << std::endl;
                else if (flag == Flags::NO_NUMBER)
                    std::cout << "The phone number does not exist!\n";
            }
            else {
                flag = phoneBook.CountTel(nameOrTel);
                if(flag == Flags::NO_SUBSCRIBER)
                    std::cout << "The subscriber`s does not exist!\n";
                else if (flag == Flags::ONE_SUBSCRIBER) {
                    phoneBook.CallTel(phoneBook.getItmyMyltimap(nameOrTel)->second, resultTelStr);
                    std::cout << resultTelStr << std::endl;
                }                    
                else if (flag == Flags::MANY_SUBSCRIBER) {
                    names = phoneBook.PhoneList(nameOrTel);
                    for (auto p : names)
                        std::cout << p << std::endl;
                    std::cout << "Enter the subscriber`s number " << nameOrTel << std::endl;                    
                    std::string str;
                    std::getline(std::cin, str);
                    while (!phoneBook.phoneSearch(nameOrTel, str)) {
                        std::cout << "The phone is not in the list!\nTry again!\n\n";
                        std::getline(std::cin, str);
                    }
                    phoneBook.CallTel(str, resultTelStr);
                    std::cout << resultTelStr << std::endl;
                }
            }
            break;
        case 2:
            std::cout << "Enter the subscriber's name or phone number: ";
            std::getline(std::cin, nameOrTel);
            std::cout << "Enter the text of the SMS: ";
            std::getline(std::cin, sms);
            if (phoneBook.operateSelect(nameOrTel)) {
                flag = phoneBook.SmsTel(nameOrTel, sms, resultTelStr);
                if (flag == Flags::OK)
                    std::cout << resultTelStr << std::endl;
                else if (flag == Flags::NO_NUMBER)
                    std::cout << "The phone number does not exist!\n";
            }
            else {
                flag = phoneBook.CountTel(nameOrTel);
                if (flag == Flags::NO_SUBSCRIBER)
                    std::cout << "The subscriber`s does not exist!\n";
                else if (flag == Flags::ONE_SUBSCRIBER) {
                    phoneBook.SmsTel(phoneBook.getItmyMyltimap(nameOrTel)->second, sms, resultTelStr);
                    std::cout << resultTelStr << std::endl;
                }                    
                else if (flag == Flags::MANY_SUBSCRIBER) {
                    names = phoneBook.PhoneList(nameOrTel);
                    std::cout << "Enter the subscriber`s number " << nameOrTel << std::endl;
                    for (auto p : names)
                        std::cout << p << std::endl;
                    std::string str;
                    std::getline(std::cin, str);
                    phoneBook.SmsTel(str, sms, resultTelStr);
                    std::cout << resultTelStr << std::endl;
                }
            }
            break;

        default:
            std::cout << "Incorrect comand!\nTry again!\n\n";
            break;
        }
    }
}
