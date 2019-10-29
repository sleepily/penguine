#include <iostream>
#include <string>
#include <stdio.h>
#include "XML.h"
#include "rapidxml.hpp"

namespace penguine
{
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
		// std::cout << m_XMLContents << std::endl;
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

		for (rapidxml::xml_node<>* node = m_Node; node != NULL; node = node->next_sibling())
		{
			output += std::string(node->name()) + ": \n";
			for (rapidxml::xml_attribute<>* pAttr = node->first_attribute(); pAttr != NULL; pAttr = pAttr->next_attribute())
				output += "\t" + std::string(pAttr->name()) + " = " + std::string(pAttr->value()) + ",\n";
		}
			
		return output;
	}
}
