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

	Achievements(string title1, string description1, int scoreValue1)
	{
		m_title = title1;
		m_description = description1;
		m_scoreValue = scoreValue1;
	}
	~Achievements() {}

	string getAchievementsData()
	{
		string data = "\nTitle: " + m_title;
		data += "\nDescription: " + m_description;
		data += "\nScore Value: " + m_scoreValue;
		data += "\n";
		return data;
	}
};

class Games : public Achievements
{
private:
	string m_gameName;
	string m_publisher;
	string m_developer;
	size_t m_achiNum;
	Achievements* m_pAchievements = nullptr;


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
	~Games()
	{
		delete[] m_pAchievements;
		m_pAchievements = nullptr;
	}

	void setAchievementInfo()
	{
		string m_title;
		string m_description;
		int m_scoreValue;
		size_t achSize;

		//set number
		cin >> achSize;


		this->setAchievementSize(achSize);
		for (int i = 0; i < achSize; i++)
		{
			// title
			getline(cin, m_title);
			getline(cin, m_title);
			// description
			getline(cin, m_description);
			// value
			cin >> m_scoreValue;
			cout << "AAA";
			this->m_pAchievements[i] = Achievements(m_title, m_description, m_scoreValue);
		}
	}

	void setAchievementSize(size_t achSize)
	{
		m_achiNum = achSize;
		m_pAchievements = new Achievements[achSize];
	}

	void getAchievementData()
	{
		for (int i = 1; i <= m_achiNum; i++)
		{
			cout << "\nThe NO." << i << "Achievement is" << this->m_pAchievements[i - 1].getAchievementsData() << endl;
		}
	}
	size_t getAchiSize()
	{
		return m_achiNum;
	}

	string getGameInfo()
	{
		string data = "\nThe name of Game: " + m_gameName + "\n";
		data += "\nThe name of Publisher: " + m_publisher + "\n";
		data += "\nThe name of Developer name: " + m_developer + "\n";
		data += "\n";
		return data;
	}
	void getAllAchiData()
	{
		for (int i = 0; i < m_achiNum; i++)
		{
			cout << this->m_pAchievements[i].getAchievementsData();
		}

	}
};


class Platform : public Games
{
private:
	string m_platformName;
	string m_manufacturer;
	size_t m_gameNum;
	Games* m_pGames = nullptr;

public:
	Platform()
	{
		m_platformName = "Your Console";
		m_manufacturer = "Default Empty";
	}

	Platform(string platformName1, string manufacturer1)
	{
		m_platformName = platformName1;
		m_manufacturer = manufacturer1;
	}

	~Platform()
	{
		// *m_pGames()
		delete[] m_pGames;
		m_pGames = nullptr;
	}

	void setGamesSize()
	{
		size_t gamesNum;
		cin >> gamesNum;
		m_gameNum = gamesNum;
		m_pGames = new Games[gamesNum];
	}

	void setGamesInfo()
	{
		string gamesName3, publisher3, developer3;

		for (int i = 0; i < m_gameNum; i++)
		{
			// name
			cout << "n";
			getline(cin, gamesName3);
			getline(cin, gamesName3);
			// publisher
			cout << "publisher3";
			getline(cin, publisher3);
			// developer
			cout << "developer";
			getline(cin, developer3);

			this->m_pGames[i] = Games(gamesName3, publisher3, developer3);

			this->m_pGames[i].setAchievementInfo();
		}
	}

	size_t getGamesSize()
	{
		return m_gameNum;
	}
	Games getGameNum(int i)
	{
		return this->m_pGames[i];
	}
	string getPlatData()
	{
		string data = "\nThe name of platform: " + m_platformName + "\n";
		data += "\nThe name of manufacturer: " + m_manufacturer + "\n";
		data += "\n";
		return data;
	}
	void getAllPlatData(int platNum)
	{
		for (int i = 0; i < platNum; i++)
		{
			cout << this->getPlatData();
		}
	}
	void getAllGameData()
	{
		for (int i = 0; i < m_gameNum; i++)
		{
			cout << this->m_pGames[i].getGameInfo();
		}
	}
	void getAllAchiInfo(size_t gameNum)
	{
		this->m_pGames[gameNum].getAchievementData();
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

};




int main()
{
	Platform* console = nullptr;
	size_t consoleNum;
	string consoleName, manufactureName, gameName, publisher, developer;
	size_t menuC1 = 0, menuC2 = 0;

	cout << "Dear client, this is a console application for your games and achievements!\n" << endl;

	cout << "Please input the console numbers for this application!\n" << endl;

	// Get number of consoles
	cin >> consoleNum;

	console = new Platform[consoleNum];

	for (int i = 0; i < consoleNum; i++)
	{
		// get name
		cout << "Please input No." << i+1 << " console's type-name.\n" << endl;
		
		getline(cin, consoleName);
		getline(cin, consoleName);
		
		// get manufacture name
		cout << "Please input No." << i + 1 << " console's manufacturer name.\n" << endl;
		getline(cin, manufactureName);

		console[i] = Platform(consoleName, manufactureName);
		cout << console[i].getPlatData();

		// get game number
		cout << "number";
		console[i].setGamesSize();

		console[i].setGamesInfo();

	}

	// Main Menu
	while (menuC1 != 1)
	{
		console->getAllPlatData(consoleNum);

		// ask which console they want to check
		cin >> menuC1;

		console[menuC1 - 1].getAllGameData();

		// which game?
		cin >> menuC2;
		console[menuC1 - 1].getAllAchiInfo(menuC2 - 1);

		// wanna go back?
		//1 no , 2 yes
		cin >> menuC1;
	}


	return 0;
}