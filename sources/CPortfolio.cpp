#include <iostream>
#include <string>
#include "../headers/CPortfolio.h"
#include <fstream>
#include <iomanip>
#include <vector>


CPortfolio::CPortfolio()  {
    m_strToITPortfolio = "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/ITportfolio.txt";
    m_strToETFPortfolio = "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/ETFPortfolio.txt";
}

CPortfolio::CPortfolio(const string &mStrPortfolioName, int mNSimbols, const string &mStrCurrency, CBroker *broker,
                       const CDataBase &portfolioData, const CRisk &portfolioRisk, const CReturn &portfolioReturn,
                       const CStock &stock, const CETF &etf) : m_strPortfolioName(mStrPortfolioName),
                                                               m_nSimbols(mNSimbols), m_strCurrency(mStrCurrency),
                                                               broker(broker), portfolioData(portfolioData),
                                                               portfolioRisk(portfolioRisk),
                                                               portfolioReturn(portfolioReturn), stock(stock),
                                                               etf(etf) {}

void CPortfolio::setMStrPortfolioName(const string &mStrPortfolioName) {
    m_strPortfolioName = mStrPortfolioName;
}

void CPortfolio::setMStrCurrency(const string &mStrCurrency) {
    m_strCurrency = mStrCurrency;
}

const std::string &CPortfolio::getMStrPortfolioName() const {
    return m_strPortfolioName;
}

const std::string &CPortfolio::getMStrCurrency() const {
    return m_strCurrency;
}

void CPortfolio::printAssetInfo() const {
    std::cout<<getMStrAssetName();
}

int CPortfolio::getMNSimbols() const {
    return m_nSimbols;
}

void CPortfolio::setMNSimbols(int mNSimbols) {
    m_nSimbols = mNSimbols;
}

int CPortfolio::createUserPortfolio()  {
    int selection;
    cout<<"Hello "<<endl;
    cout<<"Input 1---Get info about Portfolios"<<endl;
    cout<<"Input 2---Get info about stocks"<<endl;
    cout<<"Input 3---Get info about ETF"<<endl;
    cout<<"Input 0---Logout"<<endl;

    cin>>selection;

    return selection;


}

void CPortfolio::userPortfolio()  {
    string strPortfolioName, strCurrency;
    int nSymbolsSum;
    double dMoneyInPortfolio;
    bool portfolioDone = false;
    while (!portfolioDone){
        int selectioPorftolio = createUserPortfolio();
        switch(selectioPorftolio){

            ///Choosing of portfolio with if, else if and else condition
            case 1:{
                cout<<"Choose portfolio: 1 - IT, 2 - ETF"<<endl;
                //CPortfolio infoItPortfolio;
                CDataBase itDatabase;



                int nChoosePortfolioFromFile;
                cin>>nChoosePortfolioFromFile;
                if(nChoosePortfolioFromFile == 1){

                    fstream infoIT;
                    infoIT.open(itDatabase.getMStrToItPortfolio(), fstream::in | fstream::out);

                    ///Here is creating tuple type to get different type of values from file with library fstream
                    tuple<string, int, string, double, double,double,double,double, double> itPortfolioInfo =
                            make_tuple("", 0, "", 0.0, 0.0, 0.0,0.0,0.0,0.0);
                    string strNameIT, strSymboltupl;
                    int nEtfCount;
                    double dAmountMoney, dPredictedSum,dGoogle, dAmazon,dApple, dPortfolioRi;

                    while (!infoIT.eof()) {
                        infoIT>>ws;
                        getline(infoIT, strNameIT,'\n');
                        infoIT>>ws;
                        infoIT >> nEtfCount;
                        infoIT >> strSymboltupl;
                        infoIT >> dAmountMoney;
                        infoIT >> dPredictedSum;
                        infoIT >> dGoogle;
                        infoIT >> dAmazon;
                        infoIT >> dApple;
                        infoIT >> dPortfolioRi;
                        itPortfolioInfo = make_tuple(strNameIT, nEtfCount, strSymboltupl, dAmountMoney,dPredictedSum, dGoogle,
                                                     dAmazon,dApple,dPortfolioRi);
                    }

                    cout << "IT portfolio name: ";
                    cout << get<0>(itPortfolioInfo) << endl;
                    cout << "IT portfolio how many Assets in the portfolio: ";
                    cout << get<1>(itPortfolioInfo) << endl;
                    cout << "IT portfolio currency: ";
                    cout << get<2>(itPortfolioInfo) << endl;
                    cout << "How many you are investing: ";
                    cout << get<3>(itPortfolioInfo) << endl;
                    cout << "Predicted sum: ";
                    cout << get<4>(itPortfolioInfo) << endl;

                    cout<<"Google allocation in portfolio: "<<get<5>(itPortfolioInfo)<<endl;
                    cout<<"Amazon allocation in portfolio: "<<get<6>(itPortfolioInfo)<<endl;
                    cout<<"Apple allocation in portfolio: "<<get<7>(itPortfolioInfo)<<endl;
                    cout << "Risk of IT portfolio: ";
                    cout << get<8>(itPortfolioInfo) << endl;
                    infoIT.close();


                } else if(nChoosePortfolioFromFile == 2){
                    CPortfolio etfInfoPortfolio;
                    fstream infoETF;
                    infoETF.open(etfInfoPortfolio.getMStrToEtfPortfolio(), fstream::in | fstream::out);
                    tuple<string, int, string, double, double,double,double,double, double> etfPortfolioInfo =
                            make_tuple("", 0, "", 0.0, 0.0, 0.0,0.0,0.0,0.0);
                    string strName, strSymboltupl;
                    int nEtfCount;
                    double dAmountMoney, dPredictedSum,dGoogle, dAmazon,dApple, dPortfolioRi;

                    while (!infoETF.eof()) {
                        infoETF>>ws;
                        getline(infoETF, strName,'\n');
                        infoETF>>ws;
                        infoETF >> nEtfCount;
                        infoETF >> strSymboltupl;
                        infoETF >> dAmountMoney;
                        infoETF >> dPredictedSum;
                        infoETF >> dGoogle;
                        infoETF >> dAmazon;
                        infoETF >> dApple;
                        infoETF >> dPortfolioRi;
                        etfPortfolioInfo = make_tuple(strName, nEtfCount, strSymboltupl, dAmountMoney,dPredictedSum, dGoogle,
                                                      dAmazon,dApple,dPortfolioRi);
                    }


                    cout << "ETF portfolio name: ";
                    cout << get<0>(etfPortfolioInfo) << endl;
                    cout << "ETF portfolio how many Assets in the portfolio: ";
                    cout << get<1>(etfPortfolioInfo) << endl;
                    cout << "ETF portfolio currency: ";
                    cout << get<2>(etfPortfolioInfo) << endl;
                    cout << "How many you are investing: ";
                    cout << get<3>(etfPortfolioInfo) << endl;
                    cout << "Predicted sum: ";
                    cout << get<4>(etfPortfolioInfo) << endl;
                    cout<<"QQQ allocation in portfolio: "<<get<5>(etfPortfolioInfo)<<endl;
                    cout<<"IXN allocation in portfolio: "<<get<6>(etfPortfolioInfo)<<endl;
                    cout<<"XLK allocation in portfolio: "<<get<7>(etfPortfolioInfo)<<endl;
                    cout << "Risk of ETF portfolio: ";
                    cout << get<8>(etfPortfolioInfo) << endl;

                }
                else{
                    cout<<"You insert wrong data"<<endl;
                }

                break;
            }
            case 2:{
                stock.stockInfo();
                break;
            }
            case 3:{
                etf.etfInfo();
                break;
            }

            case 0:{
                portfolioDone = true;
                break;
            }
            default:{
                cerr << "Unknown command" << endl;
                break;
            }
        }
    }

}

double CPortfolio::getMDAmountToSpend() const {
    return m_dAmountToSpend;
}

double CPortfolio::setMDAmountToSpend(double mDAmountToSpend) {
    m_dAmountToSpend = mDAmountToSpend;
}

int CPortfolio::getMNDaysForPrediction() const {
    return m_nDaysForPrediction;
}

void CPortfolio::setMNDaysForPrediction(int mNDaysForPrediction) {
    m_nDaysForPrediction = mNDaysForPrediction;
}

const string &CPortfolio::getMStrToItPortfolio() const {
    return m_strToITPortfolio;
}

const string &CPortfolio::getMStrToEtfPortfolio() const {
    return m_strToETFPortfolio;
}

CPortfolio::~CPortfolio() = default;












