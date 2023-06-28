#include "hamming.h"
int compute(const char *lhs, const char *rhs){
    int distance = 0;
    size_t lhsLength = strlen(lhs);
    size_t rhsLength = strlen(rhs);
    if (lhsLength != rhsLength){
        return -1;
    }

    if (strlen(lhs) == strlen(rhs)){
        for (size_t index = 0; index < strlen(lhs); index++){
            if (lhs[index] != rhs[index]){
                distance += 1;
            }
        }
    }
    return distance;
}


