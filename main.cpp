#include<bits/stdc++.h>

#include "building.hpp"
#include "user.hpp"

using namespace std;


int bid;




class handler{
	map<string,building>nxBuilding;
	map<string,user>nxUser;
	map<int,bookings>nxBooking;
	// set<bookings>all_bookings;
public:
	void add_building(string buildingName)
	{
		building temp;
		temp.init(buildingName);
		nxBuilding[temp.get_name()]=temp;
		cout<<"Building added\n";
	}


	void add_user(user temp)
	{
		nxUser[temp.get_name()]=temp;
		// user_added
	}

	void add_bookings(bookings temp)
	{
		nxBooking[temp.get_id()]=temp;
	}

	void get_booking_details(string name)
	{
		auto temp=nxUser[name];
		// temp.get_bookings();
	}	

	void add_floor(string floorName,string buildingName)
	{
		floorr temp;
		temp.init(floorName);
		auto&nx=nxBuilding[buildingName];
		nx.add_floor(temp);
	}

	void add_room(string floorName,string buildingName,string roomName)
	{
		confRoom temp;
		temp.init(roomName);
		auto&nx=nxBuilding[buildingName];
		nx.add_room(floorName,roomName);
	}

	void book(int start,int end,string buildingName,string floorName,string roomName,string userName)
	{
		auto&nx=nxBuilding[buildingName];

		if(nxUser.find(userName)==nxUser.end())
		{
			user temp;
			temp.init(userName);
			nxUser[userName]=temp;

		}

		if(!nx.is_booking_possible(floorName,roomName,start,end))
		{
			cout<<"Booking_not_possible\n";
		}
		else
		{
			nx.book(floorName,roomName,start,end);
			auto&ux=nxUser[userName];
			bookings temp;
			temp.init(bid++,buildingName,floorName,roomName,start,end);
			cout<<"Booking successfull\n";
			// all_bookings.insert(temp);
		}

	}

	void search(int start,int end,string buildingName,string floorName)
	{
		auto&nx=nxBuilding[buildingName];
		nx.get_all_rooms(floorName,start,end);
	}

	void cancel(int start,int end,string buildingName,string floorName,string roomName)
	{
		auto&nx=nxBuilding[buildingName];
		nx.cancel_booking(floorName,roomName,start,end);
		cout<<"booking cancelled\n";
	}

	// void print_all_bookings()
	// {
	// 	for(auto i : all_bookings)
	// 	{
	// 		i.print_bookings();
	// 	}
	// }
};


int main()
{
	handler Handler;
	string s;
	while(cin>>s)
	{
		if(s=="add_building")
		{
			string name;
			cin>>name;
			Handler.add_building(name);
		}
		else if(s=="add_floor")
		{
			string fn,bn;
			cin>>bn>>fn;
			Handler.add_floor(fn,bn);
		}
		else if(s=="add_confroom")
		{
			string fn,bn,rn;
			cin>>fn>>bn>>rn;
			Handler.add_room(fn,bn,rn);
		}
		else if(s=="book")
		{
			string fn,bn,rn,un;
			int a,b;
			cin>>fn>>bn>>rn>>un>>a>>b;
			Handler.book(a,b,bn,fn,rn,un);
		}
		// else if(s=="list")
		// {
		// 	string un;
		// 	cin>>un;
		// 	Handler.list(un);
		// }
		else if(s=="search")
		{
			int a,b;
			string bn,fn;
			cin>>a>>b>>bn>>fn;
			Handler.search(a,b,bn,fn);
		}
		else if(s=="cancel")
		{
			int a,b;
			string bn,fn,rn;
			cin>>a>>b>>bn>>fn>>rn;
			Handler.cancel(a,b,bn,fn,rn);
		}
	}

}