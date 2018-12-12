#pragma once
#include <xmemory>
#include <stdexcept>
#if _HAS_CXX17
#include <xpolymorphic_allocator.h>
#endif /* _HAS_CXX17 */

template<typename T, typename Alloc = std::allocator<T>>
class Vector
{
public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type* iterator;
	typedef value_type& referance;
	typedef size_t size_type;
	typedef ptrdiff_t defference_type;

public:
	Vector();
	Vector(size_type n, const value_type& value);
	~Vector();

private:
	iterator m_start;
	iterator m_finish;
	iterator m_end_of_storage;
	Alloc m_alloc;
};

template<class T, typename Alloc>
Vector<T, Alloc>::Vector()
	: m_start(0)
	, m_finish(0)
	, m_end_of_storage(0)
{
}

template<class T, typename Alloc>
Vector<T, Alloc>::Vector(size_type n, const value_type& value)
	: m_start(0)
	, m_finish(0)
	, m_end_of_storage(0)
{
	m_start = m_alloc.allocate(n);
	std::_Uninitialized_fill_n(m_start, n, value, m_alloc);
	m_finish = m_start + n;
	m_end_of_storage = m_finish;
}

template<class T, typename Alloc>
Vector<T, Alloc>::~Vector()
{
}