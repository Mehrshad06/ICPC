#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define sari ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair

const int mxn = 1005;
char al[30];
char amme[6][6];
bool mark[100];
map<char, pii> ma;

void jadval(string s)
{
	int i = 0, j = 0;
	int t = 0;
	int tt = 0;
	while(j < 5)
	{
		// cout << "{";
		while(t < s.size() && (s[t] == ' ' || mark[s[t] - 'a'])) 
		{
			// cout << s[t];
			t++;
		}
		// cout << s[t] << "}  [";
		while(mark[al[tt] - 'a'] && tt < 26) 
		{
			// cout << al[tt];
			tt++;
		}
		// cout << al[tt] << "]\n";
		if(t < s.size())
		{
			amme[i][j] = s[t];
			t++;
			mark[amme[i][j] - 'a'] = 1;
		}
		else
		{
			amme[i][j] = al[tt];
			tt++;
			mark[amme[i][j] - 'a'] = 1;
		}
		i++;
		if(i > 4)
		{
			i = 0;
			j++;
		}
	}
}

int32_t main()
{
	// sari
	int t = 0;
	for(int i = 0; i < 26; i++)
	{
		if('a' + i == 'q') continue;
		al[t++] = 'a' + i;
	}
	// for(int i = 0; i < 25; i++) cout << al[i] << ' ';
	// cout << '\n';
	string key, s;
	getline(cin, key);
	getline(cin, s);
	string kk, ss;
	kk = ss = "";
	int n = s.size();
	for(int i = 0; i < n; i++)
	{
		if(s[i] != ' ') ss += s[i];
	}
	jadval(key);
	// for(int  i = 0; i < 5; i++)
	// {
		// for(int j = 0; j < 5; j++)
		// {
			// cout << amme[j][i] << " ";
		// }
		// cout << '\n';
	// }
	// cout << ss << '\n';
	n = ss.size();
	t = 0;
	s = "";
	for(int i = 0; i < ss.size(); i+=2)
	{
		// cout << i << " ";
		if(ss[i] != ss[i + 1] && i + 1 < n)
		{
			s += ss[i];
			s += ss[i + 1];
			t += 2;
		}
		else
		{
			if(ss[i] == ss[i + 1] && i + 1 < n)
			{
				s += ss[i];
				s += 'x';
				i--;
				t += 1;
			}
		}
	}
	if(t != ss.size()) s += ss[ss.size() - 1];
	if(s.size() % 2) s += 'x';
	// cout << '\n';
	// cout << s << '\n';
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			ma[amme[i][j]] = mp(i, j);
		}
	}
	string ans = "";
	n = s.size();
	for(int i = 0; i < n; i+=2)
	{
		// cout << i;
		pii q1, q2;
		q1 = ma[s[i]];
		q2 = ma[s[i + 1]];
		pii ans1, ans2;
		ans1 = q1;
		ans2 = q2;
		if(q1.S == q2.S)
		{
			// cout << "! ";
			ans1.F++;
			ans1.F %= 5;
			ans2.F++;
			ans2.F %= 5;
			s[i] = amme[ans1.F][ans1.S];
			s[i + 1] = amme[ans2.F][ans2.S];
			continue;
		}
		if(q1.F == q2.F)
		{
			// cout << "@ ";
			ans1.S++;
			ans1.S %= 5;
			ans2.S++;
			ans2.S %= 5;
			s[i] = amme[ans1.F][ans1.S];
			s[i + 1] = amme[ans2.F][ans2.S];
			continue;
		}
		// cout << "# ";
		swap(ans1.F, ans2.F);
		s[i] = amme[ans1.F][ans1.S];
		s[i + 1] = amme[ans2.F][ans2.S];
	}
	// cout << '\n';
	for(int i = 0; i < n; i++)
	{
		s[i] = s[i] - 'a' + 'A'; 
	}
	cout << s << '\n';
}
