#pragma once
#include <string>
#include <fstream>
#include "rapidxml.hpp"

namespace penguine
{
	class XML
	{
	private:
		rapidxml::xml_document<>* m_XMLDocument;
		rapidxml::xml_attribute<>* m_XMLAttribute;
		char* m_XMLContents;
		std::string m_FileName;

		rapidxml::xml_node<>* m_RootNode;
		rapidxml::xml_node<>* m_Node;

		size_t m_FileSize = 0;

		void ReadFile(std::string path);
		bool Parse();
	public:
		XML(std::string path);
		~XML();

		size_t GetFileSize();

		std::string ToString();
	};
}