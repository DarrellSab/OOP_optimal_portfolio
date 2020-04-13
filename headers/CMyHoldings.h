
#ifndef KURSINIS_DARBAS_CMYHOLDINGS_H
#define KURSINIS_DARBAS_CMYHOLDINGS_H

///forward declaration
class CPortfolio;
#include "CBroker.h"
#include <string>
/**This class help for class CClient get info about portfolios and the assets from CPortfolio class and indirect
 * from CETF and CStock
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
*/
class CMyHolding
{
public:

    /**
     * Constructor to create objects of class CMyHolding
     * @param mStrHoldingName string type to set and get name of holding
     * @param mDTotalSum double type to count total sum of all portfolios
     * @param mDDayGain double type to get day gain of object of class CMyHolding
     * @param mDTotalGain  double type to get total gain of object of class CMyHolding
     * @param portfolio  CPortfolio type to relate with class CPortfolio in aggregation relation
     * @param mStrHoldingRegisterDate string type to set register date of the holding
     */
    CMyHolding(const std::string &mStrHoldingName, double mDTotalSum, double mDDayGain, double mDTotalGain,
               CPortfolio *portfolio, std::string mStrHoldingRegisterDate);

    CMyHolding();
/**
 * @brief Method get register data of holding
 * @return const string
 */
    const std::string &getMStrHoldingRegisterDate() const;
    /**
     * @brief Method set register Date of Holding
     * @param mStrHoldingRegisterDate string type and setting is with help of library ctime
     * @return void
     */

    void setMStrHoldingRegisterDate(const std::string &mStrHoldingRegisterDate);
    /**
     * @brief Method gets holding name
     * @return const string
     */

    const std::string &getMStrHoldingName() const;
    /**
     * @brief Methos sets holding name
     * @param mStrHoldingName
     * @return void
     */

    void setMStrHoldingName(const std::string &mStrHoldingName);

    double getMDTotalSum() const;

    void setMDTotalSum(double mDTotalSum);

    double getMDDayGain() const;

    void setMDDayGain(double mDDayGain);

    double getMDTotalGain() const;

    void setMDTotalGain(double mDTotalGain);

    /**
     * @brief Method gets items of holding menu to enter in main menu for holding information
     * @return int
     */

    int holdingMenu();
    /**
     * @brief Method set and gets all information about holding of Client
     * @return void
     */

    void createHoldingMenu();

    const std::string &getMStrPathForHolding() const;

    virtual ~CMyHolding();


protected:
private:
    std::string m_strHoldingName;
    std::string m_strHoldingRegisterDate;
    std::string m_strPathForHolding;
    double m_dTotalSum;
    double m_dDayGain;
    double m_dTotalGain;
    CPortfolio *portfolio;

};
#endif //KURSINIS_DARBAS_CMYHOLDINGS_H
