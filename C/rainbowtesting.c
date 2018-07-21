#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

WINDOW *createwindow(int height, int width, int y0, int x0);
void removewindow(WINDOW *the_window);
void buildmenu(WINDOW *the_window, int highlight);

	// Highlight represents a cursor, choices represents menu items.
	// For more items and cursors, make more of these.
	int highlight = 1;
	char *choices[5] =
	{
		"I",
		"II",
		"III",
		"IV",
		"Exit"
	};
	// sizeof(choices) gives the size of an array of character pointers.
	// Character pointers are bigger than 1.
	// So, we need to divide by the size of a character pointer.
	int n = sizeof(choices)/sizeof(char *);

int main ()
{

	int choice = 0;
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
	buildmenu(tl,highlight);
	while(1)
	{
		// This will get complicated with multiple menus.
		ch = wgetch(tl);
		switch(ch)
		{
			case KEY_UP:
				// If I'm at the top and I press up,
				if( highlight == 1 )
					// Highlight the last option
					highlight = n;
				else
					// Otherwise, move up the list
					--highlight;
				break;
			case KEY_DOWN:
				// If I'm at the bottom and I press down,
				if( highlight == n)
					// Highlight the first option
					highlight = 1;
				else
					// Otherwise, move down the list
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
			default:
				break;
		}
		buildmenu(tl, highlight);
		// User pressed enter.
		if( choice != 0 )
			break;
	}
	// Clear to end of line.
	clrtoeol;
	refresh();
	getch();
	delwin(tl);
	delwin(tr);
	delwin(bl);
	delwin(br);
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
void buildmenu(WINDOW *the_window, int highlight)
{
	int i, x, y;
	// Choose a sensible location inside the current box
	// where we will start our menu.
	x = 2;
	y = 2;
	for ( i = 0; i < n; ++i )
	{
		if ( highlight == i + 1 )
		{
			wattron(the_window, A_REVERSE);
			mvwprintw(the_window, y, x, "%s", choices[i]);
			wattroff(the_window, A_REVERSE);
		}
		else
			mvwprintw(the_window, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(the_window);
}


















