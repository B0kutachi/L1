#pragma once
#include <iostream>
#include <string>

using namespace std;

//////////////////////// Post - пост в блоге пользователя с платным аккаунтом
class Post
{
	string _title;
	string _text;
public:
	void SetTitle(string title);
	void SetText(string text);
	string GetTitle();
	string GetText();
	Post(string title, string text);
};

//////////////////////// User - обычный пользователь
class User
{
	int _id;
	string _login;
	string _password;
protected:
	void SetId(int id);
public:
	void SetLogin(string login);
	void SetPassword(string password);
	int GetId();
	string GetLogin();
	string GetPassword();
	User(int id, string login, string password);
	bool IsCorrectPassword(string password);
};


//////////////////////// Paid User - пользователь с платным аккаунтом
class PaidUser : public User
{
	Post* _posts;
	int _postsCount;
public:
	void SetPosts(Post* posts, int postsCount);
	Post* GetPosts();
	int GetPostsCount();
	PaidUser(int id, string login, string password, Post* posts, int postsCount);
	PaidUser(int id, string login, string password);

};