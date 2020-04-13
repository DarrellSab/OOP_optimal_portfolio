#ifndef KURSINIS_DARBAS_CUSER_H
#define KURSINIS_DARBAS_CUSER_H

#include <string>
/**
 * @author Darius Sabaliauskas
 * @version Optimal Portfolio 0.1
 * @date 2020-01-07*/
 /**
 * This class create the user who will be use the program, a trader, a broker or an administrator and
 * have some classes that are derived from CUser:  CClient, CBroker, CAdministrator
 */

class CUser
{
public:
    CUser(std::string m_strUsername);

    CUser(const std::string &mStrUsername, const std::string &mStrPassword, const std::string &mStrLoginStatus,
          const std::string &mStrRegisterDate, const std::string &mStrPhoneNumber, const std::string &mStrEmail,
          const std::string &mStrAddress);

    CUser();
    /**
     *
     * @return const string
     */

    const std::string &getMStrUsername();
    /**
     *
     * @param mStrUsername
     * @return void
     */

    void setMStrUsername(const std::string &mStrUsername);
    /**
     *
     * @return const string
     */

    const std::string &getMStrPassword() const;
    /**
     *
     * @param mStrPassword
     * @return void
     */

    void setMStrPassword(const std::string &mStrPassword);
    /**
     *
     * @return const string
     */

    const std::string &getMStrRegisterDate() const;
    /**
     *
     * @param mStrRegisterDate
     * @return void
     */

    void setMStrRegisterDate(const std::string &mStrRegisterDate);
    /**
     *
     * @return const string
     */

    const std::string &getMStrPhoneNumber() const;
    /**
     *
     * @param mStrPhoneNumber
     * @return void
     */

    void setMStrPhoneNumber(const std::string &mStrPhoneNumber);
    /**
     *
     * @return const string
     */

    const std::string &getMStrEmail() const;
    /**
     *
     * @param mStrEmail
     * @return void
     */

    void setMStrEmail(const std::string &mStrEmail);
    /**
     *
     * @return const string
     */

    const std::string &getMStrAddress() const;
    /**
     *
     * @param mStrAddress
     * @return void
     */

    void setMStrAddress(const std::string &mStrAddress);

    virtual void getAllInfoAboutUser() = 0;

    virtual ~CUser();

protected:
private:

    std::string m_strUsername;
    std::string m_strPassword;
    std::string m_strLoginStatus;
    std::string m_strRegisterDate;
    std::string m_strPhoneNumber;
    std::string m_strEmail;
    std::string m_strAddress;
};
#endif //KURSINIS_DARBAS_CUSER_H
