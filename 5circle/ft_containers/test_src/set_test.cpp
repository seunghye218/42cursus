/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:45:57 by seunghye          #+#    #+#             */
/*   Updated: 2023/02/06 20:34:49 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <set>
#include <vector>

#include "utility.hpp"
#include "set.hpp"
#include "vector.hpp"

const std::string GREEN = "\x1B[1;32m";
const std::string REDD = "\x1B[1;31m";
const std::string YELLOW = "\x1B[1;33m";
const std::string WHITE = "\x1B[1;39m";
const std::string RESET = "\033[0m";

using std::cout;
using std::endl;

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

template <class T, class C>
void fillSet(NAMESPACE::set<T, C> &mp) {
        mp.insert(16);
        mp.insert(8);
        mp.insert(23);
        mp.insert(7);
        mp.insert(19);
        mp.insert(29);
        mp.insert(41);
        mp.insert(4);
        mp.insert(11);
}

int	main()
{
	cout << REDD + "==========" + "constructor" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> first;                           // empty set of ints

		int myints[]= {10,20,30,40,50};
		NAMESPACE::set<int> second (myints,myints+5);        // range

		NAMESPACE::set<int> third (second);                  // a copy of second

		NAMESPACE::set<int> fourth (second.begin(), second.end());  // iterator ctor.

		NAMESPACE::set<int,classcomp> fifth;                 // class as Compare

		bool(*fn_pt)(int,int) = fncomp;
		NAMESPACE::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
	}
	cout << REDD + "==========" + "begin, end" + "==========" + RESET << endl;
	{
 		 int myints[] = {75,23,65,42,13};
		NAMESPACE::set<int> myset (myints,myints+5);

		std::cout << "myset contains:";
		for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}
	cout << REDD + "==========" + "rbegin, rend" + "==========" + RESET << endl;
	{
		int myints[] = {21,64,17,78,49};
		NAMESPACE::set<int> myset (myints,myints+5);

		NAMESPACE::set<int>::reverse_iterator rit;

		std::cout << "myset contains:";
		for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
			std::cout << ' ' << *rit;

		std::cout << '\n';
	}
	cout << REDD + "==========" + "empty" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;

		myset.insert(20);
		myset.insert(30);
		myset.insert(10);

		std::cout << "myset contains:";
		while (!myset.empty())
		{
			std::cout << ' ' << *myset.begin();
			myset.erase(myset.begin());
		}
		std::cout << '\n';
	}
	cout << REDD + "==========" + "size" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; ++i) myints.insert(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.erase(5);
		std::cout << "3. size: " << myints.size() << '\n';
	}
	cout << REDD + "==========" + "max_size" + "==========" + RESET << endl;
	{
		int i;
		NAMESPACE::set<int> myset;

		if (myset.max_size()>1000)
		{
			for (i=0; i<1000; i++) myset.insert(i);
			std::cout << "The set contains 1000 elements.\n";
		}
		else std::cout << "The set could not hold 1000 elements.\n";
	}
	cout << REDD + "==========" + "insert" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;
		NAMESPACE::set<int>::iterator it;
		NAMESPACE::pair<NAMESPACE::set<int>::iterator,bool> ret;

		// set some initial values:
		for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

		ret = myset.insert(20);               // no new element inserted

		if (ret.second==false) it=ret.first;  // "it" now points to element 20

		myset.insert (it,25);                 // max efficiency inserting
		myset.insert (it,24);                 // max efficiency inserting
		myset.insert (it,26);                 // no max efficiency inserting

		int myints[]= {5,10,15};              // 10 already in set, not inserted
		myset.insert (myints,myints+3);

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "erase" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;
		NAMESPACE::set<int>::iterator it;

		// insert some values:
		for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

		it = myset.begin();
		++it;                                         // "it" points now to 20

		myset.erase (it);

		myset.erase (40);

		it = myset.find (60);
		myset.erase (it, myset.end());

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "swap" + "==========" + RESET << endl;
	{
		int myints[]={12,75,10,32,20,25};
		NAMESPACE::set<int> first (myints,myints+3);     // 10,12,75
		NAMESPACE::set<int> second (myints+3,myints+6);  // 20,25,32

		first.swap(second);

		std::cout << "first contains:";
		for (NAMESPACE::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (NAMESPACE::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "clear" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;

		myset.insert (100);
		myset.insert (200);
		myset.insert (300);

		std::cout << "myset contains:";
		for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		myset.clear();
		myset.insert (1101);
		myset.insert (2202);

		std::cout << "myset contains:";
		for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "key_comp" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;
		int highest;

		NAMESPACE::set<int>::key_compare mycomp = myset.key_comp();

		for (int i=0; i<=5; i++) myset.insert(i);

		std::cout << "myset contains:";

		highest=*myset.rbegin();
		NAMESPACE::set<int>::iterator it=myset.begin();
		do {
			std::cout << ' ' << *it;
		} while ( mycomp(*(++it),highest) );

		std::cout << '\n';
	}
	cout << REDD + "==========" + "value_comp" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;

		NAMESPACE::set<int>::value_compare mycomp = myset.value_comp();

		for (int i=0; i<=5; i++) myset.insert(i);

		std::cout << "myset contains:";

		int highest=*myset.rbegin();
		NAMESPACE::set<int>::iterator it=myset.begin();
		do {
			std::cout << ' ' << *it;
		} while ( mycomp(*(++it),highest) );

		std::cout << '\n';
	}
	cout << REDD + "==========" + "find" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;
		NAMESPACE::set<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

		it=myset.find(20);
		myset.erase (it);
		myset.erase (myset.find(40));

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "count" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;

		// set some initial values:
		for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

		for (int i=0; i<10; ++i)
		{
			std::cout << i;
			if (myset.count(i)!=0)
			std::cout << " is an element of myset.\n";
			else
			std::cout << " is not an element of myset.\n";
		}
	}
	cout << REDD + "==========" + "lower_bound" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;
		NAMESPACE::set<int>::iterator itlow,itup;

		for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

		itlow=myset.lower_bound (30);                //       ^
		itup=myset.upper_bound (60);                 //                   ^

		myset.erase(itlow,itup);                     // 10 20 70 80 90

		std::cout << "myset contains:";
		for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "upper_bound" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;
		NAMESPACE::set<int>::iterator itlow,itup;

		for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

		itlow=myset.lower_bound (30);                //       ^
		itup=myset.upper_bound (60);                 //                   ^

		myset.erase(itlow,itup);                     // 10 20 70 80 90

		std::cout << "myset contains:";
		for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "equal_range" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;

		for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

		NAMESPACE::pair<NAMESPACE::set<int>::const_iterator,NAMESPACE::set<int>::const_iterator> ret;
		ret = myset.equal_range(30);

		std::cout << "the lower bound points to: " << *ret.first << '\n';
		std::cout << "the upper bound points to: " << *ret.second << '\n';
	}
	cout << REDD + "==========" + "get_allocator" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int> myset;
		int * p;
		unsigned int i;

		// allocate an array of 5 elements using myset's allocator:
		p=myset.get_allocator().allocate(5);

		// assign some values to array
		for (i=0; i<5; i++) p[i]=(i+1)*10;

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		myset.get_allocator().deallocate(p,5);
	}
	cout << REDD + "==========" + "operator" + "==========" + RESET << endl;
	{
		NAMESPACE::set<int, int> foo;
			for (int i = 0; i < 10; i++)
				foo[i] = (i * 4);
		NAMESPACE::set<int, int> bar;
			for (int i = 0; i < 10; i++)
				bar[i] = (i * 3);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	cout << REDD + "==========" + "iterator" + "==========" + RESET << endl;
	{
		{
			NAMESPACE::set<int, int> v;
			for (int i = 0; i < 10; i++)
				v[i] = (i * 4);
			// for (set<int>::const_iterator it = v.begin(); it != v.end(); ++it)
			NAMESPACE::set<int, int>::const_iterator it = v.begin();
			NAMESPACE::set<int, int>::const_iterator ite = v.end();
			while (it != ite){
					std::cout << it->second << std::endl;
					it++;
			}

			// test comparison of 2 iterators (const & non-const)
			NAMESPACE::set<int, char> a;
			for (int i = 0 ; i < 6; i ++)
					a[i] = (i + 'a');
			NAMESPACE::set<int, char>::iterator it1 = ++a.begin();
			NAMESPACE::set<int, char>::const_iterator cit = ++(++a.begin());
			std::cout << (it1 != cit) << std::endl;
		}
		{
			NAMESPACE::set<int, int> v;
			for (int i = 0; i < 10; i++)
				v[i] = (i * 4);
			std::string s = "0101010001111010101010101001010111101";
			for (unsigned int i = 0; i < s.size(); i++) {
				if (s[i] == '1')
					v[i] = (i);
				if (s[i] == '0')
					v.erase(--v.end());
			}

			// for (NAMESPACE::set<int, int>::const_iterator it = v.begin(); it != v.end(); ++it)
			NAMESPACE::set<int, int>::const_reverse_iterator it = v.rbegin();
			NAMESPACE::set<int, int>::const_reverse_iterator ite = v.rend();
			while (it != ite) {
				std::cout << it->second << std::endl;
				it++;
			}
		}
	}
	cout << REDD + "==========" + "compare" + "==========" + RESET << endl;
	{
		// NAMESPACE::set<int, int> mp1, mp2, mp3, mp4;

		NAMESPACE::set<int, int> mp;
		NAMESPACE::vector<int> v;
		fillMap(mp);
		for (NAMESPACE::set<int, int>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::set<int, int>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::set<int, int, std::greater<int> > mp1;
		fillMap(mp1);
		v.push_back(mp1.begin()->first);
		mp1.erase(41);
		v.push_back(mp1.begin()->first);
		mp1.erase(29);
		v.push_back(mp1.begin()->first);
		NAMESPACE::set<int, int, std::greater<int> > mp2;
		mp2.insert(NAMESPACE::make_pair(3, 3));
		v.push_back(mp2.begin()->first);
		mp2.erase(3);
		if (mp2.begin() == mp2.end())
			v.push_back(1);
		NAMESPACE::set<int, int, std::plus<int> > mp3;
		fillMap(mp3);
		for (NAMESPACE::set<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::set<int, int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::set<int, int, std::minus<int> > mp4;
		fillMap(mp4);
		for (NAMESPACE::set<int, int>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::set<int, int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::set<int, int, std::greater_equal<int> > mp5;
		fillMap(mp5);
		for (NAMESPACE::set<int, int>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::set<int, int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::set<int, int, std::multiplies<int> > mp6;
		fillMap(mp6);
		for (NAMESPACE::set<int, int>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::set<int, int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::set<int, int, std::bit_xor<int> > mp7;
		fillMap(mp7);
		for (NAMESPACE::set<int, int>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::set<int, int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::set<int, int, std::logical_and<int> > mp8;
		fillMap(mp8);
		for (NAMESPACE::set<int, int>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::set<int, int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
		v.push_back(mp1.size());
		
		NAMESPACE::vector<int>::iterator it = v.begin();
		NAMESPACE::vector<int>::iterator ite = v.end();
		while (it != ite) {
			std::cout << *it << std::endl;
			it++;
		}
	}
}
