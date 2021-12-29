template<class T>
quadMap<T>::quadMap()
{
	static_assert(std::is_pointer<T>(), "This class can only use pointers");
}