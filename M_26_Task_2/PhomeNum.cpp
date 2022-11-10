#include "PhoneNum.h"

PhoneNum::PhoneNum() { m_phoneNum = ""; }

std::string PhoneNum::getPhoneNum() { return m_phoneNum; }

bool PhoneNum::setPhoneNum(std::string& phoneNum) {
	if (std::regex_match(phoneNum.c_str(), pEntrance)) {
		m_phoneNum = std::regex_replace(phoneNum.c_str(), pExitDigit, "");
		m_phoneNum = std::regex_replace(m_phoneNum.c_str(), pExitEight, "8");
		return true;
	}
	else
		return false;
}
