#ifndef SUMMARY_REPORT_H
#define SUMMARY_REPORT_H

#include <map>
#include "structs.h"

namespace SummaryReport
{
    struct CityInformation
    {
        std::string cityName;
        int cityId;
        double averageCloudCover, averageAtmosphericPressure, rainProbability;
        std::string graphics;

        struct OtherInformation
        {
            int totalOccurrence;
            XYrange originalRange, finalRange;
            int sumCloudCover, sumAtmosphericPressure;
            int citySize;
        } otherInformation;

        std::string toString();
    };

    void displayWeatherForecastSummaryReport();

    void store_Original_XYrange(CityInformation &city, const int index);
    void store_Final_XYrange(CityInformation &city);

    void findRespectiveData(int &minX, int &maxX, int &minY, int &maxY, int &count, std::string &cityName, const int index);

    int getMinValue(int a, int b);
    int getMaxValue(int a, int b);

    void storeSumAndAverage(CityInformation &city);
    int getCloudCoverValue(int rowIndex, int colIndex);
    int getAtmosphericPressureValue(int rowIndex, int colIndex);
    double getTwoSigFigValue(double value);

    void storeRainProbabilityAndGraphics(CityInformation &city);
    void appendCharacters(std::string &str, int noOfTimes, char character, bool isAddnewline = true);
    std::string createGraphics(int firstLine, int secondLine, int thirdLine);
}

#endif