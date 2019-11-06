#include <iostream>
#include <string>
#include <stdio.h>
#include <cctype>
#include <algorithm>
#include "XML.h"
#include "rapidxml.hpp"

namespace penguine
{
	rapidxml::xml_node<>* XML::FindChildNode(rapidxml::xml_node<>* pNode, char* szName)
	{
		for (rapidxml::xml_node<>* pChild = pNode->first_node(); pChild != NULL; pChild = pChild->next_sibling()) {
			if (strcmp(pChild->name(), szName) == 0) return pChild;
		}
		return NULL;
	}

	rapidxml::xml_attribute<>* XML::FindAttribute(rapidxml::xml_node<>* pNode, char* szName)
	{
		for (rapidxml::xml_attribute<>* pAttr = pNode->first_attribute(); pAttr != NULL; pAttr = pAttr->next_attribute())
		{
			if (strcmp(pAttr->name(), szName) == 0) return pAttr;
		}
		return NULL;
	}

	XML::XML(std::string path)
	{
		m_Node = new rapidxml::xml_node<>(rapidxml::node_type::node_document);
		m_RootNode = new rapidxml::xml_node<>(rapidxml::node_type::node_document);

		ReadFile(path);
		Parse();
	}

	void XML::ReadFile(std::string path)
	{
		std::ifstream inputFile(path, std::ios::binary);
		std::streampos streampos_begin = inputFile.tellg();
		inputFile.seekg(0, std::ios::end);
		std::streampos streampos_end = inputFile.tellg();
		size_t fileSize = streampos_end - streampos_begin;
		inputFile.seekg(0, std::ios::beg);

		m_FileSize = fileSize;
		m_FileName = path;

		m_XMLContents = new char[fileSize + 1];
		memset(m_XMLContents, 0, fileSize + 1);
		inputFile.read(m_XMLContents, fileSize);
		std::cout << m_XMLContents << std::endl;
		inputFile.close();
	}
	
	bool XML::Parse()
	{
		m_XMLDocument = new rapidxml::xml_document<>();
		m_XMLDocument->parse<0>(m_XMLContents);

		m_RootNode = m_XMLDocument->first_node();
		m_Node = m_RootNode->first_node();

		std::string temp = m_Node->name();

		return true;
	}

	size_t XML::GetFileSize()
	{
		if (m_FileSize > 0)
			return m_FileSize;

		return 0;
	}
	
	std::string XML::ToString()
	{
		std::string output;

		output += "XML File " + m_FileName + ": \n\n";

		output += ToStringRecursive(m_Node, 0);
			
		return output;
	}

	std::string XML::ToStringRecursive(rapidxml::xml_node<>* firstSibling, unsigned int level)
	{
		std::string output;

		std::string t = "";

		for (unsigned int i = 0; i < level; i++)
			t += "\t";

		for (rapidxml::xml_node<>* siblingNode = firstSibling; siblingNode != NULL; siblingNode = siblingNode->next_sibling())
		{
			output += t + "\n<" + std::string(siblingNode->name()) + "> \n";

			// Trim Name to filter out empty values
			std::string nodeValueTrimmed = siblingNode->value();
			nodeValueTrimmed.erase(std::remove_if(nodeValueTrimmed.begin(), nodeValueTrimmed.end(), std::isspace), nodeValueTrimmed.end());
			nodeValueTrimmed.erase(std::remove_if(nodeValueTrimmed.begin(), nodeValueTrimmed.end(), std::isblank), nodeValueTrimmed.end());

			// Print node value
			if (!nodeValueTrimmed.empty())
				output += t + "\t" + std::string(siblingNode->value()) + "\n\n";
			else
				output += t + "\t{ no value }\n\n";
			output += t + "\t- - - - - - - -\n";

			// Print its attributes
			for (rapidxml::xml_attribute<>* pAttr = siblingNode->first_attribute(); pAttr != NULL; pAttr = pAttr->next_attribute())
				output += t + "\t" + std::string(pAttr->name()) + " = \"" + std::string(pAttr->value()) + "\"\n";
			output += t + "\t- - - - - - - -\n";

			// Print its children
			for (rapidxml::xml_node<>* childNode = siblingNode->first_node(); childNode != NULL; childNode = childNode->next_sibling())
				output += t + "\t" + ToStringRecursive(childNode, ++level) + "\"\n";
		}

		return output;
	}
}
