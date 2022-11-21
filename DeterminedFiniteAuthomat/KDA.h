#pragma once
#include <string>
#include <vector>
class KDA
{
public:
	KDA(std::string alphabet, std::vector<int> space);
	KDA();
	KDA operator<<(const KDA& other);
	bool isWordHere(std::string word);

private:
	int returnNextStand(std::vector<int> stands);


	std::string alphabet;
	std::vector<int> space;
	int q0;
	int next;
	std::vector<int> endStands;
};

