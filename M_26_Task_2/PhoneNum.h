#pragma once
#include <string>
#include <regex>

//pattern для валидации номера тел (сам писал!)
const std::regex pEntrance("(\\+7)?(8)?(\\(?\\d{3}\\)? ?\\-?\\d{3} ?\\-?\\d{2} ?\\-?\\d{2})");
const std::regex pExitDigit("\\D");
const std::regex pExitEight("^[7]");

class PhoneNum {
	std::string m_phoneNum;
public:
	PhoneNum();

	std::string getPhoneNum();
	bool setPhoneNum(std::string& phoneNum);
};
