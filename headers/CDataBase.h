#ifndef KURSINIS_DARBAS_CDATABASE_H
#define KURSINIS_DARBAS_CDATABASE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "CRisk.h"
#include "CReturn.h"


//using namespace std;
///forward declaration
class CAsset;
/**
 * This class connect with database in this program database represent the files with extension .csv and .txt
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
 */

class CDataBase  {

public:

    CDataBase();

    CDataBase(CAsset *asset);
    /**
     * @brief Method get and set data of ETF to database in this program database are the files and relation with them
     * is through  fstream library
     * @return void
     */

    void inputForETF();
    /**
     *@brief Method get and set data of Stocks to database in this program database are the files and relation with them
     * is through fstream library
     * @return void
     */

   void inputForStock();
    /**
     * @brief calculate meanOfAsset
     * @param v
     * @return double
     */

    double meanOfAsset(const std::vector<double> &v);
    /**
     * @brief Method helps to set size of std::vector
     * @param v double std::vector type to set std::vector with some value
     * @param m int type std::vector the begining of std::vector
     * @param n int type the ending of std::vector
     * @return std::vector<double>
     */

    std::vector<double> slice(const std::vector<double> &v, int m, int n);
    /**
     * @brief Method calculate return of Assets
     * @param v std::vector type std::vector with value of returns
     * @param beginOfstd::vector int type the begining of std::vector
     * @param endOfstd::vector int type the ending of std::vector
     * @return std::vector<double>std::vector
     */

    std::vector<double> returnOfAsset(std::vector<double> &v, int beginOfVector, int endOfVector);

    void choosePortfolio();

    const std::string &getMStrToItPortfolio() const;

    void setMStrToItPortfolio(const std::string &mStrToItPortfolio);

     std::string getMStrToetfPortfolio() const;

    //void setMStrToetfPortfolio(const std::string &mStrToetfPortfolio);

    virtual ~CDataBase();

private:
    std::string m_strTOETFPortfolio;
    std::string m_strToITPortfolio;
    std::string strInstrumentName, strSymbol, strTradeDate;
    double dMarketValue, dInstrumenAmount,dDayGain, dTotalGain;
    CAsset *asset;


};


#endif //KURSINIS_DARBAS_CDATABASE_H
