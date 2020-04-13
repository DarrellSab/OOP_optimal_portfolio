#ifndef KURSINIS_DARBAS_CADMINISTRATOR_H
#define KURSINIS_DARBAS_CADMINISTRATOR_H

#include <iostream>
#include <string>

#include "CUser.h"
#include "CClient.h"

/**
 * @brief The class CAdministrator creates object of administrator that maintain, change the program Optimal Portfolio.
 * @details The class CAdministrator inherits some properties from class CUser
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
 *
 */
class CAdministrator : public CUser  {

public:
    CAdministrator();
    /**
     * @brief Constructor which creates object with name and can get methods from classes CClient and CDataBase.
     * The relationship with the class CClient is aggregation and with the class CDataBase is a composition
     * @param mStrNameOfAdministrator
     * @param client
     * @param databaseAdmin
     */

    CAdministrator(const string &mStrNameOfAdministrator, CClient *client, const CDataBase &databaseAdmin);

/**
 * @brief Method helps to get info about administrator through menu
 * @return int
 */
    int adminMenu();
    /**
     * @brief Method with while loop, switch expression and fstream library to register the administrator and can get
     * info about administrator
     * @return void
     */

    void createAdministratorMenu();
    /**
     * @brief Method sets name for object of this class
     * @param mStrNameOfAdministrator this parameter set name of administrator of program
     * @return void
     */
    void setMStrNameOfAdministrator(const string &mStrNameOfAdministrator);

    /**
     * @brief Method gets name of object created with class CAdministrator
     * @return const string
     */

    const string &getMStrNameOfAdministrator() const;

    void getAllInfoAboutUser() override;

    virtual ~CAdministrator();

private:
    string m_strNameOfAdministrator;
    CClient *client;
    CDataBase databaseAdmin;

};

#endif //KURSINIS_DARBAS_CADMINISTRATOR_H
