#include <curses.h>
#include <unistd.h>

int main () {
	int ch;
	int a;
	int b;
	initscr();
	raw();
	noecho();
	ch = getch();
	printw("%c",ch);
	for (a = 0; a < 20; a++)
	{
		for (b = 0; b < 20; b++)
		{
			mvaddch(2*a+1,2*b-1,ch);
			refresh();
			usleep(900);
		}
	}
	getch();
	endwin();
	return 0;
}
