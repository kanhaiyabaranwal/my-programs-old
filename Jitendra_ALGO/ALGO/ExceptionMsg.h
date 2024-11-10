#include <string>

class ExpectionMsg {
private:
	std::string _msg;
public:
	ExpectionMsg(const std::string& msg) : _msg(msg) {};
	ExpectionMsg() : _msg("") {}
	const std::string& getMsg() { return _msg; }
};

