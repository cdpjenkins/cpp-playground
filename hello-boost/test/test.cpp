#include <string>
using namespace std;

#define BOOST_TEST_MODULE your_test_module
#include <boost/test/included/unit_test.hpp>

string make_full_name(const string &first_name, const string &last_name) {
    return first_name + " " + last_name;
}

BOOST_AUTO_TEST_CASE( your_test_case ) {
    std::vector<int> a{1, 2};
    std::vector<int> b{1, 2};
    BOOST_TEST( a == b );
}

BOOST_AUTO_TEST_CASE ( make_full_name_combines_first_and_last_names_according_to_English_convention )
{
    string first_name = "John";
    string last_name = "Doe";

    BOOST_TEST(make_full_name(first_name, last_name) == "John Doe");
}
