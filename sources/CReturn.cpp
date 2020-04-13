#include "../headers/CReturn.h"
#include "../headers/CRisk.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <iterator>
using namespace std;

CReturn::CReturn(double mDPortfolioReturn) : m_dPortfolioReturn(mDPortfolioReturn) {}

CReturn::CReturn() {}

vector<double> CReturn::slice(std::vector<double> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;

    vector<double> vec(first, last);
    return vec;
}

vector<double> CReturn::returnOfAsset(std::vector<double> &v, int beginOfVector, int endOfVector) {
    for(int i = 0; i<v.size(); i++){
        if(i == v.size()-1){
            break;
        }
        v[i] = (v[i+1]/v[i])-1;

    }

    vector<double> justReturn;
    beginOfVector = 0;
    endOfVector = 250;
    justReturn  = slice(v, beginOfVector,endOfVector);
    return justReturn;
}

double CReturn::meanOfAsset(std::vector<double> const &v) {
    double sumAssetCloseReturn = 0;


    for(int i = 0; i < v.size(); i++){
        sumAssetCloseReturn += v[i];
    }


    return sumAssetCloseReturn/v.size();
}

vector<double> CReturn::returnAndMeanDiffrence(vector<double> &v, double d) {
    for(int i = 0; i < v.size(); i++){
        v[i] = pow((v[i] -d),2);
    }

    return v;
}

double CReturn::portfolioReturn(vector<double>& returnAsset, vector<double>& weigths, int assetTotal) {
    double portfolioDayReturn = 0;
    for(int i= 0; i<assetTotal; i++){
        portfolioDayReturn += returnAsset[i]*weigths[i];
    }
    double portfolioYearreturn  = portfolioDayReturn*250*100;

    return portfolioYearreturn;
}

vector<vector<double>> CReturn::optimalPortfolio(vector<vector<double>> varCovMatrix, vector<double>& returnAsset,
                                                 int totalWeightsInPortfolio, int row, int col) {
    multimap<double, vector<double>> multimapForWR;
    int tempRowWeights = 5;
    int tempColWeights = 3;
    vector<vector<double>> allPortfolioReturns;
    int hi, hii,hij;
    double portfolioVaria1;
    double  portfolioYearReturn = 0.0;
    double portfolioDayReturn = 0.0;
    double portfolioFinalYearReturn = 0.0;
    double sum;
    double MAX = 1.0;
    ///Here is creating array to get random weights with function srand until the sum will be 1.0
    double rnd[totalWeightsInPortfolio];
    srand(time(NULL));

    vector <double> weights;
    vector<double> randomWeights;
    vector<double> WeightsRandom;
    vector<double> weightsAndreturn;
    vector<double> weightsChosen;
    vector<double> portYearVector;

    ////Here is making calculation with random 100000 porfolios
    double sumWeights;
    int totalRandomPortfolio = 100000;
    int k=0;
    while ( k !=totalRandomPortfolio){
        sumWeights = 0.0;
        while (sumWeights != MAX) {
            sumWeights = 0.0;
            portfolioDayReturn = 0.0;
            sum = 0.0;
            ///here is making random numbers for portfolio weights
            while (sum != MAX) {
                sum = 0.0;
                for (int i = 0; i < totalWeightsInPortfolio; i++) {
                    int tempRandInt = rand() % 100 + 1;
                    double temRandDouble = ((double) tempRandInt) / 100;
                    rnd[i] = temRandDouble;
                    sum += rnd[i]; ///sum of weights in array that to get 1
                }
            }
            ///copying weights that get sum 1 to vector, to get sum of vector and check in while loop
            vector<double> weights(rnd + 0, rnd + totalWeightsInPortfolio);
            vector<double>::iterator vecItr;
            for (vecItr = weights.begin(); vecItr != weights.end(); ++vecItr) {
                sumWeights += *vecItr;///sum of vector value
            }

            for (int i = 0; i < totalWeightsInPortfolio; i++) {
                portfolioDayReturn += returnAsset[i] * weights[i];

            }

            int tempPortRet = portfolioDayReturn * 10000;
            portfolioDayReturn = ((double) tempPortRet / 100);
            portfolioYearReturn = portfolioDayReturn * 250;
            ///Multimap gets key - double and value -vector
            multimapForWR.insert(pair<double, vector<double>>(portfolioYearReturn, weights));

        }
        k++;
        ///Here from multimap is getting info about chosen the biggest value of portfolio and its weigths
        multimap<double, vector<double>>::iterator multItr;
        multItr = multimapForWR.end();
        --multItr;
        for(int i =0; i<totalWeightsInPortfolio; i++){
            weightsChosen.push_back(multItr->second[i]);
        }
        portfolioFinalYearReturn = multItr->first;

    }

    ///here will be count Variance of porftolio
    int weightCol = 1;
    vector<vector<double>> transposeWeights;
    transposeWeights.resize(col, vector<double>(row));
    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {
            transposeWeights[j][i] = weightsChosen[i];
        }
    }
    int tempRow = col;
    int tempCol = row;
    vector<vector<double>> tempVec;
    tempVec.resize(tempCol, vector<double>(tempRow));


    for (int i = 0; i < tempRow; i++) {
        for (int j = 0; j < tempCol; j++) {
            tempVec[i][j] = 0;
            for (int k = 0; k < tempCol; k++) {   ///count elements in row or column
                tempVec[i][j] += transposeWeights[i][k] * varCovMatrix[k][j];
            }
        }

    }
    portfolioVaria1 = 0.0;
    vector<vector<double>> portfolioVaria;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < row; k++) {   ///count elements in row or column
                portfolioVaria1 += tempVec[i][k] * weightsChosen[j];
            }
        }

    }

   ///Put allocation of portfolio, return, std in vector

    double portfolioLastSTD = CRisk::portfolioStd(portfolioVaria1);
    int tempPortSTD = portfolioLastSTD*10000;
    portfolioLastSTD = ((double)tempPortSTD/10000);
    double portfolioYearSTD = portfolioLastSTD*250;
    vector<double> returnSTDportfolio;
    returnSTDportfolio.push_back(portfolioFinalYearReturn);
    returnSTDportfolio.push_back(portfolioYearSTD);

    vector<vector<double>> allInfoAboutOptimalPortfolio;
    ///To vector of vectors push_back the vector of weights of the portfolio
    allInfoAboutOptimalPortfolio.push_back(weightsChosen);
    ///To vector of vectors push_back the vector of return and risk of the portfolio
    allInfoAboutOptimalPortfolio.push_back(returnSTDportfolio);

    return allInfoAboutOptimalPortfolio;
}

double CReturn::getMDPortfolioReturn() const {
    return m_dPortfolioReturn;
}

double CReturn::setMDPortfolioReturn(double mDPortfolioReturn) {
    m_dPortfolioReturn = mDPortfolioReturn;
}

CReturn::~CReturn() = default;
