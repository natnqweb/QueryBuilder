#pragma once
#include <string>
#ifdef QUERYBUILDER_API
#define QUERY_BUILDER_API __declspec(dllexport)
#else
#define QUERY_BUILDER_API __declspec(dllimport)
#endif

class QUERY_BUILDER_API QueryBuilder
{
	std::string strQuery{};
public:
    QueryBuilder();
    ~QueryBuilder();

	QueryBuilder& Select(std::string str);
	QueryBuilder& From(std::string str);
	QueryBuilder& GroupBy(std::string str);
	QueryBuilder& Into(std::string str);
	QueryBuilder& SelectFrom(std::string strSelect,std::string strFrom);
	QueryBuilder& Having(std::string str);
	QueryBuilder& Union(std::string str);
	QueryBuilder& InnerJoin(std::string str);
	QueryBuilder& Join(std::string str);
	QueryBuilder& For(std::string str);
	QueryBuilder& Where(std::string str);
	QueryBuilder& Distinct(std::string str);
	QueryBuilder& OrderBy(std::string str);
	QueryBuilder& Top(std::string str);
	QueryBuilder& As(std::string str);
	QueryBuilder& IsNotNull(std::string str);
	QueryBuilder& Sum(std::string str);
	QueryBuilder& Count(std::string str);
	QueryBuilder& SelectAs(std::string strSelect,std::string strAs);
    QueryBuilder& WhereInSubquery(std::string strWhere, QueryBuilder& SubQuery);
    QueryBuilder& Or(std::string str);
    QueryBuilder& And(std::string str);
    QueryBuilder& End();
    void ClearQuery();




	QueryBuilder& operator()(std::string str);
    QueryBuilder& operator()(QueryBuilder& qry);
    void operator+=(QueryBuilder& qry);
    void operator+=(std::string str);
    QueryBuilder& operator[](std::string str);
    QueryBuilder& operator[](QueryBuilder& qry);
	std::string& GetQuery();
	


};
QueryBuilder::QueryBuilder() {}
QueryBuilder::~QueryBuilder(){}
QueryBuilder& QueryBuilder::End()
{
    strQuery += ";";
    return *this;
}
QueryBuilder& QueryBuilder::operator()(QueryBuilder& qry)
{
    strQuery = strQuery + " (" + qry.GetQuery() + ") ";
    return *this;
}
void QueryBuilder::operator+=(QueryBuilder& qry)
{
    strQuery += qry.GetQuery();
}
void QueryBuilder::operator+=(std::string str)
{
    strQuery += str;
}
QueryBuilder& QueryBuilder::operator[](QueryBuilder& qry)
{
    strQuery = strQuery + " [" + qry.GetQuery() + "] ";
    return *this;
}
QueryBuilder& QueryBuilder::Select(std::string str)
{
    static auto bFirstSelect = true;
    if (bFirstSelect)
        strQuery = strQuery + "SELECT " + str;
    else
        strQuery = strQuery + " SELECT " + str;
    bFirstSelect = false;
    return *this;
}
void QueryBuilder::ClearQuery()
{
    strQuery.clear();
}
QueryBuilder& QueryBuilder::And(std::string str)
{
    strQuery += " AND ";
    strQuery += str;
    return *this;
}
QueryBuilder& QueryBuilder::Or(std::string str)
{
    strQuery += " OR ";
    strQuery += str;
    return *this;
}
QueryBuilder& QueryBuilder::From(std::string str)
{
    strQuery += " FROM ";
    strQuery += str;
    return *this;
}
QueryBuilder& QueryBuilder::WhereInSubquery(std::string strWhere, QueryBuilder& SubQuery)
{
    strQuery += " WHERE ";
    strQuery += strWhere;
    strQuery += " IN ";
    strQuery += "(";
    strQuery += SubQuery.GetQuery();
    strQuery += ") ";
    return *this;
}

QueryBuilder& QueryBuilder::GroupBy(std::string str)
{
    strQuery += " GROUP BY ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::Into(std::string str)
{
    strQuery += " INTO ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::SelectFrom(std::string strSelect, std::string strFrom)
{
    strQuery = strQuery + "SELECT " + strSelect + " FROM " + strFrom;

    return *this;
}

QueryBuilder& QueryBuilder::Having(std::string str)
{
    strQuery += " HAVING ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::Union(std::string str)
{
    strQuery += " UNION ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::InnerJoin(std::string str)
{
    strQuery += " INNER JOIN ";
    strQuery += str;
    return *this;
}
QueryBuilder& QueryBuilder::Join(std::string str)
{
    strQuery += " JOIN ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::For(std::string str)
{
    strQuery += " FOR ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::Where(std::string str)
{
    strQuery += " WHERE ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::Distinct(std::string str)
{
    strQuery += " DISTINCT ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::OrderBy(std::string str)
{
    strQuery += " ORDER BY ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::Top(std::string str)
{
    strQuery = strQuery + " TOP(" + str + ") ";

    return *this;
}

QueryBuilder& QueryBuilder::As(std::string str)
{

    strQuery += " AS ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::IsNotNull(std::string str)
{
    strQuery += " IS NOT NULL ";
    strQuery += str;
    return *this;
}

QueryBuilder& QueryBuilder::Sum(std::string str)
{
    strQuery = strQuery + " SUM(" + str + ") ";
    return *this;
}

QueryBuilder& QueryBuilder::Count(std::string str)
{
    strQuery = strQuery + " COUNT(" + str + ") ";
    return *this;
}

QueryBuilder& QueryBuilder::SelectAs(std::string strSelect, std::string strAs)
{
    strQuery = strQuery + " SELECT " + strSelect + " AS " + strAs;
    return *this;
}

QueryBuilder& QueryBuilder::operator()(std::string str)
{
    strQuery = strQuery + " (" + str + ") ";
    return *this;
}

QueryBuilder& QueryBuilder::operator[](std::string str)
{
    strQuery = strQuery + " [" + str + "] ";

    return *this;
}

std::string& QueryBuilder::GetQuery()
{
    return strQuery;
}

