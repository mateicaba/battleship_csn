#include "Game.h"

Game::Game() :USER(0), COMPUTER(1), STARTED(1)
{
	state = 0;
	secondHitPlayed = false;
}

bool Game::check(Board& board)
{
	if (board.getBoatInfo() == 13)
	{
		board.messageBox("JOCUL    INCEPE!    PREGATITI-VA");
		return true;
	}
	else if (board.getBoatInfo() > 13)
	{
		board.messageBox("MUTATI    BARCILE    IN    POZITII    VALIDE!");
	}
	else { board.messageBox("MUTATI    BARCILE    DIN    MIJLOC    PE    GRID"); }

	return false;
}


void Game::start(sf::RenderWindow& win, Board& board, Boat& boat, computerBoard& cb)
{
	if (cb.getBoatInfo()) { board.messageBox("AI    CASTIGAT!    FELICITARI!"); }
	else if (!board.checkBoatOnGrid()) { board.messageBox("AI PIERDUT! MAI INCEARCA O DATA!"); }

	else if (!cb.getBoatInfo() || board.checkBoatOnGrid()) {
		// USER PLAY ON COMPUTER GRID
		if (state == USER) {
			board.messageBox("INCERCATI  POZITII  PE  GRIDUL  DIN  DREAPTA");
			if (cb.gridEvent(win)) {
				// IF THE GAME IS STARTED SET STATUS TO FALSE AND BLOCK BOAT POSITION
				boat.setStatus(false);
				if (cb.returnHitInformation() && !secondHitPlayed) { state = USER; secondHitPlayed = true; }
				else { state = COMPUTER; secondHitPlayed = false; }
			}
		}
		else {
			// COMPUTER PLAY ON THE USER GRID
			if (cb.play(board)) { state = USER; }
			else {
				board.messageBox("CALCULATORUL    A    NIMERIT!"); cb.play(board);
				state = USER;
			}
			board.messageBox("CALCULATORUL    ALEGE...");
		}
	}
}