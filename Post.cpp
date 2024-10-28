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
:postType(postType), title(title), mediaUrl(mediaUrl), videoLength(videoLength)
{
	auto time_stamp = std::chrono::steady_clock::now();
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
	time_t time_stamp; //time stamp when post gets created
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


// Story inherit from post
Story::Story(const std::string &postType, const std::string &title, const std::string &mediaUrl, int videoLength) : Post(postType, title, mediaUrl, videoLength)
{
	

}
void Story::displayPost() const {
	Post::displayPost(); //Get the default one to have the featurs
	int timeExpire = computeTimeToExpiration();

	if(timeExpire > 0){
		std::cout << "Time left: " << timeExpire  << "Hours" << std::endl;
	}else{
		std::cout << "Story has Expired!" << std::endl;
	}
}

