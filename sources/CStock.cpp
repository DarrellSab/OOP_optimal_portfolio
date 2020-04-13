#include "../headers/CStock.h"
#include "../headers/CAsset.h"
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include<itpp/itbase.h>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <tuple>

using namespace itpp;
using namespace std;

CStock::CStock() {
    m_strPathToGoogle = "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/google_close.csv";
    m_strPathToAppl = "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/aapl_close.csv";
    m_strPathtToAmznDate = "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/amzn_close.csv";
}
void CStock::printAssetInfo() const {
    cout<<getMStrAssetName();
}



CStock::CStock(const string &mStrAssetName, const string &mStrSymbol, const string &mStrTradeDate, double mDAmount,
               double mDMarketValue, double mDDayGain, double mDTotalGain) : CAsset(mStrAssetName, mStrSymbol,
                                                                                    mStrTradeDate, mDAmount,
                                                                                    mDMarketValue, mDDayGain,
                                                                                    mDTotalGain, 0) {}

int CStock::stockMenu() {

    int selection;
    cout<<"Info about Stock"<<endl;
    cout<<"Input 1---Get info about Stocks"<<endl;
    cout<<"Input 2---Buy or sell IT portfolio of stocks"<<endl;
    cout<<"Input 0---Logout"<<endl;

    cin>>selection;

    return selection;

}

void CStock::stockInfo() {

    string stockName, checkName, stockMapKeyData;
    ///Tuple of vectors of vectors of vectors which gets data from database through class CAsset
    tuple<vector<double>, vector<vector<double>>,  vector<vector<double>>> fromAsset = CAsset::getFromBase();

///Menu for info about stocks
    bool stockDone = false;
    while(!stockDone){
        int selection = stockMenu();
        switch (selection){
            case 1:{

                cout<<"Stocks on database: Apple, Google, Amazon, All data"<<endl;
                cout<<"Enter stock name or all: "<<endl;

                        string strCheckName;
                        cin>>strCheckName;
                        if(strCheckName == "Google") {
                            cout << "Google Return of year " << (get<0>(fromAsset)[0]) * 100 * 250 << " % " << endl;
                            double googleRisk = CAsset::riskOfAsset(get<2>(fromAsset)[0], 250);
                            cout << "Google risk " << googleRisk << " % " << endl;
                        }else if ( strCheckName == "Amazon"){
                            cout << "Amazon  return of year " << (get<0>(fromAsset)[1])*100*250 <<" % "<< endl;
                            double amazonRisk = CAsset::riskOfAsset(get<2>(fromAsset)[1], 250);
                            cout << "Amazon risk " << amazonRisk <<" % "<< endl;
                        }else if(strCheckName == "Apple"){
                            cout << "Apple return of year " << (get<0>(fromAsset)[2])*100*250 <<" % "<< endl;
                            double appleRisk = CAsset::riskOfAsset(get<2>(fromAsset)[2], 250);
                            cout << "Apple risk " << appleRisk <<" % "<< endl;
                        }else if(strCheckName == "all"){
                            cout << "Google Return of year " << (get<0>(fromAsset)[0]) * 100 * 250 << " % " << endl;
                            double googleRisk = CAsset::riskOfAsset(get<2>(fromAsset)[0], 250);
                            cout << "Google risk " << googleRisk << " % " << endl;
                            cout << "Amazon  return of year " << (get<0>(fromAsset)[1])*100*250 <<" % "<< endl;
                            double amazonRisk = CAsset::riskOfAsset(get<2>(fromAsset)[1], 250);
                            cout << "Amazon risk " << amazonRisk <<" % "<< endl;
                            cout << "Apple return of year " << (get<0>(fromAsset)[2])*100*250 <<" % "<< endl;
                            double appleRisk = CAsset::riskOfAsset(get<2>(fromAsset)[2], 250);
                            cout << "Apple risk " << appleRisk <<" % "<< endl;
                        }
                        else{
                            cout<<"Wrong name"<<endl;
                        }

                break;}

            case 2:{
                dataStock.inputForStock();
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

const string &CStock::getMStrPathToGoogle() const {
    return m_strPathToGoogle;
}

const string &CStock::getMStrPathToAppl() const {
    return m_strPathToAppl;
}

const string &CStock::getMStrPathtToAmznDate() const {
    return m_strPathtToAmznDate;
}


CStock::~CStock() = default;