#include <ncurses.h>

int main()
{
	int ch;
	initscr(); 		// on
	raw();	   		// no line buffering -- we don't press enter to refresh
	keypad(stdscr, TRUE);   // Get F1, F2, etc
	noecho();		// No echoing input from usr. Escape characters don't appear.
	printw("Type something!\n");
	ch = getch();
	if(ch == KEY_F(1))
		printw("F1 detected");
	else
	{
		attron(A_BOLD);  // Attribute on...
		printw("%c", ch);
		attroff(A_BOLD); // Attribute off.
	}
	refresh();		 // Print
	getch();		 // Get user input
	endwin();		 // Turn off
	return 0;
}
