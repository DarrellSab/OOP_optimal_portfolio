#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#include "../headers/CUser.h"
CUser::CUser() {}

CUser::CUser(const string &mStrUsername, const string &mStrPassword, const string &mStrLoginStatus,
             const string &mStrRegisterDate, const string &mStrPhoneNumber, const string &mStrEmail,
             const string &mStrAddress) : m_strUsername(mStrUsername), m_strPassword(mStrPassword),
                                          m_strLoginStatus(mStrLoginStatus), m_strRegisterDate(mStrRegisterDate),
                                          m_strPhoneNumber(mStrPhoneNumber), m_strEmail(mStrEmail),
                                          m_strAddress(mStrAddress) {}


CUser::CUser(string m_strUsername) {
    this->m_strUsername = m_strUsername;
    this->m_strPassword = m_strPassword;
    this->m_strLoginStatus = m_strLoginStatus;
    this->m_strRegisterDate = m_strRegisterDate;
    this->m_strPhoneNumber = m_strPhoneNumber;
    this->m_strEmail = m_strEmail;
    this->m_strAddress = m_strAddress;

}

void CUser::setMStrUsername(const string &mStrUsername) {
    m_strUsername = mStrUsername;
}

const string &CUser::getMStrUsername() {
    return m_strUsername;
}

const string &CUser::getMStrPassword() const {
    return m_strPassword;
}

void CUser::setMStrPassword(const string &mStrPassword) {
    m_strPassword = mStrPassword;
}

const string &CUser::getMStrRegisterDate() const {
    return m_strRegisterDate;
}

void CUser::setMStrRegisterDate(const string &mStrRegisterDate) {
    m_strRegisterDate = mStrRegisterDate;
}

const string &CUser::getMStrPhoneNumber() const {
    return m_strPhoneNumber;
}

void CUser::setMStrPhoneNumber(const string &mStrPhoneNumber) {
    m_strPhoneNumber = mStrPhoneNumber;
}

const string &CUser::getMStrEmail() const {
    return m_strEmail;
}

void CUser::setMStrEmail(const string &mStrEmail) {
    m_strEmail = mStrEmail;
}

const string &CUser::getMStrAddress() const {
    return m_strAddress;
}

void CUser::setMStrAddress(const string &mStrAddress) {
    m_strAddress = mStrAddress;
}



CUser::~CUser() {}



