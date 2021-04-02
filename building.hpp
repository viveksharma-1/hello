#include<bits/stdc++.h>
#include "floor.hpp"
	using namespace std;


	
	class building
	{
		string name;
		// set<floor>Floors;
		map<string,floorr>nxFloor;
	public:
		
		void init(string s)
		{
			name=s;
		}

		string get_name()
		{
			return name;
		}

		void add_floor(floorr temp)
		{
			// try{

			// }
			// catch(...)
			// {
				
			// }


			// Floors.insert(temp);
			nxFloor[temp.get_name()]=temp;
		}

		void add_room(string floorName,string roomName)
		{
			auto&nx=nxFloor[floorName];
			confRoom temp;
			temp.init(roomName);
			nx.add_confroom(temp);
		}
		bool is_booking_possible(string floorName,string roomName,int start,int end)
		{
			// if(nxFloor.find(floorName)!=nxFloor.end())
			// {
			// 	cout<<"here...\n";
			// 	return 0;
			// }
			auto temp=nxFloor[floorName];
			if(!temp.is_booking_possible(roomName,start,end))
			{
				cout<<"here///\n";
				return 0;
			}

			return 1;

		}

		void book(string floorName,string roomName,int start,int end)
		{

			
			if(!is_booking_possible(floorName,roomName,start,end))
			{

				return ;
			}

			
			auto&temp=nxFloor[floorName];
			temp.book(roomName,start,end);

		}

		void get_all_rooms(string floorName,int start,int end)
		{
			auto&temp=nxFloor[floorName];
			temp.get_all_room(start,end);
		}
		void cancel_booking(string floorName,string roomName,int start,int end)
		{
			auto&temp=nxFloor[floorName];
			temp.cancel_booking(roomName,start,end);
		}



	};
