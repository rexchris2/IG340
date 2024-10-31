// TO DO: #include all the standard libraries and your own libraries here
#ifndef POST_H_
#define POST_H_

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
// To DO: define the class Post with the necessary functions' prototypes and data fields

class Post
{
private:
  // This is a helper function -- it should be private.
  std::chrono::steady_clock::time_point time_stamp;
  std::string postType;
  std::string title;
  std::string mediaUrl;
  int videoLength;
  int numLikes;

public:
  Post();
  Post(const std::string &postType, const std::string &title, const std::string &mediaUrl, int videoLength);
 //BIG 3!!!
  ~Post();
  Post(const Post &other);
  Post &operator=(const Post &other);

  void setPostType(const std::string &postType);
  void setTitle(const std::string &title);
  void setMediaUrl(const std::string &setMediaUrl);
  void setVideoLength(const int &videoLength);

  std::string getPostType() const;
  std::string getTitle() const;
  std::string getMediaUrl() const;
  int getVideoLength() const;

  virtual void displayPost() const;
  void editPost();
  // This is a function that allows you to compare two posts based on their title.
  // You may directly include it in your class definition.
  // You don't need to modify it but will have to put it inside your class.
  // Operator overloading function prototype:
  bool operator==(const Post &otherPost) const;

  int computeTimeToExpiration() const;

  friend std::istream &operator>>(std::istream &in, Post &post);

  friend std::ostream &operator<<(std::ostream &out, const Post &post);
};

// Reel is subclass of Post
class Reel : public Post
{
private:
public:
  Reel(const std::string &postType, const std::string &title, const std::string &mediaUrl, int videoLength);
};

// Story is subclass of Post
class Story : public Post
{
private:
public:
  Story(const std::string &postType, const std::string &title, const std::string &mediaUrl, int videoLength);

  void displayPost() const override;
};

#endif
