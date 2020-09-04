#include "stats.h"
#include <bits/stdc++.h>
#include <math.h>
namespace Statistics {
    
    float ComputeAverage(const std::vector<float>& floatVector) {
        float sumVector = 0, numberOfElementsVector = 0;
        for(int i = 0; i < floatVector.size(); i++)
        {
            if(isnan(floatVector[i]))
                continue;
            sumVector += floatVector[i];
            numberOfElementsVector++;
        }
        return sumVector / numberOfElementsVector;
    }
    
    float ComputeMaximum(const std::vector<float>& floatVector) {
        float max = std::numeric_limits<float>::min();
        for(int i = 0; i < floatVector.size(); i++)
        {
            if(!isnan(floatVector[i]) && max < floatVector[i])
                max = floatVector[i];
        }
        if(max == std::numeric_limits<double>::min())
            return NAN;
        return max;
    }
    
    float ComputeMinimum(const std::vector<float>& floatVector) {
        float min = std::numeric_limits<float>::max();
        for(int i = 0; i < floatVector.size(); i++)
        {
            if(!isnan(floatVector[i]) && min > floatVector[i])
                min = floatVector[i];
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
        cout<<statsObj.average<<" "statsObj.max<<" "statsObj.min<<endl;
        return statsObj;
    }
    
}
