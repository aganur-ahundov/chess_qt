#include "game.h"
#include "igamecontroller.h"
#include "igraphicscontroller.h"



Game::Game()
{
    m_gameController = QSharedPointer < IGameController > ( new IGameController() );
    m_graphController = QSharedPointer < IGraphicsController > ( new IGraphicsController() );

    connect( m_graphController.data(), SIGNAL( clicked_on_board( QPoint ) )
             , m_gameController.data(), SLOT( boardHaveBeenClicked(QPoint) ) );
}
