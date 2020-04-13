/**
 * This class show info about Asset - Stocks, it inherited from class CAsset
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
 */


#ifndef KURSINIS_DARBAS_CSTOCK_H
#define KURSINIS_DARBAS_CSTOCK_H

#include <string>
#include "CAsset.h"


class CStock : public  CAsset {
public:
    CStock(const string &mStrAssetName, const string &mStrSymbol, const string &mStrTradeDate, double mDAmount,
           double mDMarketValue, double mDDayGain, double mDTotalGain);

    CStock();
    /**
     * @brief Method which gets the items of Stock info menu with the switch statement and the cases conditions
     * @return int
     */
    int stockMenu();
    /**
     * @brief Method gets and sets all info about stock using switch statement, case, if, else if, else conditions and
     * while loop
     * @return void
     */

    void stockInfo();
    /**
     * @return void
     */

    void printAssetInfo() const override;

    const string &getMStrPathToGoogle() const;

    const string &getMStrPathToAppl() const;

    const string &getMStrPathtToAmznDate() const;


    virtual ~CStock();

private:
    CDataBase dataStock;
    std::string m_strPathToGoogle;
    std::string m_strPathToAppl;
    std::string m_strPathtToAmznDate;

};


#endif //KURSINIS_DARBAS_CSTOCK_H
