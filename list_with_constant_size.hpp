#ifndef _LIST_WITH_CONSTANT_SIZE_HPP_
#define _LIST_WITH_CONSTANT_SIZE_HPP_

#include <list>
#include <stdint.h> // for int32_t

namespace misc {

struct list_of_ints : private std :: list<int32_t> {
	size_t sz;
	typedef std :: list<int32_t> :: const_iterator const_iterator;
	typedef std :: list<int32_t> :: iterator iterator;
	typedef std :: list<int32_t> :: const_reference const_reference;

	explicit list_of_ints() : std :: list<int32_t>(), sz(0) {
	}

	const std :: list<int32_t> & get() const {
		return *this;
	}
	void push_back(int32_t v) {
		++ sz;
		this -> std :: list<int32_t> :: push_back(v);
	}
	size_t size() const {
		// assert (sz == this -> std :: list<int32_t> :: size()) ;
		return sz;
	}
	bool empty() const {
		return this -> std :: list<int32_t> :: empty();
	}
	iterator begin() {
		return this -> std :: list<int32_t> :: begin();
	}
	iterator end() {
		return this -> std :: list<int32_t> :: end();
	}
	iterator erase(iterator i) {
		-- sz;
		return this -> std :: list<int32_t> :: erase(i);
	}
	void insert(iterator i, int32_t v) {
		++ sz;
		this -> std :: list<int32_t> :: insert(i, v);
	}
private:
	list_of_ints(const std :: list<int32_t> &) {} // this should never happen. It'd be a problem as this->sz would then be wrong, I think.

};

} // namespace misc

#endif
