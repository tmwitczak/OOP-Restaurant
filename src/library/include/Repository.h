#ifndef RESTAURANT_REPOSITORY_H
#define RESTAURANT_REPOSITORY_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	template <typename T>
	class Repository
	{
	public:
		bool add(T element);
		void remove(T element);
		void saveToFile(std::string filename) const;
		void readFromFile(std::string filename);
		std::vector<T> getAll() const;

	protected:
		std::vector<T> elements;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_REPOSITORY_H */