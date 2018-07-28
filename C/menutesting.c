#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

WINDOW *createwindow(int height, int width, int y0, int x0, int id);
void removewindow(WINDOW *the_window);
void buildmenu(WINDOW *the_window, int highlight);
void band(WINDOW *the_window);
void curl(WINDOW *the_window);
void clearwin(WINDOW *the_window);
void navigatemenu(WINDOW *the_window);
void snake(WINDOW *the_window);
void zone(WINDOW *the_window);

// TODO: Make this into a struct that holds all of this data 
//       then, the  menu becomes arbitrary.
	// Highlight represents a cursor, choices represents menu items.
	// For more items and cursors, make more of these.
	int highlight = 1;
	char *choices[5] =
	{
		"Band",
		"Curl",
		"Snake",
		"Zone",
		"Exit"
	};
	// sizeof(choices) gives the size of an array of character pointers.
	// Character pointers are bigger than 1.
	// So, we need to divide by the size of a character pointer.
	int n = sizeof(choices)/sizeof(char *);

int main ()
{
	WINDOW *tl;
	WINDOW *tr; 
	WINDOW *bl;
	WINDOW *br;
	int ch;
	int a, b, x, y;
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	getmaxyx(stdscr, y, x);
	start_color();
	refresh();
	// These lines initialize colors so we can do rainbows as desired
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
 	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);

	// These lines create windows in the program, top left to bottom right
	tl = createwindow(y/2,x/2, 0, 0, 1);
	tr = createwindow(y/2,x/2, 0, x/2, 2);
	bl = createwindow(y/2,x/2, y/2, 0, 3);
	br = createwindow(y/2,x/2, y/2, x/2, 4);
	refresh();
	// This allows us to use function keys in each of the windows
	keypad(stdscr, TRUE);
	keypad(tl, TRUE);
	keypad(tr, TRUE);
	keypad(bl, TRUE);
	keypad(br, TRUE);
	bool playing = true;
	while(playing)
	{
			int windowselection;
			windowselection = wgetch(stdscr);
			if( windowselection == KEY_F(1))
			{
				navigatemenu(tl);
			}
			else if( windowselection == KEY_F(2))
			{
				navigatemenu(tr);
			}
			else if( windowselection == KEY_F(3))
			{
				navigatemenu(bl);
			}
			else if( windowselection == KEY_F(4))
			{
				navigatemenu(br);
			}
			else if( windowselection == KEY_F(9))
			{
				playing = false;
			}
			else
			{
				continue;
			}
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

void navigatemenu(WINDOW *the_window)
{
	clearwin(the_window);
	buildmenu(the_window,highlight);
	while(1)
	{
		int choice = 0;
		int ch;
		wrefresh(the_window);
		// This will get complicated with multiple menus.
		ch = wgetch(the_window);
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
			case '\n':
				choice = highlight;
				break;
			default:
				break;
		}
		// User pressed enter.
		if( choice == 1 )
			{
				clearwin(the_window);
				band(the_window);
				clearwin(the_window);
			}
		else if( choice == 2 )
			{
				clearwin(the_window);
				curl(the_window);
				clearwin(the_window);
			}
		else if( choice == 3 )
			{
				clearwin(the_window);
				snake(the_window);
				clearwin(the_window);
			}
		else if( choice == 4 )
			{
				clearwin(the_window);
				zone(the_window);
				clearwin(the_window);
			}
		else if( choice != 0 )
			{
				break;
			}
		buildmenu(the_window, highlight);
	}


}

WINDOW *createwindow(int height, int width, int y0, int x0, int id)
{
	// This will convert the integer id into a character
	id += '0';
	// Let's initialize a window.
	WINDOW *the_window;
	the_window = newwin(height, width, y0, x0);
	// We're going to put a box around the window.
	wborder(the_window, ':', ':', '~', '~', id, 'x', 'x', 'x');
	wrefresh(the_window);
	return the_window;
}

void removewindow(WINDOW *the_window)
{
	delwin(the_window);
}

// TODO: Fix weird coloring issues with the menu options
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

void band(WINDOW *the_window)
{
	int i, j, x, y, ch;
	ch = getch();
	getmaxyx(the_window, y, x);
	for ( i = 1; i < y-1; i ++)
	{
		for ( j = 1; j < x-1; j++ )
		{
			wattron(the_window, COLOR_PAIR(i % 7));
			mvwaddch(the_window, i, j, ch);
			wattroff(the_window, COLOR_PAIR(i % 7));
			wrefresh(the_window);
			usleep(1500);
		}
	}
	getch();

}

void curl(WINDOW *the_window)
{
	int i, j, xmax, ymax, xmin, ymin, ch;
	xmin = 1;
	ymin = 1;
	ch = getch();
	getmaxyx(the_window, ymax, xmax);
	ymax -= 2;
	xmax -= 2;
	while( ymax >= ymin && xmax >= xmin )
	{
		for( j = xmin; j <= xmax; j++ )
		{
			wattron(the_window, COLOR_PAIR(i % 7));
			mvwaddch(the_window, ymin, j, ch);
			wattroff(the_window, COLOR_PAIR(i % 7));
			wrefresh(the_window);
			usleep(1500);
		}
		ymin += 1;
		for( i = ymin; i <= ymax; i++ )
		{
			wattron(the_window, COLOR_PAIR(i % 7));
			mvwaddch(the_window, i, xmax, ch);
			wattroff(the_window, COLOR_PAIR(i % 7));
			wrefresh(the_window);
			usleep(1500);
		}
		xmax -= 1;
		for( j = xmax; j >= xmin; j-- )
		{
			wattron(the_window, COLOR_PAIR(i % 7));
			mvwaddch(the_window, ymax, j, ch);
			wattroff(the_window, COLOR_PAIR(i % 7));
			wrefresh(the_window);
			usleep(1500);
		}
		ymax -= 1;
		for( i = ymax; i >= ymin; i-- )
		{
			wattron(the_window, COLOR_PAIR(i % 7));
			mvwaddch(the_window, i, xmin, ch);
			wattroff(the_window, COLOR_PAIR(i % 7));
			wrefresh(the_window);
			usleep(1500);
		}
		xmin += 1;
	}
	getch();
}


void snake(WINDOW *the_window)
{
	int i, j, xmin, xmax, ymin, ymax, ch;
	ch = getch();
	getmaxyx(the_window, ymax, xmax);
	xmin = 1;
	while( xmin < xmax-1 )
	{
		for ( j = 1; j < ymax-1; j++ )
		{
			mvwaddch(the_window, j, xmin, ch);
			wrefresh(the_window);
			usleep(10000);
		}
		xmin++;
		for ( j = ymax-2; j >= 1; j-- )
		{
			mvwaddch(the_window, j, xmin, ch);
			wrefresh(the_window);
			usleep(10000);
		}
		xmin++;
	}
	getch();
}

void zone(WINDOW *the_window)
{
	int i, j, ymax, ymin, xmax, xmin, cursor;
	char ch;
	xmin = 1;
	ymin = 1;
	cursor = 0;
	getmaxyx(the_window, ymax, xmax);
	ymax -= 2;
	xmax -= 2;
	while( xmin <= xmax && ymin < ymax )
	{
		if ( cursor > 2 )
		{
			cursor = 0;
		}
		for ( j = ymin; j < ymax; j++ )
		{
			if ( cursor == 0 )
			{
				ch = '&';
				wmove(the_window, j, xmin);
				wprintw(the_window, "%c", ch);
			}
			else if ( cursor == 1 )
			{
				ch = '%';
				wmove(the_window, j, xmin);
				wprintw(the_window, "%c", ch);
			}
			else if ( cursor == 2 )
			{
				ch = '$';
				wmove(the_window, j, xmin);
				wprintw(the_window, "%c", ch);
			}
		}
		xmin++;
		for ( i = xmin-1; i <= xmax; i++ )
		{
			if ( cursor == 0 )
			{
				ch = '&';
				wmove(the_window, ymax, i);
				wprintw(the_window, "%c", ch);
			}
			else if ( cursor == 1 )
			{
				ch = '%';
				wmove(the_window, ymax, i);
				wprintw(the_window, "%c", ch);
			}
			else if ( cursor == 2 )
			{
				ch = '$';
				wmove(the_window, ymax, i);
				wprintw(the_window, "%c", ch);
			}
		}
		ymax--;
		for ( j = ymin; j <= ymax; j++ )
		{
			if ( cursor == 0 )
			{
				ch = '&';
				wmove(the_window, j, xmax);
				wprintw(the_window, "%c", ch);
			}
			else if ( cursor == 1 )
			{
				ch = '%';
				wmove(the_window, j, xmax);
				wprintw(the_window, "%c", ch);
			}
			else if ( cursor == 2 )
			{
				ch = '$';
				wmove(the_window, j, xmax);
				wprintw(the_window, "%c", ch);
			}
		}
		xmax--;
		for ( i = xmin; i <= xmax; i++ )
		{
			if ( cursor == 0 )
			{
				ch = '&';
				wmove(the_window, ymin, i);
				wprintw(the_window, "%c", ch);
			}
			else if ( cursor == 1 )
			{
				ch = '%';
				wmove(the_window, ymin, i);
				wprintw(the_window, "%c", ch);
			}
			else if ( cursor == 2 )
			{
				ch = '$';
				wmove(the_window, ymin, i);
				wprintw(the_window, "%c", ch);
			}
		}
		ymin++;
		wrefresh(the_window);
		usleep(200000);
		cursor++;
	}
	getch();
}

void clearwin(WINDOW *the_window)
{
	int i, j, x, y, ch;
	ch = ' ';
	getmaxyx(the_window, y, x);
	for ( i = 1; i < y-1; i++ )
	{
		for ( j = 1; j < x-1; j ++ )
		{
			mvwaddch(the_window, i, j, ch);
		}
	}
	wrefresh(the_window);
}












