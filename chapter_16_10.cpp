#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstdlib>

using namespace std;

struct Review
{
	string title;
	int rating;
	double price;
};

bool operator<(const shared_ptr < Review> &r1, const shared_ptr<Review> &r2);
bool worseThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool betterThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool worseThanP(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool betterThanP(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool FillReview(shared_ptr<Review> &rr);
shared_ptr<Review> make_Review();
void ShowReview(shared_ptr<Review> &rr);

int main()
{
	vector<shared_ptr<Review>> books;
	shared_ptr<Review> temp(new Review);
	while (FillReview(temp))
	{
		books.push_back(temp);
		temp = make_Review();
	}

	if (books.size() > 0)
	{
		vector<shared_ptr<Review>> sbook(books);
		cout << "Thank you. You entered the following:\n" << books.size() << " ratings:\n" << "Rating\tBook\tPrice\n";
		for_each(books.begin(), books.end(), ShowReview);
		char ch;
		cout << "Enter measures of sort:\no to old ";
		cout << "t to title,r to down rating,\nR to up rating" << " p to down price ,P to up price,f(F) to shuffle,\nq to quit: ";
		cin >> ch;
		while (tolower(ch) != 'q')
		{
			switch (ch)
			{
			case 'o':
				cout << "Not Sort:\nRating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case 't':
				sort(sbook.begin(), sbook.end());
				cout << "Sorted by title:\nRating\tBook\tPrice\n";
				for_each(sbook.begin(), sbook.end(), ShowReview);
				break;
			case 'r':
				sort(sbook.begin(), sbook.end(), worseThan);
				cout << "Sorted by down rating:\nRating\tBook\tPrice\n";
				for_each(sbook.begin(), sbook.end(), ShowReview);
				break;
			case 'R':
				sort(sbook.begin(), sbook.end(), betterThan);
				cout << "Sorted by up rating:\nRating\tBook\tPrice\n";
				for_each(sbook.begin(), sbook.end(), ShowReview);
				break;
			case 'p':
				sort(sbook.begin(), sbook.end(), worseThanP);
				cout << "Sorted by down price:\nRating\tBook\tPrice\n";
				for_each(sbook.begin(), sbook.end(), ShowReview);
				break;
			case 'P':
				sort(sbook.begin(), sbook.end(), betterThanP);
				cout << "Sorted by up price:\nRating\tBook\tPrice\n";
				for_each(sbook.begin(), sbook.end(), ShowReview);
				break;
			case 'F':
			case 'f':
				random_shuffle(sbook.begin(), sbook.end());
				cout << "After shuffling:\nRating\tBook\n";
				for_each(sbook.begin(), sbook.end(), ShowReview);
				break;
			default:
				cout << "Error input! Input again!";
				break;
			}
			cout << "Enter the next measures:\no to old";
			cout << " t to title,r to down rating,\nR to up rating " << "p to down price,P to up price,q to quit: ";
			cin >> ch;
		}
	}
	else
		cout << "No entries.";
	cout << "Bye.\n";

	return 0;
}

bool operator<(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title&&r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool worseThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool betterThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	if (r1->rating > r2->rating)
		return true;
	else
		return false;
}

bool worseThanP(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}

bool betterThanP(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	if (r1->price > r2->price)
		return true;
	else
		return false;
}

shared_ptr<Review> make_Review()
{
	return shared_ptr<Review>(new Review);
}

bool FillReview(shared_ptr<Review> &rr)
{
	cout << "Enter book title (enter quit to quit): ";
	getline(cin, rr->title);
	if (rr->title == "quit")
		return false;
	cout << "Enter book rating: ";
	cin >> rr->rating;
	cout << "Enter book price: ";
	cin >> rr->price;
	if (!cin)
		return false;
	while (cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(shared_ptr<Review> &rr)
{
	cout << rr->rating << "\t" << rr->title << "\t" << rr->price << endl;
}