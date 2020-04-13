#include "../headers/CETF.h"
#include <iostream>
using namespace std;


CETF::CETF() {
    m_strPathToETFInfo= "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/etf_info.txt";
    m_strPathToQQQ = "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/qqq_close.csv";
    m_strPathToIXN = "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/ixn_close.csv";
    m_strPathToXLK = "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/xlk_close.csv";
}

/**
 * @brief Constructor which create object of the class CETF
 * @param mDNav
 * @param databaseEtf
 */



void CETF::printAssetInfo() const {
    cout<<getMStrAssetName();
}

int CETF::etfMenu() {

    int selection;
    cout<<"Info about ETF"<<endl;
    cout<<"Input 1---Info and action with ETF, insert ETF name"<<endl;
    cout<<"Input 2---Buy or sell ETF portfolio of ETFs"<<endl;
    cout<<"Input 0---Logout"<<endl;
    cin>>selection;

    return selection;

}

void CETF::etfInfo() {

    string stockName, checkName, stockMapKeyData;
    tuple<vector<double>, vector<vector<double>>,  vector<vector<double>>> fromAsset = CAsset::getFromBase();
    string strCheckEtf;

///menu for info about stocks
    bool stockDone = false;
    while(!stockDone){
        int selection = etfMenu();
        switch (selection){
            case 1: {
                ///creating object of fstream to get info from file for Stocks
                fstream fin;
                fin.open(getMStrPathToEtfInfo(), fstream::in | fstream::out);
                cout << "ETF on  database: QQQ, IXN and XLK and all data about ETF" << endl;
                cout << "Enter ETF name or all: " << endl;
                cin >> strCheckEtf;

                if (strCheckEtf == "qqq") {


                    cout << "QQQ Return of year " << (get<0>(fromAsset)[3]) * 100 * 250 << " % " << endl;
                    double googleRisk = CAsset::riskOfAsset(get<2>(fromAsset)[3], 250);
                    cout << "QQQ risk " << googleRisk << " % " << endl;
                } else if (strCheckEtf == "ixn") {
                    cout << "IXN  return of year" << (get<0>(fromAsset)[4]) * 100 * 250 << " % " << endl;
                    double amazonRisk = CAsset::riskOfAsset(get<2>(fromAsset)[4], 250);
                    cout << "IXN risk " << amazonRisk << " % " << endl;
                }
                else if (strCheckEtf == "xlk") {

                    cout << "XLK return of year " << (get<0>(fromAsset)[5]) * 100 * 250 << " % " << endl;
                    double appleRisk = CAsset::riskOfAsset(get<2>(fromAsset)[5], 250);
                    cout << "XLK risk " << appleRisk << " % " << endl;
                }else if (strCheckEtf == "all") {

                    cout << "QQQ Return of year " << (get<0>(fromAsset)[3]) * 100 * 250 << " % " << endl;
                    double googleRisk = CAsset::riskOfAsset(get<2>(fromAsset)[3], 250);
                    cout << "QQQ risk " << googleRisk << " % " << endl;
                    cout << "IXN  return of year" << (get<0>(fromAsset)[4]) * 100 * 250 << " % " << endl;
                    double amazonRisk = CAsset::riskOfAsset(get<2>(fromAsset)[4], 250);
                    cout << "IXN risk " << amazonRisk << " % " << endl;
                    cout << "XLK return of year " << (get<0>(fromAsset)[5]) * 100 * 250 << " % " << endl;
                    double appleRisk = CAsset::riskOfAsset(get<2>(fromAsset)[5], 250);
                    cout << "XLK risk " << appleRisk << " % " << endl;
                }


                else{
                    cout<<"Please enter valid name"<<endl;
                }

                break;
                }

            case 2:{
                etfData.inputForETF();
                break;
            }

            case 0:{
                stockDone = true;
                break;
            }
            default:{
                cerr << "Unknown command" << endl;
                break;

            }
        }

    }
}


CETF::~CETF() {}

const string &CETF::getMStrPathToEtfInfo() const {
    return m_strPathToETFInfo;
}

const string &CETF::getMStrPathToQqq() const {
    return m_strPathToQQQ;
}

const string &CETF::getMStrPathToIxn() const {
    return m_strPathToIXN;
}

const string &CETF::getMStrPathToXlk() const {
    return m_strPathToXLK;
}


