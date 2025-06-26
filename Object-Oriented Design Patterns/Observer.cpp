#include <vector>
#include <string>
using namespace std;

class Observer {
public:
	virtual void notify(string& itemName) = 0;
};

class Customer : public Observer {
private:
	string name;
	int notifications;

public:
	Customer(string& name) : name(name), notifications(0) {}

	void notify(string& itemName) override {
		notifications += 1;
	}

	int countNotifications() {
		return notifications;
	}
};

class OnlineStoreItem {
private:
	string itemName;
	int stock;
	vector<Observer*> listCustomer;
public:
	OnlineStoreItem(string& itemName, int stock) : itemName(itemName), stock(stock) {}

	void subscribe(Observer* observer) {
		listCustomer.push_back(observer);
	}

	void unsubscribe(Observer* observer) {
		auto it = find(listCustomer.begin(), listCustomer.end(), observer);
		if (it != listCustomer.end()) {
			listCustomer.erase(it);
		}
	}

	void updateStock(int newStock) {
		int currentStock = stock;
		stock = newStock;
		if (currentStock == 0 && newStock > 0) {
			notifyCustomers();
		}
	}
private:
	void notifyCustomers() {
		for (Observer* customer : listCustomer) {
			customer->notify(itemName);
		}
	}
};
