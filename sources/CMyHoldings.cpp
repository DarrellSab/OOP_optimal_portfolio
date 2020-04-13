#include "../headers/CMyHoldings.h"
#include "../headers/CPortfolio.h"

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;

CMyHolding::CMyHolding() {
    m_strPathForHolding= "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/holding.txt";
}

CMyHolding::CMyHolding(const string &mStrHoldingName, double mDTotalSum, double mDDayGain, double mDTotalGain,
                       CPortfolio *portfolio, std::string mStrHoldingRegisterDate)
        : m_strHoldingName(mStrHoldingName), m_dTotalSum(mDTotalSum),
          m_dDayGain(mDDayGain), m_dTotalGain(mDTotalGain),
          portfolio(portfolio), m_strHoldingRegisterDate(mStrHoldingRegisterDate) {}


double CMyHolding::getMDTotalSum() const {
    return m_dTotalSum;
}

void CMyHolding::setMDTotalSum(double mDTotalSum) {
    m_dTotalSum = mDTotalSum;
}

double CMyHolding::getMDDayGain() const {
    return m_dDayGain;
}

void CMyHolding::setMDDayGain(double mDDayGain) {
    m_dDayGain = mDDayGain;
}

double CMyHolding::getMDTotalGain() const {
    return m_dTotalGain;
}

void CMyHolding::setMDTotalGain(double mDTotalGain) {
    m_dTotalGain = mDTotalGain;
}

int CMyHolding::holdingMenu() {
    int selection;
    cout<<"Input 1---Set Holding name"<<endl;
    cout<<"Input 2---Holdings"<<endl;
    cout<<"Input 3---Login"<<endl;
    cout<<"Input 0---Logout"<<endl;
    cin>>selection;
    return selection;

}

void CMyHolding::createHoldingMenu() {
    string strHoldingName, strHoldingRegisterDate;
    bool doneHolding = false;
    while (!doneHolding){
        int selectUser = holdingMenu();
        switch (selectUser){
            case 1:{
                ofstream user;
                user.open(getMStrPathForHolding());
                cout<<"Insert Holding Name: ";
                cin>>strHoldingName;
                user<<strHoldingName<<endl;
                time_t timeNow = time(0);
                tm* localtm = localtime(&timeNow);
                user<<asctime(localtm);
                user.close();
                break;
            }
            case 2:{
                fstream fs;
                fs.open(getMStrPathForHolding(),fstream::in | fstream::out);
                cout<<"Holding name: "<<endl;
                getline(fs,strHoldingName, '\n');
                setMStrHoldingName(strHoldingName);
                cout<<getMStrHoldingName()<<endl;
                fs>>ws;
                getline(fs,strHoldingRegisterDate, '\n');
                setMStrHoldingRegisterDate(strHoldingRegisterDate);
                cout<<getMStrHoldingRegisterDate()<<endl;
                fs>>ws;
                fs.close();
                break;
            }
            case 3:{
                portfolio->userPortfolio();
                break;
            }
            case 0:{
                doneHolding = true;
                break;
            }

            default:{
                cerr << "Unknown command" << endl;
                break;
            }
        }
    }


}

const string &CMyHolding::getMStrHoldingName() const {
    return m_strHoldingName;
}

void CMyHolding::setMStrHoldingName(const string &mStrHoldingName) {
    m_strHoldingName = mStrHoldingName;
}

const string &CMyHolding::getMStrHoldingRegisterDate() const {
    return m_strHoldingRegisterDate;
}

void CMyHolding::setMStrHoldingRegisterDate(const string &mStrHoldingRegisterDate) {
    m_strHoldingRegisterDate = mStrHoldingRegisterDate;
}

CMyHolding::~CMyHolding() {

}

const string &CMyHolding::getMStrPathForHolding() const {
    return m_strPathForHolding;
}



















