#include"string.h"
using namespace IceCola;


std::istream& operator>>(std::istream& _cin, string& s)
{
	s.clear();
	char c;
	c = _cin.get();
	while (c != ' ' && c != '\n')
	{
		s.push_back(c);
		c = _cin.get();
	}
	return _cin;
}

string::string(const char* str)
{
	if (str == nullptr)
	{
		assert(0);
	}
	_capacity = _size = strlen(str);
	_str = new char[_size + 1];
	strcpy(_str, str);
}

string::string(const string& s):_str(nullptr)
{
	string tmp(s._str);
	this->swap(tmp);
}

string& IceCola::string::operator=(const string& s)
{
	string tmp(s._str);
	if (this != &s)
	{
		this->swap(tmp);
	}
	return *this;
}

string::~string()
{
	delete[] _str;
	_str = nullptr;
	_size = _capacity = 0;
}

string::iterator string::begin()
{
	return _str;
}
string::iterator string::end()
{
	return _str + _size;
}

// modify
void string::push_back(char c)
{
	if (_size == _capacity)
	{
		reserve(_capacity == 0? 4:_capacity * 2);
	}
	_str[_size] = c;
	_size++;
	_str[_size] = '\0';
}
string& string::operator+=(char c)
{
	push_back(c);
	return *this;
}

void string::append(const char* str)
{
	while (*str != '\0')
	{
		push_back(*str);
		str++;
	}
}

string& string::operator+=(const char* str)
{
	append(str);
	return *this;
}

void string::clear()
{
	_size = 0;
	_str[0] = '\0';
}

void string::swap(string& s)
{
	std::swap(_str, s._str);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}

const char* string::c_str() const
{
	return _str;
}

// capacity
size_t string::size() const
{
	return _size;
}

size_t string::capacity() const
{
	return _capacity;
}

bool string::empty() const
{
	return _size == 0 ? true : false;
}

void string::resize(size_t n, char c)
{
	if (n > _capacity)
	{
		reserve(_capacity == 0 ? 4 : _capacity * 2);
	}
	if (n < _size)
	{

		_size = n;
		_str[_size] = '\0';
	}
	else
	{
		for (int i = _size; i < n; i++)
		{
			_str[i] = c;
		}
		_size = n;
		_str[_size] = '\0';
	}
}

void string::reserve(size_t n)
{
	if (n > _capacity)
	{
		char* tmp = new char[n + 1];
		memcpy(tmp, _str, (_size + 1) * sizeof(char));
		delete[] _str;
		_str = tmp;
		_capacity = n;
	}
}

// access
char& string::operator[](size_t index)
{
	assert(index < _size);
	return *(_str + index);
}

const char& string::operator[](size_t index)const
{
	assert(index < _size);
	return *(_str + index);
}

//relational operators
bool string::operator<(const string& s)
{
	return strcmp(_str, s._str) < 0;
}

bool string::operator<=(const string& s)
{
	return ((* this < s)||(*this == s));
}

bool string::operator>(const string& s)
{
	return strcmp(_str, s._str) > 0;
}

bool string::operator>=(const string& s)
{
	return ((*this > s) || (*this == s));
}

bool string::operator==(const string& s)
{
	return strcmp(_str, s._str) == 0;
}

bool string::operator!=(const string& s)
{
	return strcmp(_str, s._str) != 0;
}

// 返回c在string中第一次出现的位置
size_t string::find(char c, size_t pos) const
{
	assert(pos < _size);
	for (int i = pos; i < _size; i++)
	{
		if (_str[i] == c)
		{
			return i;
		}
	}
	return npos;
}

// 返回子串s在string中第一次出现的位置
size_t string::find(const char* s, size_t pos) const
{
	assert(pos < _size);
	char* substr = strstr(_str + pos, s);
	if(substr)
	{
		return substr - _str;
	}
	else
	{
		return npos;
	}
}

// 在pos位置上插入字符c/字符串str，并返回该字符的位置
string& string::insert(size_t pos, char c)
{
	assert(pos <= _size);
	if (_size == _capacity)
	{
		reserve(_capacity == 0? 4 : _capacity * 2);
	}
	char* cur = _str + _size + 1;
	while (cur > _str + pos)
	{
		*cur = *(cur - 1);
		cur--;
	}
	_str[pos] = c;
	_size++;
	return *this;
}

string& string::insert(size_t pos, const char* str)
{
	assert(pos <= _size);
	int len = strlen(str);
	if (_capacity < len + _size)
	{
		reserve(len + _size);
	}
	char* end = _str + _size;
	while (end >= _str + pos)
	{
		*(end + len) = *end;
		end--;
	}
	strncpy(_str + pos, str, len);
	_size += len;
	return *this;
}

// 删除pos位置上的元素，并返回该元素的下一个位置
string& string::erase(size_t pos, size_t len)
{
	assert(pos < _size);
	int leftLen = _size - pos;
	if (len >= leftLen)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		int cur = pos;
		int next = pos + len;
		while (next < _size)
		{
			_str[cur] = _str[next];
			cur++;
			next++;
		}
		_size -= len;

	}
	return *this;
}
