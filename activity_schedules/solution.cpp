/*Problem Statement
Given a number of days n (1 ≤ n ≤ 10), print all possible sequences of daily activities using the set:
{"Swimming", "Running", "Football"}
subject to the constraint that no two consecutive days have the same activity.
Input
A single integer n (1 ≤ n ≤ 10).
Output
Print each valid schedule on its own line, with activities separated by a single space.
After listing all schedules, print a final line: COUNT: X where X is the total number of schedules
generated.*/

/*  Example
  Input:
2
output:
Swimming Running 
Swimming Football 
Running Swimming 
Running Football 
Football Swimming 
Football Running 
COUNT: 6 */

//Recursion solution:

  #include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,cnt=0;
void activity_schedules(int x,vector<string>cur)
{
    if(x==n)
    {
        cnt++;
        for(int i=0;i<n;i++)
        cout<<cur[i]<<" ";
        cout<<endl;
        return;
    }
    vector<string>choic1=cur;
        choic1.push_back("Swimming");
        vector<string>choic2=cur;
        choic2.push_back("Running");
        vector<string>choic3=cur;
        choic3.push_back("Football");
        
    if(cur.empty()){
        activity_schedules(x+1,choic1);
        activity_schedules(x+1,choic2);
        activity_schedules(x+1,choic3);
    }
    else if(cur.back()=="Swimming")
    {
        activity_schedules(x+1,choic2);
        activity_schedules(x+1,choic3);
    }
     else if(cur.back()=="Running")
    {
        activity_schedules(x+1,choic1);
        activity_schedules(x+1,choic3);
    }
     else if(cur.back()=="Football")
    {
        activity_schedules(x+1,choic1);
        activity_schedules(x+1,choic2);
    }
   
}
void Solve()
{
  cin>>n;
  activity_schedules(0,{});
  cout<<"COUNT: "<<cnt<<endl;
}
 
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	 //cin >> t;
	while (t--) {
		Solve();
	}

	return 0;
}
//name:aisha_braiwesh
//ID:aishabraiwesh@gmail.com
