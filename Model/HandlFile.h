//
// Created by shoam on 12/11/19.
//

#ifndef GOOGLE_PROJECT_SHOAMCO_HANDLFILE_H
#define GOOGLE_PROJECT_SHOAMCO_HANDLFILE_H

#include <vector>
#include <string>
class HandleFile{


public:
    std::vector<std::string> FileToArray(std::string file_name);
};




inline  std::vector<std::string> HandleFile::FileToArray(std::string file_name){
    std::ifstream file(file_name);
//    ifstream file("../../source_text.txt");
    std::vector<std::string> lines;
    if(file.is_open())
    {



    }
    return lines;
}
#endif //GOOGLE_PROJECT_SHOAMCO_HANDLFILE_H
