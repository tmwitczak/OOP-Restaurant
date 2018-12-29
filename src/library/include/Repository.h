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
template <typename T>
bool Restaurant::Repository<T>::add(T element)
{
	// TODO: Implement bool Restaurant::Repository<T>::add(T element)
	return false;
}
//--------------------------------------------------------------------------------------------------
template <typename T>
void Restaurant::Repository<T>::remove(T element)
{
	// TODO: Implement void Restaurant::Repository<T>::remove(T element)
}
//--------------------------------------------------------------------------------------------------
template <typename T>
void Restaurant::Repository<T>::saveToFile(std::string filename) const
{
	// TODO: Implement void Restaurant::Repository<T>::saveToFile(std::string filename) const
}
//--------------------------------------------------------------------------------------------------
template <typename T>
void Restaurant::Repository<T>::readFromFile(std::string filename)
{
	// TODO: Implement void Restaurant::Repository<T>::readFromFile(std::string filename)
}
//--------------------------------------------------------------------------------------------------
template <typename T>
std::vector<T> Restaurant::Repository<T>::getAll() const
{
	// TODO: Implement std::vector<T> Restaurant::Repository<T>::getAll() const
	return std::vector<T>();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_REPOSITORY_H */