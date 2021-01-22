#include <iostream>
#include <string>
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
		m_title = "Defualt Empty";
		m_description = "Defualt Empty";
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
		m_gameName = "Defualt Empty";
		m_publisher = "Defualt Empty";
		m_developer = "Defualt Empty";
	}

	Games(string gameName1, string publisher1, string developer1)
	{
		m_gameName = gameName1;
		m_publisher = publisher1;
		m_developer = developer1;
	}
	
	void setAchievementSize(int achSize)
	{
		m_pAchievements = new Achievements[achSize];
	}
	
	void setAchievementData(string title2, string description2, int scoreValue2, int achSize)
	{
		m_pAchievements[achSize] = Achievements(title2, description2, scoreValue2);
	}

	void setAchievementMemberOrdinal(int achMemOrdinal)
	{
		m_achievementsNum = achMemOrdinal;
	}

	void getAchievementData()
	{
		for (int i = 1; i <= m_achievementsNum; i++)
		{
			cout << "\nThe NO." << i << "Achievement is" << m_pAchievements[i - 1].getAchievementsData() << endl;
		}
	}

	int getAchMemberOrdinal()
	{
		return m_achievementsNum;
	}

	string getGameName()
	{
		return m_gameName;
	}

	string getPublisher()
	{
		return m_publisher;
	}

	string getGameInfo()
	{
		string data = "\nThe name of Game: " + m_gameName + "\n";
		data += "\nThe name of Publisher: " + m_publisher + "\n";
		data += "\nThe name of Developer name: " + m_developer + "\n";
		data += "\n";
		return data;
	}

	void deleteAchArray()
	{
		delete[] m_pAchievements;
		m_pAchievements = nullptr;
	}
};


class Platform
{
private:
	string m_platformName;
	string m_manufacturer;
	Games* m_pGames = nullptr;

public:
	Platform()
	{
		m_platformName = "Your Console";
		m_manufacturer = "Default Empty";
	}

	Platform (string platformName1, string manufacturer1)
	{
		m_platformName = platformName1;
		m_manufacturer = manufacturer1;
	}

	void setPlatformName (string platName)
	{
		m_platformName = platName;
	}

	void setManufacturer (string manufacName)
	{
		m_manufacturer = manufacName;
	}

	void setGamesSize (int gamesNum)
	{
		m_pGames = new Games[gamesNum];
	}

	void setAchievementsSize(int gamesNum, int achSize)
	{
		m_pGames[gamesNum].setAchievementMemberOrdinal(achSize);
	}

	void setGamesInfo (string gamesName3, string publisher3, string developer3, int achNum3)
	{
		m_pGames[achNum3] = Games(gamesName3, publisher3, developer3);
	}
	
	void setAchievementInfo(
		string title4, 
		string description4, 
		int scoreValue4, 
		int gameSize4, int achNum4)
	{
		m_pGames[gameSize4].setAchievementData(title4, description4, scoreValue4, achNum4);
	}

	void setAchievementOrdinal(int gamesSize5, int achMemOrdinal)
	{
		m_pGames[gamesSize5].setAchievementMemberOrdinal(achMemOrdinal);
	}

	int getAchMemOrdianl(int achMemOrd1)
	{
		return m_pGames[achMemOrd1].getAchMemberOrdinal();
	}

	void getGamesInfo(int gamesSize)
	{
		cout << m_pGames[gamesSize].getGameInfo();
	}
	
	void getAchievementsAllInfo(int achAllInfo)
	{
		m_pGames[achAllInfo].getAchievementData();
	}

	string getPlatData()
	{
		string data = "\nThe name of platform: " + m_platformName + "\n";
		data += "\nThe name of manufacturer: " + m_manufacturer + "\n";
		data += "\n";
		return data;
	}

	string getPlatformName()
	{
		return m_platformName;
	}

	string getManufacturer()
	{
		return m_manufacturer;
	}
	
	void getPlatformAllInfo(int allItemsNum)
	{
		cout << getPlatData() << endl;

		for (int k = 1; k <= allItemsNum; k++)
		{
			cout << k << ") " << m_pGames[k - 1].getGameInfo() << endl;
			m_pGames[k - 1].getAchievementData();
		}
	}

	void delGamesArray()
	{
		delete[] m_pGames;
		m_pGames = nullptr;
	}

	void delAllMem()
	{
		m_pGames->deleteAchArray();
		delGamesArray();
	}
};




int main()
{
	cout << "Dear client, this is a console application for your games and achievements!\n" << endl;

	cout << "You can rename your console.\n" << endl;

	

	
	return 0;
}