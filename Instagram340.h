#ifndef INSTAGRAM340_H
#define INSTAGRAM340_H

#include "LinkedBagDS/LinkedBag.h"
#include "User.h"
#include <string>
// TO DO include necessary libraries

// This class only contains a list of users
// It should allow clients to add users and retrieve a user from the list
class Instagram340
{
private:
	LinkedBag<User> users;

public:
	Instagram340();

	// Big 3!!
	virtual ~Instagram340();
	Instagram340(const Instagram340 &aInsta);
	Instagram340 &operator=(const Instagram340 &aInsta);

	void createUser(const std::string &username, const std::string &password, const std::string &email,
									const std::string &bio, const std::string &profilePicture);

	bool loginUser(const std::string &username, const std::string &password, User &currentUser);

	User getUser(const int &indexK);

	friend std::ostream &operator<<(std::ostream &out, const Instagram340 &insta);
};
#endif