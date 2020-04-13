/**
 * This class calculate return of portfolio and search optimal portfolio
 * @author Darius Sabaliauskas Group ISit-18
 * @date 2020-01-07
 */

#ifndef KURSINIS_DARBAS_CRETURN_H
#define KURSINIS_DARBAS_CRETURN_H


#include <vector>

class CReturn {
public:

    CReturn();

    CReturn(double mDPortfolioReturn);
    /**
     * @brief Method get vector with set begining and ending
     * @param v data of vector type
     * @param m int type begining of vector for index of vector
     * @param n int type ending of vector for index of vector
     * @return vector<double>
     */

    std::vector<double> slice(const std::vector<double> &v, int m, int n);
    /**
     * @brief Method get return of Asset
     * @param v vector type for calculate of return
     * @param beginOfVector int type for begining of vector
     * @param endOfVector int type ending of vector
     * @return vector<double>
     */

    std::vector<double> returnOfAsset(std::vector<double> &v, int beginOfVector, int endOfVector);
    /**
     * @brief Method get mean of Asset
     * @param v vector type for data about mean of asset of year period
     * @return double
     */

    double meanOfAsset(const std::vector<double> &v);
    /**
     * @brief Method calculate return and mean diffrence and all data hold in vector type container
     * @param v vector type to take info get with function returnOfAsset()
     * @param d double type data of mean of Asset
     * @return vector<double>
     */

    std::vector<double> returnAndMeanDiffrence(std::vector<double> &v, double d);
    /**
     * @brief Method calculate portfolio return and hold in variable of double type
     * @param returnAsset vector type set data got with function return of Asset
     * @param weigths vector type set weigths of Assset that to take info about
     * how many every Assethave a part in portfolio
     * @param assetTotal int type, how many portfolio include Assets in portfolio
     * @return double
     */

    double portfolioReturn(std::vector<double> &returnAsset, std::vector<double> &weigths, int assetTotal);
    /**
     * @brief Method calculate portfolio which have the biggest return with the lowest risk
     * @param varCovMatrix type vector of vectors calculate matrix of all returns of the Assets of the portfolio
     * @param returnAsset vector type which get in information about retrun of portfolio
     * @param totalWeightsInPortfolio int type to use for calculation and show how many is the Assets in portfolio
     * @param row int type is using to show for vectors or vetors how many row have the data
     * @param col int type is using to show for vectors or vetors how many columns have the data
     * @return static vector<vector<double>>
     */

    static std::vector<std::vector<double>>  optimalPortfolio(std::vector<std::vector<double>> varCovMatrix,
                                                              std::vector<double> &returnAsset,
                                                              int totalWeightsInPortfolio, int row, int col);

    double getMDPortfolioReturn() const;

    double setMDPortfolioReturn(double mDPortfolioReturn);

    virtual ~CReturn();

private:
    double m_dPortfolioReturn;
};


#endif //KURSINIS_DARBAS_CRETURN_H
