#ifndef KURSINIS_DARBAS_CASSET_H
#define KURSINIS_DARBAS_CASSET_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;
#include "CDataBase.h"

/**
 * This class is pure virtual class and from it are inhereted those class: CPortfolio, CStock, CETF
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
 */

class CAsset
{
public:
/**
 *@brief This class is the virtual class and we can not create it objects, but we can inherit methods of this class
 * and derived classes of this class are CStock, CETF, CPortfolio,
 * @param mStrAssetName set name of the Asset of the string type
 * @param mStrSymbol set symbol of the Asset of the string type
 * @param mStrTradeDate set date when getting Asset and it is the string type for this operation is using library ctime
 * @param mDAmount double parameter that get and set amaount of Assets
 * @param mDMarketValue double parameter that get and set Value of Assets
 * @param mDDayGain
 * @param mDTotalGain
 * @param mNPredictionDays
 */
    CAsset(const std::string &mStrAssetName, const std::string &mStrSymbol, const std::string &mStrTradeDate,
           double mDAmount, double mDMarketValue, double mDDayGain, double mDTotalGain, int mNPredictionDays);

    CAsset();
/**
 * @brief Method set name of Asset
 * @return const string
 */
    const std::string &getMStrAssetName() const;


    /**
     * @brief Method get data from database through the class CDataBase
     * @return tuple<vector<double>, vector<vector<double>>,  vector<vector<double>>>
     */

    tuple<vector<double>, vector<vector<double>>,  vector<vector<double>>>  getFromBase();

    virtual void printAssetInfo() const = 0;

    /**
     * @brief Method helps to set size of vector for next method returnOfAsset()
     * @param v Type of vector, here insert vector
     * @param m type int to set from which value (index) you are starting the vector
     * @param n type int to set from which value (index) you ending the vector
     * @return vector<double>
     */

    vector<double> slice(const vector<double> &v, int m, int n);
    /**
     * @brief Method returns what is returns of one Asset in the setting period, get info for this from database
     * @param v type vector of double all info about some Asset
     * @param beginOfVector type int the beginning of the vector
     * @param endOfVector type int ending of the vector
     * @return vector<double>
     */

    vector<double> returnOfAsset(vector<double> &v, int beginOfVector, int endOfVector);
    /**
     * @brief Method calculate mean of one Asset
     * @param v vector of double it is from vector that is got when was calculating prices wiht method returnOfAsset()
     * @return  double
     */

    double meanOfAsset(const vector<double> &v);
    /**
     * @brief Method return diffrence between vector of returns and double value of mean of return of Asset
     * @param v vector of doubles got from return of Assets
     * @param d double type which is get with method meanOfAsset()
     * @return vector<double>
     */

    vector<double> returnAndMeanDiffrence(vector<double> &v, double d);
    /**
     * @brief Method gets risk of one Asset
     * @param v vector of doubles got with method returnAndMeanDiffrence()
     * @param n double type that show how much big is set of values of Asset
     * @return double
     */

    double riskOfAsset(vector<double> &v, int n);

    virtual ~CAsset();

protected:
private:
    std::string m_strAssetName;
    std::string m_strSymbol;
    std::string m_strTradeDate;
    double m_dAmount;
    double m_dMarketValue;
    double m_dDayGain;
    double m_dTotalGain;
    int m_nPredictionDays;

};

#endif //KURSINIS_DARBAS_CASSET_H
