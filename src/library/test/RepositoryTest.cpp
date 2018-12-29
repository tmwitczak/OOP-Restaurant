#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Repository.h"
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(RepositoryCoreFunctionalityTestSuite)
    BOOST_AUTO_TEST_CASE(RepositoryAddTestCase)
    {
		Restaurant::Repository<int> repository;
		int element = 0;

		repository.add(element);

		std::vector<int> vector1 = { element },
						 vector2 = repository.getAll();

		BOOST_REQUIRE_EQUAL(std::equal(vector1.begin(), vector1.end(), vector2.begin()), true);
    }
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////