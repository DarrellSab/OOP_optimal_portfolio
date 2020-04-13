cmake_minimum_required(VERSION 3.15)
project(kursinis_darbas)

set(CMAKE_CXX_STANDARD 14)
link_directories(/usr/include/itpp)
add_executable(kursinis_darbas main.cpp sources/CUser.cpp headers/CUser.h sources/CClient.cpp headers/CClient.h sources/CBroker.cpp headers/CBroker.h sources/CPortfolio.cpp headers/CPortfolio.h sources/CMyHoldings.cpp headers/CMyHoldings.h sources/CAsset.cpp headers/CAsset.h sources/CStock.cpp headers/CStock.h sources/CETF.cpp headers/CETF.h /home/darius/kursiniam_pavyzdziai/kursinis_darbas
        duomenys.txt sources/CAdministrator.cpp headers/CAdministrator.h sources/CRisk.cpp headers/CRisk.h sources/CReturn.cpp headers/CReturn.h sources/CDataBase.cpp headers/CDataBase.h)
target_link_libraries(kursinis_darbas itpp)