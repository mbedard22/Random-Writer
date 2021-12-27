// Copyright
#include "RandWriter.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_methods) {
     RandWriter test("stringnirts",  2);
     BOOST_REQUIRE(test.order_k() == 2);
     BOOST_REQUIRE(test.freq("ng") == 1);
     BOOST_REQUIRE_THROW(test.freq("ngn"), std::exception);
     BOOST_REQUIRE(test.freq("ng", 'n') == 1);
     BOOST_REQUIRE_THROW(test.freq("ngn", 'n'), std::exception);
     BOOST_REQUIRE(test.k_Rand("ri") == 'n');
     BOOST_REQUIRE_THROW(test.k_Rand("rin"), std::exception);
     BOOST_REQUIRE_THROW(test.k_Rand("ab"), std::exception);
     BOOST_REQUIRE((test.generate("st", 50)).size() == 50);
}
