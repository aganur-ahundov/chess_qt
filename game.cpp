#include "game.h"
#include "igamecontroller.h"
#include "igraphicscontroller.h"



Game::Game()
{
    m_gameController = QSharedPointer < IGameController > ( new IGameController() );
    m_graphController = QSharedPointer < IGraphicsController > ( new IGraphicsController() );

    connect( m_graphController.data(), SIGNAL( clicked_on_board( QPoint ) )
             , m_gameController.data(), SLOT( boardHaveBeenClicked( QPoint ) ) );

    connect( m_gameController.data(), SIGNAL( moved( QPoint,QPoint ) )
             , m_graphController.data(), SLOT( move_piece( QPoint,QPoint ) ) );

    connect( m_gameController.data(), SIGNAL( boared_create_piece_signal( QString,QPoint))
             , m_graphController.data(), SLOT( create_piece( QString,QPoint )) );

    m_gameController->start();
}


void Game::display() const
{
    m_graphController->show();
}
