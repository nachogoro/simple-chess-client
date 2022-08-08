#include <simplechess/GameManager.h>

#include <iostream>

std::string getPieceRepresentation(simplechess::Piece piece)
{
	if (piece.color() == simplechess::Color::White)
	{
		switch (piece.type())
		{
			case simplechess::PieceType::Pawn:
				return "\u2659";
			case simplechess::PieceType::Rook:
				return "\u2656";
			case simplechess::PieceType::Knight:
				return "\u2658";
			case simplechess::PieceType::Bishop:
				return "\u2657";
			case simplechess::PieceType::Queen:
				return "\u2655";
			case simplechess::PieceType::King:
				return "\u2654";
		}
	}
	else
	{
		switch (piece.type())
		{
			case simplechess::PieceType::Pawn:
				return "\u265F";
			case simplechess::PieceType::Rook:
				return "\u265C";
			case simplechess::PieceType::Knight:
				return "\u265E";
			case simplechess::PieceType::Bishop:
				return "\u265D";
			case simplechess::PieceType::Queen:
				return "\u265B";
			case simplechess::PieceType::King:
				return "\u265A";
		}
	}

	throw std::runtime_error("Unknown piece");
}

void drawBoard(const simplechess::Board& board)
{
	//std::cout << "\[[2J";
	std::cout << "+---+---+---+---+---+---+---+---+\n";
	for (uint8_t rank = 8; rank > 0; rank--)
	{
		std::cout << "|";
		for (char file = 'a'; file <= 'h'; ++file)
		{
			const std::optional<simplechess::Piece> piece = board.pieceAt(simplechess::Square::fromRankAndFile(rank, file));
			const std::string toDraw = piece ? getPieceRepresentation(*piece) : " ";
			std::cout << " " << toDraw << " |";
		}
		std::cout << "\n";
		std::cout << "+---+---+---+---+---+---+---+---+\n";
	}
}

int main()
{
	const simplechess::GameManager gameMgr;
	simplechess::Game game = gameMgr.createNewGame();

	while (game.gameState() == simplechess::GameState::Playing)
	{
		drawBoard(game.currentStage().board());
		std::cin.get();
		const auto move = *game.allAvailableMoves().begin();
		game = gameMgr.makeMove(
				game,
				move);
	}

	std::cout << static_cast<int>(game.gameState()) << "\n";
	if (game.gameState() == simplechess::GameState::Drawn)
	{
		std::cout << static_cast<int>(game.drawReason()) << "\n";
	}

	return 0;
}
