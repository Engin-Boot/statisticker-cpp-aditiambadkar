#include "stats.h"
#include <bits/stdc++.h>
namespace Statistics {
    
    Stats ComputeStatistics(const std::vector<float>& floatVector) {
        struct Stats statsObj = {NAN, NAN, NAN};
        auto size_floatVector = floatVector.size();
        if(size_floatVector == 0)
        {
            return statsObj;
        }
        statsObj.average = accumulate( floatVector.begin(), floatVector.end(), 0.0) / size_floatVector;
        statsObj.max = *max_element(floatVector.begin(), floatVector.end());
        statsObj.min = *min_element(floatVector.begin(), floatVector.end());
        return statsObj;
    }
}
