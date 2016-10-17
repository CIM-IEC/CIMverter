#ifndef CIMPARSER_H
#define CIMPARSER_H

#include <libxml++/libxml++.h>
#include <glibmm/ustring.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>

#include "BaseClass.h"
#include "task.h"

class CIMParser : public xmlpp::SaxParser
{
public:
	CIMParser();
	~CIMParser();

	std::vector<BaseClass*> Objects;

protected:
	void on_end_document() override;
	void on_start_element(const Glib::ustring& name, const AttributeList& properties) override;
	void on_end_element(const Glib::ustring& name) override;
	void on_characters(const Glib::ustring& characters) override;

	static Glib::ustring get_rdf_id(const AttributeList &properties);
	static Glib::ustring get_rdf_resource(const AttributeList &properties);
	static std::string get_rdf_enum(const AttributeList &properties);
	static bool is_only_whitespace(const Glib::ustring &characters);
	static Glib::ustring replace_whitespace(const Glib::ustring &characters);

private:
	std::stack<BaseClass*> elementStack;
	std::stack<Glib::ustring> tagStack;
	std::queue<Task> taskQueue;
};



#endif // CIMPARSER_H
