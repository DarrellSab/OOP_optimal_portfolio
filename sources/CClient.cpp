#include "../headers/CClient.h"
#include "../headers/CPortfolio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;

CClient::CClient() {
    m_strPathForClient= "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/client.txt";
}

CClient::CClient(const string &mStrClientName, const string &mStrCreditCardInfo, const string &mStrAccount,
                 double mDAccountBalance, const CMyHolding &myHolding) : m_strClientName(mStrClientName),
                                                                         m_strCreditCardInfo(mStrCreditCardInfo),
                                                                         m_strAccount(mStrAccount),
                                                                         m_dAccountBalance(mDAccountBalance),
                                                                         myHolding(myHolding) {}

const std::string &CClient::getMStrClientName() const {
    return m_strClientName;
}

void CClient::setMStrClientName(const std::string &mStrClientName) {
    m_strClientName = mStrClientName;
}

const std::string &CClient::getMStrCreditCardInfo() const {
    return m_strCreditCardInfo;
}

void CClient::setMStrCreditCardInfo(const std::string &mStrCreditCardInfo) {
    m_strCreditCardInfo = mStrCreditCardInfo;
}

int CClient::clientMenu() {

    int selection;
    cout<<"Hello new Client"<<endl;
    cout<<"Input 1---User register"<<endl;
    cout<<"Input 2---User Info"<<endl;
    cout<<"Input 3---Login"<<endl;
    cout<<"Input 0---Logout"<<endl;
    cin>>selection;
    return selection;

}

void CClient::createClientMenu() {
    string userName,userFullName, userPassword, userRegisterDate, userCreditCard, userPhoneNumber,
            userEmail, userAddress;

    bool doneClient = false;
    while (!doneClient){
        int selectUser = clientMenu();
        switch (selectUser){
            case 1:{
                fstream user;
                user.open(getMStrPathForClient(),fstream::in | fstream::out);
                cout<<"Insert User Name One Word: ";
                cin>>userName;
                user<<userName<<endl;
                cout<<"Insert Password: ";
                cin>>userPassword;
                user<<userPassword<<endl;
                cout<<"Insert Full Name: ";
                cin.ignore(1,' ');
                getline(cin,userFullName);
                user<<userFullName<<endl;
                time_t timeNow = time(0);
                tm* localtm = localtime(&timeNow);
                user<<asctime(localtm);
                cout<<"Insert Number Of Card: ";
                cin.ignore(0,' ');
                getline(cin,userCreditCard);
                user<<userCreditCard<<endl;
                cout<<"Insert Phone Number, like 370-123-445678: ";
                cin.ignore(0,' ');
                getline(cin,userPhoneNumber);
                user<<userPhoneNumber<<endl;
                cout<<"Insert Email: ";
                cin.ignore(0,' ');
                getline(cin,userEmail);
                user<<userEmail<<endl;
                user>>ws;
                cout<<"Insert address: ";
                cin.ignore(0,' ');
                getline(cin,userAddress);
                user<<userAddress<<endl;
                user.close();
                break;
            }
            case 2:{
                fstream fs;
                fs.open(getMStrPathForClient(),fstream::in | fstream::out);
                cout<<"Data about user: "<<endl;
                getline(fs,userName, '\n');
                CUser::setMStrUsername(userName);
                //cout<<CUser::getMStrUsername()<<endl;
                fs>>ws;
                getline(fs,userPassword, '\n');
                CUser::setMStrPassword(userPassword);
                //cout<<CUser::getMStrPassword()<<endl;
                fs>>ws;
                getline(fs,userFullName, '\n');
                setMStrClientName(userFullName);
                cout<<CClient::getMStrClientName()<<endl;
                fs>>ws;
                getline(fs,userRegisterDate, '\n');
                CUser::setMStrRegisterDate(userRegisterDate);
                cout<<CUser::getMStrRegisterDate()<<endl;
                fs>>ws;
                getline(fs,userCreditCard, '\n');
                setMStrCreditCardInfo(userCreditCard);
                cout<<getMStrCreditCardInfo()<<endl;
                fs>>ws;
                getline(fs,userPhoneNumber, '\n');
                CUser::setMStrPhoneNumber(userPhoneNumber);
                cout<<CUser::getMStrPhoneNumber()<<endl;
                fs>>ws;
                getline(fs,userEmail, '\n');
                CUser::setMStrEmail(userEmail);
                cout<<CUser::getMStrEmail()<<endl;
                fs>>ws;
                getline(fs,userAddress, '\n');
                CUser::setMStrAddress(userAddress);
                cout<<CUser::getMStrAddress()<<endl;
                fs>>ws;
                fs.close();
                break;
            }
            case 3:{
                string strClientName, strClientPsw;
                cout<<"Please insert User name: "<<endl;
                cin>>strClientName;
                cout<<"Please insert password: "<<endl;
                cin>>strClientPsw;
                fstream clientLogin;
                clientLogin.open(getMStrPathForClient(),fstream::in | fstream::out);
                getline(clientLogin,userName, '\n');
                CUser::setMStrUsername(userName);
                clientLogin>>ws;
                getline(clientLogin,userPassword, '\n');
                CUser::setMStrPassword(userPassword);
                if(strClientName == CUser::getMStrUsername() && strClientPsw == CUser::getMStrPassword()){
                    myHolding.createHoldingMenu();
                }else{
                    cout<<"You insert wrong data"<<endl;
                }
                clientLogin.close();
                break;
            }
            case 0:{

                doneClient = true;
                break;
            }

            default:{
                cerr << "Unknown command" << endl;
                break;
            }
        }
    }


}

CClient::~CClient() {

}



void CClient::getAllInfoAboutUser() {
    cout<<" User name: "<<CUser::getMStrUsername()<<endl;

}

const string &CClient::getMStrPathForClient() const {
    return m_strPathForClient;
}
























