#include "..\include\FileReaderAssests.h" 

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

FileReaderAssests::FileReaderAssests(std::string p_Textures)
{

	std::fstream textureFile(p_Textures, std::ios_base::in);
	std::string textureLine = "";

	if (textureFile.is_open()) {

		while (getline(textureFile, textureLine))
		{
			std::string str;
			std::istringstream isstr(textureLine);
			isstr >> str;

			std::string tempTag; std::string tempFile;

			if (str == "id:") { isstr >> tempTag; }

			isstr >> str;

			if (str == "file:") { isstr >> tempFile; }

			m_Textures.push_back(std::make_pair(tempTag, tempFile));
		}
	}
	else {
		std::cout << "cannot open the File" << std::endl;
	}

}

std::vector<std::pair<std::string, std::string>> FileReaderAssests::getTextures()
{
	return m_Textures;
}

