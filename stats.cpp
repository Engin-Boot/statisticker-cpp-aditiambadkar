#include "stats.h"
#include <bits/stdc++.h>
namespace Statistics {
    
    Stats ComputeStatistics(const std::vector<float>& floatVector) {
        struct Stats statsObj = {NAN, NAN, NAN};
        if(floatVector.size() == 0)
        {
            return statsObj;
        }
        std::vector<int>::iterator itr = floatVector.begin();
        float sumVector = 0, numberOfElementsVector = 0;
        while(itr != floatVector.end())
        {
            if(isnan(*itr))
                continue;
            sumVector = sumVector + *itr;
            numberOfElementsVector++;
        }
        statsObj.average = sumVector / numberOfElementsVector;
        statsObj.max = *max_element(floatVector.begin(), floatVector.end());
        statsObj.min = *min_element(floatVector.begin(), floatVector.end());
        return statsObj;
    }
}
