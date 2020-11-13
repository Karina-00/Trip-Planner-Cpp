#pragma once

template <class T>
class Base {
	std::vector<T*> list;
public:
	~Base();
	T* getElementByIndex(int i);
	void operator+=(T* newElement);
	int getListLength();
};


template <class T>
Base<T>::~Base() {
	for (int i = 0; i < this->getListLength(); i++)
		delete list[i];
}

template <class T>
T* Base<T>::getElementByIndex(int i) {
	if (i < this->getListLength())
		return list[i];
	else return nullptr;
}

template <class T>
void Base<T>::operator+=(T* newElement) {
	list.push_back(newElement);
}

template <class T>
int Base<T>::getListLength() {
	return list.size();
}
