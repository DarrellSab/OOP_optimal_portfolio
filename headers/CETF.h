/**
 * This class show info about Asset - ETF, it inherited from class CAsset
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
 */


#ifndef KURSINIS_DARBAS_CETF_H
#define KURSINIS_DARBAS_CETF_H

#include "CAsset.h"


class CETF : public CAsset
        {
public:

    CETF();

    /**
     * @return void
     */

    void printAssetInfo() const override;
    /**
     * @brief Method which get the items of ETF menu
     * @return int
     */

    int etfMenu();
    /**
     * @brief Method get and set all info about object of class CETF
     * @return void
     */

    void etfInfo();

    const string &getMStrPathToEtfInfo() const;

    const string &getMStrPathToQqq() const;

    const string &getMStrPathToIxn() const;

    const string &getMStrPathToXlk() const;


    virtual ~CETF();

protected:
private:

    CDataBase etfData;
    std::string m_strPathToETFInfo;
    std::string m_strPathToQQQ;
    std::string m_strPathToIXN;
    std::string m_strPathToXLK;

};


#endif //KURSINIS_DARBAS_CETF_H
