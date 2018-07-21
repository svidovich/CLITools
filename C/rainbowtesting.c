#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

WINDOW *createwindow(int heigh, int width, int y0, int x0);

int main ()
{
	srand(time(0));
	int ch;
	int a, b, x, y;
	initscr();
	raw();
	start_color();
	noecho();
	getmaxyx(stdscr, y, x);
	ch = getch();
	getch();
	endwin();
	return 0;
}



WINDOW *createwindow(int heigh, int width, int y0, int x0)
{
	// Let's initialize a window.
	WINDOW *the_window;
	the_window = newwin(height, width, starty, startx);
	// We're going to put a box around the window.
	box(the_window, 0, 0);
	wrefresh(the_window);
	return the_window;
}

void removewindow(WINDOW *the_window)
{
	delwin(the_window);
}
