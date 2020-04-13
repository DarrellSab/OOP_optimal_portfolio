#include <iostream>
#include <string>
#include <cmath>
#include <tuple>
#include <vector>
#include "../headers/CAsset.h"
#include "../headers/CStock.h"
#include "../headers/CETF.h"

CAsset::CAsset() {}

CAsset::CAsset(const std::string &mStrAssetName, const std::string &mStrSymbol, const std::string &mStrTradeDate,
               double mDAmount, double mDMarketValue, double mDDayGain, double mDTotalGain, int mNPredictionDays)
        : m_strAssetName(
        mStrAssetName), m_strSymbol(mStrSymbol), m_strTradeDate(mStrTradeDate), m_dAmount(mDAmount), m_dMarketValue(
        mDMarketValue), m_dDayGain(mDDayGain), m_dTotalGain(mDTotalGain), m_nPredictionDays(mNPredictionDays) {}

const std::string &CAsset::getMStrAssetName() const {
    return m_strAssetName;
}

///this method get data of IT stocks and ETF from database files
tuple<vector<double>, vector<vector<double>>,  vector<vector<double>>> CAsset::getFromBase() {

     double dApplecloseData, damznCloseData, dGoogleClose, dQQQcloseData, dIXNcloseData, dXLKcloseData;
     vector<double> appleCloseData, amznCloseData, googleCloseData, qqqCloseData, ixnCloseData, xlkCloseData;
     ///Here is creating object of the class CStock to get data from database about all Stocks
     CStock stock;

     ///The vector that get data seperate for IT and for ETF info about close price
     vector<vector<double>> closeOfIT;
     vector<vector<double>> closeOfETF;

     vector<vector<double>> allMeanOfAssets;

                fstream closeGoogle;
                ///Here program is getting info from files that to show when is asking about return and risk of one Asset
                closeGoogle.open( stock.getMStrPathToGoogle(), ios::in);
                while (!closeGoogle.eof()){
                    closeGoogle>>dGoogleClose;
                    googleCloseData.emplace_back(dGoogleClose);
                }
                closeGoogle.close();

                vector<double> justGoogleReturn = returnOfAsset(googleCloseData,0,250);
                double meanOfGoogle = meanOfAsset(justGoogleReturn);

                fstream closeAmzn;
                closeAmzn.open(stock.getMStrPathtToAmznDate(), ios::in);
                while (!closeAmzn.eof()){
                    closeAmzn>>damznCloseData;
                    amznCloseData.emplace_back(damznCloseData);
                }
                closeAmzn.close();

                vector <double> justAmazonReturn = returnOfAsset(amznCloseData,0,250);
                double meanOfAmazon = meanOfAsset(justAmazonReturn);

                fstream closeAppl;
                closeAppl.open(stock.getMStrPathToAppl(), ios::in);
                while (!closeAppl.eof()){
                    closeAppl>>dApplecloseData;
                    appleCloseData.emplace_back(dApplecloseData);
                }
                closeAppl.close();
                vector<double> justAppleReturn = returnOfAsset(appleCloseData,0,250);
                double meanOFApple = meanOfAsset(justAppleReturn);

                ///Here is creating object of the class CETF to get data from database
                CETF etf;

                fstream closeQQQ;
                closeQQQ.open(etf.getMStrPathToQqq(), ios::in);
                while (!closeQQQ.eof()){
                    closeQQQ>>dQQQcloseData;
                    qqqCloseData.emplace_back(dQQQcloseData);
                }
                closeQQQ.close();

                vector<double> justQQQReturn = returnOfAsset(qqqCloseData,0,250);
                double meanOFQQQ = meanOfAsset(justQQQReturn);

                fstream closeIXN;
                closeIXN.open(etf.getMStrPathToIxn(), ios::in);
                while (!closeIXN.eof()){
                    closeIXN>>dIXNcloseData;
                    ixnCloseData.emplace_back(dIXNcloseData);
                }
                closeIXN.close();

                vector<double> justIXNReturn = returnOfAsset(ixnCloseData,0,250);
                double meanOFIXN = meanOfAsset(justIXNReturn);

                fstream closeXLK;
                closeXLK.open(etf.getMStrPathToXlk(), ios::in);
                while (!closeXLK.eof()){
                    closeXLK>>dXLKcloseData;
                    xlkCloseData.emplace_back(dXLKcloseData);
                }
                closeXLK.close();
                vector<double> justXLKReturn = returnOfAsset(xlkCloseData,0,250);
                double meanOFXLK = meanOfAsset(justXLKReturn);
                ///vector of vectors contain vectors of ETF stocks return
                vector<vector<double>> vectorOfAllReturn;
                vectorOfAllReturn.emplace_back(justGoogleReturn);
                vectorOfAllReturn.emplace_back(justAmazonReturn);
                vectorOfAllReturn.emplace_back(justAppleReturn);
                vectorOfAllReturn.emplace_back(qqqCloseData);
                vectorOfAllReturn.emplace_back(ixnCloseData);
                vectorOfAllReturn.emplace_back(xlkCloseData);

/////////////////////////////////////////////////////////////////////////////////////////
///vector of mean of assets
                vector<double> vectorOfReturn{meanOfGoogle, meanOfAmazon, meanOFApple, meanOFQQQ, meanOFIXN, meanOFXLK};
////////////////////////////////////////////////////////////////////////////////////////
///Vector of diffrence betwean mean and return of Asset price
///vectors of squared diffrence between return and mean of return for IT portfolio
                vector<double> diffrenceMeanReturnGoogle = returnAndMeanDiffrence(justGoogleReturn,meanOfGoogle);

                vector<double> diffrenceMeanReturnAmazon = returnAndMeanDiffrence(justAmazonReturn,meanOfAmazon);

                vector<double> diffrenceMeanReturnApple = returnAndMeanDiffrence(justAppleReturn,meanOFApple);
                ///vector of vectors for diffence vectors of IT portfolio
                vector<vector<double>> vectorForCovarianceMatrixIT;

                vectorForCovarianceMatrixIT.emplace_back(diffrenceMeanReturnGoogle);

                vectorForCovarianceMatrixIT.emplace_back(diffrenceMeanReturnAmazon);

                vectorForCovarianceMatrixIT.emplace_back(diffrenceMeanReturnApple);
                ///vectors of squared diffrence between return and mean of return for ETF portfolio
                vector<double> diffrenceMeanReturnQQQ = returnAndMeanDiffrence(justQQQReturn,meanOFQQQ);

                vector<double> diffrenceMeanReturnIXN = returnAndMeanDiffrence(justIXNReturn,meanOFIXN);

                vector<double> diffrenceMeanReturnXLK = returnAndMeanDiffrence(justXLKReturn,meanOFXLK);
                ///vector of vectors for diffence vectors of ETF portfolio
                vector<vector<double>> vectorForCovarianceMatrixAlldifrence;
    vectorForCovarianceMatrixAlldifrence.emplace_back(diffrenceMeanReturnGoogle);
    vectorForCovarianceMatrixAlldifrence.emplace_back(diffrenceMeanReturnAmazon);
    vectorForCovarianceMatrixAlldifrence.emplace_back(diffrenceMeanReturnApple);
    vectorForCovarianceMatrixAlldifrence.emplace_back(diffrenceMeanReturnQQQ);
    vectorForCovarianceMatrixAlldifrence.emplace_back(diffrenceMeanReturnIXN);
    vectorForCovarianceMatrixAlldifrence.emplace_back(diffrenceMeanReturnXLK);

//////////////////////////////////////////////////////////////////////////////////////////////
///Tuple of vectors of vectors of returns, diffrence between mean and returns, mean of returns
tuple<vector<double>, vector<vector<double>>,  vector<vector<double>>> tupleOFAllInfo;
tupleOFAllInfo = make_tuple(vectorOfReturn, vectorOfAllReturn, vectorForCovarianceMatrixAlldifrence);
tie(vectorOfReturn, vectorOfAllReturn, vectorForCovarianceMatrixAlldifrence) = tupleOFAllInfo;

    return tupleOFAllInfo;


        }

vector<double> CAsset::slice(std::vector<double> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;

    vector<double> vec(first, last);
    return vec;
}

vector<double> CAsset::returnOfAsset(std::vector<double> &v, int beginOfVector, int endOfVector) {
    for(int i = 0; i<v.size(); i++){
        if(i == v.size()-1){
            break;
        }
        v[i] = (v[i+1]/v[i])-1;

    }

    vector<double> justReturn;
    beginOfVector = 0;
    endOfVector = 250;
    justReturn  = CAsset::slice(v, beginOfVector,endOfVector);
    /*for (const auto& x : justReturn ){
        cout<<x<<endl;
    }*/
    return justReturn;
}

double CAsset::meanOfAsset(std::vector<double> const &v) {
    double sumAssetCloseReturn = 0;
    //double meanAppleCloseReturn;

    for(int i = 0; i < v.size(); i++){
        sumAssetCloseReturn += v[i];
    }


    return sumAssetCloseReturn/v.size();
}

vector<double> CAsset::returnAndMeanDiffrence(vector<double> &v, double d) {
    for(int i = 0; i < v.size(); i++){
        v[i] = pow((v[i] -d),2);
    }

    return v;
}

double CAsset::riskOfAsset(vector<double> &v, int n) {
    double sum = 0.0;
    for(int i =0; i< n; i++){
        sum += v[i];
    }

    return (sqrt(sum))*100;
}



CAsset::~CAsset() = default;












