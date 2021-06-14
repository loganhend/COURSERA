#pragma once
#include "date.h"
#include <string>
#include <memory>
using namespace std;

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation {
	And,
	Or
};

struct Node {
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

struct EmptyNode : public Node {
	bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node{
public:
	DateComparisonNode(Comparison comparison, const Date& date);
	bool Evaluate(const Date& date, const string& event) const override;
private:
	Comparison comparison_;
	Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(Comparison comparison, const string& val);
	bool Evaluate(const Date& date, const string& event) const override;
private:
	Comparison comparison_;
	string val_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(LogicalOperation op, shared_ptr<Node> lhr, shared_ptr<Node> rhr);
	bool Evaluate(const Date& date, const string& event) const override;
private:
	LogicalOperation op_;
	shared_ptr<Node> lhr_, rhr_;
};


