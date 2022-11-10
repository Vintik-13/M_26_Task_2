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
	//���������� ��������
	Flags AddTel(std::string tel, std::string name); 
	//������� ����������� ��������������� ����� ��������
	// ��� ����� �������� ��� ����� ��������																  
	bool operateSelect(std::string nameOrTel); 
	//���������� ���������� �� ��� � ��������
	bool phoneSearch(const std::string name, const std::string tel);
	//������ �� ������ ���
	Flags CallTel(std::string tel, std::string& result);
	//��� �� ������ ���
	Flags SmsTel(std::string tel, std::string sms, std::string& result);
	//���-�� ������� ������ ��������
	Flags CountTel(std::string subscriber);
	//���������� �������� �� ������ ������ ��������� myltimap
	myMyltimap_t::iterator getItmyMyltimap(std::string name);
	//������ ������� ������ ��������
	std::vector<std::string> PhoneList(std::string subscriber);
	//������ �� ����� ��������	
};

