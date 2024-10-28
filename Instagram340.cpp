// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <string>
#include "Instagram340.h"
#include <memory>

Instagram340::Instagram340()
{
	// TO DO: implement constructor
}

Instagram340::~Instagram340()
{
	Instagram340::users.clear();
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

		//Get node to find index
	  std::shared_ptr<Node<User>> usrNode = users.findKthItem(indexK);
    if (usrNode != nullptr) {
        return usrNode->getItem();
    } else {
			return User();
		}
		
}

std::ostream &operator<<(std::ostream& out, const Instagram340& insta){
	out << "Welcome to Instagram340!!!!!";
	return out;
}

