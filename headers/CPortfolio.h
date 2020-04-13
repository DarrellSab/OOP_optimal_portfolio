/**
 * This class is connected with CBroker, CDatabase,CRisk, CReturn,CStock and CETF classes
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
 */

#ifndef KURSINIS_DARBAS_CPORTFOLIO_H
#define KURSINIS_DARBAS_CPORTFOLIO_H

#include <string>
#include "CAsset.h"
#include "CClient.h"
#include "CStock.h"
#include "CETF.h"
#include "CBroker.h"
#include "CRisk.h"
#include "CReturn.h"
#include "CDataBase.h"
#include "CMyHoldings.h"


class CPortfolio : public CAsset
{
public:

    CPortfolio(const string &mStrPortfolioName, int mNSimbols, const string &mStrCurrency, CBroker *broker,
               const CDataBase &portfolioData, const CRisk &portfolioRisk, const CReturn &portfolioReturn,
               const CStock &stock, const CETF &etf);

    CPortfolio();
    /**
     * @brief Method set name of the portfolio
     * @param mStrPortfolioName string type to set name
     * @return void
     */

    void setMStrPortfolioName(const string &mStrPortfolioName);
    /**
     * @brief Method set currency of the portfolio
     * @param mStrCurrency string type set currency of the portfolio
     * @return void
     */

    void setMStrCurrency(const string &mStrCurrency);
    /**
     * @brief Method print info about Asset
     * @return void
     */

    void printAssetInfo() const override;
    /**
     * @brief Method get porftolio name
     * @return const string
     */

    const std::string &getMStrPortfolioName() const;

    const std::string &getMStrCurrency() const;

    /**
     * @brief Method get symbol of the poetfolio
     * @return int
     */

    int getMNSimbols() const;
    /**
     * @brief Method set symbol of Asset in the portfolio
     * @param mNSimbols
     * @return void
     */

    void setMNSimbols(int mNSimbols);

    /**
     * @brief Method get the items of portfolio menu
     * @return int
     */

    int createUserPortfolio();
    /**
     * @brief Mehtod set and get all information about the portfolios
     * @return void
     */

    void userPortfolio();

    double getMDAmountToSpend() const;

    double setMDAmountToSpend(double mDAmountToSpend);

    int getMNDaysForPrediction() const;

    void setMNDaysForPrediction(int mNDaysForPrediction);

    const string &getMStrToItPortfolio() const;

    const string &getMStrToEtfPortfolio() const;

    virtual ~CPortfolio();

protected:
private:
    std::string m_strPortfolioName;
    int m_nSimbols;
    double m_dAmountToSpend;
    std::string m_strCurrency;
    int m_nDaysForPrediction;
    std::string m_strToITPortfolio;
    std::string m_strToETFPortfolio;
    CBroker *broker;
    CDataBase portfolioData;
    CRisk portfolioRisk;
    CReturn portfolioReturn;
    CStock stock;
    CETF etf;



};
#endif //KURSINIS_DARBAS_CPORTFOLIO_H
