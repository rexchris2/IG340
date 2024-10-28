// TO DO: #include all the standard libraries and your own libraries here
#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>
#include "LinkedBagDS/LinkedBag.h"
#include "Post.h"

// To DO: define the class User with the necessary functions and data fields
class User : public LinkedBag<Post>
{
private:
  LinkedBag<Post> posts;
  std::string username;
  std::string password;
  std::string email;
  std::string bio;
  std::string profilePic;

public:
  User();
  User(const std::string &username, const std::string &password, const std::string &email, const std::string bio, const std::string &profilePic);

  void setUsername(const std::string &username);
  void setPassword(const std::string &password);
  void setEmail(const std::string &email);
  void setBio(const std::string &bio);
  void setProfilePic(const std::string &profilePic);

  std::string getUsername();
  std::string getPassword();
  std::string getEmail();
  std::string getBio();
  std::string getProfilePic();

  void displayProfile();
  void addPost(const Post &newPost);
  void displayAllPost() const;
  void modifyPost(int k, const std::string &newTitle);
  void deletePost(int k);
  void editPost(int k);
  void getKthPost(int k);

  // This is a function that allows you to compare two users based on their username and email address.
  // You may directly include it in your class definition.
  // You don't need to modify it but will have to put it inside your class.
  // Operator == overloading function prototype:

  bool operator==(const User &otherUser) const;

  friend std::ostream &operator<<(std::ostream &out, const User &user);
  //friend std::istream &operator<<(std::istream &in, const User &user);
};

#endif