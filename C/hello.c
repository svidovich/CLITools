#include <ncurses.h>
int main()
{
	initscr(); 		/* Starts curses   */
	printw("Testing...");   /* Prints...  	   */
	refresh(); 		/* Puts to screen  */
	getch();		/* Wait for USR    */
	endwin();		/* Ends curses	   */
}
