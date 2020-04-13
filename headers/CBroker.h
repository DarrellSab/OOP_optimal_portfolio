#ifndef KURSINIS_DARBAS_CBROKER_H
#define KURSINIS_DARBAS_CBROKER_H

#include "CUser.h"
#include "CDataBase.h"
#include <string>
#include "CAsset.h"
/**
 * CBroker class create object of broker who is related with class CPortfolio through aggregation relationship
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
 */
class CBroker : public CUser
{
public:
    /*CBroker(std::string mStrUsername, const std::string &mStrBrokerName, const std::string &mStrPhoneNumber,
            const std::string &mStrEmail, double mDSalary);*/

    //CBroker(const std::string &mStrUsername);
/**
 * @brief Constructor that create object which have Broker name and some salary
 * @param mStrBrokerName type of string set Broker name
 * @param mDSalary type double set Salary for object of the class of CBroker
 */
    CBroker(const std::string &mStrBrokerName, double mDSalary);

    CBroker();
/**
 * @brief Method get Broker name from member field m_strBrokerName
 * @return const string
 */
    const std::string &getMStrBrokerName() const;
    /**
     * @brief Method set Broker name
     * @param mStrBrokerName type of string set name
     * @return void
     */

    void setMStrBrokerName(const std::string &mStrBrokerName);

    double getMDSalary() const;

    void setMDSalary(double mDSalary);

    /**
     * @brief this CBroker member function is creating menu to get info or to create broker account
     * @return int
     */
    int brokerMenu();
    /**
     * @brief This function create Broker menu through this you can register, change info about Broker
     * @return void
     */

    void createBrokerMenu();

    void getAllInfoAboutUser() override;

    virtual ~CBroker();

protected:
private:
    std::string m_strBrokerName;
    double m_dSalary;
    CAsset *asset;
    CDataBase *brokerDatabase;

};
#endif //KURSINIS_DARBAS_CBROKER_H
