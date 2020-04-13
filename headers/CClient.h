
#ifndef KURSINIS_DARBAS_CCLIENT_H
#define KURSINIS_DARBAS_CCLIENT_H

#include <iostream>
#include <string>
#include "CUser.h"
#include "CMyHoldings.h"
#include "CDataBase.h"
///forward declaration
class CPortfolio;
///forward declaration
class CAsset;
/**
 * This class create client objects and maintain them
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
 */

class CClient : public CUser
{
public:

    CClient(const string &mStrClientName, const string &mStrCreditCardInfo, const string &mStrAccount,
            double mDAccountBalance, const CMyHolding &myHolding);

    CClient();

    /**
     * @brief Method get Client name
     * @return const string
     */

    const std::string &getMStrClientName() const;
    /**
     * @brief Method set Client name
     * @param mStrClientName set Client name which is using to enter to program
     * @return void
     */

    void setMStrClientName(const std::string &mStrClientName);
    /**
     * @brief Method get Credit card number
     * @return const string
     */

    const std::string &getMStrCreditCardInfo() const;
    /**
     * @brief Method set number of credit card of Client
     * @param mStrCreditCardInfo type of string for setting number of Credit card
     * @return void
     */

    void setMStrCreditCardInfo(const std::string &mStrCreditCardInfo);

     /**
     * @brief Method create Client menu through which you can set and get data for Client
     * @return void
     */

    void createClientMenu();
    /**
     * @brief Method create items of Client menu
     * @return int
     */

    int clientMenu();

    void getAllInfoAboutUser() override;


    const string &getMStrPathForClient() const;

    virtual ~CClient();

private:
    std::string m_strClientName;
    std::string m_strCreditCardInfo;
    std::string m_strAccount;
    string m_strPathForClient;
    double m_dAccountBalance;
    CMyHolding myHolding;

};


#endif //KURSINIS_DARBAS_CCLIENT_H
