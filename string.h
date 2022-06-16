#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>

namespace IceCola
{
	
	class string
	{
		friend std::ostream& operator<<(std::ostream& _cout, const string& s)
		{
			for (int i = 0; i < s.size(); i++)
			{
				_cout << s[i];
			}
			return _cout;
		}
		friend std::istream& operator>>(std::istream& _cin, string& s);
	public:
		const size_t npos = -1;
		string(const char* str = "");
		string(const string& s);
		string& operator=(const string& s);
		~string();
	
		// iterator
		typedef char* iterator;
		iterator begin();
		iterator end();

		// modify
		void push_back(char c);
		string& operator+=(char c);
		void append(const char* str);
		string& operator+=(const char* str);
		void clear();
		void swap(string& s);
		const char* c_str()const;

		// capacity
		size_t size()const;
		size_t capacity()const;
		bool empty()const;
		void resize(size_t n, char c = '\0');
		void reserve(size_t n);
		
		// access
		char& operator[](size_t index);
		const char& operator[](size_t index)const;

		//relational operators
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);

		// ����c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const;
		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const;
		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);
		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		string& erase(size_t pos, size_t len);

	private:
		char* _str;
		int _size;
		int _capacity;
	};

}
