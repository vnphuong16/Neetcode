#include <string>
using namespace std;

class Singleton {
private:
	Singleton() {}
	string strValue;

public:
	static Singleton *getInstance() {
		static Singleton instance;
		return &instance;
	}

	string getValue() {
		return strValue;
	}

	void setValue(string &value) {
		strValue = value;
	}
};