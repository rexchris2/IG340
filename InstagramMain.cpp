#include <iostream>
#include <string>

// TO DO: #include any other libraries you need
#include "Instagram340.h"
#include "User.h"
#include "Post.h"
#include "LinkedBagDS/LinkedBag.h"

using namespace std;

/**
 *
 * Displays the application's main menu
 * pre create a new object of type User
 * @param user object to interact with
 *
 * */
void displayUserManu(User &user)
{
	int userChoice = 0;
	do
	{
		std::cout << "\n==============================================================" << std::endl;
		std::cout << "|                       Instagram340                         |" << std::endl;
		std::cout << "==============================================================" << std::endl;
		cout << "\nHi, " << user.getUsername() << ", what would you like to do:\n"
				 << "1. Display Profile\n"
				 << "2. Modify Password\n"
				 << "3. Create Post\n"
				 << "4. Display All Posts\n"
				 << "5. Display Kth Post\n"
				 << "6. Modify Post\n"
				 << "7. Delete Post\n"
				 << "8. Edit Post\n"
				 << "0. Logout\n"
				 << "Choice: ";
		cin >> userChoice;
		std::cout << "\n\n\n";

		switch (userChoice)
		{
		case 1:
		{
			// TO DO: display user's profile information
			//      : e.g. user.displayProfile();
			// user.displayProfile();
			std::cout << user;
			// std::cout << insta;
			break;
		}
		case 2:
		{
			// TO DO: ask for new password and update user's password
			std::string newPass;
			std::cout << "Enter your new password!: ";
			std::cin >> newPass;
			user.setPassword(newPass);
			std::cout << "Password Changed Successfully";
			break;
		}
		case 3:
		{

			// TO DO: ask user to choose between Reel and Story, ask them to input post details:
			//        (title, media URL, video length in seconds)
			//        Your program should set the time stamp to current time (code provided in Post.cpp)
			// then create the post and add it to the user's posts

			Post newPost;
			std::string postType;

			std::cout << "Enter Post Type (Reel or Story):";
			std::cin >> postType;
			std::cin.ignore();
			std::cin >> newPost;

			if (postType == "Reel")
			{
				if (newPost.getVideoLength() > 90)
				{
					std::cout << "Reel exceeds 90 seconds!" << std::endl;
				}
				else
				{
					Reel newReel("Reel", newPost.getTitle(), newPost.getMediaUrl(), newPost.getVideoLength());
					user.addPost(newReel);
					std::cout << "Reel added successfully!" << std::endl;
				}
			}
			else if (postType == "Story")
			{
				if (newPost.getVideoLength() > 60)
				{
					std::cout << "Story exceeds 60 seconds!" << std::endl;
				}
				else
				{
					Story newStory("Story", newPost.getTitle(), newPost.getMediaUrl(), newPost.getVideoLength());
					user.addPost(newStory);
					std::cout << "Story added successfully!" << std::endl;
				}
			}
			else
			{
				std::cout << "Invalid post type. Please enter either 'Reel' or 'Story'." << std::endl;
			}
			break;
		}
		case 4:
		{
			// TO DO: display all user's posts
			//        You may re-use code from class demo
			// Post newPost;
			// std::cout << newPost;
			user.displayAllPost();
			break;
		}
		case 5:
		{
			// TO DO: ask the user for a value k
			// Find the Kth post, if k > Linked Bag size,
			//    return an error message that includes the size of the Linked Bag

			int k;
			std::cout << "Enter the index of the post to display.\n";
			std::cin >> k;

			user.getKthPost(k - 1);

			break;
		}
		case 6:
		{
			// TO DO: ask the user for the index of the post they want to modify and the new title
			// Find the post, then update the title.
			// If index > Linked Bag size,
			//    return an error message that includes the size of the Linked Bag
			int k;
			std::string postRename;

			std::cout << "Index of the post that needs to be modified\n";
			std::cin >> k;

			std::cout << "What would you like to rename the post?\n";
			std::cin >> postRename;
			// Find post and modify
			user.modifyPost(k, postRename);

			std::cout << "Post updated!" << std::endl;

			break;
		}
		case 7:
		{
			// TO DO: ask the user for the index of the post they want to delete
			// Find the post, then remove it from the list.
			// If index > LinkedBag size,
			//    return an error message that includes the size of the Linked Bag
			int k;
			std::cout << "Enter Post Index to delete: ";
			std::cin >> k;

			user.deletePost(k - 1);

			break;
		}
		case 8:
		{
			// TO DO edit the post
			int k;
			std::cout << "Enter Post Index to edit: ";
			std::cin >> k;

			user.editPost(k - 1);

			break;
		}
		case 0:
		{
			std::cout << "========================" << std::endl;
			std::cout << "    Logging you out." << std::endl;
			std::cout << "========================" << std::endl;

			break;
		}
		default:
			cout << "Invalid choice. Please try again." << std::endl;
		}

	} while (userChoice != 0);
	return;
}

int main()
{
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one user

	Instagram340 instagram;
	User newUser;
	int userInput;
	do
	{
		std::cout << instagram;

		std::cout << "1. Create Account\n";
		std::cout << "2. Login\n";
		std::cout << "3. Close App\n";
		std::cout << "Choice: " << std::endl;
		std::cin >> userInput;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (userInput == 1)
		{
			std::cout << "Account Creation!" << std::endl;
			std::cin >> newUser;

			instagram.createUser(newUser.getUsername(), newUser.getPassword(), newUser.getEmail(), newUser.getBio(), newUser.getProfilePic());

			User currentUser = instagram.getUser(0);
			displayUserManu(currentUser);
		}
		else if (userInput == 2)
		{
			std::string username, password;
			std::cout << "Enter your username: ";
			std::cin >> username;
			std::cout << "Enter your password: ";
			std::cin >> password;
			User currentUser;

			if (instagram.loginUser(username, password, currentUser))
			{
				std::cout << "Login successful!" << std::endl;
				displayUserManu(currentUser);
			}
			else
			{
				std::cout << "Invalid username or password. Please try again." << std::endl;
			}
		}

		else if (userInput == 3)
		{
			std::cout << "Closing Application" << std::endl;
		}
		else
		{
			std::cout << "Wrong Choice" << std::endl;
		}
	} while (userInput != 3);
	return 0;
}