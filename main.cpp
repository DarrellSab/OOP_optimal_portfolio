/**
 The programm Optimal Portfolio
 calculate return and risk of portfolio
 and make decision which portfolio is optimal,
 for that use historical everyday close prices of Assets of one year.
 Those prices takes from database.
 The database in this program changed with files extensions .csv and .txt
 @author Darius Sabaliauskas
 Group ISit-18
 @date 2020-01-07
 @version 0.1

 */
#include <iostream>
#include "headers/CClient.h"
#include "headers/CBroker.h"
#include "headers/CAdministrator.h"
#include "headers/CPortfolio.h"
#include "headers/CAsset.h"
#include "headers/CStock.h"
#include "headers/CETF.h"
using namespace std;

///Here is the function which is starting main menu of the program
int useMenu();

int main() {
 /**
  * In while loop and with switch condition
  * is creating objects: client, broker and administrator that take to functions
  * which run creating of Client, Broker and Administrator menus  */
    bool doneMenu = false;
    while (!doneMenu) {
        int selection = useMenu();
        switch (selection){
            case 1: {
                CClient client;
                client.createClientMenu();
                break;
            }
            case 2:
            {
                CBroker broker;
                broker.createBrokerMenu();
                break;
            }

            case 3:
            {
                CAdministrator administrator;
                administrator.createAdministratorMenu();
                break;
            }

            case 0:
            {
                doneMenu = true;
                break;
            }
            default:
            {
                cerr << "Unknown command" << endl;
                break;
            }

        }
    }


    return 0;
}
int useMenu(){
    int selection;
    cout<<"Hello new Guest of Portfolio program"<<endl;
    cout<<"Input 1---Trader"<<endl;
    cout<<"Input 2---Broker"<<endl;
    cout<<"Input 3---Administrator"<<endl;
    cout<<"Input 0---Logout"<<endl;
    cin>>selection;

    return selection;
}


