//
// Created by shoam on 12/10/19.
//

#ifndef AUTOCOMPLETEGOOGLE_GOOGLESEARCH_H
#define AUTOCOMPLETEGOOGLE_GOOGLESEARCH_H

#include <vector>
#include <string>
#include "AutoCompleteData.h"
#include "OffLineData.h"

class GoogleSearch{
public:

    std::vector<AutoCompleteData> GetBestKCompletions(const std::string& prefix);
    void Run();
    OffLineData offLineData;

};

inline void GoogleSearch::Run() {
    /**
    The function waiting for user input  ,get input and  printing  the best  5 complement * */
    std::string input;
    while(true){
        std::cout << "enter search\n ";
        std::getline (std::cin,input);//get input user
//        std::cout<<"input "<<input<<std::endl;
        std::vector<AutoCompleteData> best_completions= GetBestKCompletions(input);
        printAllCompletion(best_completions);
    }
}
inline std::vector<AutoCompleteData> GoogleSearch::GetBestKCompletions(const std::string& prefix){
    return offLineData.GetVectorCompletion(prefix);
}
#endif //AUTOCOMPLETEGOOGLE_GOOGLESEARCH_H
