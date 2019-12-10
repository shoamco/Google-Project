//
// Created by shoam on 12/10/19.
//

#ifndef AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H
#define AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H

#include <string>

class AutoCompleteData {
public:
    AutoCompleteData(std::string source_text, int offset, std::string completed_sentence);

    int CalculateSource();

    friend std::ostream &operator<<(std::ostream &ostream, const AutoCompleteData autoCompleteData);

    std::string GetCompletedSentence();

private:
    std::string source_text;
    int offset;
    std::string completed_sentence;
    int score;

};

inline std::string AutoCompleteData::GetCompletedSentence() {
    return completed_sentence;

}

inline int AutoCompleteData::CalculateSource() {
    return 1;
}

inline   AutoCompleteData::AutoCompleteData(std::string source_text, int offset, std::string completed_sentence)
        : source_text(source_text), offset(offset), completed_sentence(completed_sentence) {
    score = CalculateSource();

}

inline std::ostream &operator<<(std::ostream &ostream, const AutoCompleteData autoCompleteData) {
    ostream << "\n\nAutoCompleteData: \n";
    ostream << "source_text: " << autoCompleteData.source_text;
    ostream << "\noffset: " << autoCompleteData.offset;
    ostream << "\ncompleted_sentence: " << autoCompleteData.completed_sentence;
    ostream << "\nscore: " << autoCompleteData.score;

    return ostream << std::endl;
}

#endif //AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H
