#include "node.h"

template<typename T>
bool Compare(Comparison op, const T& lhr, const T& rhr) {
	switch(op) {
	case Comparison::Less:
		return lhr < rhr;
	case Comparison::LessOrEqual:
		return lhr <= rhr;
	case Comparison::Greater:
		return lhr > rhr;
	case Comparison::GreaterOrEqual:
		return lhr >= rhr;
	case Comparison::Equal:
		return lhr == rhr;
	case Comparison::NotEqual:
		return lhr != rhr;
	}
	return false;
}

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

DateComparisonNode::DateComparisonNode(Comparison comparison, const Date& date):
		comparison_(comparison),date_(date) {}

EventComparisonNode::EventComparisonNode(Comparison comparison, const string& val):
		comparison_(comparison),val_(val) {}

LogicalOperationNode::LogicalOperationNode(LogicalOperation op, shared_ptr<Node> lhr, shared_ptr<Node> rhr):
		op_(op),lhr_(lhr),rhr_(rhr) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	return Compare(comparison_,date,date_);
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	return Compare(comparison_,event,val_);
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	switch(op_) {
	case LogicalOperation::And:
		return lhr_->Evaluate(date,event) && rhr_->Evaluate(date,event);
	case LogicalOperation::Or:
		return lhr_->Evaluate(date,event) || rhr_->Evaluate(date,event);
	}
	return false;
}





