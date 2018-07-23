#include <curses.h>
#include <unistd.h>

void starburst(MEVENT mouseevent);
int main ()
{
	int ch, a, b;
	bool cont = true;
	initscr();
	clear();
	noecho();
	mousemask(BUTTON1_CLICKED, NULL);
	keypad(stdscr, TRUE);
	MEVENT mouseevent;
	// keypad(window, TRUE); Need this line with additional windows, per window
	printw("Click!\n");
	printw("Press F1 to leave.\n");
	refresh();
	getmaxyx(stdscr, a, b);
	while (cont)
	{
		ch = getch();
		// If we detect F1,
		if ( ch == KEY_F(1) )
		{
			// Exit.
			cont = false;
		}
		// If we detect a mouse,
		else if ( ch == KEY_MOUSE )
		{
			// Check if we got the event okay.
			if ( getmouse(&mouseevent) == OK )
			{
				// getmouse returns the struct
				// {
				//   short id;        id of device
				//   int x, y, z;     coordinates
				//   mmask_t bstate;  button state bits
				if( mouseevent.bstate & BUTTON1_CLICKED )
				{
					starburst(mouseevent);
//					int z = mouseevent.z;
//					printw("Left Click\n");
//					mvwaddch(stdscr,y,x,"the");
					refresh();
					continue;
//					mvaddch(a-2, b-6, u);
//					mvwaddch(0, 2, y);
//					mvwaddch(0, 4, z);
				}
			}
		}
	}
	endwin();
	return 0;
}



void starburst(MEVENT mouseevent)
{
	move(mouseevent.y + 1, mouseevent.x);
//	printw("%d,%d",mouseevent.y,mouseevent.x);
	printw("*");
	move(mouseevent.y - 1 , mouseevent.x);
	printw("*");
	move(mouseevent.y, mouseevent.x + 1);
	printw("*");
	move(mouseevent.y, mouseevent.x - 1);
	printw("*");
}
