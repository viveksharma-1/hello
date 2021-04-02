#include<bits/stdc++.h>
using namespace std;

	class confRoom
	{
		string name;
		vector<int>availablity;
	public:
		
		void init(string s)
		{
			name=s;
			for(int i=0;i<25;i++)availablity.push_back(0);
		}

		string get_name()
		{
			return name;
		}
		bool check_availablity(int start,int end)
		{
			// try{	

			// }	
			// catch(...)
			// {

			// }
			bool ok = 1;
			for(int i=start+1;i<=end-1;i++)
			{
				if(availablity[i])
				{
					ok=0;
				}
			}
			return ok;
		}

		void book(int start,int end)
		{
			for(int i=start;i<=end;i++)
			{
				availablity[i]=1;
			}
		}
		void cancel_booking(int start,int end)
		{
			for(int i=start;i<=end;i++)
			{
				availablity[i]=0;
			}
		}

	};
