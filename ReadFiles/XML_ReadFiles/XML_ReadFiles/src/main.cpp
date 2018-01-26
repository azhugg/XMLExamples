
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;


#include "../tinyxml/AfTinyXml.h"

struct Note
{
	int id;
	char when[32];
	char who[32];
	char what[128];
};

vector<Note> notes;

int main()
{
	// 解析xml
	TiXmlDocument xml_doc;
	if(!xml_doc.LoadFile("example02b.xml"))
	{
		return -1;
	}

	// 根节点
	TiXmlElement* xml_root = xml_doc.RootElement();
	if (NULL == xml_root)
	{
		return -1;
	}

	// 获取元素的文本与属性

	TiXmlElement* xml_NoteList = xml_root->FirstChildElement("NoteList");
	if(xml_NoteList)
	{
		TiXmlElement* xml_Note = xml_NoteList->FirstChildElement("Note");
		while(xml_Note)
		{
			// 取得子元素的文本
			int id = AfTinyXml::childAsInt(xml_Note, "id");
			string when = AfTinyXml::childAsText(xml_Note, "when");
			string who = AfTinyXml::childAsText(xml_Note, "who");			
			string what = AfTinyXml::childAsText(xml_Note, "what");
			
			// 保存到列表
			Note r;
			r.id = id;
			strcpy(r.when, when.c_str());
			strcpy(r.who, who.c_str());
			strcpy(r.what, what.c_str());
			notes.push_back(r);

			// 下一个兄弟元素
			xml_Note = xml_Note->NextSiblingElement("Note");
		}
	}


	return 0;
}

