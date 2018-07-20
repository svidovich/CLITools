#include <curses.h>

int main () {
	int ch;
	bool quit = true;
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	printw("ShItTy TypeR v0.000000.\nF1: Bold\nF2: Exit\n");
	while(quit)
	{
		ch = getch();
		if (ch == KEY_F(1))
		{
			ch = getch();
			attron(A_BOLD);
			printw("%c",ch);
			attroff(A_BOLD);
		}	
		else if(ch == KEY_F(2))
		{
			quit = false;
		}	
		else
		{
			printw("%c",ch);
		}
		refresh();
	}
	endwin();
	return 0;
}
