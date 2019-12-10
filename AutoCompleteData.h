//
// Created by shoam on 12/10/19.
//

#ifndef AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H
#define AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H

#include <string>

class AutoCompleteData {
public:
    AutoCompleteData(std::string completed_sentence, std::string source_text);

//    int CalculateSource();

private:
    std::string completed_sentence;
    std::string source_text;
    int offset;
    int score;

};

inline   AutoCompleteData::AutoCompleteData(std::string completed_sentence, std::string source_text)
        : completed_sentence(completed_sentence), source_text(source_text) {

}

#endif //AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H
