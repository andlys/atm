#pragma once
#include <string>
#include "lib/fmt/time.h"

using namespace std;

class Action {
private:
    const std::time_t _datetime;
    const string _content;
	virtual const string do_toString() const {
		return _content;
	}
public:
    // present since our derived classes use base constuctor of no args
	Action():
        _datetime(time(nullptr)) {}
    Action(const string& content):
        _datetime(time(nullptr)), _content(content) {}
    virtual ~Action() {};

    // It seems better to return string, not string&
	const string toString() const {
		return do_toString();
	}

    const std::time_t& datetime() const {
        return _datetime;
    }

    const string datetimeString() const {
        return fmt::format("{:%Y-%m-%d %H:%M:%S}", *localtime(&_datetime));
    }
};
