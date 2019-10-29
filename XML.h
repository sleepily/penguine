#pragma once
#include <string>
#include <fstream>
#include "rapidxml.hpp"

namespace penguine
{
	class XML
	{
	private:
		rapidxml::xml_document<> m_XMLDocument;
		rapidxml::xml_attribute<>* m_XMLAttribute;
		char* m_XMLContents;

		rapidxml::xml_node<>* m_RootNode;
		rapidxml::xml_node<>* m_Node;

		int m_FileSize = -1;

		void ReadFile(std::string path);
		bool Parse();
	public:
		XML(std::string path);
		~XML();

		int GetFileSize();

		static std::string ToString();
	};
}