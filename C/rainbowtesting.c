#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

WINDOW *createwindow(int height, int width, int y0, int x0);
void removewindow(WINDOW *the_window);
void buildmenu(WINDOW *the_window, int n);//, char *string)

int main ()
{
	char *choices[]
	{
		"I",
		"II",
		"III",
		"IV",
		"Exit"
	}
	// sizeof(choices) gives the size of an array of character pointers.
	// Character pointers are bigger than 1.
	// So, we need to divide by the size of a character pointer.
	int n = sizeof(choices)/sizeof(char *);
	WINDOW *tl;
	WINDOW *tr; 
	WINDOW *bl;
	WINDOW *br;
	srand(time(0));
	int ch;
	int a, b, x, y;
	initscr();
	cbreak();
//	raw();
	noecho();
	getmaxyx(stdscr, y, x);
	refresh();
	tl = createwindow(y/2,x/2, 0, 0);
	tr = createwindow(y/2,x/2, 0, x/2);
	bl = createwindow(y/2,x/2, y/2, 0);
	br = createwindow(y/2,x/2, y/2, x/2);
	keypad(tl, TRUE);
	keypad(tr, TRUE);
	keypad(bl, TRUE);
	keypad(br, TRUE);
	refresh();
	buildmenu(tl,1);
	refresh();
	getch();
	delwin(tl);
	delwin(tr);
	endwin();
	return 0;
}



WINDOW *createwindow(int height, int width, int y0, int x0)
{
	// Let's initialize a window.
	WINDOW *the_window;
	the_window = newwin(height, width, y0, x0);
	// We're going to put a box around the window.
	wborder(the_window, ':', ':', '~', '~', 'x', 'x', 'x', 'x');
	wrefresh(the_window);
	return the_window;
}

void removewindow(WINDOW *the_window)
{
	delwin(the_window);
}

// Builds a menu with n options
void buildmenu(WINDOW *the_window, int n)//, char *string)
{
	int i, x, y;
	n++;
	getmaxyx(the_window, y, x);
	mvwprintw(the_window, y/2, x/2, "%s", "Menu Item");
	
//	for ( i = 0; i < n; i++)
//	{
//		wattron(the_window, A_BOLD);
//		mvwprint()
//	}
	wrefresh(the_window);
}


















