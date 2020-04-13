#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;
#include "../headers/CAdministrator.h"

CAdministrator::CAdministrator() {}
/**
 *
 * @param mStrNameOfAdministrator through this parameter we are setting name of Administrator
 * @param client through this parameter we can access to methods and members field of class CClient to change some data
 * @param databaseAdmin through this parameter we can access to methods
 * and members field of class CDataBase to change some data
 */

CAdministrator::CAdministrator(const string &mStrNameOfAdministrator, CClient *client, const CDataBase &databaseAdmin)
        : m_strNameOfAdministrator(mStrNameOfAdministrator), client(client), databaseAdmin(databaseAdmin) {}

int CAdministrator::adminMenu() {
    int selection;
    cout<<"Hello Admin"<<endl;
    cout<<"Input 1---Register Administrator"<<endl;
    cout<<"Input 2---Show info about Admin"<<endl;
    cout<<"Input 3---Login"<<endl;
    cout<<"Input 0---Logout"<<endl;
    cin>>selection;

    return selection;
}

void CAdministrator::createAdministratorMenu() {
    string userName,userFullName, userPassword, userRegisterDate, userEmail;
    string strPathToAdmin = "/home/darius/kursiniam_pavyzdziai/OOP_optimal_portfolio/database_files/administrator.txt";
    bool doneAdmin = false;
    while (!doneAdmin) {
        int selection = adminMenu();
        switch (selection){
            case 1: {
                ///Here we are inserting data about administrator to file of database and using switch statement
                ofstream user;
                user.open(strPathToAdmin);
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
                cout<<"Insert Email: ";
                cin>>userEmail;
                user<<userEmail<<endl;
                user.close();
                break;
            }
            case 2:
            {
                ///Here we get out data from file about administrator use for that switch statement
                fstream fs;
                fs.open(strPathToAdmin,fstream::in | fstream::out);
                cout<<"Data about Administrator: "<<endl;
                getline(fs,userName, '\n');
                CUser::setMStrUsername(userName);
                //cout<<CUser::getMStrUsername()<<endl;
                fs>>ws;
                getline(fs,userPassword, '\n');
                CUser::setMStrPassword(userPassword);
                //cout<<CUser::getMStrPassword()<<endl;
                fs>>ws;
                getline(fs,userFullName, '\n');
                setMStrNameOfAdministrator(userFullName);
                cout<<getMStrNameOfAdministrator()<<endl;
                fs>>ws;
                getline(fs,userRegisterDate, '\n');
                CUser::setMStrRegisterDate(userRegisterDate);
                cout<<CUser::getMStrRegisterDate()<<endl;
                fs>>ws;
                getline(fs,userEmail, '\n');
                CUser::setMStrEmail(userEmail);
                cout<<CUser::getMStrEmail()<<endl;
                fs>>ws;
                fs.close();
                break;
            }

            case 3:
            {
                cout<<"Please insert user name: ";
                string strCheckUserName;
                cin>>strCheckUserName;
                cout<<"Please insert password: ";
                string strCheckPassword;
                cin>>strCheckPassword;
                fstream checkInfo;
                checkInfo.open(strPathToAdmin,fstream::in | fstream::out);
                getline(checkInfo,userName, '\n');
                CUser::setMStrUsername(userName);
                checkInfo>>ws;
                getline(checkInfo,userPassword, '\n');
                CUser::setMStrPassword(userPassword);

               /**
                * Here we you use if, else if and else condition statements that to get or to change data of objects
                * of the classes CBroker, CClient, CDataBase and CAdministrator.
                * The objects of those classes are creating in checking of condition
                */

                if (strCheckUserName == CUser::getMStrUsername() && strCheckPassword == CUser::getMStrPassword()){
                    cout<<"What information do you want to change: Client - 1, Broker -2, Database -3,"
                          " Administrator -4"<<endl;
                    int nSelect;
                    cin>>nSelect;
                    if(nSelect == 1){
                        CClient adminToClientInfo;
                        adminToClientInfo.createClientMenu();
                    }else if (nSelect == 2){
                        CBroker adminToBrokerInfo;
                        adminToBrokerInfo.createBrokerMenu();
                    }else if(nSelect == 3){
                        ///Here we are getting to Stock or to ETF database
                        CDataBase  adminToDataBaseInfo;
                        cout<<"What do you want to change? Stock - 1, ETF -2"<<endl;
                        int nStockORETF;
                        cin>>nStockORETF;
                        if(nStockORETF == 1){
                            adminToDataBaseInfo.inputForStock();
                        }else if (nStockORETF == 2){
                            adminToDataBaseInfo.inputForETF();
                        }else{
                            cout<<"You insert wrong database"<<endl;
                        }

                    }else if(nSelect == 4){
                        CAdministrator administrator;
                        administrator.createAdministratorMenu();
                    }else{
                        cout<<"You insert wrong decision, please repeat you choice"<<endl;
                    }

                }else{
                    cout<<"You insert wrong User name"<<endl;
                }

                checkInfo.close();

                break;
            }
            case 0:
            {
                doneAdmin = true;
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

const string &CAdministrator::getMStrNameOfAdministrator() const {
    return m_strNameOfAdministrator;
}

void CAdministrator::setMStrNameOfAdministrator(const string &mStrNameOfAdministrator) {
    m_strNameOfAdministrator = mStrNameOfAdministrator;
}

CAdministrator::~CAdministrator() {

}

void CAdministrator::getAllInfoAboutUser() {
    cout<<" User name: "<<CUser::getMStrUsername()<<endl;
}




