#ifndef RESTAURANT_REPOSITORY_H
#define RESTAURANT_REPOSITORY_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <algorithm>
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	template <typename T>
	class Repository
	{
	public:
		Repository() = default;
		Repository(std::vector<T> const &elements);
		Repository(Repository const &) = delete;
		Repository(Repository &&) = delete;
		Repository &operator=(Repository const &) = delete;
		Repository &operator=(Repository &&) = delete;
		virtual ~Repository() = default;

		void add(T const &element);
		void remove(T const &element);
		virtual void saveToFile(std::string const &filename) const;
		virtual void readFromFile(std::string const &filename);
		std::vector<T> const &getAll() const;

	protected:
		std::vector<T> elements;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Restaurant::Repository<T>::Repository(std::vector<T> const &elements)
	:	elements(elements)
{
}
//--------------------------------------------------------------------------------------------------
template <typename T>
void Restaurant::Repository<T>::add(T const &element)
{
	elements.push_back(element);
}
//--------------------------------------------------------------------------------------------------
template <typename T>
void Restaurant::Repository<T>::remove(T const &element)
{
	elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
}
//--------------------------------------------------------------------------------------------------
template <typename T>
void Restaurant::Repository<T>::saveToFile(std::string const &filename) const
{
	// TODO: Implement void Restaurant::Repository<T>::saveToFile(std::string filename) const
}
//--------------------------------------------------------------------------------------------------
template <typename T>
void Restaurant::Repository<T>::readFromFile(std::string const &filename)
{
	// TODO: Implement void Restaurant::Repository<T>::readFromFile(std::string filename)
}
//--------------------------------------------------------------------------------------------------
template <typename T>
std::vector<T> const &Restaurant::Repository<T>::getAll() const
{
	return elements;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_REPOSITORY_H */