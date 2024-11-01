// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <string>
#include "Instagram340.h"
#include <memory>

Instagram340::Instagram340()
{
	// TO DO: implement constructors
}

Instagram340::~Instagram340()
{
	Instagram340::users.clear();
}

Instagram340::Instagram340(const Instagram340 &aInsta)
		: users(aInsta.users)
{
}

Instagram340 &Instagram340::operator=(const Instagram340 &aInsta)
{
	if (this != &aInsta)
	{
		users = aInsta.users;
	}
	return *this;
}

void Instagram340::createUser(const std::string &username, const std::string &password, const std::string &email,
															const std::string &bio, const std::string &profilePicture)
{
	// TO DO: implement function
	User newU;
	newU.setUsername(username);
	newU.setPassword(password);
	newU.setEmail(email);
	newU.setBio(bio);
	newU.setProfilePic(profilePicture);

	users.add(newU);
}

User Instagram340::getUser(const int &indexK)
{
	// TO DO: implement function

	// Get node to find index
	std::shared_ptr<Node<User>> usrNode = users.findKthItem(indexK);
	if (usrNode != nullptr)
	{
		return usrNode->getItem();
	}
	else
	{
		return User();
	}
}

std::ostream &operator<<(std::ostream &out, const Instagram340 &insta)
{
	out << "\n\n=======================" << "\n";
	out << "Welcome to Instagram340" << "\n";
	out << "=======================" << "\n";

	return out;
}

bool Instagram340::loginUser(const std::string &username, const std::string &password, User &currentUser)
{
	for (int i = 0; i < users.getSize(); ++i)
	{
		auto usrNode = users.findKthItem(i);

		if (usrNode != nullptr)
		{
			User tempUser = usrNode->getItem();
			if (tempUser.getUsername() == username && tempUser.getPassword() == password)
			{
				currentUser = tempUser;
				return true;
			}
		}
	}
	return false;
}