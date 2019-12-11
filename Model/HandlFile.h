//
// Created by shoam on 12/11/19.
//

#ifndef GOOGLE_PROJECT_SHOAMCO_HANDLFILE_H
#define GOOGLE_PROJECT_SHOAMCO_HANDLFILE_H

#include <vector>
#include <string>
#include "../Model/OffLineData.h"

class HandleFile {


public:
    std::vector<std::string> FileToArray(std::string file_name);

    MapComplete JsonFileToMap(std::string file_name);
};


inline MapComplete HandleFile::JsonFileToMap(std::string file_name) {

    MapComplete map_data;
    int score;
    std::string completed_sentence;
    std::string source_text;
    json offline_data;

    std::ifstream file(file_name);
    if (file.is_open()) {
        offline_data = json::parse(file);

        for (json::iterator it = offline_data.begin(); it != offline_data.end(); ++it) {
            completed_sentence = it.key();

            score = it.value()[1];
            source_text = it.value()[0];
            int line;

            VectorCompletion vectorComplete;
            for (int i = 0; i < it.value()[2].size(); ++i) {//enter to vector  all completed sentence
                line = it.value()[2][i];
                AutoCompleteData autoCompleteData(source_text, line, completed_sentence, score);
                vectorComplete.push_back(autoCompleteData);
            }

            std::pair<std::string, VectorCompletion> pair_data(completed_sentence, vectorComplete);
            map_data.insert(pair_data);
        }
    } else { throw "Unable to open file"; }
    return map_data;
}

inline std::vector<std::string> HandleFile::FileToArray(std::string file_name) {
    std::cout << "in FileToArray\n";
    std::ifstream file(file_name);
    std::vector<std::string> lines;

    if (file.is_open()) {
        std::string line;
        int i = 0;
        while (getline(file, line)) {
            std::cout << "line: " << line << std::endl;
            lines.push_back(line);

        }
    } else {
        throw;
    }


    return lines;
}

#endif //GOOGLE_PROJECT_SHOAMCO_HANDLFILE_H
