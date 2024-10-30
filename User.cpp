// TO DO: #include needed standard libraries and your own libraries here
#include "User.h"

// TO DO: function implementations

User::User()
{
}

void User::setUsername(const std::string &newUName)
{
	username = newUName;
}

std::string User::getUsername()
{
	return username;
}

void User::setPassword(const std::string &newPw)
{
	password = newPw;
}
std::string User::getPassword()
{
	return password;
}

void User::setEmail(const std::string &newEmail)
{
	email = newEmail;
}

std::string User::getEmail()
{
	return email;
}

void User::setBio(const std::string &newBio)
{
	bio = newBio;
}

std::string User::getBio()
{
	return bio;
}

void User::setProfilePic(const std::string &newPfp)
{
	profilePic = newPfp;
}

std::string User::getProfilePic()
{
	return profilePic;
}
void User::displayProfile()
{
	// User Info
	std::cout << "===== User Profile =====" << std::endl;
	std::cout << "Username: " << getUsername() << std::endl;
	std::cout << "Email: " << getEmail() << std::endl;
	std::cout << "Bio: " << getBio() << std::endl;
	std::cout << "profilePic: " << getProfilePic() << std::endl;
	std::cout << "========================" << std::endl;
	// Password change test
	// std::cout << "password: " << getPassword() << std::endl;
}

void User::addPost(const Post &newPost)
{

	posts.add(newPost); // add Post
}

// Display all post(reuse from class)
void User::displayAllPost() const
{
	std::cout << "The user has " << posts.getCurrentSize() << " posts:" << std::endl;

	std::vector<Post> postItems = posts.toVector();

	int numberOfEntries = static_cast<int>(postItems.size());
	for (int i = 0; i < numberOfEntries; i++)
	{
		std::cout << "===== User Post =====" << std::endl;
		std::cout << "Index: " << i + 1 << std::endl;
		std::cout << postItems[i];
		std::cout << "========================" << std::endl;
	}
}

void User::getKthPost(int k)
{
	std::shared_ptr<Node<Post>> post = posts.findKthItem(k);

	if (post != nullptr)
	{
		post->getItem().displayPost(); // get the item and then display it
	}
	else
	{
		std::cout << "No Post found!" << std::endl;
	}
}

void User::modifyPost(int k, const std::string &newTitle)
{
	std::shared_ptr<Node<Post>> postN = posts.findKthItem(k - 1);
	int size = posts.getCurrentSize();

	// have a check parameters
	if (k < 0 || k >= size)
	{
		std::cout << "Invalid Index Choice!" << std::endl;
		return;
	}
	if (postN != nullptr)
	{

		// Get item
		Post postItem = postN->getItem();

		// Modify the item
		postItem.setTitle(newTitle);

		// Then set it/change title
		postN->setItem(postItem);
	}
}

void User::deletePost(int k)
{
	std::shared_ptr<Node<Post>> curr = posts.findKthItem(k);
	std::shared_ptr<Node<Post>> prev = posts.findKthItem(k - 1);

	// have check parameters
	int size = posts.getCurrentSize();
	if (k < 0 || k >= size)
	{
		std::cout << "Invalid Index Choice!" << std::endl;
		return;
	}
	if (prev != nullptr)
	{
		prev->setNext(curr->getNext());
	}
	posts.decrementItemCount();
	std::cout << "Post Deleted Successfully!" << std::endl;
}

void User::editPost(int k)
{
	std::shared_ptr<Node<Post>> edit = posts.findKthItem(k);

	if (edit != nullptr)
	{
		Post editItem = edit->getItem();					 // Get the item
		std::string type = editItem.getPostType(); // Get the Post Type

		// Post edit outcomes for reel and story
		if (type == "Reel")
		{
			std::cout << "Filter, Ar Effects and music has been added!" << std::endl;
		}
		else if (type == "Story")
		{
			std::cout << "Filter,Music,Stickers and effects have been added!" << std::endl;
		}
		else
		{
			std::cout << "Error!" << std::endl;
		}
	}
	else
	{
		std::cout << "No post found!" << std::endl;
	}
}

// Operator == overloading implementation
bool User::operator==(const User &otherUser) const
{
	return (User::username == otherUser.username) && (User::email == otherUser.email);
}

std::ostream &operator<<(std::ostream &out, const User &user)
{
	out << "===== User Profile =====\n";
	out << "Username: " << user.username << "\n";
	out << "Email: " << user.email << "\n";
	out << "Bio: " << user.bio << "\n";
	out << "Profile Picture: " << user.profilePic << "\n";
	out << "========================\n";
	return out;
}

std::istream& operator>>(std::istream& in, User& user){
	std::cout << "Enter your username: ";
    getline(in, user.username);

    std::cout << "Enter your password: ";
    getline(in, user.password);

    std::cout << "Enter your email: ";
    getline(in, user.email);

    std::cout << "Enter your bio: ";
    getline(in, user.bio);

    std::cout << "Enter the path to your profile picture: ";
    getline(in, user.profilePic);

    return in;
}