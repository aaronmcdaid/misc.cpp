#ifndef _LIST_WITH_CONSTANT_SIZE_HPP_
#define _LIST_WITH_CONSTANT_SIZE_HPP_

#include <list>
#include <stdint.h> // for int32_t
#include <stddef.h>
#include <cstddef>

namespace misc {

template <typename T>
struct list_with_constant_size : private std :: list<T> {
	size_t sz;
	typedef typename std :: list<T> :: const_iterator const_iterator;
	typedef typename std :: list<T> :: iterator iterator;
	typedef typename std :: list<T> :: const_reference const_reference;

	explicit list_with_constant_size() : std :: list<T>(), sz(0) {
	}

	const std :: list<T> & get() const {
		return *this;
	}
	void push_back(T v) {
		++ sz;
		this -> std :: list<T> :: push_back(v);
	}
	void push_front(T v) {
		++ sz;
		this -> std :: list<T> :: push_front(v);
	}
	size_t size() const {
		// DON'T ENABLE THIS ASSERT, IT WOULD DEFEAT THE PURPOSE. Unless you're testing of course // assert (sz == this -> std :: list<T> :: size()) ;
		return sz;
	}
	bool empty() const {
		return this -> std :: list<T> :: empty();
	}
	iterator begin() {
		return this -> std :: list<T> :: begin();
	}
	iterator end() {
		return this -> std :: list<T> :: end();
	}
	iterator erase(iterator i) {
		-- sz;
		return this -> std :: list<T> :: erase(i);
	}
	void insert(iterator i, T v) {
		++ sz;
		this -> std :: list<T> :: insert(i, v);
	}
private:
	list_with_constant_size(const std :: list<T> &) {} // this should never happen. It'd be a problem as this->sz would then be wrong, I think.

};

} // namespace misc

#endif
