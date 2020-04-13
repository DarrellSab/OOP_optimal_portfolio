#include "../headers/CDataBase.h"
#include "../headers/CAsset.h"
#include "../headers/CReturn.h"
#include "../headers/CRisk.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <ctime>
#include <iomanip>

using namespace std;

CDataBase::CDataBase() {
    m_strTOETFPortfolio= "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/ETFPortfolio.txt";
    m_strToITPortfolio= "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/ITportfolio.txt";
}

CDataBase::CDataBase(CAsset *asset) : asset(asset) {}

void CDataBase::inputForETF() {
    string strPortfolioName,strCurrency;
    int nSymbolsSum;
    double dSpendMoney, dPredictionSum, dPortfolioRisk;
    cout<<"Info about ETF portfolio before buying or selling"<<endl;
    tuple<vector<double>, vector<vector<double>>,  vector<vector<double>>> dataForChosenPortfolio = asset->getFromBase();
    std::vector<std::string> stockVec;
    vector<double> returnETF;
    returnETF.emplace_back(get<0>(dataForChosenPortfolio)[3]);
    returnETF.emplace_back(get<0>(dataForChosenPortfolio)[4]);
    returnETF.emplace_back(get<0>(dataForChosenPortfolio)[5]);
    vector<double> dQQQ = get<1>(dataForChosenPortfolio)[3];
    vector<double> dIXN = get<1>(dataForChosenPortfolio)[4];
    vector<double> dXLK = get<1>(dataForChosenPortfolio)[5];
    /**
     * Here we do the calculation the risk and the return of  ETF portfolio through dependencies relation with the classes
     * CRisk and CReturn. The first step covariance-variance matrix then we using method CReturn::optimalPortfolio()
     */
    vector<vector<double>> covarianceMatrixETF =  CRisk::covarianceVarianceMatrix(dQQQ,dIXN,
                                                                                  dXLK,250,3);
    vector<vector<double>> optimalAllocationETF = CReturn::optimalPortfolio(covarianceMatrixETF,
                                                                            returnETF,3,3,1);

    cout<<fixed<<setprecision(3)<<"ETF Portfolio year return "<<optimalAllocationETF[1][0]<<endl;
    cout<<fixed<<setprecision(3)<<"ETF Portfolio risk (std) of year "<<optimalAllocationETF[1][1]<<endl;
    cout<<fixed<<setprecision(2)<<"QQQ allocation in portfolio: "<<optimalAllocationETF[0][0]<<endl;
    cout<<fixed<<setprecision(2)<<"IXN allocation in portfolio: "<<optimalAllocationETF[0][1]<<endl;
    cout<<fixed<<setprecision(2)<<"XLK allocation in portfolio: "<<optimalAllocationETF[0][2]<<endl;
    CDataBase db;


    cout<<"Do you buy portfolio insert - 1, sell - 2, logout - 0"<<endl;

    int nETFChose;
    cin>>nETFChose;
    bool bBoolEtf = false;

while (!bBoolEtf){


        if (nETFChose == 1) {
            string portfolioName, currency;
            int symbolsSum;

            fstream buyETF;
            buyETF.open(db.getMStrToetfPortfolio(), fstream::in | fstream::out);
            if (!buyETF.is_open()) {
                cout << "The error was happend when you open a file" << endl;
            } else {
                cout << "You are buying ETF portfolio" << endl;
                cout << "Insert Portfolio Name: ";
                cin.ignore(1, ' ');
                getline(cin, portfolioName);
                buyETF << portfolioName << endl;

                cout << "Insert  how many Symbols: ";
                cin >> symbolsSum;
                buyETF << symbolsSum << endl;

                cout << "Insert which currency do you use: ";
                cin.ignore(1, ' ');
                getline(cin, currency);
                buyETF << currency << endl;

                cout << "How many money do you want to spend?: ";
                cin >> dSpendMoney;
                buyETF << dSpendMoney<<endl;

                double dWritingPredictedSum = dSpendMoney + ((optimalAllocationETF[1][0] / 100) * dSpendMoney);
                buyETF<<dWritingPredictedSum<<endl;
                ///Saving an Allocation of ETF portfolio

                buyETF<<optimalAllocationETF[0][0]<<endl;
                buyETF<<optimalAllocationETF[0][1]<<endl;
                buyETF<<optimalAllocationETF[0][2]<<endl;
                buyETF<<optimalAllocationETF[1][1]<<endl;
                buyETF.close();
            }
            fstream infoETF;
            infoETF.open(db.getMStrToetfPortfolio(), fstream::in | fstream::out);
            cout << "Information about portfolio and the Prediction of you income after 1 year: " << endl;

            ///Here is creating tuple type to get diffrente type of values from file with library fstream
            tuple<string, int, string, double, double,double,double,double, double> etfPortfolioInfo =
                    make_tuple("", 0, "", 0.0, 0.0, 0.0,0.0,0.0,0.0);
            string strName, strSymboltupl;
            int nEtfCount;
            double dAmountMoney, dPredictedSum,dGoogle, dAmazon,dApple, dPortfolioRi;

            while (!infoETF.eof()) {
                infoETF>>ws;
                getline(infoETF, strName,'\n');
                //infoETF>>ws;
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
            cout << "BUT YOU RISK!!! ";
            cout << get<8>(etfPortfolioInfo) << endl;
            infoETF.close();
            break;
        } else if (nETFChose == 2) {
            fstream cleanETF;
            cleanETF.open(db.getMStrToetfPortfolio(), fstream::in | fstream::out |fstream::trunc);
            cleanETF.close();
            break;

        }
    if(nETFChose == 0){
        bBoolEtf = true;
        break;
    }
}

}

void CDataBase::inputForStock() {
    cout<<"Info about Stock portfolio before buying or selling"<<endl;
    tuple<vector<double>, vector<vector<double>>,  vector<vector<double>>> dataForChosenPortfolio = asset->getFromBase();
    vector<double> returnIT;
    returnIT.emplace_back(get<0>(dataForChosenPortfolio)[0]);
    returnIT.emplace_back(get<0>(dataForChosenPortfolio)[1]);
    returnIT.emplace_back(get<0>(dataForChosenPortfolio)[2]);

    vector<double> google = get<1>(dataForChosenPortfolio)[0];
    vector<double> amazon = get<1>(dataForChosenPortfolio)[1];
    vector<double> apple = get<1>(dataForChosenPortfolio)[2];
    /**
     * Here we do the calculation the risk and the return of  IT portfolio through dependencies relation with the classes
     * CRisk and CReturn. The first step covariance-variance matrix then we using method CReturn::optimalPortfolio()
     */
    vector<vector<double>> covarianceMatrix = CRisk::covarianceVarianceMatrix(google,amazon,
                                                                               apple,250,3);
    vector<vector<double>> optimalAllocation = CReturn::optimalPortfolio(covarianceMatrix, returnIT,
                                                                         3,3,1);
    cout<<fixed<<setprecision(2)<<"IT Portfolio year return "<<optimalAllocation[1][0]<<endl;
    cout<<fixed<<setprecision(2)<<"IT Portfolio risk (std) of year "<<optimalAllocation[1][1]<<endl;
    cout<<fixed<<setprecision(2)<<"Google allocation in portfolio: "<<optimalAllocation[0][0]<<endl;
    cout<<fixed<<setprecision(2)<<"Amazon allocation in portfolio: "<<optimalAllocation[0][1]<<endl;
    cout<<fixed<<setprecision(2)<<"Apple allocation in portfolio: "<<optimalAllocation[0][2]<<endl;
    CDataBase dbIT;

        cout<<"Do you buy portfolio insert - 1, sell - 2, logout - 0"<<endl;
        bool portfolioDone = false;
        int nITChose;
        cin >> nITChose;
        while(!portfolioDone){

    if (nITChose == 1) {
        string strPortfolioName, strCurrency;
        int nSymbolsSum;
        double dSpendMoney, dPredictionSum, dPortfolioRisk;
        fstream buyIT;
        buyIT.open(dbIT.getMStrToItPortfolio(), fstream::in | fstream::out);
        if (!buyIT.is_open()) {
            cout << "The error was happend when you open a file" << endl;
        } else {

            cout << "You are buying IT portfolio" << endl;
            cout << "Insert Portfolio Name: ";
            cin.ignore(1, ' ');
            getline(cin, strPortfolioName);
            buyIT << strPortfolioName << endl;

            cout << "Insert  how many Symbols: ";
            cin >> nSymbolsSum;
            buyIT << nSymbolsSum << endl;

            cout << "Insert which currency do you use: ";
            cin.ignore(1, ' ');
            getline(cin, strCurrency);
            buyIT << strCurrency << endl;

            cout << "How many money do you want to spend?: ";
            cin >> dSpendMoney;
            buyIT << dSpendMoney<<endl;

            double dWritingPredictedSum = dSpendMoney + ((optimalAllocation[1][0] / 100) * dSpendMoney);
            buyIT<<dWritingPredictedSum<<endl;

            ///Saving an Allocation of IT portfolio

            buyIT<<optimalAllocation[0][0]<<endl;
            buyIT<<optimalAllocation[0][1]<<endl;
            buyIT<<optimalAllocation[0][2]<<endl;
            buyIT<<optimalAllocation[1][1]<<endl;


        }

        fstream infoIT;
        infoIT.open(dbIT.getMStrToItPortfolio(), fstream::in | fstream::out);
        cout << "Information about portfolio and the Prediction of you income after 1 year: " << endl;

        ///Here is creating tuple type to get different type of values from file with library fstream
        tuple<string, int, string, double, double,double,double,double, double> itPortfolioInfo =
                make_tuple("", 0, "", 0.0, 0.0, 0.0,0.0,0.0,0.0);
        string strName, strSymboltupl;
        int nEtfCount;
        double dAmountMoney, dPredictedSum,dGoogle, dAmazon,dApple, dPortfolioRi;

        while (!infoIT.eof()) {
            infoIT>>ws;
            getline(infoIT, strName,'\n');
            infoIT >> nEtfCount;
            infoIT >> strSymboltupl;
            infoIT >> dAmountMoney;
            infoIT >> dPredictedSum;
            infoIT >> dGoogle;
            infoIT >> dAmazon;
            infoIT >> dApple;
            infoIT >> dPortfolioRi;
            itPortfolioInfo = make_tuple(strName, nEtfCount, strSymboltupl, dAmountMoney,dPredictedSum, dGoogle,
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
        cout << "BUT YOU RISK!!! ";
        cout << get<8>(itPortfolioInfo) << endl;
        infoIT.close();
        break;
    } else if (nITChose == 2) {
        fstream cleanIT;
        cleanIT.open(dbIT.getMStrToItPortfolio(), fstream::in | fstream::out | fstream::trunc);
        cleanIT.close();
        break;

    } else if(nITChose == 0){
        portfolioDone = true;
        break;
    }

}

    }

double CDataBase::meanOfAsset(std::vector<double> const &v) {
    double sumAssetCloseReturn = 0;
    //double meanAppleCloseReturn;

    for(int i = 0; i < v.size(); i++){
        sumAssetCloseReturn += v[i];
    }


    return sumAssetCloseReturn/v.size();
}

vector<double> CDataBase::slice(std::vector<double> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;

    vector<double> vec(first, last);
    return vec;
}

vector<double> CDataBase::returnOfAsset(std::vector<double> &v, int beginOfVector, int endOfVector) {
    for(int i = 0; i<v.size(); i++){
        if(i == v.size()-1){
            break;
        }
        v[i] = (v[i+1]/v[i])-1;

    }

    vector<double> justReturn;
    beginOfVector = 0;
    endOfVector = 250;
    justReturn  = slice(v, beginOfVector,endOfVector);
    /*for (const auto& x : justReturn ){
        cout<<x<<endl;
    }*/
    return justReturn;
}

CDataBase::~CDataBase() {

}

void CDataBase::choosePortfolio() {
    //tuple<vector<double>, vector<vector<double>>,  vector<vector<double>>> dataForChosenPortfolio = asset->getFromBase();
    cout<<"Choose which Portfolio do you want to buy: Google, Amazon, Apple - 1, QQQ, IXN, XLK - 2"<<endl;
    int nstockChose;
    cin>>nstockChose;
    if(nstockChose == 1){
        CDataBase::inputForStock();
    } else if (nstockChose == 2){
        CDataBase::inputForETF();
    }

}

const string &CDataBase::getMStrToItPortfolio() const {
    return m_strToITPortfolio;
}

void CDataBase::setMStrToItPortfolio(const string &mStrToItPortfolio) {
    m_strToITPortfolio = mStrToItPortfolio;
}

string CDataBase::getMStrToetfPortfolio() const {
    return m_strTOETFPortfolio;
}

/*void CDataBase::setMStrToetfPortfolio(const string &mStrToetfPortfolio) {
    m_strTOETFPortfolio;
}*/



