#include "masterVisual.h"
void addGuess(MastermindWindow& mwin, const string code, const int size, const char startLetter, int round)
{
	int c = 0;
	for ( int i = 0; i < size; ++i){
		if (code[i] =='A' ){
			c = 1;
		}
		else if (code[i] =='B' ){
			c = 2;
		}
		else if (code[i] =='C' ){
			c = 3;
		}
		else if (code[i] =='D' ){
			c = 4;
		}
		else if (code[i] =='E' ){
			c = 5;
		}
		else if (code[i] =='F' ){
			c = 6;
		}
		mwin.vr.push_back(new Rectangle{Point{padX + (2*i)*padX,padY + (2*round)*padY},padX,padY});
		mwin.vr[mwin.vr.size()-1].set_fill_color(c);
		mwin.attach(mwin.vr[mwin.vr.size()-1]);
	}
}
void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter, const int size,
				 const int round)
{	for(int i = 0; i < correctCharacter; ++i) {
		
			mwin.vc.push_back(new Circle{Point{9*padX + i*(padX*2/size), static_cast<int>(2.5*padY + (2*round-1)*padY)},padX/(2*size)});
			mwin.vc[mwin.vc.size()-1].set_fill_color(7);
			mwin.attach(mwin.vc[mwin.vc.size()-1]);

	}
	for(int j = 0; j < correctPosition; ++j) {
		
			mwin.vc.push_back(new Circle{Point{9*padX + j*(padX*2/size), static_cast<int>(2.5*padY + (2*round-1)*padY)},padX/(2*size)});
			mwin.vc[mwin.vc.size()-1].set_fill_color(0);
			mwin.attach(mwin.vc[mwin.vc.size()-1]);
	}
}

void hideCode(MastermindWindow &mwin, const int size)
{
	mwin.vr.push_back(new Rectangle{Point{padX, 3 * padY}, winW - size * padX, padY});
	mwin.vr[mwin.vr.size() - 1].set_fill_color(Color::black);
	mwin.attach(mwin.vr[mwin.vr.size() - 1]);
}

MastermindWindow::MastermindWindow(Point xy, int w, int h, const string &title) : Window(xy, w, h, title),
																				  button_pressed{false},
																				  guessBtn{upperLeftCornerBtn, btnW, btnH, "Add", cb_guess},
																				  guess{upperLeftCornerInBox, inBoxW, inBoxH, "Guess"}
{
	attach(guess);
	attach(guessBtn);
};

string MastermindWindow::wait_for_guess()
{
	while (!button_pressed)
	{
		Fl::wait();
	}
	button_pressed = false;
	string newGuess = guess.get_string();
	guess.clear_value();
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput)
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input[i];
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again\n";
		}
	}
	return guess;
}
