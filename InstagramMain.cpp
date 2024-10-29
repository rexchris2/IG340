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
		cout << "\n Hi, " << user.getUsername() << ", what would you like to do:\n"
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

			std::cin >> newPost;
			user.addPost(newPost);

			// if (postType == "Reel")
			// {
			// 	if (videoLength > 90)
			// 	{
			// 		std::cout << "Reel Exceeds 90 seconds!" << std::endl;
			// 	}
			// 	else
			// 	{
			// 		Reel newReel(postType, postName, urlName, videoLength);
			// 		user.addPost(newReel);
			// 	}
			// }
			// else if (postType == "Story")
			// {
			// 	if (videoLength > 60)
			// 	{
			// 		std::cout << "Story Exceeds 60 seconds!" << std::endl;
			// 	}
			// 	else
			// 	{
			// 		Story newStory(postType, postName, urlName, videoLength);
			// 		user.addPost(newStory);
			// 	}
			// }
			// else
			// {
			// 	std::cout << "Invalid choice" << std::endl;
			// }

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
			cout << "Logging you out." << endl;
			break;
		}
		default:
			cout << "Invalid choice. Please try again." << std::endl;
		}

	} while (userChoice != 0);
}

int main()
{
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one user
	User newUser;
	Instagram340 instagram;
	std::string username, password, email, bio, profilePic;

	std::cout << instagram;
	std::cin >> newUser;

	 instagram.createUser(newUser.getUsername(), newUser.getPassword(), newUser.getEmail(), newUser.getBio(),newUser.getProfilePic());

	User currentUser = instagram.getUser(0);

	displayUserManu(currentUser);

	return 0;
}