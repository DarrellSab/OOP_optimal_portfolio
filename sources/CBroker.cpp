#include "../headers/CBroker.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;



CBroker::CBroker(const string &mStrBrokerName, double mDSalary) : m_strBrokerName(mStrBrokerName),
                                                                  m_dSalary(mDSalary) {}

CBroker::CBroker() {}

const string &CBroker::getMStrBrokerName() const {
    return m_strBrokerName;
}

void CBroker::setMStrBrokerName(const string &mStrBrokerName) {
    m_strBrokerName = mStrBrokerName;
}

double CBroker::getMDSalary() const {
    return m_dSalary;
}

void CBroker::setMDSalary(double mDSalary) {
     m_dSalary = mDSalary;
}

int CBroker::brokerMenu() {
    int selection;
    cout<<"Hello "<<getMStrBrokerName()<<" Broker"<<endl;
    cout<<"Input 1---Register"<<endl;
    cout<<"Input 2---Get info about broker"<<endl;
    cout<<"Input 3---Login"<<endl;
    cout<<"Input 0---Logout"<<endl;
    cin>>selection;

    return selection;
}

void CBroker::createBrokerMenu() {
    string userName,userFullName, userPassword, userRegisterDate, userPhoneNumber,
            userEmail, userAddress;
    string strPathToBroker = "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/broker.txt";
    bool doneBroker = false;
    while (!doneBroker) {
        int selection = brokerMenu();
        switch (selection){
            case 1: {
                fstream user;
                user.open(strPathToBroker,fstream::in | fstream::out);
                cout<<"Insert User Name: ";
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
                cout<<"Insert Phone Number, like 370-123-445678: ";
                cin>>userPhoneNumber;
                user<<userPhoneNumber<<endl;
                cout<<"Insert Email: ";
                cin>>userEmail;
                user<<userEmail<<endl;
                cout<<"Insert address: ";
                cin.ignore(1,' ');
                getline(cin,userAddress);
                user<<userAddress<<endl;
                user.close();
                break;
            }
            case 2:
            {
                fstream fs;
                fs.open(strPathToBroker,fstream::in | fstream::out);
                cout<<"Data about Broker: "<<endl;
                getline(fs,userName, '\n');
                CUser::setMStrUsername(userName);
                //cout<<CUser::getMStrUsername()<<endl;
                fs>>ws;
                getline(fs,userPassword, '\n');
                CUser::setMStrPassword(userPassword);
                //cout<<CUser::getMStrPassword()<<endl;
                fs>>ws;
                getline(fs,userFullName, '\n');
                setMStrBrokerName(userFullName);
                cout<<getMStrBrokerName()<<endl;
                fs>>ws;
                getline(fs,userRegisterDate, '\n');
                CUser::setMStrRegisterDate(userRegisterDate);
                cout<<CUser::getMStrRegisterDate()<<endl;
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

            case 3:
            {
                string nCheckBrokerName, nCheckBrokerPassword;
                cout<<"Please insert you User name "<<endl;
                cin>>nCheckBrokerName;
                cout<<"Please insert password"<<endl;
                cin>>nCheckBrokerPassword;
                fstream checkInfo;
                checkInfo.open(strPathToBroker,fstream::in | fstream::out);
                getline(checkInfo,userName, '\n');
                CUser::setMStrUsername(userName);
                checkInfo>>ws;
                getline(checkInfo,userPassword, '\n');
                CUser::setMStrPassword(userPassword);
                if(nCheckBrokerName == CUser::getMStrUsername() && nCheckBrokerPassword == CUser::getMStrPassword()){
                    /**
                     * Here is creating object of class CDataBase which to get access to methods inputForETF() and
                     * inputForStock() that to put some Assets in to database that can use those data
                     */

                    CDataBase brokerPathToDataBase;
                    int getAboutETFStock;
                    cout<<"To which data do you want to get? The Assets of ETF portfolio  - 1,"
                          "The Assets of Stock - 2"<<endl;
                    cin>>getAboutETFStock;
                    if(getAboutETFStock == 1){
                        brokerPathToDataBase.inputForETF();
                    }else if(getAboutETFStock == 2){

                        brokerPathToDataBase.inputForStock();
                    }else{
                        cout<<"You insert wrong data"<<endl;
                    }

                }else{
                    cout<<"You input wrong data"<<endl;
                }
                checkInfo.close();
                break;
            }

            case 0:
            {
                doneBroker = true;
                break;
            }
            default:
            {
                cerr << "Unknown command" << endl;
                break;
            }

        }
    }

}


CBroker::~CBroker() {}

void CBroker::getAllInfoAboutUser() {
    cout<<" User name: "<<CUser::getMStrUsername()<<endl;
}
