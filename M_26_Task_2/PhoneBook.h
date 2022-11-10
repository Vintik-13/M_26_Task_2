#pragma once

#include <map>
#include <string>
#include <vector>
#include "PhoneNum.h"

using myMap_t = std::map<std::string, std::string>;
using myMyltimap_t = std::multimap<std::string, std::string>;

enum class Flags {
	OK,
	ERR_TEL,
	DUBL_NUMBER,
	NO_NUMBER,
	NO_SUBSCRIBER,
	ONE_SUBSCRIBER,
	MANY_SUBSCRIBER,
};

class PhoneBook {
	myMap_t m_bookTel;
	myMyltimap_t m_bookName;	

public:
	PhoneBook();
	//Добавление абонента
	Flags AddTel(std::string tel, std::string name); 
	//Помытка реализовать самостоятельный выбор действия
	// при вводе телефона или имени абонента																  
	bool operateSelect(std::string nameOrTel); 
	//Определяет существует ли тел у абонента
	bool phoneSearch(const std::string name, const std::string tel);
	//Звонок по номеру тел
	Flags CallTel(std::string tel, std::string& result);
	//СМС по номеру тел
	Flags SmsTel(std::string tel, std::string sms, std::string& result);
	//Кол-во номеров одного абонента
	Flags CountTel(std::string subscriber);
	//Возвращает итератор на первый объект аббонента myltimap
	myMyltimap_t::iterator getItmyMyltimap(std::string name);
	//Вектор номеров одного абонента
	std::vector<std::string> PhoneList(std::string subscriber);
	//Звонок по имени абонента	
};

