#include "../headers/CRisk.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

CRisk::CRisk() {}

CRisk::CRisk(double mDPortfolioRisk) : m_dPortfolioRisk(mDPortfolioRisk) {}

vector<vector<double>> CRisk::covarianceVarianceMatrix(vector<double> &v, vector<double> &v1,
                                                        vector<double> &v2, int row, int col) {

    int row1 = col;
    int col1 = row;
    vector<vector<double>> vect2D;
    vect2D.resize(col,vector<double>(col));
    vect2D[0] = v;
    vect2D[1] = v1;
    vect2D[2] = v2;

    vector<vector<double>> transposeVect2D;
    transposeVect2D.resize(vect2D[0].size(),vector<double>());


    for(int i = 0; i <vect2D.size(); i++){

        for(int j =0; j<vect2D[i].size(); j++){

            if(transposeVect2D[j].size() != vect2D.size()){
                transposeVect2D[j].resize(vect2D.size());
            }
            transposeVect2D[j][i] = vect2D[i][j];
        }
    }

    int row2 = col;
    int col2 = col;
    vector<vector<double>> varianceVect2D;
    varianceVect2D.resize(col2,vector<double>(row2));


    for(int i = 0; i <varianceVect2D.size(); i++){
        for(int j =0; j<varianceVect2D[i].size(); j++){
            varianceVect2D[i][j] = 0;
            for(int k = 0; k<col; k++){   //count elements in row or column
                varianceVect2D[i][j] += transposeVect2D[i][k]*vect2D[k][j];
            }
        }

    }


    return varianceVect2D;
}

double CRisk::portfolioVariance(vector<vector<double>>& varCovMatrix, vector<double>& weigth, int row, int col) {
    //row =3, col = 1
    int weightCol = 1;
    vector<vector<double>> transposeWeights;
    transposeWeights.resize(col,vector<double>(row));
    for(int i = 0; i <row; i++){

        for(int j = 0; j<col; j++){
            transposeWeights[j][i] = weigth[i];
        }
    }
    int tempRow = col;
    int tempCol = row;
    vector<vector<double>> tempVec;
    tempVec.resize(tempCol,vector<double>(tempRow));


    for(int i = 0; i <tempRow; i++){
        for(int j =0; j<tempCol; j++){
            tempVec[i][j] = 0;
            for(int k = 0; k<tempCol; k++){   ///count elements in row or column
                tempVec[i][j] += transposeWeights[i][k]*varCovMatrix[k][j];
            }
        }
        cout<<endl;
    }
    double portfolioVaria1 = 0.0;
    vector<vector<double>> portfolioVaria;
    for(int i = 0; i <row; i++){
        for(int j =0; j<row; j++){
            for(int k = 0; k<row; k++){   ///count elements in row or column
                portfolioVaria1 += tempVec[i][k]*weigth[j];
            }
        }
        cout<<endl;
    }


    return portfolioVaria1;
}

double CRisk::portfolioStd(double variance) {

    return (sqrt(variance));
}

double CRisk::getMDPortfolioRisk() const {
    return m_dPortfolioRisk;
}

double CRisk::setMDPortfolioRisk(double mDPortfolioRisk) {
    m_dPortfolioRisk = mDPortfolioRisk;
}

CRisk::~CRisk() = default;
