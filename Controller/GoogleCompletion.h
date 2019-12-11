//
// Created by shoam on 12/10/19.
//

#ifndef AUTOCOMPLETEGOOGLE_GOOGLESEARCH_H
#define AUTOCOMPLETEGOOGLE_GOOGLESEARCH_H

#include "../View/CompletionView.h"
#include <vector>
#include <string>
#include "Model/AutoCompleteData.h"
#include "Model/OffLineData.h"
/**
 GoogleCompletion
 * */
class GoogleCompletion{
public:
    GoogleCompletion( OffLineData offLineData);
    std::vector<AutoCompleteData> GetBestKCompletions(const std::string& prefix);
    void Run();
    OffLineData offLineData;

};
inline   GoogleCompletion::GoogleCompletion( OffLineData offLineData):offLineData(offLineData){

}
inline void GoogleCompletion::Run() {
    /**
    The function waiting for user input  ,get input and  printing  the best  5 complement * */
    std::string input;
    CompletionView completionView;
    while(true){
        std::cout << "enter search\n ";
        std::getline (std::cin,input);//get input user
//        std::cout<<"input "<<input<<std::endl;
        std::vector<AutoCompleteData> best_completions= GetBestKCompletions(input);
//        printAllCompletion(best_completions);
//        completionView.printToUser(best_completions);
        completionView.printToUser(best_completions,offLineData);
    }
}
inline std::vector<AutoCompleteData> GoogleCompletion::GetBestKCompletions(const std::string& prefix){
    return offLineData.GetVectorCompletion(prefix);
}
#endif //AUTOCOMPLETEGOOGLE_GOOGLESEARCH_H
