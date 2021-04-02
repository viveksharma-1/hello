#include<bits/stdc++.h>
#include "booking.hpp"

	using namespace std;
	class user{
		public:
		string name;
		map<bookings,int>userBookings;
	
		void init(string s)
		{
			name=s;
		}
		// void add_bookings(bookings temp)
		// {
		// 	userBookings[temp]=1;
		// }
		string get_name()
		{
			return name;
		}
		// void get_bookings()
		// {
		// 	for(auto i : userBookings)
		// 	{
		// 		i.first.print_bookings();
		// 	}
		// }
	};

