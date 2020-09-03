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
    
    Stats ComputeStatistics(const std::vector<float>& floatVector) {
        struct Stats statsObj = {NAN, NAN, NAN};
        if(floatVector.size() == 0)
        {
            return statsObj;
        }
        statsObj.average = ComputeAverage(floatVector);
        statsObj.max = *max_element(floatVector.begin(), floatVector.end());
        statsObj.min = *min_element(floatVector.begin(), floatVector.end());
        return statsObj;
    }
    
}
