#include "Users.h"

void Post::SetTitle(string title) {
	this->_title = title;
}
void Post::SetText(string text) {
	this->_text = text;
}
string Post::GetTitle() { return _title; }
string Post::GetText() { return _text; }
Post::Post(string title, string text) {
	SetTitle(title);
	SetText(text);
};

///////////////////////////////////////////////////////////////

void User::SetId(int id) {
	_id = id;
}
void User::SetLogin(string login) {
	// {, }, <, >, @, # , $, %, ^, :, *
	for (int i = 0; i < login.length(); i++) {
		if ((login[i] == 123) || (login[i] == 125) || (login[i] == 58) || (login[i] == 60) || (login[i] == 62) || (login[i] == 64) || (login[i] == 35) || (login[i] == 36) || (login[i] == 37) || (login[i] == 94) || (login[i] == 42)) {
			// числовые значения символов ASCII (число соответствует символу)
			cout << "Login can't contain symbols {, }, <, >, @, # , $, %, ^, :, *\n";
			exit(0);
		}
	}
	_login = login;
}
void User::SetPassword(string password) {
	_password = password;
}
int User::GetId() { return _id; }
string User::GetLogin() { return _login; }
string User::GetPassword() { return _password; }
User::User(int id, string login, string password) {
	SetId(id);
	SetLogin(login);
	SetPassword(password);
}
bool User::IsCorrectPassword(string password) {
	return (password == _password);
}

///////////////////////////////////////////////////////////////

void PaidUser::SetPosts(Post* posts, int postsCount) {
	if (postsCount < 0)
	{
		throw exception("Posts count must be more than 0");
	}
	_posts = posts;
	_postsCount = postsCount;
}

Post* PaidUser::GetPosts() { return _posts; }
int PaidUser::GetPostsCount() { return _postsCount; }

PaidUser::PaidUser(int id, string login, string password, Post* posts, int postsCount) :User(id, login, password) {
	SetPosts(posts, postsCount);
}
PaidUser::PaidUser(int id, string login, string password) :User(id, login, password)
{}
