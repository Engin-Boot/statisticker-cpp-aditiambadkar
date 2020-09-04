#include "stats.h"
#include <bits/stdc++.h>
#include <math.h>
namespace Statistics {
    
    float ComputeAverage(const std::vector<float>& floatVector) {
        std::vector<float>::const_iterator itr = floatVector.begin();
        float sumVector = 0, numberOfElementsVector = 0;
        while(itr != floatVector.end())
        {
            if(!isnan(*itr))
            {
                sumVector = sumVector + *itr;
                numberOfElementsVector++;
            }
            itr++;
        }
        return sumVector / numberOfElementsVector;
    }
    
    float ComputeMaximum(const std::vector<float>& floatVector) {
        std::vector<float>::const_iterator itr = floatVector.begin();
        float max = std::numeric_limits<float>::min();
        while(itr != floatVector.end())
        {
            if(!isnan(*itr) && max < *itr)
            {
                max = *itr;
            }
            itr++;
        }
        if(max == std::numeric_limits<double>::min())
            return NAN;
        return max;
    }
    
    float ComputeMinimum(const std::vector<float>& floatVector) {
        std::vector<float>::const_iterator itr = floatVector.begin();
        float min = std::numeric_limits<float>::max();
        while(itr != floatVector.end())
        {
            if(!isnan(*itr) && min > *itr)
            {
                min = *itr;
            }
            itr++;
        }
        if(min == std::numeric_limits<double>::max())
            return NAN;
        return min;
    }
    
    Stats ComputeStatistics(const std::vector<float>& floatVector) {
        struct Stats statsObj = {NAN, NAN, NAN};
        if(floatVector.size() == 0)
        {
            return statsObj;
        }
        statsObj.average = ComputeAverage(floatVector);
        statsObj.max = ComputeMaximum(floatVector);
        statsObj.min = ComputeMinimum(floatVector);
        return statsObj;
    }
    
}
