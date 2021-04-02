#include<bits/stdc++.h>


	using namespace std;
	class bookings{
		int id;
		string buildingName;

		string floorName;
		string roomName;
		int start;
		int end;
	public:
		void init (int x,string s,string b,string c,int q,int w)
		{
			id=x;
			buildingName=s;
			floorName=b;
			roomName=c;
			start=q;
			end=w;
		}
		int get_id()
		{
			return id;
		}
		void print_bookings()
		{
			cout<<buildingName<<" "<<floorName<<" "<<roomName<<"\n";
		}

	};
		
