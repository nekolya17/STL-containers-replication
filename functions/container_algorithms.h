#pragma once 
#ifndef CONT_ALGORITHMS_H
#define CONT_ALGORITHMS_H

namespace comp{

    template <typename T>
    bool is_equal(T itBegin1, T itEnd2, T itBegin2){
        for(;itBegin1 != itEnd2;++itBegin1, ++itBegin2){
            if(*itBegin1 != *itBegin2)
                return false;
        }
        return true;
    }


}

#endif