// TO DO: #include all the standard libraries and your own libraries here
#include <chrono>
#include <iostream>
#include "Post.h"
#include <ctime>

// TO DO: function implementations

Post::Post() : postType(""), title(""), mediaUrl(""), videoLength(0)
{
	// When creating a post, you may use this code to set time stamp
	auto time_stamp = std::chrono::steady_clock::now();
}

Post::Post(const std::string &postType, const std::string &title, const std::string &mediaUrl, int videoLength)
		: postType(postType), title(title), mediaUrl(mediaUrl), videoLength(videoLength)
{
	auto time_stamp = std::chrono::steady_clock::now();
}

Post::~Post()
{
}

Post::Post(const Post &aPost)
		: postType(aPost.postType), title(aPost.title), mediaUrl(aPost.mediaUrl),
			videoLength(aPost.videoLength), numLikes(aPost.numLikes),
			time_stamp(aPost.time_stamp)
{
}

Post &Post::operator=(const Post &aPost)
{
	if (this != &aPost)
	{
		postType = aPost.postType;
		title = aPost.title;
		mediaUrl = aPost.mediaUrl;
		videoLength = aPost.videoLength;
		numLikes = aPost.numLikes;
		time_stamp = aPost.time_stamp;
	}
	return *this;
}
void Post::setPostType(const std::string &newPostType)
{
	postType = newPostType;
}
std::string Post::getPostType() const
{
	return postType;
}
void Post::setTitle(const std::string &newTitle)
{
	title = newTitle;
}

std::string Post::getTitle() const
{
	return title;
}

void Post::setMediaUrl(const std::string &newMediaUrl)
{
	mediaUrl = newMediaUrl;
}

std::string Post::getMediaUrl() const
{
	return mediaUrl;
}

void Post::setVideoLength(const int &newVideoLength)
{
	videoLength = newVideoLength;
}

int Post::getVideoLength() const
{
	return videoLength;
}

void Post::displayPost() const
{
	time_t time_stamp; // time stamp when post gets created
	time(&time_stamp);

	std::cout << "Post Type: " << getPostType() << std::endl;
	std::cout << "Title: " << getTitle() << std::endl;
	std::cout << "Media Url: http://" << getMediaUrl() << std::endl;
	std::cout << "Video Length: " << getVideoLength() << " seconds" << std::endl;
	std::cout << "Time Posted: " << ctime(&time_stamp) << std::endl;
}

// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Post::operator==(const Post &otherPost) const
{
	return Post::title == otherPost.title;
}

// When displaying a story, use this to compute expected expiration time: timeToExpiration
// Define this as a private function
int Post::computeTimeToExpiration() const
{
	const int secondsInHour = 3600;
	// 24 hours in seconds
	const int expiresAfter = 24 * secondsInHour;

	// Get current time
	auto time_now = std::chrono::steady_clock::now();
	// Compute elapsed time since post creation
	std::chrono::duration<double> elapsed_seconds = time_now - Post::time_stamp;
	// time to expiration in hours
	int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;

	return timeToExpiration;
}

// Reel inherit from post
Reel::Reel(const std::string &postType, const std::string &title, const std::string &mediaUrl, int videoLength) : Post(postType, title, mediaUrl, videoLength)
{
}
// Destructor
Reel::~Reel()
{
}
Reel::Reel(const Reel &aReel)
		: Post(aReel)
{
}
Reel &Reel::operator=(const Reel &aReel)
{
	if (this != &aReel)
	{
		Post::operator=(aReel);
	}
	return *this;
}

// Story inherit from post
Story::Story(const std::string &postType, const std::string &title, const std::string &mediaUrl, int videoLength) : Post(postType, title, mediaUrl, videoLength)
{
}
// Destruc
Story::~Story()
{
}

Story::Story(const Story &aStory)
		: Post(aStory)
{
}

Story &Story::operator=(const Story &aStory)
{
	if (this != &aStory)
	{
		Post::operator=(aStory);
	}
	return *this;
}
void Story::displayPost() const
{
	Post::displayPost(); // Get the default one to have the featurs
	int timeExpire = computeTimeToExpiration();

	if (timeExpire > 0)
	{
		std::cout << "Time left: " << timeExpire << "Hours" << std::endl;
	}
	else
	{
		std::cout << "Story has Expired!" << std::endl;
	}
}

std::istream &operator>>(std::istream &in, Post &post)
{
	std::string postType, title, mediaUrl;
	int videoLength;

	// std::cout << "Enter Post Type: ";
	// in >> postType;
	// post.setPostType(postType);

	std::cout << "Enter Title: ";
	in.ignore();
	std::getline(in, title);
	post.setTitle(title);

	std::cout << "Enter Media URL: ";
	std::getline(in, mediaUrl);
	post.setMediaUrl(mediaUrl);

	std::cout << "Enter Video Length (seconds): ";
	in >> videoLength;
	post.setVideoLength(videoLength);

	return in;
}

std::ostream &operator<<(std::ostream &out, const Post &post)
{
	time_t time_stamp; // time stamp when post gets created
	time(&time_stamp);

	out << "OverLoad PostFunc\n";
	out << "Post Type: " << post.postType << "\n";
	out << "Title: " << post.title << "\n";
	out << "Media Url: http://" << post.mediaUrl << "\n";
	out << "Video Length: " << post.videoLength << " seconds" << "\n";
	out << "Time Posted: " << ctime(&time_stamp) << "\n";

	return out;
}