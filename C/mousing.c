#include <curses.h>

int main ()
{
	int ch;
	bool cont = true;
	initscr();
	mousemask(BUTTON1_CLICKED, NULL);
	keypad(stdscr, TRUE);
	printw("Click!\n");
	printw("Press F1 to leave.\n");
	refresh();
	while (cont)
	{
		MEVENT mouseevent;
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
					int y = mouseevent.y;
					int x = mouseevent.x;
					int z = mouseevent.z;
					printw("Left Click\n");
					mvaddch(0, 0, y);
//					mvwaddch(0, 2, y);
//					mvwaddch(0, 4, z);
					refresh();
				}
			}
		}
	}
	endwin();
	return 0;
}
