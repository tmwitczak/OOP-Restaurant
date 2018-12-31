#include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Repository.h"
//--------------------------------------------------------------------------------------------------
template <typename T>
bool compareVectors(std::vector<T> const &container1, std::vector<T> const &container2)
{
	return std::equal(container1.begin(), container1.begin(), container2.begin());
}
//--------------------------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(Repository_CoreFunctionality_TestSuite)
	BOOST_AUTO_TEST_CASE(Repository_ConstructFromVectorAndGetAllElements_TestCase)
	{
		std::vector<std::shared_ptr<int>> const elements1 = { std::make_shared<int>(0) };

		Restaurant::Repository<std::shared_ptr<int>> repository(elements1);
		std::vector<std::shared_ptr<int>> const &elements2 = repository.getAll();

		BOOST_REQUIRE_EQUAL(compareVectors(elements1, elements2), true);
	}
    BOOST_AUTO_TEST_CASE(Repository_AddElementAndGetAllElements_TestCase)
    {
		Restaurant::Repository<std::shared_ptr<int>> repository;
		auto const element = std::make_shared<int>(0);

		repository.add(element);
		std::vector<std::shared_ptr<int>> const &elements = repository.getAll();

		BOOST_REQUIRE_EQUAL(compareVectors({ element }, elements), true);
    }
	BOOST_AUTO_TEST_CASE(Repository_AddElementThenRemoveElementAndGetAllElements_TestCase)
	{
		Restaurant::Repository<std::shared_ptr<int>> repository;
		auto const element = std::make_shared<int>(0);

		repository.add(element);
		repository.remove(element);
		std::vector<std::shared_ptr<int>> const &elements = repository.getAll();

		BOOST_REQUIRE_EQUAL(elements.empty(), true);
	}
	BOOST_AUTO_TEST_CASE(Repository_ConstructFromVectorAndSaveToFile_TestCase)
	{
		// TODO: Write Repository_ConstructFromVectorAndSaveToFile_TestCase
	}
	BOOST_AUTO_TEST_CASE(Repository_ConstructFromVectorThenSaveAndReadFromFile_TestCase)
	{
		// TODO: Write Repository_ConstructFromVectorThenSaveAndReadFromFile_TestCase
	}
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////