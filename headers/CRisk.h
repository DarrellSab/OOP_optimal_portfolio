/**
 * This class calculate risk (standard deviation) of portfolios
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
 */


#ifndef KURSINIS_DARBAS_CRISK_H
#define KURSINIS_DARBAS_CRISK_H

#include <iostream>
#include <vector>


class CRisk {
public:
    CRisk(double mDPortfolioRisk);

    CRisk();
    /**
     * @brief Method calculate matrix of covariance and variance for portfolio to help calculate risk of the portfolio
     * @param v vector type get in data of first Asset of portfolio
     * @param v1 vector type get in data of second Asset of portfolio
     * @param v2 vector type get in data of third Asset of portfolio
     * @param row int type to show how many row has a matrix
     * @param col int type to show how many columns has a matrix
     * @return static vector<vector<double>>
     */

    static std::vector<std::vector<double>> covarianceVarianceMatrix(std::vector<double> &v, std::vector<double> &v1,
                                                                     std::vector<double> &v2, int row, int col);

    /**
     * @brief Method calculate variance of portfolio this data is using calculate risk for portfolio(Standard deviation)
     * @param varCovMatrix type vector of vectors get data from method covarianceVarianceMatrix()
     * @param weigth vector type is using get in data with the weights Assets of the portfolio
     * @param row int type to show how many row has a matrix
     * @param col int type to show how many columns has a matrix
     * @return double
     */
    double portfolioVariance(std::vector<std::vector<double>> &varCovMatrix,
            std::vector<double> &weigth, int row, int col);
    /**
     * @brief Method calculate risk of the portfolio - standard deviation to help calculate std of portfolio
     * taking library cmath
     * @param variance duoble type takes data have got with method portfolioVariance()
     * @return static double
     */

    static double portfolioStd(double variance);

    double getMDPortfolioRisk() const;

    double setMDPortfolioRisk(double mDPortfolioRisk);

    virtual ~CRisk();

private:
    double m_dPortfolioRisk;
};


#endif //KURSINIS_DARBAS_CRISK_H
