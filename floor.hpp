#include<bits/stdc++.h>
#include "confroom.hpp"


	class floorr
	{
		string name;
		set<confRoom>ConfRooms;
		map<string,confRoom>nxconfRoom;
	public:
		
		void init(string s)
		{
			name=s;
		}

		string get_name()
		{
			return name;
		}

		void add_confroom(confRoom temp)
		{
			// try{

			// }
			// catch(...)
			// {
				
			// }


			
			nxconfRoom[temp.get_name()]=temp;
		}

		bool is_booking_possible(string s,int start,int end)
		{
			// if(nxconfRoom.find(s)!=nxconfRoom.end())
			// {
			// 	cout<<"here|\n";
			// 	return 0;
			// }
			auto temp=nxconfRoom[s];
			if(!temp.check_availablity(start,end))
			{
				cout<<"here|\n";
				return 0;
			}
			return 1;

		}

		void book(string s,int start,int end)
		{
			if(!is_booking_possible(s,start,end))
			{

				return;
			}
			auto&temp=nxconfRoom[s];
			temp.book(start,end);
		}
		void get_all_room(int start,int end)
		{
			for(auto i : nxconfRoom)
			{
				if(i.second.check_availablity(start,end))
				{
					cout<<i.second.get_name()<<" available\n";
				}
			}
		}

		void cancel_booking(string roomName,int start,int end)
		{
			auto&temp=nxconfRoom[roomName];
			temp.cancel_booking(start,end);
		}


	};
