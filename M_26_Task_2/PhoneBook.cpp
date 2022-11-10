#include "PhoneBook.h"

PhoneBook::PhoneBook(){}

Flags PhoneBook::AddTel(std::string tel, std::string name) {
	PhoneNum _tel;
	if (!_tel.setPhoneNum(tel)) {
		return Flags::ERR_TEL;
	}
	else {
		std::pair<std::string, std::string> tPair(_tel.getPhoneNum(), name);
		myMap_t::iterator itM = this->m_bookTel.begin();
		itM = this->m_bookTel.find(_tel.getPhoneNum());
		if (itM == m_bookTel.end()) {
			this->m_bookTel.insert(tPair);
			std::pair<std::string, std::string> nPair(name, _tel.getPhoneNum());
			this->m_bookName.insert(nPair);
			return Flags::OK;
		}			
		else 
			return Flags::DUBL_NUMBER;
	}
}

bool PhoneBook::operateSelect(std::string nameOrTel) {
	return nameOrTel.find_first_not_of("0123456789") == std::string::npos ? true : false;
}

bool PhoneBook::phoneSearch(const std::string name, const std::string tel)
{
	int count = m_bookName.count(name);
	if (count == 0)
		return false;
	myMyltimap_t::iterator it = m_bookName.find(name);
	for (int i = 0; i < count; i++) {
		if (it->second == tel)
			return true;
	}
	return false;
}

Flags PhoneBook::CallTel(std::string tel, std::string& result)
{
	myMap_t::iterator itTel = m_bookTel.find(tel);
		if (itTel == m_bookTel.end())
			return Flags::NO_NUMBER;
		else {
			result = "CALL: " + itTel->second;
			return Flags::OK;
		}
}

Flags PhoneBook::SmsTel(std::string tel, std::string sms, std::string& result)
{
	myMap_t::iterator itTel = m_bookTel.find(tel);
	if (itTel == m_bookTel.end())
		return Flags::NO_NUMBER;
	else {
		result = sms + " " + itTel->second;
		return Flags::OK;
	}
}

Flags PhoneBook::CountTel(std::string subscriber) {
	int count = m_bookName.count(subscriber);
	if (count == 0)
		return Flags::NO_SUBSCRIBER;
	else if (count == 1)
		return Flags::ONE_SUBSCRIBER;
	else
		return Flags::MANY_SUBSCRIBER;
}

myMyltimap_t::iterator PhoneBook::getItmyMyltimap(std::string name) {
	myMyltimap_t::iterator it = m_bookName.find(name);
	return it;
}

std::vector<std::string> PhoneBook::PhoneList(std::string subscriber) {
	int count = m_bookName.count(subscriber);
	std::vector<std::string> tmp;
	myMyltimap_t::iterator it = m_bookName.find(subscriber);
	while (count != 0) {
		tmp.push_back(it->second);
		count--; it++;
	}
	return tmp;
}





