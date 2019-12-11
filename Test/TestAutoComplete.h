

#ifndef AUTOCOMPLETEGOOGLE_TESTAUTOCOMPLETE_H
#define AUTOCOMPLETEGOOGLE_TESTAUTOCOMPLETE_H

//#include <gtest/gtest.h>
#include <iostream>
#include "Controller/GoogleCompletion.h"
#include "Model/AutoCompleteData.h"
#include "Model/OffLineData.h"
#include <string>
#include <json.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "Model/HandlFile.h"
using json = nlohmann::json;
void testRunSearch();
void testCreateAutoCompleteData();
void testCreateAutoCompleteData();
void test_init_offline_data();
void test_json_file();
void test_open_json_file();
void test_file_to_array();
#endif //AUTOCOMPLETEGOOGLE_TESTAUTOCOMPLETE_H
