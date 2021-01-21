#include <iostream>
using namespace std;

class Achievements
{
private:
	string m_title;
	string m_description;
	int m_scoreValue;

public:
	Achievements()
	{
		m_title = "NONE";
		m_description = "NONE";
		m_scoreValue = 0;
	}
	
	Achievements (string title1, string description1, int scoreValue1)
	{
		m_title = title1;
		m_description = description1;
		m_scoreValue = scoreValue1;
	}

	string getAchievementsData()
	{
		string data = "\nTitle: " + m_title;
		data += "\nDescription: " + m_description;
		data += "\nScore Value: " + m_scoreValue;
		data += "\n";
		return data;
	}
};

class Games
{
private:
	string m_gameName;
	string m_publisher;
	string m_developer;
	int m_achievementsNum;
	Achievements* m_pAchievements;

public:
	Games()
	{
		m_gameName = "NONE";
		m_publisher = "NONE";
		m_developer = "NONE";
	}

	Games(string gameName1, string publisher1, string developer1)
	{
		m_gameName = gameName1;
		m_publisher = publisher1;
		m_developer = developer1;
	}
	
	void setAchievementSize(int i)
	{
		m_pAchievements = new Achievements[i];
	}
	
	void setAchievementData(string title2, string description2, int scoreValue2, int achSize)
	{
		m_pAchievements[achSize] = Achievements(title2, description2, scoreValue2);
	}

	void setAchievementMemberSize(int achMemSize)
	{
		m_achievementsNum = achMemSize;
	}

	void getAchievementData()
	{
		for (int i = 1; i <= m_achievementsNum; i++)
		{
			
		}
	}
};


class Platform
{
private:
	string m_name;
	string m_manufacturer;
	Games* m_pGames;

public:
	Platform()
	{
		m_name = "NONE";
		m_manufacturer = "NONE";
	}
	
	void setPlatform(int j)
	{
		m_pGames = new Games[j];
	}
	string getPlatformData()
	{
		string data = "\nThe Games you own: "
	}
};




int main()
{

	return 0;
}