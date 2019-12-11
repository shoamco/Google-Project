//
// Created by shoam on 12/11/19.
//

#ifndef GOOGLE_PROJECT_SHOAMCO_COMPLETIONVIEW_H
#define GOOGLE_PROJECT_SHOAMCO_COMPLETIONVIEW_H

#include "../Model/OffLineData.h"

class CompletionView{
public:
     void printToUser(VectorCompletion best_completions,OffLineData offLineData);
//     void printToUser(VectorCompletion best_completions);
};

inline void CompletionView::printToUser(VectorCompletion vec,OffLineData offLineData) {
    for (int i = 0; i < vec.size(); i++) {

        size_t index=vec.at(i).GetOffset();
        std::cout <<"(line:"<<index<<") "<< offLineData.getLineByOffset(index)<<std::endl;

    }
}

#endif //GOOGLE_PROJECT_SHOAMCO_COMPLETIONVIEW_H
