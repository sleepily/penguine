#pragma once
#include <string>
#include <fstream>
#include <list>
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

		std::string ToStringRecursive(rapidxml::xml_node<>* firstSibling, unsigned int level);
		void ReadFile(std::string path);
		bool Parse();
	public:
		static rapidxml::xml_node<>* FindChildNode(rapidxml::xml_node<>* pNode, const char* szName);
		static rapidxml::xml_attribute<>* FindAttribute(rapidxml::xml_node<>* pNode, const char* szName);
		XML(std::string path);

		size_t GetFileSize();

		rapidxml::xml_node<>* GetRootNode();

		std::string ToString();
	};
}