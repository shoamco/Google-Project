#include <iostream>
#include "Test/TestAutoComplete.h"
#include <json.hpp>


using json = nlohmann::json;

int main() {
//    test_open_json_file();
    testRunSearch();
//    testCreateAutoCompleteData();
//    test_init_offline_data();
//    test_file_to_array();
    return 0;
}

//int main(int argc, char *argv[]) {
//
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}